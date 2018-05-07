#ifndef THREAD_H
#define THREAD_H

#include <QtWidgets/QMainWindow>
#include "ui_thread.h"

class Thread : public QMainWindow
{
	Q_OBJECT

public:
	Thread(QWidget *parent = 0);
	~Thread();

private:
	Ui::ThreadClass ui;
};

#endif // THREAD_H
