#pragma once
/***************************************************************************//**
 * @file qbx_MUI.h
 * @author  
 * @section 
 ******************************************************************************/
#ifndef QBX_MUI_H
#define QBX_MUI_H

/////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

/////////////////////////////////////////////////////////////////////////////////

class qbx_MUI : public QGraphicsView
{
	Q_OBJECT

public:
	qbx_MUI(QWidget *parent = 0);
	
	virtual ~qbx_MUI();

	void reinit();

	/** @param roll angle [deg] */
	inline void setRoll(float roll)
	{
		m_roll = roll;
	}

	/** @param pitch angle [deg] */
	inline void setPitch(float pitch)
	{
		m_pitch = pitch;
	}

	inline void setWaring(bool flag)
	{
		m_Waring_flag = flag;
	}

	void update();


protected:

	void resizeEvent(QResizeEvent *event);

private:

	QGraphicsScene *m_scene;
	QGraphicsSvgItem *m_itemBack;
	QGraphicsSvgItem *m_itemHand;
	QGraphicsSvgItem *m_itemRing;
	QGraphicsTextItem *m_itemLabel0;
	QGraphicsTextItem *m_itemLabel1;
	QGraphicsTextItem *m_itemLabel2;
	QGraphicsTextItem *m_itemLabel3;

	QFont m_labelsFont;
	QColor m_labelsColor;

	const float m_originalLabelsX;
	const float m_originalLabel1Y;
	const float m_originalLabel2Y;
	const float m_originalLabel3Y;
	const float m_originalLabel0X;
	const float m_originalLabel0Y;
	float m_labelsDeltaY_new;
	float m_labelsDeltaY_old;

	const float m_originalPixPerAlt;

	bool m_Waring_flag = false;

	float m_roll;
	float m_pitch;

	float m_scaleX;
	float m_scaleY;
	const int m_originalHeight;
	const int m_originalWidth;
	QPointF m_originalMUICtr;

	QPointF m_originalAdiCtr;

	void init();

	void reset();

	
	void updateView();
};


#endif // QBX_MUI_H

