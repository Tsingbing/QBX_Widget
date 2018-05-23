/***************************************************************************//**
* @file qbx_MUI.cpp
* @author
* @section
******************************************************************************/
#ifndef QBX_MUI_CPP
#define QBX_MUI_CPP
#endif // !QBX_MUI_CPP

#include "qbx_MUI.h"

qbx_MUI::qbx_MUI(QWidget *parent) :
	QGraphicsView(parent),
	m_scene(0),
	m_itemBack(0),
	m_itemLabel0(0),
	m_itemLabel1(0),
	m_itemLabel2(0),
	m_itemLabel3(0),
	m_scaleX(1.0f),
	m_scaleY(1.0f),
	m_roll(0.0f),
	m_pitch(0.0f),
	m_originalWidth(1000),
	m_originalHeight(1000),
	m_originalMUICtr(500.0f,500.0f),
	m_originalLabelsX(947),
	m_originalLabel0X(810),
	m_originalLabel0Y(485),
	m_labelsColor(44, 255, 121),
	m_originalPixPerAlt(33.0f),
	m_originalLabel1Y(335),
	m_originalLabel2Y(500),
	m_originalLabel3Y(665),
	m_labelsDeltaY_new(0.0f),
	m_labelsDeltaY_old(0.0f)
{
	reset();

	m_labelsFont.setFamily("ºÚÌå");
	m_labelsFont.setPointSizeF(21.0f);
	m_labelsFont.setStretch(QFont::Condensed);
	m_labelsFont.setWeight(QFont::Bold);

	m_scene = new QGraphicsScene(this);
	setScene(m_scene);

	m_scene->clear();

	init();
}

qbx_MUI::~qbx_MUI()
{
	if (m_scene)
	{
		m_scene->clear();
		delete m_scene;
		m_scene = 0;
	}

	reset();
}

void qbx_MUI::reinit()
{
	if (m_scene)
	{
		m_scene->clear();
		init();
	}
}

void qbx_MUI::update()
{
	updateView();
	m_labelsDeltaY_old = m_labelsDeltaY_new;
}

void qbx_MUI::resizeEvent(QResizeEvent * event)
{
	QGraphicsView::resizeEvent(event);

	reinit();
}

void qbx_MUI::init()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	reset();

	m_itemBack = new QGraphicsSvgItem(":/MUI/Resources/images/MUI/mui_face.svg");
	m_itemBack->setCacheMode(QGraphicsItem::NoCache);
	m_itemBack->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_scene->addItem(m_itemBack);

	m_itemRing = new QGraphicsSvgItem(":/MUI/Resources/images/MUI/mui_ring2.svg");
	m_itemRing->setCacheMode(QGraphicsItem::NoCache);
	m_itemRing->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemRing->setTransformOriginPoint(m_originalMUICtr);
	m_scene->addItem(m_itemRing);

	m_itemHand = new QGraphicsSvgItem(":/MUI/Resources/images/MUI/mui_ring.svg");
	m_itemHand->setCacheMode(QGraphicsItem::NoCache);
	m_itemHand->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemHand->setTransformOriginPoint(m_originalMUICtr);
	m_scene->addItem(m_itemHand);

	m_itemLabel0 = new QGraphicsTextItem(QString("99"));
	m_itemLabel0->setCacheMode(QGraphicsItem::NoCache);
	//m_itemLabel0->setZValue(m_labelsZ);
	m_itemLabel0->setDefaultTextColor(m_labelsColor);
	m_itemLabel0->setFont(m_labelsFont);
	m_itemLabel0->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLabel0->moveBy(m_scaleX * (m_originalLabel0X - m_itemLabel0->boundingRect().width() / 2.0f),
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

	m_itemLabel2 = new QGraphicsTextItem(QString("99"));
	m_itemLabel2->setCacheMode(QGraphicsItem::NoCache);
	//m_itemLabel1->setZValue(m_labelsZ);
	m_itemLabel2->setDefaultTextColor(m_labelsColor);
	m_itemLabel2->setFont(m_labelsFont);
	m_itemLabel2->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLabel2->moveBy(m_scaleX * (m_originalLabelsX - m_itemLabel1->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalLabel2Y - m_itemLabel1->boundingRect().height() / 2.0f));
	m_scene->addItem(m_itemLabel2);	

	m_itemLabel3 = new QGraphicsTextItem(QString("99"));
	m_itemLabel3->setCacheMode(QGraphicsItem::NoCache);
	//m_itemLabel1->setZValue(m_labelsZ);
	m_itemLabel3->setDefaultTextColor(m_labelsColor);
	m_itemLabel3->setFont(m_labelsFont);
	m_itemLabel3->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLabel3->moveBy(m_scaleX * (m_originalLabelsX - m_itemLabel3->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalLabel3Y - m_itemLabel3->boundingRect().height() / 2.0f));
	m_scene->addItem(m_itemLabel3);


	centerOn(width() / 2.0f, height() / 2.0f);

	updateView();
}

void qbx_MUI::reset()
{
}

void qbx_MUI::updateView()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	m_itemLabel0->setPlainText(QString("%1").arg(m_pitch , 5, 'f', 0, QChar(' ')));

	m_itemHand->setRotation(m_roll);
	m_itemRing->setRotation(m_roll);
	m_itemHand->show();
	m_itemRing->show();

	int tmp = floor(m_pitch + 0.5f);
	int alt = tmp - (tmp % 5);

	float alt1 = (float)alt + 5.0f;
	float alt2 = (float)alt;
	float alt3 = (float)alt - 5.0f;

	m_labelsDeltaY_new = m_scaleY * m_originalPixPerAlt * m_pitch;

	while (m_labelsDeltaY_new > m_scaleY * 150.0f)
	{
		m_labelsDeltaY_new = m_labelsDeltaY_new - m_scaleY * 165.0f;
	}

	if (m_labelsDeltaY_new < 0.0f && m_pitch > alt2)
	{
		alt1 += 5.0f;
		alt2 += 5.0f;
		alt3 += 5.0f;
	}

	m_itemLabel1->moveBy(0.0f, m_labelsDeltaY_new - m_labelsDeltaY_old);
	m_itemLabel2->moveBy(0.0f, m_labelsDeltaY_new - m_labelsDeltaY_old);
	m_itemLabel3->moveBy(0.0f, m_labelsDeltaY_new - m_labelsDeltaY_old);

	if (alt1 >= 0.0f && alt1 <= 180.0f)
	{
		m_itemLabel1->setVisible(true);
		m_itemLabel1->setPlainText(QString("%1").arg(alt1 - 90, 5, 'f', 0, QChar(' ')));
	}
	else
	{
		m_itemLabel1->setVisible(false);
	}

	if (alt2 >= 0.0f && alt2 <= 180.0f)
	{
		m_itemLabel2->setVisible(true);
		m_itemLabel2->setPlainText(QString("%1").arg(alt2 - 90, 5, 'f', 0, QChar(' ')));
	}
	else
	{
		m_itemLabel2->setVisible(false);
	}

	if (alt3 >= 0.0f && alt3 <= 180.0f)
	{
		m_itemLabel3->setVisible(true);
		m_itemLabel3->setPlainText(QString("%1").arg(alt3 - 90, 5, 'f', 0, QChar(' ')));
	}
	else
	{
		m_itemLabel3->setVisible(false);
	}

	m_scene->update();
}
