#include "serial.h"
#include <math.h>



Serial::Serial(QWidget *parent)
	: QMainWindow(parent)
	, transactionCount(0)
	, m_timerId(0)
	, m_realTime(0.0)
{
	ui.setupUi(this);
	const auto infos = QSerialPortInfo::availablePorts();
	for (const QSerialPortInfo &info : infos)
		ui.serialPortComboBox->addItem(info.portName());

	connect(ui.runButton, &QPushButton::clicked, this, &Serial::transaction);
	connect(&thread, &MasterThread::response, this, &Serial::showResponse);
	connect(&thread, &MasterThread::error, this, &Serial::processError);
	connect(&thread, &MasterThread::timeout, this, &Serial::processTimeout);
	m_timerId = startTimer(0);
	m_time.start();
}

Serial::~Serial()
{
	if (m_timerId) killTimer(m_timerId);
}

void Serial::transaction()
{
	setControlsEnabled(false);
	ui.statusLabel->setText(tr("Status: Running, connected to port %1.")
		.arg(ui.serialPortComboBox->currentText()));
	switch (ui.sendCMDBox->currentText().toInt())
	{
	case 0:
		setRequestData(CMD_MOVE);
		break;
	case 1:
		setRequestData(CMD_STATE);
		break;
	case 2:
		setRequestData(CMD_FORMATE);
		break;
	case 3:
		setRequestData(CMD_LASERCONTROL);
		break;
	case 4:
		setRequestData(CMD_PICTUREINF);
		break;
	case 5:
		setRequestData(CMD_GPSCOORD);
		break;
	case 6:
		setRequestData(CMD_SOUNDCONTROL);
		break;
	case 7:
		setRequestData(CMD_DOWNLOADCONTROL);
		break;
	default:
		break;
	}
	//setRequestData(CMD_MOVE);

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
		/*ui.trafficLabel->setText(
				tr(	" Speed       %1"
				"\n\rDirection:  %2"
				"\n\rlightpower: %3")
				.arg(QString::number(DataStateAck.speed))
				.arg(QString::number(DataStateAck.Direction))
				.arg(QString::number(DataStateAck.Power)));*/

		ui.trafficLabel->setText(tr(
			"\n\r-DatastateAck.speed	 : %1"
			"\n\r-DatastateAck.Direction : %2"
			"\n\r-DatastateAck.Power     : %3"
			"\n\r-DatastateAck.Temp      : %4"
			"\n\r-DatastateAck.Hum		 : %5"
			"\n\r-DatastateAck.Roll		 : %6"
			"\n\r-DatastateAck.pitch	 : %7"
			"\n\r-DatastateAck.Yaw		 : %8"
			"\n\r-DatastateAck.pointID	 : %9"
			"\n\r-DatastateAck.v         : %10"
			"\n\r-DatastateAck.NowDeepth : %11"
			"\n\r-DatastateAck.point.x	 : %12"
			"\n\r-DatastateAck.point.y   : %13"
		)
			.arg((int)(DataStateAck.speed))
			.arg((int)(DataStateAck.Direction))
			.arg((int)(DataStateAck.Power))
			.arg((int)(DataStateAck.Temp))
			.arg((int)(DataStateAck.Hum))
			.arg((int)(DataStateAck.Roll))
			.arg((int)(DataStateAck.pitch))
			.arg((int)(DataStateAck.Yaw))
			.arg((int)(DataStateAck.pointID))
			.arg((int)(DataStateAck.v))
			.arg((int)(DataStateAck.NowDeepth))
			.arg((int)(DataStateAck.point.x))
			.arg((int)(DataStateAck.point.y))
		);
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
	requestData[0] = 0xAA;
	requestData[2] = 0xFE;
	requestData[3] = 0x01;
	switch (cmd)
	{
		case CMD_MOVE: //0
			Code = QByteArray::fromRawData((char*)&DataMove, sizeof(DataMove));
			requestData[1] = sizeof(DataMove) + 6;
			requestData[4] = 0x00;
			break;
		case CMD_STATE:
			requestData[1] = 1 + 6;
			requestData[4] = 0x01;
			Code[0] = 0x00;
			break;
		case CMD_FORMATE:
			requestData[1] = 1 + 6;
			requestData[4] = 0x02;
			Code[0] = 0x00;
			break;
		case CMD_LASERCONTROL:
			requestData[1] = 1 + 6;
			requestData[4] = 0x03;
			Code[0] = 0x00;
			break;
		case CMD_PICTUREINF:
			requestData[1] = 1 + 6;
			requestData[4] = 0x04;
			Code[0] = 0x00;
			break;
		case CMD_GPSCOORD:
			requestData[1] = 1 + 6;
			requestData[4] = 0x05;
			Code[0] = 0x00;
			break;
		case CMD_SOUNDCONTROL:
			requestData[1] = 1 + 6;
			requestData[4] = 0x06;
			Code[0] = 0x00;
			break;
		case CMD_DOWNLOADCONTROL:
			requestData[1] = 1 + 6;
			requestData[4] = 0x07;
			Code[0] = 0x00;
			break;
		default:
			break;
	}
	requestData += Code;
	requestData += 0xBB;

	ui.requestLineEdit->setText(requestData.toHex(':'));
}

void Serial::getResponseData(const QByteArray & s)
{
	//if (QString(s.toHex()).left(2) == "aa" && QString(s.toHex()).right(2) == "bb")
	if (s[0] == (char)0xaa && s[s.size() - 1] == (char)0xbb)
	{
		switch (s[4])
		{
		case CMD_MOVE: //0
			memcpy(&DataMove, s.data() + 5, s[1] - 6);//截取字节段copy到结构体。
			break;
		case CMD_STATE:
			memcpy(&DataStateAck, s.data() + 5, s[1] - 6);//截取字节段copy到结构体。
			break;
		case CMD_FORMATE:

			break;
		case CMD_LASERCONTROL:

			break;
		case CMD_PICTUREINF:

			break;
		case CMD_GPSCOORD:

			break;
		case CMD_SOUNDCONTROL:

			break;
		case CMD_DOWNLOADCONTROL:

			break;
		default:
			break;
		}
	}
}

void Serial::timerEvent(QTimerEvent * event)
{
	/////////////////////////////////
	QObject::timerEvent(event);
	/////////////////////////////////

	float timeStep = m_time.restart();

	m_realTime = m_realTime + timeStep / 1000.0f;

	DataMove.Speed = 50.0f * sin(m_realTime / 10.0f) + 50.0f; //速度
	DataMove.Direction = 100.0f * sin(m_realTime / 10.0f);     // 方向
	DataMove.lightpower = 5.0f * sin(m_realTime / 10.0f) + 5.0f;     //电量，0-5 
	DataMove.Deepset = 128.0f * sin(m_realTime / 20.0f);      //温度 +-128 
	DataMove.Roll = 180.0f * sin(m_realTime / 10.0f);    	 //侧倾角
	DataMove.Yaw = 50.0f  * sin(m_realTime / 20.0f) + 50.0f;		 //湿度 百分之 0-100 
}

