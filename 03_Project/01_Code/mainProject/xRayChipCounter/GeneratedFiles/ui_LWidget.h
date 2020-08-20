/********************************************************************************
** Form generated from reading UI file 'LWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LWIDGET_H
#define UI_LWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LWidget
{
public:

    void setupUi(QWidget *LWidget)
    {
        if (LWidget->objectName().isEmpty())
            LWidget->setObjectName(QStringLiteral("LWidget"));
        LWidget->resize(400, 300);

        retranslateUi(LWidget);

        QMetaObject::connectSlotsByName(LWidget);
    } // setupUi

    void retranslateUi(QWidget *LWidget)
    {
        LWidget->setWindowTitle(QApplication::translate("LWidget", "LWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LWidget: public Ui_LWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LWIDGET_H
