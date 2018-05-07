#include "qbx_voyage.h"

qbx_Voyage::qbx_Voyage(QWidget * parent) : 
	QGraphicsView(parent),
	m_scene(0),
	m_itemBack(0),
	m_itemLabel(0),
	m_scaleX(1.0f),
	m_scaleY(1.0f),
	m_originalWidth(1920),
	m_originalHeight(95),
	m_originalLabelX(912),
	m_originalLabelY(65),
	m_labelsColor(0, 255, 0)
{
	reset();

	m_scene = new QGraphicsScene(this);
	setScene(m_scene);

	m_scene->clear();
	m_labelsFont.setFamily("黑体");
	m_labelsFont.setPointSizeF(50.0f);
	m_labelsFont.setStretch(QFont::Condensed);
	m_labelsFont.setWeight(QFont::Bold);
	init();
}

qbx_Voyage::~qbx_Voyage() 
{
	if (m_scene)
	{
		m_scene->clear();
		delete m_scene;
		m_scene = 0;
	}

	reset();
}

void qbx_Voyage::reinit()
{
	if (m_scene)
	{
		m_scene->clear();
		init();
	}
}

void qbx_Voyage::update()
{
	updateView();
}

void qbx_Voyage::setSumLength(float sumLength)
{
	m_sumLength = sumLength;
}

void qbx_Voyage::resizeEvent(QResizeEvent * event)
{
	QGraphicsView::resizeEvent(event);

	reinit();
}

void qbx_Voyage::init()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	reset();

	m_itemBack = new QGraphicsSvgItem(":/Voyage/Resources/Voyage/Voyage.svg");
	m_itemBack->setCacheMode(QGraphicsItem::NoCache);
	m_itemBack->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_scene->addItem(m_itemBack);
	centerOn(width() / 2.0f, height() / 2.0f);

	m_itemLabel = new QGraphicsTextItem(QString("99999"));
	m_itemLabel->setCacheMode(QGraphicsItem::NoCache);
	//m_itemLabel->setZValue(m_labelsZ);
	m_itemLabel->setDefaultTextColor(m_labelsColor);
	m_itemLabel->setFont(m_labelsFont);
	m_itemLabel->setTransform(QTransform::fromScale(m_scaleX, m_scaleY), true);
	m_itemLabel->moveBy(m_scaleX * (m_originalLabelX - m_itemLabel->boundingRect().width() / 2.0f),
		m_scaleY * (m_originalLabelY - m_itemLabel->boundingRect().height() / 2.0f));
	m_scene->addItem(m_itemLabel);

	updateView();
}

void qbx_Voyage::reset()
{
}

void qbx_Voyage::updateView()
{
	m_scaleX = (float)width() / (float)m_originalWidth;
	m_scaleY = (float)height() / (float)m_originalHeight;

	m_itemLabel->setVisible(true);
	m_itemLabel->setPlainText(QString("%1 M").arg(m_sumLength, 5, 'f', 0, QChar(' ')));

	m_scene->update();
}
