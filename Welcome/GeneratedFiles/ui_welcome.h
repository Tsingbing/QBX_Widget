/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeClass
{
public:

    void setupUi(QWidget *WelcomeClass)
    {
        if (WelcomeClass->objectName().isEmpty())
            WelcomeClass->setObjectName(QStringLiteral("WelcomeClass"));
        WelcomeClass->resize(600, 400);

        retranslateUi(WelcomeClass);

        QMetaObject::connectSlotsByName(WelcomeClass);
    } // setupUi

    void retranslateUi(QWidget *WelcomeClass)
    {
        WelcomeClass->setWindowTitle(QApplication::translate("WelcomeClass", "Welcome", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WelcomeClass: public Ui_WelcomeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
