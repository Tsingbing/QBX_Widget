#pragma once
/***************************************************************************//**
 * @file qbx_Menu.h
 * @author  
 * @section 
 ******************************************************************************/
#ifndef QBX_MENU_H
#define QBX_MENU_H

/////////////////////////////////////////////////////////////////////////////////

#include <QGraphicsView>
#include <QGraphicsSvgItem>

/////////////////////////////////////////////////////////////////////////////////

class qbx_Menu : public QGraphicsView
{
	Q_OBJECT

public:
	qbx_Menu(QWidget *parent = 0);
	
	virtual ~qbx_Menu();

	void reinit();

	void update();


protected:

	void resizeEvent(QResizeEvent *event);

private:

	QGraphicsScene *m_scene;
	QGraphicsSvgItem *m_itemBack;
	QGraphicsSvgItem *m_itemLogo;
	QGraphicsSvgItem *m_itemSub;

	float m_scaleX;
	float m_scaleY;
	const int m_originalHeight;
	const int m_originalWidth;
	const int m_originalLogoY;
	const int m_originalLogoX;
	const int m_originalSubY;
	const int m_originalSubX;

	void init();

	void reset();

	void updateView();
};


#endif // QBX_MENU_H

