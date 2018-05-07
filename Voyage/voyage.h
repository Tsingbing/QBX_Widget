#ifndef VOYAGE_H
#define VOYAGE_H

#include <QtWidgets/QWidget>
#include "ui_voyage.h"

class Voyage : public QWidget
{
	Q_OBJECT

public:
	Voyage(QWidget *parent = 0);
	~Voyage();

private:
	Ui::VoyageClass ui;
};

#endif // VOYAGE_H
