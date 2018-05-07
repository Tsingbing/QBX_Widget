#ifndef POWER_H
#define POWER_H

#include <QtWidgets/QWidget>
#include "ui_power.h"

class Power : public QWidget
{
	Q_OBJECT

public:
	Power(QWidget *parent = 0);
	~Power();

private:
	Ui::PowerClass ui;
};

#endif // POWER_H
