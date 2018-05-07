#pragma once
/***************************************************************************//**
 * @file qbx_Compass.h
 * @author  
 * @section 
 ******************************************************************************/
#ifndef QBX_COMPASS_H
#define QBX_COMPASS_H

/////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

/////////////////////////////////////////////////////////////////////////////////

class qbx_Compass : public QGraphicsView
{
	Q_OBJECT

public:
	qbx_Compass(QWidget *parent = 0);
	
	virtual ~qbx_Compass();

	void reinit();

	void update();

	void setDirection(float direction);

	void setDistance(float distance);

protected:

	void resizeEvent(QResizeEvent *event);

private:

	QGraphicsScene *m_scene;
	QGraphicsSvgItem *m_itemBack;
	QGraphicsSvgItem *m_itemHand;
	QGraphicsSvgItem *m_itemCase;

	float m_direction;
	float m_distance;

	float m_scaleX;
	float m_scaleY;
	const int m_originalHeight;
	const int m_originalWidth;

	QPointF m_originalCompassCtr;

	const int m_faceZ;
	const int m_handZ;
	const int m_caseZ;

	void init();

	void reset();

	void updateView();
};


#endif // QBX_COMPASS_H

