#pragma once
#include <QObject>

class qbx_Serial : public QObject {
	Q_OBJECT

public:
	qbx_Serial(QObject * parent = 0);
	~qbx_Serial();

private:
	
};
