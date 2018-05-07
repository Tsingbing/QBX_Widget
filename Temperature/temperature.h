#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QtWidgets/QWidget>
#include "ui_temperature.h"

class Temperature : public QWidget
{
	Q_OBJECT

public:
	Temperature(QWidget *parent = 0);
	~Temperature();

private:
	Ui::TemperatureClass ui;
};

#endif // TEMPERATURE_H
