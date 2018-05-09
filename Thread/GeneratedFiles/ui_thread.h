/********************************************************************************
** Form generated from reading UI file 'thread.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREAD_H
#define UI_THREAD_H

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

class Ui_ThreadClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ThreadClass)
    {
        if (ThreadClass->objectName().isEmpty())
            ThreadClass->setObjectName(QStringLiteral("ThreadClass"));
        ThreadClass->resize(600, 400);
        menuBar = new QMenuBar(ThreadClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        ThreadClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ThreadClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ThreadClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ThreadClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ThreadClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ThreadClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ThreadClass->setStatusBar(statusBar);

        retranslateUi(ThreadClass);

        QMetaObject::connectSlotsByName(ThreadClass);
    } // setupUi

    void retranslateUi(QMainWindow *ThreadClass)
    {
        ThreadClass->setWindowTitle(QApplication::translate("ThreadClass", "Thread", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ThreadClass: public Ui_ThreadClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREAD_H
