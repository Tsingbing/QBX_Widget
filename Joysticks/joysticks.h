#ifndef JOYSTICKS_H
#define JOYSTICKS_H

#include <QtWidgets/QMainWindow>
#include "ui_joysticks.h"

class Joysticks : public QMainWindow
{
	Q_OBJECT

public:
	Joysticks(QWidget *parent = 0);
	~Joysticks();

private:
	Ui::JoysticksClass ui;
};

#endif // JOYSTICKS_H
