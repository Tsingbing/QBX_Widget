#include "power.h"

Power::Power(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.widgetPower->setUsedValue(50);
	ui.widgetPower->show();
}

Power::~Power()
{

}
