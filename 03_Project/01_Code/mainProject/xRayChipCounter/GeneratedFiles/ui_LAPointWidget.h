/********************************************************************************
** Form generated from reading UI file 'LAPointWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAPOINTWIDGET_H
#define UI_LAPOINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LAPointWidget
{
public:

    void setupUi(QWidget *LAPointWidget)
    {
        if (LAPointWidget->objectName().isEmpty())
            LAPointWidget->setObjectName(QStringLiteral("LAPointWidget"));
        LAPointWidget->resize(400, 300);

        retranslateUi(LAPointWidget);

        QMetaObject::connectSlotsByName(LAPointWidget);
    } // setupUi

    void retranslateUi(QWidget *LAPointWidget)
    {
        LAPointWidget->setWindowTitle(QApplication::translate("LAPointWidget", "LAPointWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LAPointWidget: public Ui_LAPointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAPOINTWIDGET_H
