#ifndef MENU_H
#define MENU_H

#include <QtWidgets/QWidget>
#include "ui_menu.h"

class Menu : public QWidget
{
	Q_OBJECT

public:
	Menu(QWidget *parent = 0);
	~Menu();

private:
	Ui::MenuClass ui;
};

#endif // MENU_H
