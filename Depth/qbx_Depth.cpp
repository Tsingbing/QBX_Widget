/***************************************************************************//**
* @file qbx_Depth.cpp
* @author
* @section
******************************************************************************/
#ifndef QBX_DEPTH_CPP
#define QBX_DEPTH_CPP
#endif // !QBX_DEPTH_CPP

#include "qbx_Depth.h"

qbx_Depth::qbx_Depth(QWidget *parent) :
	QGraphicsView(parent),
	m_scene(0),
	m_itemBack(0),
	m_itemLabel0(0),
	m_itemLabel1(0),
	m_scaleX(1.0f),
	m_scaleY(1.0f),
	m_originalWidth(308),
	m_originalHeight(308),
	m_originalLabelsX(125),
	m_originalLabel0Y(110),
	m_originalLabel1Y(196),
	m_labelsColor(0,255,0),
	m_depth1(0),
	m_depth2(0)
{
	reset();

	m_labelsFont.setFamily("ºÚÌå");
	m_labelsFont.setPointSizeF(25.0f);
	m_labelsFont.setStretch(QFont::Condensed);
	m_labelsFont.setWeight(QFont::Bold);

	m_scene = new QGraphicsScene(this);
	setScene(m_scene);

	m_scene->clear();

	init();
}

qbx_Depth::~qbx_Depth()
{
	if (m_scene)
	{
		m_scene->clear();
		delete m_scene;
		m_scene = 0;
	}

	reset();
}

void qbx_Depth::reinit()
{
	if (m_scene)
	{
		m_scene->clear();
		init();
	}
}

void qbx_Depth::update()
{
	updateView();

}

void qbx_Depth::setDepth(float depth)
{
	m_depth1 = depth;
	m_depth2 = depth;
}

void qbx_Depth::resizeEvent(QResizeEvent * event)
{
	QGraphicsView::resizeEvent(event);

	reinit();
}

void qbx_Depth::init()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	reset();

	m_itemBack = new QGraphicsSvgItem(":/Depth/Resources/images/Depth/Depth.svg");
	m_itemBack->setCacheMode(QGraphicsItem::NoCache);
	m_itemBack->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_scene->addItem(m_itemBack);

	m_itemLabel0 = new QGraphicsTextItem(QString("99"));
	m_itemLabel0->setCacheMode(QGraphicsItem::NoCache);
	//m_itemLabel0->setZValue(m_labelsZ);
	m_itemLabel0->setDefaultTextColor(m_labelsColor);
	m_itemLabel0->setFont(m_labelsFont);
	m_itemLabel0->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLabel0->moveBy(m_scaleX * (m_originalLabelsX - m_itemLabel0->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalLabel0Y - m_itemLabel0->boundingRect().height() / 2.0f));
	m_scene->addItem(m_itemLabel0);

	m_itemLabel1 = new QGraphicsTextItem(QString("99"));
	m_itemLabel1->setCacheMode(QGraphicsItem::NoCache);
	//m_itemLabel1->setZValue(m_labelsZ);
	m_itemLabel1->setDefaultTextColor(m_labelsColor);
	m_itemLabel1->setFont(m_labelsFont);
	m_itemLabel1->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLabel1->moveBy(m_scaleX * (m_originalLabelsX - m_itemLabel1->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalLabel1Y - m_itemLabel1->boundingRect().height() / 2.0f));
	m_scene->addItem(m_itemLabel1);

	centerOn(width() / 2.0f, height() / 2.0f);

	updateView();
}

void qbx_Depth::reset()
{
}

void qbx_Depth::updateView()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	/////////////////////////////////////////////////////////////////////////////
	m_itemLabel0->setVisible(true);
	//m_itemLabel0->setPlainText(QString("%1").arg(m_depth1, 5, 'f', 0, QChar(' ')));
	m_itemLabel0->setPlainText(QString("%1").arg(m_depth1));
	m_itemLabel1->setVisible(true);
	m_itemLabel1->setPlainText(QString("%1").arg(m_depth2, 5, 'f', 0, QChar(' ')));

	m_scene->update();
}
