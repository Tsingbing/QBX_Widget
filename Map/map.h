#ifndef MAP_H
#define MAP_H

#include <QtWidgets/QWidget>
#include "ui_map.h"

class Map : public QWidget
{
	Q_OBJECT

public:
	Map(QWidget *parent = 0);
	~Map();

private:
	Ui::MapClass ui;
};

#endif // MAP_H
