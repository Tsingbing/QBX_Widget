#include "hydrophone.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Hydrophone w;
	w.show();
	return a.exec();
}
