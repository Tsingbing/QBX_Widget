#pragma once
#include <QGraphicsView>
#include <QGraphicsSvgItem>

class qbx_Voyage : public QGraphicsView {
	Q_OBJECT

public:
	qbx_Voyage(QWidget * parent = 0);
	~qbx_Voyage();

	void reinit();

	void update();

	void setSumLength(float sumLength);

protected:

	void resizeEvent(QResizeEvent *event);

private:

	QGraphicsScene *m_scene;
	QGraphicsSvgItem *m_itemBack;
	QGraphicsTextItem *m_itemLabel;

	float m_scaleX;
	float m_scaleY;
	const int m_originalHeight;
	const int m_originalWidth;
	const float m_originalLabelX;
	const float m_originalLabelY;
	float m_sumLength;

	QFont m_labelsFont;
	QColor m_labelsColor;
	QPointF m_originalAdiCtr;

	void init();

	void reset();

	void updateView();
};
