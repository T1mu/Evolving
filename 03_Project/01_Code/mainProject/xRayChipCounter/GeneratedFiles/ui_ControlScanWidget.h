/********************************************************************************
** Form generated from reading UI file 'ControlScanWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLSCANWIDGET_H
#define UI_CONTROLSCANWIDGET_H

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

QT_BEGIN_NAMESPACE

class Ui_ControlScanWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;

    void setupUi(QWidget *ControlScanWidget)
    {
        if (ControlScanWidget->objectName().isEmpty())
            ControlScanWidget->setObjectName(QStringLiteral("ControlScanWidget"));
        ControlScanWidget->resize(300, 400);
        ControlScanWidget->setMinimumSize(QSize(300, 400));
        ControlScanWidget->setMaximumSize(QSize(300, 400));
        verticalLayout = new QVBoxLayout(ControlScanWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(ControlScanWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(ControlScanWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(widget);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        toolButton = new QToolButton(ControlScanWidget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy);
        toolButton->setMinimumSize(QSize(73, 35));
        toolButton->setStyleSheet(QStringLiteral(""));
        toolButton->setIconSize(QSize(73, 50));

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(ControlScanWidget);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        sizePolicy.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy);
        toolButton_2->setMinimumSize(QSize(73, 35));

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(ControlScanWidget);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        sizePolicy.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy);
        toolButton_3->setMinimumSize(QSize(73, 35));

        horizontalLayout_2->addWidget(toolButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(1, 1);

        retranslateUi(ControlScanWidget);

        QMetaObject::connectSlotsByName(ControlScanWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlScanWidget)
    {
        ControlScanWidget->setWindowTitle(QApplication::translate("ControlScanWidget", "ControlScanWidget", Q_NULLPTR));
        label->setText(QApplication::translate("ControlScanWidget", "\345\256\207\350\210\252\345\233\276\346\230\276\347\244\272", Q_NULLPTR));
        groupBox->setTitle(QString());
        toolButton->setText(QApplication::translate("ControlScanWidget", "Scan Full", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("ControlScanWidget", "Scan Board", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("ControlScanWidget", "Clear Scan ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControlScanWidget: public Ui_ControlScanWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLSCANWIDGET_H
