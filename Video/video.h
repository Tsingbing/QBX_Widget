#ifndef VIDEO_H
#define VIDEO_H

#include <QtWidgets/QWidget>
#include "ui_video.h"

class Video : public QWidget
{
	Q_OBJECT

public:
	Video(QWidget *parent = 0);
	~Video();

private:
	Ui::VideoClass ui;
};

#endif // VIDEO_H
