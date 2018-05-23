/********************************************************************************
** Form generated from reading UI file 'tcp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_H
#define UI_TCP_H

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

class Ui_TCPClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TCPClass)
    {
        if (TCPClass->objectName().isEmpty())
            TCPClass->setObjectName(QStringLiteral("TCPClass"));
        TCPClass->resize(600, 400);
        menuBar = new QMenuBar(TCPClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TCPClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TCPClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TCPClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TCPClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TCPClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TCPClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TCPClass->setStatusBar(statusBar);

        retranslateUi(TCPClass);

        QMetaObject::connectSlotsByName(TCPClass);
    } // setupUi

    void retranslateUi(QMainWindow *TCPClass)
    {
        TCPClass->setWindowTitle(QApplication::translate("TCPClass", "TCP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TCPClass: public Ui_TCPClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_H
