/********************************************************************************
** Form generated from reading UI file 'hydrophone.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HYDROPHONE_H
#define UI_HYDROPHONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HydrophoneClass
{
public:

    void setupUi(QWidget *HydrophoneClass)
    {
        if (HydrophoneClass->objectName().isEmpty())
            HydrophoneClass->setObjectName(QStringLiteral("HydrophoneClass"));
        HydrophoneClass->resize(600, 400);

        retranslateUi(HydrophoneClass);

        QMetaObject::connectSlotsByName(HydrophoneClass);
    } // setupUi

    void retranslateUi(QWidget *HydrophoneClass)
    {
        HydrophoneClass->setWindowTitle(QApplication::translate("HydrophoneClass", "Hydrophone", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HydrophoneClass: public Ui_HydrophoneClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HYDROPHONE_H
