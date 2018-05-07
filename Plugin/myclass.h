#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QWidget>

class MyClass : public QWidget
{
	Q_OBJECT

public:
	MyClass(QWidget *parent = 0);
	~MyClass();

};

#endif // MYCLASS_H
