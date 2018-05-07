#include "compass.h"

Compass::Compass(QWidget *parent)
	: QWidget(parent),
	m_realTime(0.0f),
	m_timerId(0)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	timer->start(33);
	m_timerId = startTimer(0);

	m_time.start();
}

Compass::~Compass()
{

}

void Compass::timerEvent(QTimerEvent * event)
{
	/////////////////////////////////
	QWidget::timerEvent(event);
	/////////////////////////////////


	float timeStep = m_time.restart();
	m_realTime = m_realTime + timeStep / 1000.0f;

	float direction = 0.0f;
	direction = 180 * sin(m_realTime / 5.0f) + 180;
	ui.graphicsCompass->setDirection(direction);

	ui.graphicsCompass->update();
}
