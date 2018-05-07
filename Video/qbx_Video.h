#pragma once
#include <QWidget>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "demo_detect_track.h"

class qbx_Video : public QWidget {
	Q_OBJECT

public:
	qbx_Video(QWidget * parent = Q_NULLPTR);
	~qbx_Video();
	void setID(int id);

protected:
	QImage Mat2Image(cv::Mat cvImg);
	void paintEvent(QPaintEvent * event);

private:
	QTimer *timer;
	int m_timerId;

	cv::Mat frame;
	QImage image;
	cv::VideoCapture cap;
	ImageProcessing imp;
};
