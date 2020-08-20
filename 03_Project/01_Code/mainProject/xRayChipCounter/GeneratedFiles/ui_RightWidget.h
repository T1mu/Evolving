/********************************************************************************
** Form generated from reading UI file 'RightWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIGHTWIDGET_H
#define UI_RIGHTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "DetectorKZWidget.h"
#include "MotorWidget.h"
#include "TubeWidget.h"

QT_BEGIN_NAMESPACE

class Ui_RightWidget
{
public:
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    TubeWidget *widget;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    DetectorKZWidget *widget_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    MotorWidget *widget_2;

    void setupUi(QWidget *RightWidget)
    {
        if (RightWidget->objectName().isEmpty())
            RightWidget->setObjectName(QStringLiteral("RightWidget"));
        RightWidget->resize(500, 900);
        RightWidget->setMinimumSize(QSize(500, 0));
        RightWidget->setMaximumSize(QSize(500, 1000));
        verticalLayout_4 = new QVBoxLayout(RightWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(RightWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(460, 150));
        groupBox->setMaximumSize(QSize(9999, 9999));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
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

        widget = new TubeWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(460, 148));
        widget->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(widget);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(RightWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(460, 259));
        groupBox_2->setMaximumSize(QSize(9999, 9999));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 20));
        label_3->setMaximumSize(QSize(16777215, 20));
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setStyleSheet(QString::fromUtf8("border:0px solid;\n"
"border-bottom-width:1px;\n"
"border-radius:5px;\n"
"-moz-border-radius:5px;\n"
"border-color:#242424;\n"
"font: 75 11pt \"\346\226\260\345\256\213\344\275\223\";\n"
"background-color: #646464;"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        widget_3 = new DetectorKZWidget(groupBox_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy3);
        widget_3->setMinimumSize(QSize(460, 235));
        widget_3->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(widget_3);

        widget_3->raise();
        label_3->raise();

        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(RightWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setMinimumSize(QSize(460, 480));
        groupBox_3->setMaximumSize(QSize(9999, 9999));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
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

        widget_2 = new MotorWidget(groupBox_3);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);
        widget_2->setMinimumSize(QSize(460, 400));

        verticalLayout_2->addWidget(widget_2);


        verticalLayout_4->addWidget(groupBox_3);


        retranslateUi(RightWidget);

        QMetaObject::connectSlotsByName(RightWidget);
    } // setupUi

    void retranslateUi(QWidget *RightWidget)
    {
        RightWidget->setWindowTitle(QApplication::translate("RightWidget", "RightWidget", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("RightWidget", "Tube", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("RightWidget", "Detector", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_2->setText(QApplication::translate("RightWidget", "Motor", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RightWidget: public Ui_RightWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIGHTWIDGET_H
