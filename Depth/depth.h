#ifndef DEPTH_H
#define DEPTH_H

#include <QtWidgets/QWidget>
#include "ui_depth.h"
#include <QTimer>
#include <QTime>

class Depth : public QWidget
{
	Q_OBJECT

public:
	Depth(QWidget *parent = 0);
	~Depth();

protected:
	void timerEvent(QTimerEvent *event);

private:
	Ui::DepthClass ui;
	QTime m_time;
	float m_realTime;
	QTimer *timer;
	int m_timerId;
};

#endif // DEPTH_H
