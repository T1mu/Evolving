/********************************************************************************
** Form generated from reading UI file 'GrayCurveChart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAYCURVECHART_H
#define UI_GRAYCURVECHART_H

#include <ChartWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ScanPixWidget.h"

QT_BEGIN_NAMESPACE

class Ui_GrayCurveChart
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    ChartWidget *widget;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_min;
    QLabel *label_max;
    QToolButton *resetCurveBtn;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    ScanPixWidget *widget_3;
    QVBoxLayout *verticalLayout_5;

    void setupUi(QWidget *GrayCurveChart)
    {
        if (GrayCurveChart->objectName().isEmpty())
            GrayCurveChart->setObjectName(QStringLiteral("GrayCurveChart"));
        GrayCurveChart->resize(500, 749);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GrayCurveChart->sizePolicy().hasHeightForWidth());
        GrayCurveChart->setSizePolicy(sizePolicy);
        GrayCurveChart->setMinimumSize(QSize(500, 0));
        GrayCurveChart->setMaximumSize(QSize(500, 9999));
        verticalLayout_2 = new QVBoxLayout(GrayCurveChart);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(GrayCurveChart);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(442, 402));
        groupBox->setMaximumSize(QSize(9999, 9999));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(0, 20));
        label->setMaximumSize(QSize(16777215, 20));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setStyleSheet(QString::fromUtf8("border:0px solid;\n"
"border-bottom-width:1px;\n"
"border-radius:5px;\n"
"-moz-border-radius:5px;\n"
"border-color:#242424;\n"
"font: 75 11pt \"\346\226\260\345\256\213\344\275\223\";\n"
"background-color: #646464;"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        widget = new ChartWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(9999, 9999));

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(438, 95));
        widget_2->setMaximumSize(QSize(9999, 95));
        widget_2->setStyleSheet(QStringLiteral(""));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        label_min = new QLabel(widget_2);
        label_min->setObjectName(QStringLiteral("label_min"));
        label_min->setMinimumSize(QSize(75, 35));
        label_min->setMaximumSize(QSize(75, 35));

        horizontalLayout_2->addWidget(label_min);

        label_max = new QLabel(widget_2);
        label_max->setObjectName(QStringLiteral("label_max"));
        label_max->setMinimumSize(QSize(75, 35));
        label_max->setMaximumSize(QSize(75, 35));

        horizontalLayout_2->addWidget(label_max);

        resetCurveBtn = new QToolButton(widget_2);
        resetCurveBtn->setObjectName(QStringLiteral("resetCurveBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(resetCurveBtn->sizePolicy().hasHeightForWidth());
        resetCurveBtn->setSizePolicy(sizePolicy3);
        resetCurveBtn->setMinimumSize(QSize(75, 35));
        resetCurveBtn->setMaximumSize(QSize(75, 35));
        resetCurveBtn->setStyleSheet(QStringLiteral(""));
        resetCurveBtn->setIconSize(QSize(100, 30));
        resetCurveBtn->setCheckable(false);

        horizontalLayout_2->addWidget(resetCurveBtn);


        verticalLayout->addWidget(widget_2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_4 = new QGroupBox(GrayCurveChart);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        groupBox_4->setMinimumSize(QSize(442, 200));
        groupBox_4->setMaximumSize(QSize(9999, 9999));
        verticalLayout_3 = new QVBoxLayout(groupBox_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setEnabled(true);
        label_2->setMinimumSize(QSize(0, 20));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setStyleSheet(QString::fromUtf8("border:0px solid;\n"
"border-bottom-width:1px;\n"
"border-radius:5px;\n"
"-moz-border-radius:5px;\n"
"border-color:#242424;\n"
"font: 75 11pt \"\346\226\260\345\256\213\344\275\223\";\n"
"background-color: #646464;"));

        verticalLayout_3->addWidget(label_2);

        widget_3 = new ScanPixWidget(groupBox_4);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMinimumSize(QSize(0, 0));
        widget_3->setMaximumSize(QSize(9999, 9999));
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setSpacing(2);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(2, 2, 2, 2);

        verticalLayout_3->addWidget(widget_3);


        verticalLayout_2->addWidget(groupBox_4);


        retranslateUi(GrayCurveChart);

        QMetaObject::connectSlotsByName(GrayCurveChart);
    } // setupUi

    void retranslateUi(QWidget *GrayCurveChart)
    {
        GrayCurveChart->setWindowTitle(QApplication::translate("GrayCurveChart", "GrayCurveChart", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("GrayCurveChart", "GrayCurve", Q_NULLPTR));
        label_min->setText(QApplication::translate("GrayCurveChart", "Min:  0", Q_NULLPTR));
        label_max->setText(QApplication::translate("GrayCurveChart", "Max:  0", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        resetCurveBtn->setToolTip(QApplication::translate("GrayCurveChart", "\351\207\215\347\275\256\346\233\262\347\272\277\345\233\276", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        resetCurveBtn->setText(QApplication::translate("GrayCurveChart", "resetCurve", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        label_2->setText(QApplication::translate("GrayCurveChart", "                      ParaMeter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GrayCurveChart: public Ui_GrayCurveChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAYCURVECHART_H
