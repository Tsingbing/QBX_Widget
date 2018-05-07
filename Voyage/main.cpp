#include "voyage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Voyage w;
	w.show();
	return a.exec();
}
