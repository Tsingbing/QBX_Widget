/********************************************************************************
** Form generated from reading UI file 'joysticks.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOYSTICKS_H
#define UI_JOYSTICKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JoysticksClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *JoysticksClass)
    {
        if (JoysticksClass->objectName().isEmpty())
            JoysticksClass->setObjectName(QStringLiteral("JoysticksClass"));
        JoysticksClass->resize(600, 400);
        menuBar = new QMenuBar(JoysticksClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        JoysticksClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(JoysticksClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        JoysticksClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(JoysticksClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        JoysticksClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(JoysticksClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        JoysticksClass->setStatusBar(statusBar);

        retranslateUi(JoysticksClass);

        QMetaObject::connectSlotsByName(JoysticksClass);
    } // setupUi

    void retranslateUi(QMainWindow *JoysticksClass)
    {
        JoysticksClass->setWindowTitle(QApplication::translate("JoysticksClass", "Joysticks", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class JoysticksClass: public Ui_JoysticksClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOYSTICKS_H
