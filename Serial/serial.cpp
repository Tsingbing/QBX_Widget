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

	setRequestData(CMD_MOVE);
	thread.transaction(
		ui.serialPortComboBox->currentText(),
		ui.waitResponseSpinBox->value(),
		requestData);
}

void Serial::showResponse(const QByteArray & s)
{
	setControlsEnabled(true);
	
	//添加解析函数，将QByteArray反序列化。
	//const DataPackage_TypeDef* pData = (DataPackage_TypeDef*)(s.data());
	
	//memcpy(&DataMove, &(pData->Code), sizeof(DataMove));  //数字11 = 12 - 1字节对齐
	//if (QString(s.toHex()).left(2)== "aa" && QString(s.toHex()).right(2) == "bb")
	{
		//memcpy(&DataMove, s.data()+5, s[1] - 6);//截取字节段copy到结构体。
		getResponseData(s);
		ui.showDate->setText(s.toHex(':'));
		ui.trafficLabel->setText(
				tr(	" Speed       %1"
				"\n\rDirection:  %2"
				"\n\rlightpower: %3")
				.arg(QString::number(DataMove.Speed))
				.arg(QString::number(DataMove.Direction))
				.arg(QString::number(DataMove.lightpower)));
	}	
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

void Serial::setRequestData(TrainCmd cmd)
{
	QByteArray Code;  //
	requestData.clear();
	/*requestData[0] = 0xAA;
	DataMove.Speed = 1;
	DataMove.Direction = 2;
	DataMove.lightpower = 3;
	DataMove.Deepset = 4;
	DataMove.Roll = 5;
	DataMove.Yaw = 6;
	Code = QByteArray::fromRawData((char*)&DataMove, sizeof(DataMove));
	requestData[1] = sizeof(DataMove) + 6;*/

	//也是无法进入CMD_MOVE
	switch (cmd)
	{
		CMD_MOVE: //0
			DataMove.Speed = 1;
			DataMove.Direction = 2;
			DataMove.lightpower = 3;
			DataMove.Deepset = 4;
			DataMove.Roll = 5;
			DataMove.Yaw = 6;
			Code = QByteArray::fromRawData((char*)&DataMove, sizeof(DataMove));
			requestData[1] = sizeof(DataMove) + 6;
			break;
		CMD_STATE:

			break;
		CMD_FORMATE:

			break;
		CMD_LASERCONTROL:

			break;
		CMD_PICTUREINF:

			break;
		CMD_GPSCOORD:

			break;
		CMD_SOUNDCONTROL:

			break;
		CMD_DOWNLOADCONTROL:

			break;
		default:
			break;
	}
	requestData[2] = 0xFE;
	requestData[3] = 0x01;
	requestData[4] = 0x00;
	requestData += Code;
	requestData += 0xBB;
}

void Serial::getResponseData(const QByteArray & s)
{
	if (QString(s.toHex()).left(2) == "aa" && QString(s.toHex()).right(2) == "bb")
	{
		//无法进入cmd
		switch (int(s[4]))
		{
		CMD_MOVE: //0
			memcpy(&DataMove, s.data() + 5, s[1] - 6);//截取字节段copy到结构体。
			break;
		CMD_STATE:

			break;
		CMD_FORMATE:

			break;
		CMD_LASERCONTROL:

			break;
		CMD_PICTUREINF:

			break;
		CMD_GPSCOORD:

			break;
		CMD_SOUNDCONTROL:

			break;
		CMD_DOWNLOADCONTROL:

			break;
		default:
			break;
		}
	}
}

