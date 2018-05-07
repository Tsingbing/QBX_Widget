/********************************************************************************
** Form generated from reading UI file 'temperature.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPERATURE_H
#define UI_TEMPERATURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_temperature.h>

QT_BEGIN_NAMESPACE

class Ui_TemperatureClass
{
public:
    qbx_Temperature *graphicsTemperature;

    void setupUi(QWidget *TemperatureClass)
    {
        if (TemperatureClass->objectName().isEmpty())
            TemperatureClass->setObjectName(QStringLiteral("TemperatureClass"));
        TemperatureClass->resize(600, 579);
        graphicsTemperature = new qbx_Temperature(TemperatureClass);
        graphicsTemperature->setObjectName(QStringLiteral("graphicsTemperature"));
        graphicsTemperature->setGeometry(QRect(150, 50, 111, 401));

        retranslateUi(TemperatureClass);

        QMetaObject::connectSlotsByName(TemperatureClass);
    } // setupUi

    void retranslateUi(QWidget *TemperatureClass)
    {
        TemperatureClass->setWindowTitle(QApplication::translate("TemperatureClass", "Temperature", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TemperatureClass: public Ui_TemperatureClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPERATURE_H
