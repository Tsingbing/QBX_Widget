#include "map.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Map w;
	w.show();
	return a.exec();
}
