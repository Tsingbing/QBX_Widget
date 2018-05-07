#pragma once
/***************************************************************************//**
 * @file qbx_Temperature.h
 * @author  
 * @section 
 ******************************************************************************/
#ifndef QBX_TEMPERATURE_H
#define QBX_TEMPERATURE_H

/////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

/////////////////////////////////////////////////////////////////////////////////

class qbx_Temperature : public QGraphicsView
{
	Q_OBJECT

public:
	qbx_Temperature(QWidget *parent = 0);
	
	virtual ~qbx_Temperature();

	void reinit();

	void update();

	void setDepth(float depth);


protected:

	void resizeEvent(QResizeEvent *event);

private:

	QGraphicsScene *m_scene;
	QGraphicsSvgItem *m_itemBack;
	QGraphicsTextItem *m_itemLabel0;
	QGraphicsTextItem *m_itemLabel1;
	QGraphicsTextItem *m_itemLabel2;

	float m_scaleX;
	float m_scaleY;
	const int m_originalHeight;
	const int m_originalWidth;
	const int m_originalLabelsX;
	const int m_originalLabel0Y;
	const int m_originalLabel1Y;
	const int m_originalLabel2Y;

	QPointF m_originalAdiCtr;
	QFont m_labelsFont;
	QColor m_labelsColor;

	float m_Temperature;

	void init();

	void reset();

	void updateView();
};


#endif // QBX_TEMPERATURE_H

