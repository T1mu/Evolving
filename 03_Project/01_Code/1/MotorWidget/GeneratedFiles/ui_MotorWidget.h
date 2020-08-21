/********************************************************************************
** Form generated from reading UI file 'MotorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORWIDGET_H
#define UI_MOTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotorWidgetClass
{
public:

    void setupUi(QWidget *MotorWidgetClass)
    {
        if (MotorWidgetClass->objectName().isEmpty())
            MotorWidgetClass->setObjectName(QStringLiteral("MotorWidgetClass"));
        MotorWidgetClass->resize(600, 400);

        retranslateUi(MotorWidgetClass);

        QMetaObject::connectSlotsByName(MotorWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MotorWidgetClass)
    {
        MotorWidgetClass->setWindowTitle(QApplication::translate("MotorWidgetClass", "MotorWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MotorWidgetClass: public Ui_MotorWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORWIDGET_H
