#ifndef SERIAL_H
#define SERIAL_H

#include <QtWidgets/QMainWindow>
#include "ui_serial.h"
#include "masterthread.h"

class Serial : public QMainWindow
{
	Q_OBJECT

public:
	Serial(QWidget *parent = 0);
	~Serial();

private:
	Ui::SerialClass ui;

private slots:
	void transaction();
	void showResponse(const QString &s);
	void processError(const QString &s);
	void processTimeout(const QString &s);

private:
	void setControlsEnabled(bool enable);

private:
	int transactionCount;
	MasterThread thread;
};

#endif // SERIAL_H
