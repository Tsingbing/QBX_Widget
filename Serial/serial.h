#ifndef SERIAL_H
#define SERIAL_H

#include <QtWidgets/QMainWindow>
#include "ui_serial.h"

class Serial : public QMainWindow
{
	Q_OBJECT

public:
	Serial(QWidget *parent = 0);
	~Serial();

private:
	Ui::SerialClass ui;
};

#endif // SERIAL_H
