#include "video.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Video w;
	w.show();
	return a.exec();
}
