#ifndef OSG3D_H
#define OSG3D_H

#include <QtWidgets/QWidget>
#include "ui_osg3d.h"

class OSG3D : public QWidget
{
	Q_OBJECT

public:
	OSG3D(QWidget *parent = 0);
	~OSG3D();

private:
	Ui::OSG3DClass ui;
};

#endif // OSG3D_H
