#include "qbx_Video.h"
#include <QTimer>
#include <QPainter>
#include <qDebug>

qbx_Video::qbx_Video(QWidget * parent) 
	: QWidget(parent),
	m_timerId(0)
{
	timer = new QTimer(this);
	timer->start(1);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
}

qbx_Video::~qbx_Video() {
	
}

void qbx_Video::setID(int id)
{
	if (cap.open(id))
	{
		//cap.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
		//cap.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
		imp.robotTrackInit(cap);
	}
	else
	{
		//输出错误日志
	}
}

QImage qbx_Video::Mat2Image(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)                             //3 channels color image
	{
		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}

	return qImg;
}

void qbx_Video::paintEvent(QPaintEvent * event)
{
	cap >> frame;
	//

	frame = imp.robotTrackDetect1(frame);
	//update();
	//
	image = Mat2Image(frame);

	QPainter painter(this);
	QPixmap m_pixmap;
	m_pixmap = QPixmap::fromImage(image);
	painter.drawPixmap(0, 0, m_pixmap);
}
