#ifndef HYDROPHONE_H
#define HYDROPHONE_H

#include <QtWidgets/QWidget>
#include "ui_hydrophone.h"

class Hydrophone : public QWidget
{
	Q_OBJECT

public:
	Hydrophone(QWidget *parent = 0);
	~Hydrophone();

private:
	Ui::HydrophoneClass ui;
};

#endif // HYDROPHONE_H
