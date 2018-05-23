#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "data_struct.h"

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

	////////////////////////////////////////////
	void onButtonPressed2(int button);
	void onButtonReleased2(int button);
	void onButtonToggled2(int button, bool state);
	void onHatPressed2(int hat, int dir);
	void onHatReleased2(int hat, int dir);
	void onHatToggled2(int hat, int dir, bool state);
	void onAxesUpdated2(QList<int> values);
	////////////////////////////////////////////

private:
    Ui::MainWindow *ui;
	QJoystickInterface *joystick;
	
    QVBoxLayout *vBox;
    QList<QCheckBox*> buttonsToggled;
    QList<QCheckBox*> buttonsPressed;

    QList<QCheckBox*> hatsToggled;
    QList<QCheckBox*> hatsPressed;

    QList<QProgressBar*> axesValues;

	/////////////////////////////////
	QJoystickInterface *joystick2;
	QVBoxLayout *vBox2;
	QList<QCheckBox*> buttonsToggled2;
	QList<QCheckBox*> buttonsPressed2;

	QList<QCheckBox*> hatsToggled2;
	QList<QCheckBox*> hatsPressed2;

	QList<QProgressBar*> axesValues2;
	//////////////////////////////////

	Data_MOVE_TypeDef DataMove;//
};

#endif // MAINWINDOW_H
