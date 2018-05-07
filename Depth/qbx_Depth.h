#pragma once
/***************************************************************************//**
 * @file qbx_Depth.h
 * @author  
 * @section 
 ******************************************************************************/
#ifndef QBX_DEPTH_H
#define QBX_DEPTH_H

/////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

/////////////////////////////////////////////////////////////////////////////////

class qbx_Depth : public QGraphicsView
{
	Q_OBJECT

public:
	qbx_Depth(QWidget *parent = 0);
	
	virtual ~qbx_Depth();

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

	float m_scaleX;
	float m_scaleY;
	const int m_originalHeight;
	const int m_originalWidth;
	const int m_originalLabelsX;
	const int m_originalLabel0Y;
	const int m_originalLabel1Y;

	QPointF m_originalAdiCtr;
	QFont m_labelsFont;
	QColor m_labelsColor;

	float m_depth1;
	float m_depth2;

	void init();

	void reset();

	void updateView();
};


#endif // QBX_DEPTH_H

