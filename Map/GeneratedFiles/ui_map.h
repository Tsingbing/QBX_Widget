/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapClass
{
public:

    void setupUi(QWidget *MapClass)
    {
        if (MapClass->objectName().isEmpty())
            MapClass->setObjectName(QStringLiteral("MapClass"));
        MapClass->resize(600, 400);

        retranslateUi(MapClass);

        QMetaObject::connectSlotsByName(MapClass);
    } // setupUi

    void retranslateUi(QWidget *MapClass)
    {
        MapClass->setWindowTitle(QApplication::translate("MapClass", "Map", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MapClass: public Ui_MapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
