/***************************************************************************//**
* @file qbx_Compass.cpp
* @author
* @section
******************************************************************************/
#ifndef qbx_Compass_CPP
#define qbx_Compass_CPP
#endif // !qbx_Compass_CPP

#include "qbx_Compass.h"
#include <QGraphicsEffect>

qbx_Compass::qbx_Compass(QWidget *parent) :
	QGraphicsView(parent),
	m_scene(0),
	m_itemBack(0),
	m_itemHand(0),
	m_direction(0.0f),
	m_distance(0.0f),
	m_scaleX(1.0f),
	m_scaleY(1.0f),
	m_originalWidth(360),
	m_originalHeight(360),
	m_originalCompassCtr(179.7f, 179.7f),
	m_faceZ(10),
	m_handZ(-10),
	m_caseZ(-20)
{
	reset();

	m_scene = new QGraphicsScene(this);
	setScene(m_scene);

	m_scene->clear();

	init();
}

qbx_Compass::~qbx_Compass()
{
	if (m_scene)
	{
		m_scene->clear();
		delete m_scene;
		m_scene = 0;
	}

	reset();
}

void qbx_Compass::reinit()
{
	if (m_scene)
	{
		m_scene->clear();
		init();
	}
}

void qbx_Compass::update()
{
	updateView();
}

void qbx_Compass::setDirection(float direction)
{
	m_direction = direction;
}

void qbx_Compass::setDistance(float distance)
{
	m_distance = distance;
}

void qbx_Compass::resizeEvent(QResizeEvent * event)
{
	QGraphicsView::resizeEvent(event);

	reinit();
}

void qbx_Compass::init()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	reset();

	m_itemBack = new QGraphicsSvgItem(":/Compass/Resources/images/Compass/compass_hand.svg");
	m_itemBack->setCacheMode(QGraphicsItem::NoCache);
	m_itemBack->setZValue(m_faceZ);
	m_itemBack->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemBack->setTransformOriginPoint(m_originalCompassCtr);
	m_scene->addItem(m_itemBack);

	m_itemHand = new QGraphicsSvgItem(":/Compass/Resources/images/Compass/compass_ring.svg");
	m_itemHand->setCacheMode(QGraphicsItem::NoCache);
	m_itemHand->setZValue(m_handZ);
	m_itemHand->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemHand->setTransformOriginPoint(m_originalCompassCtr);

	m_scene->addItem(m_itemHand);

	centerOn(width() / 2.0f, height() / 2.0f);

	updateView();
}

void qbx_Compass::reset()
{
	m_itemBack = 0;
	m_itemHand = 0;
	m_direction = 0.0f;
	m_distance = 0.0f;
}

void qbx_Compass::updateView()
{
	//int direction = ceil(m_direction + 0.5);
	//float dis = ceil(m_distance + 0.5);

	//float angleH = m_direction * 0.36f;
	float angleH = m_direction;

	m_itemHand->setRotation(angleH);
//	m_itemCase->setTransform(distance * 18);

	m_scene->update();
}
