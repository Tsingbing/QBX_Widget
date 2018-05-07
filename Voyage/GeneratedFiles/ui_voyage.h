/********************************************************************************
** Form generated from reading UI file 'voyage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOYAGE_H
#define UI_VOYAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qbx_Voyage.h>

QT_BEGIN_NAMESPACE

class Ui_VoyageClass
{
public:
    qbx_Voyage *graphicsVoyage;

    void setupUi(QWidget *VoyageClass)
    {
        if (VoyageClass->objectName().isEmpty())
            VoyageClass->setObjectName(QStringLiteral("VoyageClass"));
        VoyageClass->resize(949, 400);
        graphicsVoyage = new qbx_Voyage(VoyageClass);
        graphicsVoyage->setObjectName(QStringLiteral("graphicsVoyage"));
        graphicsVoyage->setGeometry(QRect(70, 290, 821, 101));

        retranslateUi(VoyageClass);

        QMetaObject::connectSlotsByName(VoyageClass);
    } // setupUi

    void retranslateUi(QWidget *VoyageClass)
    {
        VoyageClass->setWindowTitle(QApplication::translate("VoyageClass", "Voyage", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VoyageClass: public Ui_VoyageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOYAGE_H
