/********************************************************************************
** Form generated from reading UI file 'ScanPixWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCANPIXWIDGET_H
#define UI_SCANPIXWIDGET_H

#include <DisplayWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScanPixWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSlider *slider;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLCDNumber *xposLcd;
    QLabel *label_2;
    QLCDNumber *ypoLcd;
    QLabel *label_3;
    QLCDNumber *pixLcd;
    QFrame *line_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    DisplayWidget *widget;

    void setupUi(QWidget *ScanPixWidget)
    {
        if (ScanPixWidget->objectName().isEmpty())
            ScanPixWidget->setObjectName(QStringLiteral("ScanPixWidget"));
        ScanPixWidget->resize(417, 358);
        verticalLayout = new QVBoxLayout(ScanPixWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox = new QCheckBox(ScanPixWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setMinimumSize(QSize(50, 35));
        checkBox->setMaximumSize(QSize(100, 35));
        checkBox->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_2->addWidget(checkBox);

        line = new QFrame(ScanPixWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ScanPixWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(30, 35));
        label->setMaximumSize(QSize(30, 35));
        label->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        slider = new QSlider(ScanPixWidget);
        slider->setObjectName(QStringLiteral("slider"));
        slider->setMinimum(1);
        slider->setMaximum(10);
        slider->setSingleStep(1);
        slider->setPageStep(1);
        slider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(slider);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);

        line_2 = new QFrame(ScanPixWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(ScanPixWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(30, 35));
        label_4->setMaximumSize(QSize(30, 35));
        label_4->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_3->addWidget(label_4);

        xposLcd = new QLCDNumber(ScanPixWidget);
        xposLcd->setObjectName(QStringLiteral("xposLcd"));
        xposLcd->setMinimumSize(QSize(0, 35));
        xposLcd->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(xposLcd);

        label_2 = new QLabel(ScanPixWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(30, 35));
        label_2->setMaximumSize(QSize(30, 35));
        label_2->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_3->addWidget(label_2);

        ypoLcd = new QLCDNumber(ScanPixWidget);
        ypoLcd->setObjectName(QStringLiteral("ypoLcd"));
        ypoLcd->setMinimumSize(QSize(0, 35));
        ypoLcd->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(ypoLcd);

        label_3 = new QLabel(ScanPixWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(30, 35));
        label_3->setMaximumSize(QSize(30, 35));
        label_3->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));

        horizontalLayout_3->addWidget(label_3);

        pixLcd = new QLCDNumber(ScanPixWidget);
        pixLcd->setObjectName(QStringLiteral("pixLcd"));
        pixLcd->setMinimumSize(QSize(0, 35));
        pixLcd->setMaximumSize(QSize(16777215, 35));

        horizontalLayout_3->addWidget(pixLcd);


        verticalLayout->addLayout(horizontalLayout_3);

        line_3 = new QFrame(ScanPixWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        groupBox = new QGroupBox(ScanPixWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget = new DisplayWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_4->addWidget(widget);


        verticalLayout->addWidget(groupBox);

        verticalLayout->setStretch(4, 1);

        retranslateUi(ScanPixWidget);

        QMetaObject::connectSlotsByName(ScanPixWidget);
    } // setupUi

    void retranslateUi(QWidget *ScanPixWidget)
    {
        ScanPixWidget->setWindowTitle(QApplication::translate("ScanPixWidget", "ScanPixWidget", Q_NULLPTR));
        checkBox->setText(QApplication::translate("ScanPixWidget", "Enable", Q_NULLPTR));
        label->setText(QApplication::translate("ScanPixWidget", "X1", Q_NULLPTR));
        label_4->setText(QApplication::translate("ScanPixWidget", "XPos:", Q_NULLPTR));
        label_2->setText(QApplication::translate("ScanPixWidget", "YPos:", Q_NULLPTR));
        label_3->setText(QApplication::translate("ScanPixWidget", "Pix", Q_NULLPTR));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class ScanPixWidget: public Ui_ScanPixWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCANPIXWIDGET_H
