#include "temperature.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Temperature w;
	w.show();
	return a.exec();
}
