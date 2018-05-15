#ifndef SERIAL_H
#define SERIAL_H

#include <QtWidgets/QMainWindow>
#include "ui_serial.h"
#include "masterthread.h"
#include <QTime>

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
	void showResponse(const QByteArray &s);
	void processError(const QString &s);
	void processTimeout(const QString &s);

private:
	void setControlsEnabled(bool enable);
	void setRequestData(TrainCmd cmd);
	void getResponseData(const QByteArray & s);

private:
	int transactionCount;
	QByteArray requestData;
	MasterThread thread;
	Data_STATEACK_TypeDef DataStateAck;
	Data_MOVE_TypeDef DataMove;//

protected:
	void timerEvent(QTimerEvent *event);

private:
	int m_timerId;

	float m_realTime;
	QTime m_time;
};

#endif // SERIAL_H
