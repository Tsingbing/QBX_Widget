#ifndef MUI_H
#define MUI_H

#include <QtWidgets/QWidget>
#include "ui_mui.h"
#include <QTime>
#include <QTimer>

class MUI : public QWidget
{
	Q_OBJECT

public:
	MUI(QWidget *parent = 0);
	~MUI();

private slots:
	void update();

protected:
	void timerEvent(QTimerEvent *event);

private:
	Ui::MUIClass ui;
	QTime m_time;
	float m_realTime;
	QTimer *timer;
	int m_timerId;
	int m_steps;
};

#endif // MUI_H
