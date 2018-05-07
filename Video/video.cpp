#include "video.h"

Video::Video(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.widgetVideo->setID(0);

}

Video::~Video()
{

}
