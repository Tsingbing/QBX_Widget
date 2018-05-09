/********************************************************************************
** Form generated from reading UI file 'osg3d.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSG3D_H
#define UI_OSG3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OSG3DClass
{
public:

    void setupUi(QWidget *OSG3DClass)
    {
        if (OSG3DClass->objectName().isEmpty())
            OSG3DClass->setObjectName(QStringLiteral("OSG3DClass"));
        OSG3DClass->resize(600, 400);

        retranslateUi(OSG3DClass);

        QMetaObject::connectSlotsByName(OSG3DClass);
    } // setupUi

    void retranslateUi(QWidget *OSG3DClass)
    {
        OSG3DClass->setWindowTitle(QApplication::translate("OSG3DClass", "OSG3D", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OSG3DClass: public Ui_OSG3DClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSG3D_H
