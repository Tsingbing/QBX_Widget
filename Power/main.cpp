#include "power.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Power w;
	w.show();
	return a.exec();
}
