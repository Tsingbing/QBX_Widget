#include "mui.h"

MUI::MUI(QWidget *parent)
	: QWidget(parent),
	m_realTime(0.0f),
	m_timerId(0)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	timer->start(33);
	m_timerId = startTimer(0);
	//connect(timer, SIGNAL(timeout()), this, SLOT(update()));

	m_time.start();
}

MUI::~MUI()
{

}

void MUI::timerEvent(QTimerEvent * event)
{
	/////////////////////////////////
	QWidget::timerEvent(event);
	/////////////////////////////////

	float timeStep = m_time.restart();
	m_realTime = m_realTime + timeStep / 1000.0f;

	float roll = 0.0f;
	roll = 180 * sin(m_realTime / 5.0f);
	ui.graphicsMUI->setRoll(roll);

	float pitch = 0.0f;
	pitch = 90.0f * sin(m_realTime / 40.0f) + 90.0f;
	ui.graphicsMUI->setPitch(pitch);
	ui.graphicsMUI->update();
}

void MUI::update()
{
	ui.graphicsMUI->update();
}

