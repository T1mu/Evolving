/********************************************************************************
** Form generated from reading UI file 'PixChartWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXCHARTWIDGET_H
#define UI_PIXCHARTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PixChartWidget
{
public:
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *h1;

    void setupUi(QWidget *PixChartWidget)
    {
        if (PixChartWidget->objectName().isEmpty())
            PixChartWidget->setObjectName(QStringLiteral("PixChartWidget"));
        PixChartWidget->resize(400, 300);
        PixChartWidget->setMinimumSize(QSize(400, 300));
        PixChartWidget->setMaximumSize(QSize(400, 300));
        horizontalLayout_2 = new QHBoxLayout(PixChartWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        h1 = new QHBoxLayout();
        h1->setSpacing(6);
        h1->setObjectName(QStringLiteral("h1"));

        horizontalLayout_2->addLayout(h1);


        retranslateUi(PixChartWidget);

        QMetaObject::connectSlotsByName(PixChartWidget);
    } // setupUi

    void retranslateUi(QWidget *PixChartWidget)
    {
        PixChartWidget->setWindowTitle(QApplication::translate("PixChartWidget", "PixChartWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PixChartWidget: public Ui_PixChartWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXCHARTWIDGET_H
