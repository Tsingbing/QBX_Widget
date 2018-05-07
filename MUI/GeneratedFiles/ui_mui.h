/********************************************************************************
** Form generated from reading UI file 'mui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUI_H
#define UI_MUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qbx_MUI.h"

QT_BEGIN_NAMESPACE

class Ui_MUIClass
{
public:
    qbx_MUI *graphicsMUI;

    void setupUi(QWidget *MUIClass)
    {
        if (MUIClass->objectName().isEmpty())
            MUIClass->setObjectName(QStringLiteral("MUIClass"));
        MUIClass->resize(1141, 1026);
        graphicsMUI = new qbx_MUI(MUIClass);
        graphicsMUI->setObjectName(QStringLiteral("graphicsMUI"));
        graphicsMUI->setGeometry(QRect(50, 10, 1000, 1000));
        graphicsMUI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsMUI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        retranslateUi(MUIClass);

        QMetaObject::connectSlotsByName(MUIClass);
    } // setupUi

    void retranslateUi(QWidget *MUIClass)
    {
        MUIClass->setWindowTitle(QApplication::translate("MUIClass", "MUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MUIClass: public Ui_MUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUI_H
