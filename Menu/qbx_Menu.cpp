/***************************************************************************//**
* @file qbx_Menu.cpp
* @author
* @section
******************************************************************************/
#ifndef QBX_MENU_CPP
#define QBX_MENU_CPP
#endif // !QBX_MENU_CPP

#include "qbx_Menu.h"
#include <qDebug>

qbx_Menu::qbx_Menu(QWidget *parent) :
	QGraphicsView(parent),
	m_scene(0),
	m_itemBack(0),
	m_itemLogo(0),
	m_scaleX(1.0f),
	m_scaleY(1.0f),
	m_originalWidth(1920),
	m_originalHeight(49),
	m_originalLogoX(135),
	m_originalLogoY(24),
	m_originalSubX(1880),
	m_originalSubY(24)
{
	reset();

	m_scene = new QGraphicsScene(this);
	setScene(m_scene);

	m_scene->clear();

	init();
}

qbx_Menu::~qbx_Menu()
{
	if (m_scene)
	{
		m_scene->clear();
		delete m_scene;
		m_scene = 0;
	}

	reset();
}

void qbx_Menu::reinit()
{
	if (m_scene)
	{
		m_scene->clear();
		init();
	}
}

void qbx_Menu::update()
{
	updateView();

}

void qbx_Menu::resizeEvent(QResizeEvent * event)
{
	QGraphicsView::resizeEvent(event);

	reinit();
}

void qbx_Menu::init()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	reset();

	m_itemBack = new QGraphicsSvgItem(":/Menu/Resources/images/Menu/menu_face.svg");
	m_itemBack->setCacheMode(QGraphicsItem::NoCache);
	m_itemBack->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_scene->addItem(m_itemBack);

	//无法调用logo.svg
	m_itemLogo = new QGraphicsSvgItem(":/Menu/Resources/images/Menu/menu_logo1.svg");
	m_itemLogo->setCacheMode(QGraphicsItem::NoCache);
	m_itemLogo->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLogo->moveBy(m_scaleX * (m_originalLogoX - m_itemLogo->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalLogoY - m_itemLogo->boundingRect().height() / 2.0f));

	qDebug() << m_itemLogo->boundingRect().width() << endl;
	m_scene->addItem(m_itemLogo);

	m_itemSub = new QGraphicsSvgItem(":/Menu/Resources/images/Menu/menu_sub.svg");
	m_itemSub->setCacheMode(QGraphicsItem::NoCache);
	m_itemSub->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemSub->moveBy(m_scaleX * (m_originalSubX - m_itemSub->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalSubY - m_itemSub->boundingRect().height() / 2.0f));
	m_scene->addItem(m_itemSub);
	centerOn(width() / 2.0f, height() / 2.0f);

	updateView();
}

void qbx_Menu::reset()
{
}

void qbx_Menu::updateView()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	m_scene->update();
}
