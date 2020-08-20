/********************************************************************************
** Form generated from reading UI file 'PointWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTWIDGET_H
#define UI_POINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PointWidget
{
public:

    void setupUi(QWidget *PointWidget)
    {
        if (PointWidget->objectName().isEmpty())
            PointWidget->setObjectName(QStringLiteral("PointWidget"));
        PointWidget->resize(400, 300);

        retranslateUi(PointWidget);

        QMetaObject::connectSlotsByName(PointWidget);
    } // setupUi

    void retranslateUi(QWidget *PointWidget)
    {
        PointWidget->setWindowTitle(QApplication::translate("PointWidget", "PointWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PointWidget: public Ui_PointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTWIDGET_H
