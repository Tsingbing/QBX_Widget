#ifndef TCP_H
#define TCP_H

#include <QtWidgets/QMainWindow>
#include "ui_tcp.h"

class TCP : public QMainWindow
{
	Q_OBJECT

public:
	TCP(QWidget *parent = 0);
	~TCP();

private:
	Ui::TCPClass ui;
};

#endif // TCP_H
