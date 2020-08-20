/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <MainWidgetDisplay.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout;
    QToolButton *measureBtn;
    QToolButton *paintBtn;
    QToolButton *curveBtn;
    QToolButton *hardwareBtn;
    QToolButton *fileBtn;
    QToolButton *dataBtn;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *mainBtn;
    QToolButton *threeDimBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QPushButton *btnMenu_Max;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QSpacerItem *verticalSpacer;
    QWidget *widget_main;
    QHBoxLayout *horizontalLayout_4;
    MainWidgetDisplay *widget_left;
    QVBoxLayout *verticalLayout_6;

    void setupUi(QWidget *MainWidgetClass)
    {
        if (MainWidgetClass->objectName().isEmpty())
            MainWidgetClass->setObjectName(QStringLiteral("MainWidgetClass"));
        MainWidgetClass->setEnabled(true);
        MainWidgetClass->resize(1195, 859);
        MainWidgetClass->setStyleSheet(QStringLiteral(""));
        MainWidgetClass->setProperty("sizeGripEnabled", QVariant(false));
        verticalLayout = new QVBoxLayout(MainWidgetClass);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widgetTitle = new QWidget(MainWidgetClass);
        widgetTitle->setObjectName(QStringLiteral("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        widgetTitle->setMinimumSize(QSize(0, 65));
        widgetTitle->setMaximumSize(QSize(16777215, 65));
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QStringLiteral("widgetTop"));
        horizontalLayout = new QHBoxLayout(widgetTop);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        measureBtn = new QToolButton(widgetTop);
        measureBtn->setObjectName(QStringLiteral("measureBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(measureBtn->sizePolicy().hasHeightForWidth());
        measureBtn->setSizePolicy(sizePolicy1);
        measureBtn->setChecked(false);
        measureBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(measureBtn);

        paintBtn = new QToolButton(widgetTop);
        paintBtn->setObjectName(QStringLiteral("paintBtn"));
        sizePolicy1.setHeightForWidth(paintBtn->sizePolicy().hasHeightForWidth());
        paintBtn->setSizePolicy(sizePolicy1);
        paintBtn->setChecked(false);
        paintBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(paintBtn);

        curveBtn = new QToolButton(widgetTop);
        curveBtn->setObjectName(QStringLiteral("curveBtn"));
        sizePolicy1.setHeightForWidth(curveBtn->sizePolicy().hasHeightForWidth());
        curveBtn->setSizePolicy(sizePolicy1);
        curveBtn->setChecked(false);
        curveBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(curveBtn);

        hardwareBtn = new QToolButton(widgetTop);
        hardwareBtn->setObjectName(QStringLiteral("hardwareBtn"));
        sizePolicy1.setHeightForWidth(hardwareBtn->sizePolicy().hasHeightForWidth());
        hardwareBtn->setSizePolicy(sizePolicy1);
        hardwareBtn->setStyleSheet(QStringLiteral(""));
        hardwareBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(hardwareBtn);

        fileBtn = new QToolButton(widgetTop);
        fileBtn->setObjectName(QStringLiteral("fileBtn"));
        sizePolicy1.setHeightForWidth(fileBtn->sizePolicy().hasHeightForWidth());
        fileBtn->setSizePolicy(sizePolicy1);
        fileBtn->setStyleSheet(QStringLiteral(""));
        fileBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(fileBtn);

        dataBtn = new QToolButton(widgetTop);
        dataBtn->setObjectName(QStringLiteral("dataBtn"));
        sizePolicy1.setHeightForWidth(dataBtn->sizePolicy().hasHeightForWidth());
        dataBtn->setSizePolicy(sizePolicy1);
        dataBtn->setStyleSheet(QStringLiteral(""));
        dataBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(dataBtn);

        horizontalSpacer_2 = new QSpacerItem(350, 20, QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        mainBtn = new QToolButton(widgetTop);
        mainBtn->setObjectName(QStringLiteral("mainBtn"));
        sizePolicy1.setHeightForWidth(mainBtn->sizePolicy().hasHeightForWidth());
        mainBtn->setSizePolicy(sizePolicy1);
        mainBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(mainBtn);

        threeDimBtn = new QToolButton(widgetTop);
        threeDimBtn->setObjectName(QStringLiteral("threeDimBtn"));
        sizePolicy1.setHeightForWidth(threeDimBtn->sizePolicy().hasHeightForWidth());
        threeDimBtn->setSizePolicy(sizePolicy1);
        threeDimBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout->addWidget(threeDimBtn);


        horizontalLayout_2->addWidget(widgetTop);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QStringLiteral("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QStringLiteral("labTitle"));
        labTitle->setStyleSheet(QStringLiteral(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QStringLiteral("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(3);
        gridLayout_2->setVerticalSpacing(0);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QStringLiteral("btnMenu_Max"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 4, 1, 1);

        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QStringLiteral("btnMenu_Min"));
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 3, 1, 1);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QStringLiteral("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 5, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 3, 1, 3);


        horizontalLayout_2->addWidget(widgetMenu);


        verticalLayout->addWidget(widgetTitle);

        widget_main = new QWidget(MainWidgetClass);
        widget_main->setObjectName(QStringLiteral("widget_main"));
        widget_main->setStyleSheet(QStringLiteral(""));
        horizontalLayout_4 = new QHBoxLayout(widget_main);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widget_left = new MainWidgetDisplay(widget_main);
        widget_left->setObjectName(QStringLiteral("widget_left"));
        verticalLayout_6 = new QVBoxLayout(widget_left);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_4->addWidget(widget_left);


        verticalLayout->addWidget(widget_main);


        retranslateUi(MainWidgetClass);

        QMetaObject::connectSlotsByName(MainWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *MainWidgetClass)
    {
        MainWidgetClass->setWindowTitle(QApplication::translate("MainWidgetClass", "3DCT\346\243\200\346\265\213\350\275\257\344\273\266", Q_NULLPTR));
        measureBtn->setText(QApplication::translate("MainWidgetClass", "\346\265\213\351\207\217\345\267\245\345\205\267", Q_NULLPTR));
        paintBtn->setText(QApplication::translate("MainWidgetClass", "\346\240\207\346\263\250\345\267\245\345\205\267", Q_NULLPTR));
        curveBtn->setText(QApplication::translate("MainWidgetClass", "\347\201\260\345\272\246\350\260\203\346\225\264", Q_NULLPTR));
        hardwareBtn->setText(QApplication::translate("MainWidgetClass", "\347\241\254\344\273\266\346\216\247\345\210\266", Q_NULLPTR));
        fileBtn->setText(QApplication::translate("MainWidgetClass", "\346\234\254\345\234\260\346\226\207\344\273\266", Q_NULLPTR));
        dataBtn->setText(QApplication::translate("MainWidgetClass", "\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
        mainBtn->setText(QApplication::translate("MainWidgetClass", "\344\270\273\347\225\214\351\235\242", Q_NULLPTR));
        threeDimBtn->setText(QApplication::translate("MainWidgetClass", "\344\270\211\347\273\264\350\247\206\345\233\276", Q_NULLPTR));
        labIco->setText(QString());
        labTitle->setText(QString());
        btnMenu_Max->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Min->setToolTip(QApplication::translate("MainWidgetClass", "\346\234\200\345\260\217\345\214\226", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMenu_Min->setText(QString());
#ifndef QT_NO_TOOLTIP
        btnMenu_Close->setToolTip(QApplication::translate("MainWidgetClass", "\345\205\263\351\227\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnMenu_Close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidgetClass: public Ui_MainWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
