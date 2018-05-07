#ifndef COMPASS_H
#define COMPASS_H

#include <QtWidgets/QWidget>
#include "ui_compass.h"
#include <QTime>
#include <QTimer>

class Compass : public QWidget
{
	Q_OBJECT
public:
	Compass(QWidget *parent = 0);
	~Compass();

protected:
	void timerEvent(QTimerEvent *event);

private:
	Ui::CompassClass ui;
	QTime m_time;
	float m_realTime;
	QTimer *timer;
	int m_timerId;
};

#endif // COMPASS_H
