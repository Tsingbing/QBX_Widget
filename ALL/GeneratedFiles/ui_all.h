/********************************************************************************
** Form generated from reading UI file 'all.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALL_H
#define UI_ALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ALLClass
{
public:

    void setupUi(QWidget *ALLClass)
    {
        if (ALLClass->objectName().isEmpty())
            ALLClass->setObjectName(QStringLiteral("ALLClass"));
        ALLClass->resize(600, 400);

        retranslateUi(ALLClass);

        QMetaObject::connectSlotsByName(ALLClass);
    } // setupUi

    void retranslateUi(QWidget *ALLClass)
    {
        ALLClass->setWindowTitle(QApplication::translate("ALLClass", "ALL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ALLClass: public Ui_ALLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALL_H
