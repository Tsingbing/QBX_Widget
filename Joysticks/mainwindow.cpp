#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qjoystick.h"
#include <QLabel>
#include <QList>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->verticalLayoutWidget);
    joystick = new QJoystick();

    //Exit if no joystick attached
    if(joystick->numJoysticks() == 0)
    {
        qCritical() << "No joystick attached. QUITTING...";
        exit(-1);
    }

    //Configure the joystick
    joystick->currentJoystick(0);   //choose the first joystick
    for(int i=0; i< joystick->numAxes(); i++)
    {
        Q_ASSERT(joystick->deadzone(i, (i != 2 && i != 5 ? 16000 : 0)));
    }
    joystick->bilinearEnable(true);
    joystick->bilinearConstant(1.25);


    vBox = (QVBoxLayout*)ui->verticalLayoutWidget->layout();

    //Get Joystick Name
    QLabel *jsName = new QLabel();
    ui->verticalLayoutWidget->layout()->addWidget(jsName);
    jsName->setText(joystick->name());

    //Set up the UI for the buttons toggled state
    QHBoxLayout *hButtonToggled = new QHBoxLayout();
    for(int i=0; i<joystick->numButtons(); i++)
    {
        QCheckBox *cb = new QCheckBox();
        cb->setChecked(false);
        cb->setCheckable(true);
        hButtonToggled->addWidget(cb);
        buttonsToggled.append(cb);
    }
    vBox->addLayout(hButtonToggled);

    //Set up the UI for the buttons pressed state
    QHBoxLayout *hButtonPressed = new QHBoxLayout();
    for(int i=0; i<joystick->numButtons(); i++)
    {
        QCheckBox *cb = new QCheckBox();
        cb->setChecked(false);
        cb->setCheckable(true);
        hButtonPressed->addWidget(cb);
        buttonsPressed.append(cb);
    }
    vBox->addLayout(hButtonPressed);

    //Set up the UI for the axes values
    QHBoxLayout *hAxesValues = new QHBoxLayout();
    for(int i=0; i<joystick->numAxes(); i++)
    {
        QProgressBar *pb = new QProgressBar();
        pb->setMinimum(-32768);
        pb->setMaximum(32767);
        hAxesValues->addWidget(pb);
        axesValues.append(pb);
    }
    vBox->addLayout(hAxesValues);

    //Setup the UI for the hat pressed state
    QHBoxLayout *hHatsToggled = new QHBoxLayout();
    for(int i=0; i<9; i++)
    {
        QCheckBox *cb = new QCheckBox();
        cb->setChecked(false);
        cb->setCheckable(true);
        hHatsToggled->addWidget(cb);
        hatsToggled.append(cb);
    }
    vBox->addLayout(hHatsToggled);

    //Setup the UI for the hat pressed state
    QHBoxLayout *hHatsPressed = new QHBoxLayout();
    for(int i=0; i<9; i++)
    {
        QCheckBox *cb = new QCheckBox();
        cb->setChecked(false);
        cb->setCheckable(true);
        hHatsPressed->addWidget(cb);
        hatsPressed.append(cb);
    }
    vBox->addLayout(hHatsPressed);

    //Connect the joystick signals
    connect(joystick, SIGNAL(buttonPressed(int)), this, SLOT(onButtonPressed(int)));
    connect(joystick, SIGNAL(buttonReleased(int)), this, SLOT(onButtonReleased(int)));
    connect(joystick, SIGNAL(buttonToggled(int, bool)), this, SLOT(onButtonToggled(int, bool)));
    connect(joystick, SIGNAL(hatPressed(int, int)), this, SLOT(onHatPressed(int, int)));
    connect(joystick, SIGNAL(hatReleased(int, int)), this, SLOT(onHatReleased(int, int)));
    connect(joystick, SIGNAL(hatToggled(int, int, bool)), this, SLOT(onHatToggled(int, int, bool)));
    connect(joystick, SIGNAL(axesUpdated(QList<int>)), this, SLOT(onAxesUpdated(QList<int>)));
}

MainWindow::~MainWindow()
{
    delete joystick;
    delete ui;
}

void MainWindow::onButtonPressed(int button)
{
    buttonsPressed[button]->setChecked(true);
}

void MainWindow::onButtonReleased(int button)
{
    buttonsPressed[button]->setChecked(false);
}

void MainWindow::onButtonToggled(int button, bool state)
{
    buttonsToggled[button]->setChecked(state);
}

void MainWindow::onHatPressed(int hat, int dir)
{
    hatsPressed[dir]->setChecked(true);
}

void MainWindow::onHatReleased(int hat, int dir)
{
    hatsPressed[dir]->setChecked(false);
}

void MainWindow::onHatToggled(int hat, int dir, bool state)
{
    hatsToggled[dir]->setChecked(state);
}

void MainWindow::onAxesUpdated(QList<int> values)
{
    for(int i=0; i<axesValues.count(); i++)
    {
        axesValues[i]->setValue(values[i]);
    }
}
