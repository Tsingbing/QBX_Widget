#include "all.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ALL w;
	w.show();
	return a.exec();
}
