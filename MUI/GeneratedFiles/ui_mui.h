/********************************************************************************
** Form generated from reading UI file 'mui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUI_H
#define UI_MUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "qbx_MUI.h"

QT_BEGIN_NAMESPACE

class Ui_MUIClass
{
public:
    qbx_MUI *graphicsMUI;
    QLabel *statusLabel;
    QComboBox *sendCMDBox;
    QComboBox *serialPortComboBox;
    QSpinBox *waitResponseSpinBox;
    QLabel *trafficLabel;
    QPushButton *runButton;

    void setupUi(QWidget *MUIClass)
    {
        if (MUIClass->objectName().isEmpty())
            MUIClass->setObjectName(QStringLiteral("MUIClass"));
        MUIClass->resize(1401, 1026);
        graphicsMUI = new qbx_MUI(MUIClass);
        graphicsMUI->setObjectName(QStringLiteral("graphicsMUI"));
        graphicsMUI->setGeometry(QRect(50, 10, 1000, 1000));
        graphicsMUI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsMUI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        statusLabel = new QLabel(MUIClass);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(0, 1010, 1051, 16));
        sendCMDBox = new QComboBox(MUIClass);
        sendCMDBox->setObjectName(QStringLiteral("sendCMDBox"));
        sendCMDBox->setGeometry(QRect(1210, 1000, 31, 22));
        serialPortComboBox = new QComboBox(MUIClass);
        serialPortComboBox->setObjectName(QStringLiteral("serialPortComboBox"));
        serialPortComboBox->setGeometry(QRect(1240, 1000, 81, 22));
        waitResponseSpinBox = new QSpinBox(MUIClass);
        waitResponseSpinBox->setObjectName(QStringLiteral("waitResponseSpinBox"));
        waitResponseSpinBox->setGeometry(QRect(1320, 1000, 81, 22));
        waitResponseSpinBox->setMaximum(10000);
        waitResponseSpinBox->setValue(1000);
        trafficLabel = new QLabel(MUIClass);
        trafficLabel->setObjectName(QStringLiteral("trafficLabel"));
        trafficLabel->setGeometry(QRect(1050, 450, 351, 471));
        runButton = new QPushButton(MUIClass);
        runButton->setObjectName(QStringLiteral("runButton"));
        runButton->setGeometry(QRect(1160, 1000, 41, 23));

        retranslateUi(MUIClass);

        QMetaObject::connectSlotsByName(MUIClass);
    } // setupUi

    void retranslateUi(QWidget *MUIClass)
    {
        MUIClass->setWindowTitle(QApplication::translate("MUIClass", "MUI", Q_NULLPTR));
        statusLabel->setText(QApplication::translate("MUIClass", "TextLabel", Q_NULLPTR));
        sendCMDBox->clear();
        sendCMDBox->insertItems(0, QStringList()
         << QApplication::translate("MUIClass", "0", Q_NULLPTR)
         << QApplication::translate("MUIClass", "1", Q_NULLPTR)
         << QApplication::translate("MUIClass", "2", Q_NULLPTR)
         << QApplication::translate("MUIClass", "3", Q_NULLPTR)
         << QApplication::translate("MUIClass", "4", Q_NULLPTR)
         << QApplication::translate("MUIClass", "5", Q_NULLPTR)
         << QApplication::translate("MUIClass", "6", Q_NULLPTR)
         << QApplication::translate("MUIClass", "7", Q_NULLPTR)
        );
        trafficLabel->setText(QApplication::translate("MUIClass", "No traffic.", Q_NULLPTR));
        runButton->setText(QApplication::translate("MUIClass", "\345\274\200\345\247\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MUIClass: public Ui_MUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUI_H
