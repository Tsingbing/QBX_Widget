#ifndef QBX_TEST_H
#define QBX_TEST_H

#include <QtWidgets/QWidget>
#include "ui_qbx_test.h"

class QBX_Test : public QWidget
{
	Q_OBJECT

public:
	QBX_Test(QWidget *parent = 0);
	~QBX_Test();

private:
	Ui::QBX_TestClass ui;
};

#endif // QBX_TEST_H
