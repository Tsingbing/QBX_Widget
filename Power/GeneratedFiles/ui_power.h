/********************************************************************************
** Form generated from reading UI file 'power.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWER_H
#define UI_POWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Power.h>

QT_BEGIN_NAMESPACE

class Ui_PowerClass
{
public:
    qbx_Power *widgetPower;

    void setupUi(QWidget *PowerClass)
    {
        if (PowerClass->objectName().isEmpty())
            PowerClass->setObjectName(QStringLiteral("PowerClass"));
        PowerClass->resize(600, 400);
        widgetPower = new qbx_Power(PowerClass);
        widgetPower->setObjectName(QStringLiteral("widgetPower"));
        widgetPower->setGeometry(QRect(160, 60, 251, 231));

        retranslateUi(PowerClass);

        QMetaObject::connectSlotsByName(PowerClass);
    } // setupUi

    void retranslateUi(QWidget *PowerClass)
    {
        PowerClass->setWindowTitle(QApplication::translate("PowerClass", "Power", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PowerClass: public Ui_PowerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWER_H
