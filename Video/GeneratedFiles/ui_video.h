/********************************************************************************
** Form generated from reading UI file 'video.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEO_H
#define UI_VIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Video.h>

QT_BEGIN_NAMESPACE

class Ui_VideoClass
{
public:
    qbx_Video *widgetVideo;

    void setupUi(QWidget *VideoClass)
    {
        if (VideoClass->objectName().isEmpty())
            VideoClass->setObjectName(QStringLiteral("VideoClass"));
        VideoClass->resize(974, 653);
        widgetVideo = new qbx_Video(VideoClass);
        widgetVideo->setObjectName(QStringLiteral("widgetVideo"));
        widgetVideo->setGeometry(QRect(79, 39, 721, 541));

        retranslateUi(VideoClass);

        QMetaObject::connectSlotsByName(VideoClass);
    } // setupUi

    void retranslateUi(QWidget *VideoClass)
    {
        VideoClass->setWindowTitle(QApplication::translate("VideoClass", "Video", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoClass: public Ui_VideoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEO_H
