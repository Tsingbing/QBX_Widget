#pragma once
#include <QObject>
#include <masterthread.h>

class qbx_Serial : public QObject {
	Q_OBJECT

public:
	qbx_Serial(QObject * parent = 0);
	~qbx_Serial();
	
	//设置串口号
	void setPortName(QString port);
	//解析下位机数据
	void parseData(const QByteArray &src, const QString des);

private slots:
	//发送下位机数据
	void sendData(const QByteArray &message);
	//接收下位机数据
	void reciveData(const QByteArray &message);
	

private:
	MasterThread thread;
	QByteArray data;

	QString portName;
};
