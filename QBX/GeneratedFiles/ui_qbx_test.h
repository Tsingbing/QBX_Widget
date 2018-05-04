/********************************************************************************
** Form generated from reading UI file 'qbx_test.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QBX_TEST_H
#define UI_QBX_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Video.h>

QT_BEGIN_NAMESPACE

class Ui_QBX_TestClass
{
public:
    qbx_Video *widgetVideo;

    void setupUi(QWidget *QBX_TestClass)
    {
        if (QBX_TestClass->objectName().isEmpty())
            QBX_TestClass->setObjectName(QStringLiteral("QBX_TestClass"));
        QBX_TestClass->resize(600, 400);
        widgetVideo = new qbx_Video(QBX_TestClass);
        widgetVideo->setObjectName(QStringLiteral("widgetVideo"));
        widgetVideo->setGeometry(QRect(0, 0, 601, 401));

        retranslateUi(QBX_TestClass);

        QMetaObject::connectSlotsByName(QBX_TestClass);
    } // setupUi

    void retranslateUi(QWidget *QBX_TestClass)
    {
        QBX_TestClass->setWindowTitle(QApplication::translate("QBX_TestClass", "QBX_Test", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QBX_TestClass: public Ui_QBX_TestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QBX_TEST_H
