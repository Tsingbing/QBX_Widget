#include "tcp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	TCP w;
	w.show();
	return a.exec();
}
