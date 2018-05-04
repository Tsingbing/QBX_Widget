#include "qbx_test.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QBX_Test w;
	w.show();
	return a.exec();
}
