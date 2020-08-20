/********************************************************************************
** Form generated from reading UI file 'AdjustWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTWIDGET_H
#define UI_ADJUSTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdjustWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *h1;

    void setupUi(QWidget *AdjustWidget)
    {
        if (AdjustWidget->objectName().isEmpty())
            AdjustWidget->setObjectName(QStringLiteral("AdjustWidget"));
        AdjustWidget->resize(500, 300);
        AdjustWidget->setMinimumSize(QSize(500, 300));
        AdjustWidget->setMaximumSize(QSize(500, 300));
        horizontalLayout_2 = new QHBoxLayout(AdjustWidget);
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        h1 = new QHBoxLayout();
        h1->setSpacing(0);
        h1->setObjectName(QStringLiteral("h1"));

        horizontalLayout_2->addLayout(h1);


        retranslateUi(AdjustWidget);

        QMetaObject::connectSlotsByName(AdjustWidget);
    } // setupUi

    void retranslateUi(QWidget *AdjustWidget)
    {
        AdjustWidget->setWindowTitle(QApplication::translate("AdjustWidget", "AdjustWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdjustWidget: public Ui_AdjustWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTWIDGET_H
