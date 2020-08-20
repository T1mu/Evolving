/********************************************************************************
** Form generated from reading UI file 'StateWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATEWIDGET_H
#define UI_STATEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StateWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *opentubeBtn;
    QLabel *label_4;
    QLabel *label_9;
    QToolButton *toolButton_2;
    QToolButton *opendoorBtn;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QLineEdit *frameC;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *exporeT;
    QLabel *posLabel;
    QLabel *label_3;

    void setupUi(QWidget *StateWidget)
    {
        if (StateWidget->objectName().isEmpty())
            StateWidget->setObjectName(QStringLiteral("StateWidget"));
        StateWidget->resize(818, 56);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StateWidget->sizePolicy().hasHeightForWidth());
        StateWidget->setSizePolicy(sizePolicy);
        StateWidget->setMinimumSize(QSize(0, 30));
        StateWidget->setMaximumSize(QSize(16777215, 56));
        StateWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(StateWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(StateWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 35));
        groupBox->setMaximumSize(QSize(16777215, 35));
        groupBox->setStyleSheet(QStringLiteral(""));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(4);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 0, 0, 0);
        opentubeBtn = new QToolButton(groupBox);
        opentubeBtn->setObjectName(QStringLiteral("opentubeBtn"));
        opentubeBtn->setMinimumSize(QSize(65, 30));
        opentubeBtn->setMaximumSize(QSize(16665, 16665));
        opentubeBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/tubeclose.ico"), QSize(), QIcon::Normal, QIcon::Off);
        opentubeBtn->setIcon(icon);
        opentubeBtn->setIconSize(QSize(60, 30));

        horizontalLayout_3->addWidget(opentubeBtn);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_9);

        toolButton_2 = new QToolButton(groupBox);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy1);
        toolButton_2->setMinimumSize(QSize(35, 30));
        toolButton_2->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/radio_selected.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(toolButton_2);

        opendoorBtn = new QToolButton(groupBox);
        opendoorBtn->setObjectName(QStringLiteral("opendoorBtn"));
        sizePolicy1.setHeightForWidth(opendoorBtn->sizePolicy().hasHeightForWidth());
        opendoorBtn->setSizePolicy(sizePolicy1);
        opendoorBtn->setMinimumSize(QSize(35, 30));
        opendoorBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/Lock.ico"), QSize(), QIcon::Normal, QIcon::Off);
        opendoorBtn->setIcon(icon2);
        opendoorBtn->setIconSize(QSize(25, 25));

        horizontalLayout_3->addWidget(opendoorBtn);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(35, 30));
        label_5->setMaximumSize(QSize(35, 30));
        label_5->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/image/ok.ico")));
        label_5->setScaledContents(true);

        horizontalLayout_3->addWidget(label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(100, 30));
        label_6->setMaximumSize(QSize(150, 30));
        label_6->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 10pt \"\346\226\260\345\256\213\344\275\223\";"));
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_6);

        frameC = new QLineEdit(groupBox);
        frameC->setObjectName(QStringLiteral("frameC"));
        frameC->setMinimumSize(QSize(100, 0));
        frameC->setMaximumSize(QSize(120, 35));
        frameC->setLayoutDirection(Qt::LeftToRight);
        frameC->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));
        frameC->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(frameC);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(100, 30));
        label_7->setMaximumSize(QSize(150, 30));
        label_7->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 10pt \"\346\226\260\345\256\213\344\275\223\";"));
        label_7->setScaledContents(true);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_7);

        exporeT = new QLineEdit(groupBox);
        exporeT->setObjectName(QStringLiteral("exporeT"));
        exporeT->setMinimumSize(QSize(100, 0));
        exporeT->setMaximumSize(QSize(120, 35));
        exporeT->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 213, 213);\n"
"font: 11pt \"\346\226\260\345\256\213\344\275\223\";"));
        exporeT->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(exporeT);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 2);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        posLabel = new QLabel(groupBox);
        posLabel->setObjectName(QStringLiteral("posLabel"));
        posLabel->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        posLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(posLabel);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));

        horizontalLayout_3->addWidget(label_3);

        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(6, 1);
        horizontalLayout_3->setStretch(7, 1);
        horizontalLayout_3->setStretch(8, 2);
        horizontalLayout_3->setStretch(9, 2);

        verticalLayout->addWidget(groupBox);


        retranslateUi(StateWidget);

        QMetaObject::connectSlotsByName(StateWidget);
    } // setupUi

    void retranslateUi(QWidget *StateWidget)
    {
        StateWidget->setWindowTitle(QApplication::translate("StateWidget", "StateWidget", Q_NULLPTR));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        opentubeBtn->setToolTip(QApplication::translate("StateWidget", "\346\211\223\345\274\200\347\220\203\347\256\241", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        opentubeBtn->setText(QApplication::translate("StateWidget", "...", Q_NULLPTR));
        label_4->setText(QApplication::translate("StateWidget", "0 KV", Q_NULLPTR));
        label_9->setText(QApplication::translate("StateWidget", "0.0 W", Q_NULLPTR));
        toolButton_2->setText(QString());
        opendoorBtn->setText(QString());
        label_5->setText(QString());
        label_6->setText(QApplication::translate("StateWidget", "Count\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("StateWidget", "Time\357\274\232", Q_NULLPTR));
        posLabel->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StateWidget: public Ui_StateWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATEWIDGET_H
