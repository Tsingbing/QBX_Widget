#ifndef WELCOME_H
#define WELCOME_H

#include <QtWidgets/QWidget>
#include "ui_welcome.h"

class Welcome : public QWidget
{
	Q_OBJECT

public:
	Welcome(QWidget *parent = 0);
	~Welcome();

private:
	Ui::WelcomeClass ui;
};

#endif // WELCOME_H
