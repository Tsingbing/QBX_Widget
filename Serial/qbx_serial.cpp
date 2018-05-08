#include "qbx_serial.h"

qbx_Serial::qbx_Serial(QObject * parent) 
	: QObject(parent),
	portName("COM1")
{
	connect(&thread, SIGNAL(response), this, SLOT(reciveData));
}

qbx_Serial::~qbx_Serial() {
	
}

void qbx_Serial::setPortName(QString port)
{
	this->portName = port;
}

void qbx_Serial::parseData(const QByteArray & src, const QString des)
{
	//解析数据
}

void qbx_Serial::reciveData(const QByteArray & message)
{
	this->data = message;
}

void qbx_Serial::sendData(const QByteArray & message)
{
	thread.transaction(portName,1000,message);
}
