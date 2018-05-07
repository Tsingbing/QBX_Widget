/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Menu.h>

QT_BEGIN_NAMESPACE

class Ui_MenuClass
{
public:
    qbx_Menu *graphicsMenu;

    void setupUi(QWidget *MenuClass)
    {
        if (MenuClass->objectName().isEmpty())
            MenuClass->setObjectName(QStringLiteral("MenuClass"));
        MenuClass->resize(931, 400);
        graphicsMenu = new qbx_Menu(MenuClass);
        graphicsMenu->setObjectName(QStringLiteral("graphicsMenu"));
        graphicsMenu->setGeometry(QRect(30, 20, 861, 51));

        retranslateUi(MenuClass);

        QMetaObject::connectSlotsByName(MenuClass);
    } // setupUi

    void retranslateUi(QWidget *MenuClass)
    {
        MenuClass->setWindowTitle(QApplication::translate("MenuClass", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MenuClass: public Ui_MenuClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
