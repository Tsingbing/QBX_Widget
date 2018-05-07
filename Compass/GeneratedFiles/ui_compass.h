/********************************************************************************
** Form generated from reading UI file 'compass.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPASS_H
#define UI_COMPASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Compass.h>

QT_BEGIN_NAMESPACE

class Ui_CompassClass
{
public:
    qbx_Compass *graphicsCompass;

    void setupUi(QWidget *CompassClass)
    {
        if (CompassClass->objectName().isEmpty())
            CompassClass->setObjectName(QStringLiteral("CompassClass"));
        CompassClass->resize(674, 506);
        graphicsCompass = new qbx_Compass(CompassClass);
        graphicsCompass->setObjectName(QStringLiteral("graphicsCompass"));
        graphicsCompass->setGeometry(QRect(170, 110, 256, 261));

        retranslateUi(CompassClass);

        QMetaObject::connectSlotsByName(CompassClass);
    } // setupUi

    void retranslateUi(QWidget *CompassClass)
    {
        CompassClass->setWindowTitle(QApplication::translate("CompassClass", "Compass", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CompassClass: public Ui_CompassClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPASS_H
