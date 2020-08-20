/********************************************************************************
** Form generated from reading UI file 'MoveWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVEWIDGET_H
#define UI_MOVEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MoveWidget
{
public:

    void setupUi(QWidget *MoveWidget)
    {
        if (MoveWidget->objectName().isEmpty())
            MoveWidget->setObjectName(QStringLiteral("MoveWidget"));
        MoveWidget->resize(400, 300);

        retranslateUi(MoveWidget);

        QMetaObject::connectSlotsByName(MoveWidget);
    } // setupUi

    void retranslateUi(QWidget *MoveWidget)
    {
        MoveWidget->setWindowTitle(QApplication::translate("MoveWidget", "MoveWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MoveWidget: public Ui_MoveWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVEWIDGET_H
