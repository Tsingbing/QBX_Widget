#include "welcome.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Welcome w;
	w.show();
	return a.exec();
}
