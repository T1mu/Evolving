/********************************************************************************
** Form generated from reading UI file 'MainWidgetDisplay.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGETDISPLAY_H
#define UI_MAINWIDGETDISPLAY_H

#include <GrayCurveChart.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <RightWidget.h>
#include <Ui/ViewManager/newImageView.h>
#include "CommonTools.h"
#include "FileManagement.h"
#include "MeasureWidget.h"
#include "ProcessWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWidgetDisplay
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_left;
    QVBoxLayout *verticalLayout_2;
    GrayCurveChart *widget_Curve;
    ProcessWidget *widget_Mark;
    RightWidget *widget_Hardware;
    MeasureWidget *widget_Measure;
    FileManagement *widget_File;
    QWidget *widget_right;
    QVBoxLayout *verticalLayout_3;
    newImageView *widget_2DView;
    QWidget *widget_3DView;
    CommonTools *widget_5;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QWidget *MainWidgetDisplay)
    {
        if (MainWidgetDisplay->objectName().isEmpty())
            MainWidgetDisplay->setObjectName(QStringLiteral("MainWidgetDisplay"));
        MainWidgetDisplay->resize(868, 851);
        verticalLayout = new QVBoxLayout(MainWidgetDisplay);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(MainWidgetDisplay);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget_left = new QWidget(widget);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_left->sizePolicy().hasHeightForWidth());
        widget_left->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_left);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_Curve = new GrayCurveChart(widget_left);
        widget_Curve->setObjectName(QStringLiteral("widget_Curve"));
        sizePolicy.setHeightForWidth(widget_Curve->sizePolicy().hasHeightForWidth());
        widget_Curve->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget_Curve);

        widget_Mark = new ProcessWidget(widget_left);
        widget_Mark->setObjectName(QStringLiteral("widget_Mark"));
        sizePolicy.setHeightForWidth(widget_Mark->sizePolicy().hasHeightForWidth());
        widget_Mark->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget_Mark);

        widget_Hardware = new RightWidget(widget_left);
        widget_Hardware->setObjectName(QStringLiteral("widget_Hardware"));
        sizePolicy.setHeightForWidth(widget_Hardware->sizePolicy().hasHeightForWidth());
        widget_Hardware->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget_Hardware);

        widget_Measure = new MeasureWidget(widget_left);
        widget_Measure->setObjectName(QStringLiteral("widget_Measure"));
        sizePolicy.setHeightForWidth(widget_Measure->sizePolicy().hasHeightForWidth());
        widget_Measure->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget_Measure);

        widget_File = new FileManagement(widget_left);
        widget_File->setObjectName(QStringLiteral("widget_File"));
        sizePolicy.setHeightForWidth(widget_File->sizePolicy().hasHeightForWidth());
        widget_File->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(widget_File);


        horizontalLayout->addWidget(widget_left);

        widget_right = new QWidget(widget);
        widget_right->setObjectName(QStringLiteral("widget_right"));
        sizePolicy.setHeightForWidth(widget_right->sizePolicy().hasHeightForWidth());
        widget_right->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(widget_right);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget_2DView = new newImageView(widget_right);
        widget_2DView->setObjectName(QStringLiteral("widget_2DView"));
        sizePolicy.setHeightForWidth(widget_2DView->sizePolicy().hasHeightForWidth());
        widget_2DView->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(widget_2DView);

        widget_3DView = new QWidget(widget_right);
        widget_3DView->setObjectName(QStringLiteral("widget_3DView"));
        sizePolicy.setHeightForWidth(widget_3DView->sizePolicy().hasHeightForWidth());
        widget_3DView->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(widget_3DView);


        horizontalLayout->addWidget(widget_right);

        widget_5 = new CommonTools(widget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        sizePolicy.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(widget_5);

        horizontalSpacer_2 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);


        retranslateUi(MainWidgetDisplay);

        QMetaObject::connectSlotsByName(MainWidgetDisplay);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetDisplay)
    {
        MainWidgetDisplay->setWindowTitle(QApplication::translate("MainWidgetDisplay", "MainWidgetDisplay", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWidgetDisplay: public Ui_MainWidgetDisplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGETDISPLAY_H
