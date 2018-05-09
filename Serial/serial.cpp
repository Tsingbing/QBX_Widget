#include "serial.h"
#include <QtSerialPort/QSerialPortInfo>

Serial::Serial(QWidget *parent)
	: QMainWindow(parent)
	, transactionCount(0)
{
	ui.setupUi(this);
	const auto infos = QSerialPortInfo::availablePorts();
	for (const QSerialPortInfo &info : infos)
		ui.serialPortComboBox->addItem(info.portName());

	connect(ui.runButton, &QPushButton::clicked, this, &Serial::transaction);
	connect(&thread, &MasterThread::response, this, &Serial::showResponse);
	connect(&thread, &MasterThread::error, this, &Serial::processError);
	connect(&thread, &MasterThread::timeout, this, &Serial::processTimeout);
}

Serial::~Serial()
{

}

void Serial::transaction()
{
	setControlsEnabled(false);
	ui.statusLabel->setText(tr("Status: Running, connected to port %1.")
		.arg(ui.serialPortComboBox->currentText()));
	thread.transaction(ui.serialPortComboBox->currentText(),
		ui.waitResponseSpinBox->value(),
		ui.requestLineEdit->text());
}

void Serial::showResponse(const QByteArray & s)
{
	setControlsEnabled(true);
	
	//添加解析函数，将QByteArray反序列化。
	const DataPackage_TypeDef* pData = (DataPackage_TypeDef*)(s.data());
	Data_MOVE_TypeDef DataMove;//
	memcpy(&DataMove, &(pData->Code), pData->PackageLength - 11);  //数字11 = 12 - 1字节对齐
    //memcpy(&DataMove, (char*)(pData)+4, pData->PackageLength - 6);//截取字节段copy到结构体。

	ui.trafficLabel->setText(tr("Traffic, transaction #%1:"
		"\n\r-request: %2"
		"\n\r-response: %3")
		.arg(QString::number(DataMove.Yaw)).arg(ui.requestLineEdit->text()).arg(QString(s.data())));

}

void Serial::processError(const QString & s)
{
	setControlsEnabled(true);
	ui.statusLabel->setText(tr("Status: Not running, %1.").arg(s));
	ui.trafficLabel->setText(tr("No traffic."));
}

void Serial::processTimeout(const QString & s)
{
	setControlsEnabled(true);
	ui.statusLabel->setText(tr("Status: Running, %1.").arg(s));
	ui.trafficLabel->setText(tr("No traffic."));

}

void Serial::setControlsEnabled(bool enable)
{
	ui.runButton->setEnabled(enable);
	ui.serialPortComboBox->setEnabled(enable);
	ui.waitResponseSpinBox->setEnabled(enable);
	ui.requestLineEdit->setEnabled(enable);
}

