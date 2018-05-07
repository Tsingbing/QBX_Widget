#include "depth.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Depth w;
	w.show();
	return a.exec();
}
