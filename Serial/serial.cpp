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
	//const DataPackage_TypeDef* pData = (DataPackage_TypeDef*)(s.data());
	
	//memcpy(&DataMove, &(pData->Code), sizeof(DataMove));  //数字11 = 12 - 1字节对齐
    memcpy(&DataMove, s.data()+5, s[1] - 6);//截取字节段copy到结构体。
	
	ui.trafficLabel->setText(
		tr(	" Speed       %1"
		"\n\rDirection:  %2"
		"\n\rlightpower: %3")
		.arg(QString::number(DataMove.Speed))
		.arg(QString::number(DataMove.Direction))
		.arg(QString::number(DataMove.lightpower)));
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

