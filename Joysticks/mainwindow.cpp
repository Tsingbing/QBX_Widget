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
    //this->setCentralWidget(ui->verticalLayoutWidget);
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

    //Setup the UI for the hat Toggled state
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


	////////////////////////////////////////////////////////////////////////////
	{
		//this->setCentralWidget(ui->verticalLayoutWidget_2);
		//ui->widget->setCentralWidget(ui->verticalLayoutWidget_2);
		joystick2 = new QJoystick();

		//Exit if no joystick attached
		if (joystick2->numJoysticks() == 0)
		{
			qCritical() << "No joystick attached. QUITTING...";
			exit(-1);
		}

		//Configure the joystick
		joystick2->currentJoystick(1);   //choose the first joystick
		for (int i = 0; i < joystick2->numAxes(); i++)
		{
			Q_ASSERT(joystick2->deadzone(i, (i != 2 && i != 5 ? 16000 : 0)));
		}

		joystick2->bilinearEnable(true);
		joystick2->bilinearConstant(1.25);


		vBox2 = (QVBoxLayout*)ui->verticalLayoutWidget_2->layout();

		//Get Joystick Name
		QLabel *jsName2 = new QLabel();
		ui->verticalLayoutWidget_2->layout()->addWidget(jsName2);
		jsName2->setText(joystick2->name());

		//Set up the UI for the buttons toggled state
		QHBoxLayout *hButtonToggled2 = new QHBoxLayout();
		for (int i = 0; i < joystick2->numButtons(); i++)
		{
			QCheckBox *cb = new QCheckBox();
			cb->setChecked(false);
			cb->setCheckable(true);
			hButtonToggled2->addWidget(cb);
			buttonsToggled2.append(cb);
		}
		vBox2->addLayout(hButtonToggled2);

		//Set up the UI for the buttons pressed state
		QHBoxLayout *hButtonPressed2 = new QHBoxLayout();
		for (int i = 0; i < joystick2->numButtons(); i++)
		{
			QCheckBox *cb = new QCheckBox();
			cb->setChecked(false);
			cb->setCheckable(true);
			hButtonPressed2->addWidget(cb);
			buttonsPressed2.append(cb);
		}
		vBox2->addLayout(hButtonPressed2);

		//Set up the UI for the axes values
		QHBoxLayout *hAxesValues2 = new QHBoxLayout();
		for (int i = 0; i < joystick2->numAxes(); i++)
		{
			QProgressBar *pb = new QProgressBar();
			pb->setMinimum(-32768);
			pb->setMaximum(32767);
			hAxesValues2->addWidget(pb);
			axesValues2.append(pb);
		}
		vBox2->addLayout(hAxesValues2);

		//Setup the UI for the hat Toggled state
		QHBoxLayout *hHatsToggled2 = new QHBoxLayout();
		for (int i = 0; i < 9; i++)
		{
			QCheckBox *cb = new QCheckBox();
			cb->setChecked(false);
			cb->setCheckable(true);
			hHatsToggled2->addWidget(cb);
			hatsToggled2.append(cb);
		}
		vBox2->addLayout(hHatsToggled2);

		//Setup the UI for the hat pressed state
		QHBoxLayout *hHatsPressed2 = new QHBoxLayout();
		for (int i = 0; i < 9; i++)
		{
			QCheckBox *cb = new QCheckBox();
			cb->setChecked(false);
			cb->setCheckable(true);
			hHatsPressed2->addWidget(cb);
			hatsPressed2.append(cb);
		}
		vBox2->addLayout(hHatsPressed2);

		//Connect the joystick signals
		connect(joystick2, SIGNAL(buttonPressed(int)), this, SLOT(onButtonPressed2(int)));
		connect(joystick2, SIGNAL(buttonReleased(int)), this, SLOT(onButtonReleased2(int)));
		connect(joystick2, SIGNAL(buttonToggled(int, bool)), this, SLOT(onButtonToggled2(int, bool)));
		connect(joystick2, SIGNAL(hatPressed(int, int)), this, SLOT(onHatPressed2(int, int)));
		connect(joystick2, SIGNAL(hatReleased(int, int)), this, SLOT(onHatReleased2(int, int)));
		connect(joystick2, SIGNAL(hatToggled(int, int, bool)), this, SLOT(onHatToggled2(int, int, bool)));
		connect(joystick2, SIGNAL(axesUpdated(QList<int>)), this, SLOT(onAxesUpdated2(QList<int>)));
	}
	////////////////////////////////////////////////////////////////////////////
}

MainWindow::~MainWindow()
{
	//delete joystick;
	delete joystick2;
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

//////////////////////////////////////////////////////////////////////////
void MainWindow::onButtonPressed2(int button)
{
	buttonsPressed2[button]->setChecked(true);
}

void MainWindow::onButtonReleased2(int button)
{
	buttonsPressed2[button]->setChecked(true);

}

void MainWindow::onButtonToggled2(int button, bool state)
{
	buttonsToggled2[button]->setChecked(state);
}

void MainWindow::onHatPressed2(int hat, int dir)
{
	hatsPressed2[dir]->setChecked(true);
}

void MainWindow::onHatReleased2(int hat, int dir)
{
	hatsPressed2[dir]->setChecked(false);
}

void MainWindow::onHatToggled2(int hat, int dir, bool state)
{
	hatsToggled2[dir]->setChecked(state);
}

void MainWindow::onAxesUpdated2(QList<int> values)
{
	for (int i = 0; i<axesValues2.count(); i++)
	{
		axesValues2[i]->setValue(values[i]);
	}
}
//////////////////////////////////////////////////////////////////////