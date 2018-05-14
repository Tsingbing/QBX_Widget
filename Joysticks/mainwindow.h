#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class QJoystickInterface;
class QVBoxLayout;
class QCheckBox;
class QProgressBar;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onButtonPressed(int button);
    void onButtonReleased(int button);
    void onButtonToggled(int button, bool state);
    void onHatPressed(int hat, int dir);
    void onHatReleased(int hat, int dir);
    void onHatToggled(int hat, int dir, bool state);
    void onAxesUpdated(QList<int> values);

private:
    Ui::MainWindow *ui;
    QJoystickInterface *joystick;
    QVBoxLayout *vBox;
    QList<QCheckBox*> buttonsToggled;
    QList<QCheckBox*> buttonsPressed;

    QList<QCheckBox*> hatsToggled;
    QList<QCheckBox*> hatsPressed;

    QList<QProgressBar*> axesValues;
};

#endif // MAINWINDOW_H
