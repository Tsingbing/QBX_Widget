#include "joysticks.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Joysticks w;
	w.show();
	return a.exec();
}
