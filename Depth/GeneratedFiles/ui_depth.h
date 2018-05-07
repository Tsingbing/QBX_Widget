/********************************************************************************
** Form generated from reading UI file 'depth.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPTH_H
#define UI_DEPTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Depth.h>

QT_BEGIN_NAMESPACE

class Ui_DepthClass
{
public:
    qbx_Depth *graphicsDepth;

    void setupUi(QWidget *DepthClass)
    {
        if (DepthClass->objectName().isEmpty())
            DepthClass->setObjectName(QStringLiteral("DepthClass"));
        DepthClass->resize(600, 400);
        graphicsDepth = new qbx_Depth(DepthClass);
        graphicsDepth->setObjectName(QStringLiteral("graphicsDepth"));
        graphicsDepth->setGeometry(QRect(130, 90, 256, 192));

        retranslateUi(DepthClass);

        QMetaObject::connectSlotsByName(DepthClass);
    } // setupUi

    void retranslateUi(QWidget *DepthClass)
    {
        DepthClass->setWindowTitle(QApplication::translate("DepthClass", "Depth", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DepthClass: public Ui_DepthClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPTH_H
