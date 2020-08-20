/********************************************************************************
** Form generated from reading UI file 'RWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RWIDGET_H
#define UI_RWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RWidget
{
public:

    void setupUi(QWidget *RWidget)
    {
        if (RWidget->objectName().isEmpty())
            RWidget->setObjectName(QStringLiteral("RWidget"));
        RWidget->resize(400, 300);

        retranslateUi(RWidget);

        QMetaObject::connectSlotsByName(RWidget);
    } // setupUi

    void retranslateUi(QWidget *RWidget)
    {
        RWidget->setWindowTitle(QApplication::translate("RWidget", "RWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RWidget: public Ui_RWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RWIDGET_H
