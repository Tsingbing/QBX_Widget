#ifndef MUI_H
#define MUI_H

#include <QtWidgets/QWidget>
#include "ui_mui.h"
#include <QTime>
#include <QTimer>
#include "masterthread.h"
#include "data_struct.h"
#include <QTime>
#include <QtSerialPort/QSerialPortInfo>

class MUI : public QWidget
{
	Q_OBJECT

public:
	MUI(QWidget *parent = 0);
	~MUI();

//private slots:
//	void update();

protected:
	void timerEvent(QTimerEvent *event);

private:
	Ui::MUIClass ui;
	QTime m_time;
	float m_realTime;
	QTimer *timer;
	int m_timerId;
	int m_steps;

///////////////////////////´®¿Ú ////////////////////////////
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
/////////////////////////////////////////////////////////////
};

#endif // MUI_H
