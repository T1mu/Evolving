/********************************************************************************
** Form generated from reading UI file 'RectWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTWIDGET_H
#define UI_RECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectWidget
{
public:

    void setupUi(QWidget *RectWidget)
    {
        if (RectWidget->objectName().isEmpty())
            RectWidget->setObjectName(QStringLiteral("RectWidget"));
        RectWidget->resize(400, 300);

        retranslateUi(RectWidget);

        QMetaObject::connectSlotsByName(RectWidget);
    } // setupUi

    void retranslateUi(QWidget *RectWidget)
    {
        RectWidget->setWindowTitle(QApplication::translate("RectWidget", "RectWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RectWidget: public Ui_RectWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTWIDGET_H
