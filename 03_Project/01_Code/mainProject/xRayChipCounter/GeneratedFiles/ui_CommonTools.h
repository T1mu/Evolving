/********************************************************************************
** Form generated from reading UI file 'CommonTools.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONTOOLS_H
#define UI_COMMONTOOLS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "AdjustWidget.h"
#include "CommonDevice.h"

QT_BEGIN_NAMESPACE

class Ui_CommonTools
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    AdjustWidget *widget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    CommonDevice *widget_3;

    void setupUi(QWidget *CommonTools)
    {
        if (CommonTools->objectName().isEmpty())
            CommonTools->setObjectName(QStringLiteral("CommonTools"));
        CommonTools->resize(480, 789);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CommonTools->sizePolicy().hasHeightForWidth());
        CommonTools->setSizePolicy(sizePolicy);
        CommonTools->setMinimumSize(QSize(480, 0));
        CommonTools->setMaximumSize(QSize(480, 16777215));
        verticalLayout_3 = new QVBoxLayout(CommonTools);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(CommonTools);
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

        widget = new AdjustWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(9999, 9999));

        verticalLayout->addWidget(widget);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CommonTools);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(430, 150));
        groupBox_2->setMaximumSize(QSize(9999, 9999));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setMinimumSize(QSize(0, 20));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setStyleSheet(QString::fromUtf8("border:0px solid;\n"
"border-bottom-width:1px;\n"
"border-radius:5px;\n"
"-moz-border-radius:5px;\n"
"border-color:#242424;\n"
"font: 75 11pt \"\346\226\260\345\256\213\344\275\223\";\n"
"background-color: #646464;"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        widget_3 = new CommonDevice(groupBox_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMinimumSize(QSize(400, 148));
        widget_3->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(widget_3);


        verticalLayout_3->addWidget(groupBox_2);


        retranslateUi(CommonTools);

        QMetaObject::connectSlotsByName(CommonTools);
    } // setupUi

    void retranslateUi(QWidget *CommonTools)
    {
        CommonTools->setWindowTitle(QApplication::translate("CommonTools", "CommonTools", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("CommonTools", "Histogram Modification", Q_NULLPTR));
        groupBox_2->setTitle(QString("123213"));
        label_2->setText(QApplication::translate("CommonTools", "Common Device Control", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommonTools: public Ui_CommonTools {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONTOOLS_H
