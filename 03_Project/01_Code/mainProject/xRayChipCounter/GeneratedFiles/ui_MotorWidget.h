/********************************************************************************
** Form generated from reading UI file 'MotorWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOTORWIDGET_H
#define UI_MOTORWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MotorWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *connectNetCardBtn;
    QComboBox *netCardComboBox;
    QPushButton *stopBtn;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QDoubleSpinBox *xSpeedSpinBox;
    QLabel *label_10;
    QSpinBox *xMoveSpinBox;
    QLabel *label_17;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *xNegativeBtn;
    QPushButton *xPositiveBtn;
    QSlider *xSlider;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_8;
    QDoubleSpinBox *ySpeedSpinBox;
    QLabel *label_12;
    QSpinBox *yMoveSpinBox;
    QLabel *label_18;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *yNegativeBtn;
    QPushButton *yPositiveBtn;
    QSlider *ySlider;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_10;
    QDoubleSpinBox *zSpeedSpinBox;
    QLabel *label_11;
    QSpinBox *zMoveSpinBox;
    QLabel *label_19;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_13;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *zNegativeBtn;
    QPushButton *zPositiveBtn;
    QSlider *zSlider;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_12;
    QDoubleSpinBox *rSpeedSpinBox;
    QLabel *label_13;
    QSpinBox *rMoveSpinBox;
    QLabel *label_15;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_16;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *rNegativeBtn;
    QPushButton *rPositiveBtn;
    QSlider *rSlider;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_14;
    QDoubleSpinBox *tSpeedSpinBox;
    QLabel *label_14;
    QSpinBox *tMoveSpinBox;
    QLabel *label_16;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_18;
    QSpacerItem *horizontalSpacer_15;
    QPushButton *tNegativeBtn;
    QPushButton *tPositiveBtn;
    QSlider *tSlider;

    void setupUi(QWidget *MotorWidget)
    {
        if (MotorWidget->objectName().isEmpty())
            MotorWidget->setObjectName(QStringLiteral("MotorWidget"));
        MotorWidget->resize(569, 492);
        MotorWidget->setMinimumSize(QSize(455, 375));
        horizontalLayout = new QHBoxLayout(MotorWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        connectNetCardBtn = new QPushButton(MotorWidget);
        connectNetCardBtn->setObjectName(QStringLiteral("connectNetCardBtn"));
        connectNetCardBtn->setMinimumSize(QSize(75, 25));
        connectNetCardBtn->setMaximumSize(QSize(75, 25));

        horizontalLayout_5->addWidget(connectNetCardBtn);

        netCardComboBox = new QComboBox(MotorWidget);
        netCardComboBox->setObjectName(QStringLiteral("netCardComboBox"));
        netCardComboBox->setMinimumSize(QSize(201, 25));
        netCardComboBox->setMaximumSize(QSize(201, 25));

        horizontalLayout_5->addWidget(netCardComboBox);

        stopBtn = new QPushButton(MotorWidget);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setMinimumSize(QSize(75, 25));
        stopBtn->setMaximumSize(QSize(75, 25));

        horizontalLayout_5->addWidget(stopBtn);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        xSpeedSpinBox = new QDoubleSpinBox(MotorWidget);
        xSpeedSpinBox->setObjectName(QStringLiteral("xSpeedSpinBox"));
        xSpeedSpinBox->setMinimumSize(QSize(61, 25));
        xSpeedSpinBox->setMaximumSize(QSize(61, 25));
        xSpeedSpinBox->setMaximum(1000);

        horizontalLayout_8->addWidget(xSpeedSpinBox);

        label_10 = new QLabel(MotorWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(41);
        sizePolicy.setVerticalStretch(25);
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(41, 25));
        label_10->setMaximumSize(QSize(31, 25));

        horizontalLayout_8->addWidget(label_10);

        xMoveSpinBox = new QSpinBox(MotorWidget);
        xMoveSpinBox->setObjectName(QStringLiteral("xMoveSpinBox"));
        xMoveSpinBox->setMinimumSize(QSize(55, 25));
        xMoveSpinBox->setMaximum(1000);

        horizontalLayout_8->addWidget(xMoveSpinBox);

        label_17 = new QLabel(MotorWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(31, 25));
        label_17->setMaximumSize(QSize(31, 25));

        horizontalLayout_8->addWidget(label_17);

        label_7 = new QLabel(MotorWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(21, 25));
        label_7->setMaximumSize(QSize(21, 25));

        horizontalLayout_8->addWidget(label_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_7 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        xNegativeBtn = new QPushButton(MotorWidget);
        xNegativeBtn->setObjectName(QStringLiteral("xNegativeBtn"));
        xNegativeBtn->setMinimumSize(QSize(70, 25));
        xNegativeBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_9->addWidget(xNegativeBtn);

        xPositiveBtn = new QPushButton(MotorWidget);
        xPositiveBtn->setObjectName(QStringLiteral("xPositiveBtn"));
        xPositiveBtn->setMinimumSize(QSize(70, 25));
        xPositiveBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_9->addWidget(xPositiveBtn);

        xSlider = new QSlider(MotorWidget);
        xSlider->setObjectName(QStringLiteral("xSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(xSlider->sizePolicy().hasHeightForWidth());
        xSlider->setSizePolicy(sizePolicy1);
        xSlider->setMaximum(1000);
        xSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(xSlider);


        verticalLayout_2->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_8 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        ySpeedSpinBox = new QDoubleSpinBox(MotorWidget);
        ySpeedSpinBox->setObjectName(QStringLiteral("ySpeedSpinBox"));
        ySpeedSpinBox->setMinimumSize(QSize(61, 25));
        ySpeedSpinBox->setMaximumSize(QSize(61, 25));
        ySpeedSpinBox->setMaximum(1000);

        horizontalLayout_10->addWidget(ySpeedSpinBox);

        label_12 = new QLabel(MotorWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(41, 25));
        label_12->setMaximumSize(QSize(41, 25));

        horizontalLayout_10->addWidget(label_12);

        yMoveSpinBox = new QSpinBox(MotorWidget);
        yMoveSpinBox->setObjectName(QStringLiteral("yMoveSpinBox"));
        yMoveSpinBox->setMinimumSize(QSize(55, 25));
        yMoveSpinBox->setMaximum(1000);

        horizontalLayout_10->addWidget(yMoveSpinBox);

        label_18 = new QLabel(MotorWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMinimumSize(QSize(31, 25));
        label_18->setMaximumSize(QSize(31, 25));

        horizontalLayout_10->addWidget(label_18);

        label_8 = new QLabel(MotorWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(21, 25));
        label_8->setMaximumSize(QSize(21, 25));

        horizontalLayout_10->addWidget(label_8);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_9 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_9);

        yNegativeBtn = new QPushButton(MotorWidget);
        yNegativeBtn->setObjectName(QStringLiteral("yNegativeBtn"));
        yNegativeBtn->setMinimumSize(QSize(70, 25));
        yNegativeBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_11->addWidget(yNegativeBtn);

        yPositiveBtn = new QPushButton(MotorWidget);
        yPositiveBtn->setObjectName(QStringLiteral("yPositiveBtn"));
        yPositiveBtn->setMinimumSize(QSize(70, 25));
        yPositiveBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_11->addWidget(yPositiveBtn);

        ySlider = new QSlider(MotorWidget);
        ySlider->setObjectName(QStringLiteral("ySlider"));
        ySlider->setMaximum(1000);
        ySlider->setSingleStep(0);
        ySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(ySlider);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_10 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);

        zSpeedSpinBox = new QDoubleSpinBox(MotorWidget);
        zSpeedSpinBox->setObjectName(QStringLiteral("zSpeedSpinBox"));
        zSpeedSpinBox->setMinimumSize(QSize(61, 25));
        zSpeedSpinBox->setMaximumSize(QSize(61, 25));
        zSpeedSpinBox->setMaximum(1000);

        horizontalLayout_12->addWidget(zSpeedSpinBox);

        label_11 = new QLabel(MotorWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(41, 25));
        label_11->setMaximumSize(QSize(41, 25));

        horizontalLayout_12->addWidget(label_11);

        zMoveSpinBox = new QSpinBox(MotorWidget);
        zMoveSpinBox->setObjectName(QStringLiteral("zMoveSpinBox"));
        zMoveSpinBox->setMinimumSize(QSize(55, 25));
        zMoveSpinBox->setMaximum(1000);

        horizontalLayout_12->addWidget(zMoveSpinBox);

        label_19 = new QLabel(MotorWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(31, 25));
        label_19->setMaximumSize(QSize(31, 25));

        horizontalLayout_12->addWidget(label_19);

        label_9 = new QLabel(MotorWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(21, 25));
        label_9->setMaximumSize(QSize(21, 25));

        horizontalLayout_12->addWidget(label_9);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalSpacer_11 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_11);

        zNegativeBtn = new QPushButton(MotorWidget);
        zNegativeBtn->setObjectName(QStringLiteral("zNegativeBtn"));
        zNegativeBtn->setMinimumSize(QSize(70, 25));
        zNegativeBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_13->addWidget(zNegativeBtn);

        zPositiveBtn = new QPushButton(MotorWidget);
        zPositiveBtn->setObjectName(QStringLiteral("zPositiveBtn"));
        zPositiveBtn->setMinimumSize(QSize(70, 25));
        zPositiveBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_13->addWidget(zPositiveBtn);

        zSlider = new QSlider(MotorWidget);
        zSlider->setObjectName(QStringLiteral("zSlider"));
        zSlider->setMaximum(1000);
        zSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_13->addWidget(zSlider);


        verticalLayout_2->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_12 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);

        rSpeedSpinBox = new QDoubleSpinBox(MotorWidget);
        rSpeedSpinBox->setObjectName(QStringLiteral("rSpeedSpinBox"));
        rSpeedSpinBox->setMinimumSize(QSize(61, 25));
        rSpeedSpinBox->setMaximumSize(QSize(61, 25));
        rSpeedSpinBox->setMaximum(1000);

        horizontalLayout_14->addWidget(rSpeedSpinBox);

        label_13 = new QLabel(MotorWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(41, 25));
        label_13->setMaximumSize(QSize(41, 25));

        horizontalLayout_14->addWidget(label_13);

        rMoveSpinBox = new QSpinBox(MotorWidget);
        rMoveSpinBox->setObjectName(QStringLiteral("rMoveSpinBox"));
        rMoveSpinBox->setMinimumSize(QSize(55, 25));
        rMoveSpinBox->setMaximum(360);

        horizontalLayout_14->addWidget(rMoveSpinBox);

        label_15 = new QLabel(MotorWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(31, 25));
        label_15->setMaximumSize(QSize(31, 25));

        horizontalLayout_14->addWidget(label_15);

        label_6 = new QLabel(MotorWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(40, 25));
        label_6->setMaximumSize(QSize(40, 25));

        horizontalLayout_14->addWidget(label_6);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_5);


        verticalLayout_2->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalSpacer_13 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_13);

        rNegativeBtn = new QPushButton(MotorWidget);
        rNegativeBtn->setObjectName(QStringLiteral("rNegativeBtn"));
        rNegativeBtn->setMinimumSize(QSize(70, 25));
        rNegativeBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_16->addWidget(rNegativeBtn);

        rPositiveBtn = new QPushButton(MotorWidget);
        rPositiveBtn->setObjectName(QStringLiteral("rPositiveBtn"));
        rPositiveBtn->setMinimumSize(QSize(70, 25));
        rPositiveBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_16->addWidget(rPositiveBtn);

        rSlider = new QSlider(MotorWidget);
        rSlider->setObjectName(QStringLiteral("rSlider"));
        rSlider->setMaximum(360);
        rSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_16->addWidget(rSlider);


        verticalLayout_2->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalSpacer_14 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_14);

        tSpeedSpinBox = new QDoubleSpinBox(MotorWidget);
        tSpeedSpinBox->setObjectName(QStringLiteral("tSpeedSpinBox"));
        tSpeedSpinBox->setMinimumSize(QSize(61, 25));
        tSpeedSpinBox->setMaximumSize(QSize(61, 25));
        tSpeedSpinBox->setMaximum(1000);

        horizontalLayout_17->addWidget(tSpeedSpinBox);

        label_14 = new QLabel(MotorWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(41, 25));
        label_14->setMaximumSize(QSize(41, 25));

        horizontalLayout_17->addWidget(label_14);

        tMoveSpinBox = new QSpinBox(MotorWidget);
        tMoveSpinBox->setObjectName(QStringLiteral("tMoveSpinBox"));
        tMoveSpinBox->setMinimumSize(QSize(55, 25));
        tMoveSpinBox->setMaximum(360);

        horizontalLayout_17->addWidget(tMoveSpinBox);

        label_16 = new QLabel(MotorWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(31, 25));
        label_16->setMaximumSize(QSize(31, 25));

        horizontalLayout_17->addWidget(label_16);

        label_21 = new QLabel(MotorWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(61, 25));
        label_21->setMaximumSize(QSize(61, 25));

        horizontalLayout_17->addWidget(label_21);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalSpacer_15 = new QSpacerItem(5, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_15);

        tNegativeBtn = new QPushButton(MotorWidget);
        tNegativeBtn->setObjectName(QStringLiteral("tNegativeBtn"));
        tNegativeBtn->setMinimumSize(QSize(70, 25));
        tNegativeBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_18->addWidget(tNegativeBtn);

        tPositiveBtn = new QPushButton(MotorWidget);
        tPositiveBtn->setObjectName(QStringLiteral("tPositiveBtn"));
        tPositiveBtn->setMinimumSize(QSize(70, 25));
        tPositiveBtn->setMaximumSize(QSize(70, 25));

        horizontalLayout_18->addWidget(tPositiveBtn);

        tSlider = new QSlider(MotorWidget);
        tSlider->setObjectName(QStringLiteral("tSlider"));
        tSlider->setMaximum(360);
        tSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_18->addWidget(tSlider);


        verticalLayout_2->addLayout(horizontalLayout_18);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(MotorWidget);

        QMetaObject::connectSlotsByName(MotorWidget);
    } // setupUi

    void retranslateUi(QWidget *MotorWidget)
    {
        MotorWidget->setWindowTitle(QApplication::translate("MotorWidget", "MotorWidget", Q_NULLPTR));
        connectNetCardBtn->setText(QApplication::translate("MotorWidget", "\350\277\236\346\216\245\347\275\221\345\215\241", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("MotorWidget", "\345\201\234\346\255\242\350\277\220\345\212\250", Q_NULLPTR));
        label_10->setText(QApplication::translate("MotorWidget", "mm/s", Q_NULLPTR));
        label_17->setText(QApplication::translate("MotorWidget", "mm", Q_NULLPTR));
        label_7->setText(QApplication::translate("MotorWidget", "X\350\275\264", Q_NULLPTR));
        xNegativeBtn->setText(QApplication::translate("MotorWidget", "<<", Q_NULLPTR));
        xPositiveBtn->setText(QApplication::translate("MotorWidget", ">>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MotorWidget", "mm/s", Q_NULLPTR));
        label_18->setText(QApplication::translate("MotorWidget", "mm", Q_NULLPTR));
        label_8->setText(QApplication::translate("MotorWidget", "Y\350\275\264", Q_NULLPTR));
        yNegativeBtn->setText(QApplication::translate("MotorWidget", "<<", Q_NULLPTR));
        yPositiveBtn->setText(QApplication::translate("MotorWidget", ">>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MotorWidget", "mm/s", Q_NULLPTR));
        label_19->setText(QApplication::translate("MotorWidget", "mm", Q_NULLPTR));
        label_9->setText(QApplication::translate("MotorWidget", "Z\350\275\264", Q_NULLPTR));
        zNegativeBtn->setText(QApplication::translate("MotorWidget", "<<", Q_NULLPTR));
        zPositiveBtn->setText(QApplication::translate("MotorWidget", ">>", Q_NULLPTR));
        label_13->setText(QApplication::translate("MotorWidget", "rad/s", Q_NULLPTR));
        label_15->setText(QApplication::translate("MotorWidget", "rad", Q_NULLPTR));
        label_6->setText(QApplication::translate("MotorWidget", "\350\275\254\345\217\260", Q_NULLPTR));
        rNegativeBtn->setText(QApplication::translate("MotorWidget", "<<", Q_NULLPTR));
        rPositiveBtn->setText(QApplication::translate("MotorWidget", ">>", Q_NULLPTR));
        label_14->setText(QApplication::translate("MotorWidget", "rad/s", Q_NULLPTR));
        label_16->setText(QApplication::translate("MotorWidget", "rad", Q_NULLPTR));
        label_21->setText(QApplication::translate("MotorWidget", "\350\247\222\344\275\215\347\247\273\345\217\260", Q_NULLPTR));
        tNegativeBtn->setText(QApplication::translate("MotorWidget", "<<", Q_NULLPTR));
        tPositiveBtn->setText(QApplication::translate("MotorWidget", ">>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MotorWidget: public Ui_MotorWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOTORWIDGET_H
