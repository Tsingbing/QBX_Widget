/********************************************************************************
** Form generated from reading UI file 'serial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_H
#define UI_SERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialClass
{
public:
    QWidget *centralWidget;
    QPushButton *runButton;
    QLabel *serialPortLabel;
    QLabel *waitResponseLabel;
    QSpinBox *waitResponseSpinBox;
    QComboBox *serialPortComboBox;
    QLabel *requestLabel;
    QLineEdit *requestLineEdit;
    QLabel *trafficLabel;
    QLabel *statusLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SerialClass)
    {
        if (SerialClass->objectName().isEmpty())
            SerialClass->setObjectName(QStringLiteral("SerialClass"));
        SerialClass->resize(525, 400);
        centralWidget = new QWidget(SerialClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        runButton = new QPushButton(centralWidget);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(400, 70, 75, 23));
        serialPortLabel = new QLabel(centralWidget);
        serialPortLabel->setObjectName(QStringLiteral("serialPortLabel"));
        serialPortLabel->setGeometry(QRect(40, 70, 81, 20));
        waitResponseLabel = new QLabel(centralWidget);
        waitResponseLabel->setObjectName(QStringLiteral("waitResponseLabel"));
        waitResponseLabel->setGeometry(QRect(40, 110, 91, 21));
        waitResponseSpinBox = new QSpinBox(centralWidget);
        waitResponseSpinBox->setObjectName(QStringLiteral("waitResponseSpinBox"));
        waitResponseSpinBox->setGeometry(QRect(130, 110, 81, 22));
        waitResponseSpinBox->setMaximum(10000);
        waitResponseSpinBox->setValue(10000);
        serialPortComboBox = new QComboBox(centralWidget);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));
        serialPortComboBox->setGeometry(QRect(130, 70, 81, 22));
        requestLabel = new QLabel(centralWidget);
        requestLabel->setObjectName(QStringLiteral("requestLabel"));
        requestLabel->setGeometry(QRect(40, 160, 54, 21));
        requestLineEdit = new QLineEdit(centralWidget);
        requestLineEdit->setObjectName(QStringLiteral("requestLineEdit"));
        requestLineEdit->setGeometry(QRect(130, 160, 351, 20));
        trafficLabel = new QLabel(centralWidget);
        trafficLabel->setObjectName(QStringLiteral("trafficLabel"));
        trafficLabel->setGeometry(QRect(40, 190, 431, 101));
        statusLabel = new QLabel(centralWidget);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(40, 310, 381, 16));
        SerialClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SerialClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 525, 23));
        SerialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SerialClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SerialClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SerialClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SerialClass->setStatusBar(statusBar);

        retranslateUi(SerialClass);

        QMetaObject::connectSlotsByName(SerialClass);
    } // setupUi

    void retranslateUi(QMainWindow *SerialClass)
    {
        SerialClass->setWindowTitle(QApplication::translate("SerialClass", "\344\270\262\345\217\243\346\265\213\350\257\225", Q_NULLPTR));
        runButton->setText(QApplication::translate("SerialClass", "\345\274\200\345\247\213", Q_NULLPTR));
        serialPortLabel->setText(QApplication::translate("SerialClass", "\344\270\262\345\217\243\345\217\267\357\274\232", Q_NULLPTR));
        waitResponseLabel->setText(QApplication::translate("SerialClass", "\347\255\211\345\276\205\345\223\215\345\272\224\346\227\266\351\227\264", Q_NULLPTR));
        requestLabel->setText(QApplication::translate("SerialClass", "\350\257\267\346\261\202\357\274\232", Q_NULLPTR));
        requestLineEdit->setText(QApplication::translate("SerialClass", "who are you?", Q_NULLPTR));
        trafficLabel->setText(QApplication::translate("SerialClass", "No traffic.", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("SerialClass", "Status: Not running.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialClass: public Ui_SerialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_H
