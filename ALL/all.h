#ifndef ALL_H
#define ALL_H

#include <QtWidgets/QWidget>
#include "ui_all.h"

class ALL : public QWidget
{
	Q_OBJECT

public:
	ALL(QWidget *parent = 0);
	~ALL();

private:
	Ui::ALLClass ui;
};

#endif // ALL_H
