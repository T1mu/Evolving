/********************************************************************************
** Form generated from reading UI file 'motorControl.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORCONTROL_H
#define UI_MOTORCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_motorControl
{
public:
    QSplitter *splitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnStart;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnClose;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnReset;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QDoubleSpinBox *spinboxX;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton_4;
    QLabel *label;
    QDoubleSpinBox *spinboxX_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *motorControl)
    {
        if (motorControl->objectName().isEmpty())
            motorControl->setObjectName(QStringLiteral("motorControl"));
        motorControl->resize(490, 250);
        splitter = new QSplitter(motorControl);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(80, 50, 366, 121));
        splitter->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btnStart = new QPushButton(widget);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        horizontalLayout->addWidget(btnStart);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnClose = new QPushButton(widget);
        btnClose->setObjectName(QStringLiteral("btnClose"));

        horizontalLayout->addWidget(btnClose);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btnReset = new QPushButton(widget);
        btnReset->setObjectName(QStringLiteral("btnReset"));

        horizontalLayout->addWidget(btnReset);

        splitter->addWidget(widget);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinboxX = new QDoubleSpinBox(gridLayoutWidget);
        spinboxX->setObjectName(QStringLiteral("spinboxX"));

        gridLayout->addWidget(spinboxX, 1, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 2, 4, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinboxX_2 = new QDoubleSpinBox(gridLayoutWidget);
        spinboxX_2->setObjectName(QStringLiteral("spinboxX_2"));

        gridLayout->addWidget(spinboxX_2, 1, 4, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 1, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 2, 3, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        splitter->addWidget(gridLayoutWidget);

        retranslateUi(motorControl);

        QMetaObject::connectSlotsByName(motorControl);
    } // setupUi

    void retranslateUi(QWidget *motorControl)
    {
        motorControl->setWindowTitle(QApplication::translate("motorControl", "motorControl", Q_NULLPTR));
        btnStart->setText(QApplication::translate("motorControl", "\345\274\200\345\220\257", Q_NULLPTR));
        btnClose->setText(QApplication::translate("motorControl", "\345\205\263\351\227\255", Q_NULLPTR));
        btnReset->setText(QApplication::translate("motorControl", "\345\244\215\344\275\215", Q_NULLPTR));
        label_3->setText(QApplication::translate("motorControl", "Y\350\275\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("motorControl", "X\350\275\264\351\200\237\345\272\246", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("motorControl", "\344\270\213\350\241\214", Q_NULLPTR));
        label->setText(QApplication::translate("motorControl", "X\350\275\264", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("motorControl", "\345\217\215\350\275\254", Q_NULLPTR));
        pushButton->setText(QApplication::translate("motorControl", "\346\255\243\350\275\254", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("motorControl", "\344\270\212\350\241\214", Q_NULLPTR));
        label_5->setText(QApplication::translate("motorControl", "Y\350\275\264\351\200\237\345\272\246", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class motorControl: public Ui_motorControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORCONTROL_H
