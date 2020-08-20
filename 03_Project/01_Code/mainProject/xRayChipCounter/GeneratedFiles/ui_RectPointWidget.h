/********************************************************************************
** Form generated from reading UI file 'RectPointWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTPOINTWIDGET_H
#define UI_RECTPOINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RectPointWidget
{
public:

    void setupUi(QWidget *RectPointWidget)
    {
        if (RectPointWidget->objectName().isEmpty())
            RectPointWidget->setObjectName(QStringLiteral("RectPointWidget"));
        RectPointWidget->resize(400, 300);

        retranslateUi(RectPointWidget);

        QMetaObject::connectSlotsByName(RectPointWidget);
    } // setupUi

    void retranslateUi(QWidget *RectPointWidget)
    {
        RectPointWidget->setWindowTitle(QApplication::translate("RectPointWidget", "RectPointWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RectPointWidget: public Ui_RectPointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTPOINTWIDGET_H
