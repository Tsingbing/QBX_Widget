#pragma once
#ifndef WIDGET_H  
#define WIDGET_H  

#include <QtCore>  
#include <QtGui>  
#include <QtWidgets/QWidget>
#include <QLabel>

class qbx_Power : public QWidget
{
	Q_OBJECT
public:
	qbx_Power(QWidget *parent = 0);
	~qbx_Power();
	void setUsedValue(int value);
	//void setSize(int width, int height);  
protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent * event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void showEvent(QShowEvent *event);
	void hideEvent(QHideEvent *event);

	private slots:
	void slotUpdateTimer();

private:
	QPoint beginDrag;
	bool bPressFlag;

	QPixmap backGround;
	int userdVaule;
	int currentValue;
	QLabel *startValueLabel;
	QLabel *endValueLabel;
	QLabel *dispayValueLabel;

	QTimer *updateTimer;
};

#endif // WIDGET_H  