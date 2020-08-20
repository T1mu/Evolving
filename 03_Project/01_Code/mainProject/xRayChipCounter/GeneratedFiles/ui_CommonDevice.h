/********************************************************************************
** Form generated from reading UI file 'CommonDevice.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMONDEVICE_H
#define UI_COMMONDEVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommonDevice
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QPushButton *openXRayBtn;
    QPushButton *closeXRayBtn;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_4;
    QSpinBox *voltageSpinBox;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_5;
    QSpinBox *currentSpinBox;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_8;
    QComboBox *modeComboBox;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *startPulseBtn;
    QPushButton *stopPulseBtn;
    QPushButton *getPicBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *trigComboBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QComboBox *gainComboBox;
    QHBoxLayout *horizontalLayout_11;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *modeDetectorComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QDoubleSpinBox *frameSpinBox;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QDoubleSpinBox *exposureSpinBox;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_21;
    QDoubleSpinBox *rSpeedSpinBox;
    QLabel *label_22;
    QLabel *label_23;
    QDoubleSpinBox *rMoveSpinBox;
    QLabel *label_24;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QComboBox *zhouComboBox;
    QDoubleSpinBox *zSpeedSpinBox;
    QLabel *label_11;
    QSpinBox *zMoveSpinBox;
    QLabel *label_17;
    QPushButton *zNegativeBtn;
    QPushButton *zPositiveBtn;
    QPushButton *stopBtn;

    void setupUi(QWidget *CommonDevice)
    {
        if (CommonDevice->objectName().isEmpty())
            CommonDevice->setObjectName(QStringLiteral("CommonDevice"));
        CommonDevice->resize(642, 257);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CommonDevice->sizePolicy().hasHeightForWidth());
        CommonDevice->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(CommonDevice);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(CommonDevice);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(64, 64));
        label->setMaximumSize(QSize(64, 64));

        horizontalLayout_5->addWidget(label);

        openXRayBtn = new QPushButton(groupBox);
        openXRayBtn->setObjectName(QStringLiteral("openXRayBtn"));
        openXRayBtn->setMinimumSize(QSize(45, 40));
        openXRayBtn->setMaximumSize(QSize(45, 40));

        horizontalLayout_5->addWidget(openXRayBtn);

        closeXRayBtn = new QPushButton(groupBox);
        closeXRayBtn->setObjectName(QStringLiteral("closeXRayBtn"));
        closeXRayBtn->setMinimumSize(QSize(45, 40));
        closeXRayBtn->setMaximumSize(QSize(45, 40));

        horizontalLayout_5->addWidget(closeXRayBtn);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(51, 21));
        label_4->setMaximumSize(QSize(51, 21));

        horizontalLayout_15->addWidget(label_4);

        voltageSpinBox = new QSpinBox(groupBox);
        voltageSpinBox->setObjectName(QStringLiteral("voltageSpinBox"));
        voltageSpinBox->setMinimumSize(QSize(51, 25));
        voltageSpinBox->setMaximumSize(QSize(51, 25));

        horizontalLayout_15->addWidget(voltageSpinBox);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(21, 21));
        label_7->setMaximumSize(QSize(21, 21));

        horizontalLayout_15->addWidget(label_7);


        horizontalLayout_6->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(51, 21));
        label_5->setMaximumSize(QSize(51, 21));

        horizontalLayout_16->addWidget(label_5);

        currentSpinBox = new QSpinBox(groupBox);
        currentSpinBox->setObjectName(QStringLiteral("currentSpinBox"));
        currentSpinBox->setMinimumSize(QSize(51, 25));
        currentSpinBox->setMaximumSize(QSize(25, 24));

        horizontalLayout_16->addWidget(currentSpinBox);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(21, 21));
        label_10->setMaximumSize(QSize(21, 21));

        horizontalLayout_16->addWidget(label_10);


        horizontalLayout_6->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(41, 21));
        label_8->setMaximumSize(QSize(41, 21));

        horizontalLayout_17->addWidget(label_8);

        modeComboBox = new QComboBox(groupBox);
        modeComboBox->setObjectName(QStringLiteral("modeComboBox"));
        modeComboBox->setMinimumSize(QSize(61, 25));
        modeComboBox->setMaximumSize(QSize(61, 25));

        horizontalLayout_17->addWidget(modeComboBox);


        horizontalLayout_6->addLayout(horizontalLayout_17);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(CommonDevice);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        startPulseBtn = new QPushButton(groupBox_2);
        startPulseBtn->setObjectName(QStringLiteral("startPulseBtn"));
        startPulseBtn->setMinimumSize(QSize(71, 25));
        startPulseBtn->setMaximumSize(QSize(71, 25));

        horizontalLayout_8->addWidget(startPulseBtn);

        stopPulseBtn = new QPushButton(groupBox_2);
        stopPulseBtn->setObjectName(QStringLiteral("stopPulseBtn"));
        stopPulseBtn->setMinimumSize(QSize(71, 25));
        stopPulseBtn->setMaximumSize(QSize(71, 25));

        horizontalLayout_8->addWidget(stopPulseBtn);

        getPicBtn = new QPushButton(groupBox_2);
        getPicBtn->setObjectName(QStringLiteral("getPicBtn"));
        getPicBtn->setMinimumSize(QSize(71, 25));
        getPicBtn->setMaximumSize(QSize(71, 25));

        horizontalLayout_8->addWidget(getPicBtn);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(71, 25));
        label_3->setMaximumSize(QSize(71, 25));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        trigComboBox = new QComboBox(groupBox_2);
        trigComboBox->setObjectName(QStringLiteral("trigComboBox"));
        trigComboBox->setMinimumSize(QSize(61, 25));
        trigComboBox->setMaximumSize(QSize(61, 25));

        horizontalLayout_3->addWidget(trigComboBox);


        horizontalLayout_8->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(71, 25));
        label_15->setMaximumSize(QSize(71, 25));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_15);

        gainComboBox = new QComboBox(groupBox_2);
        gainComboBox->setObjectName(QStringLiteral("gainComboBox"));
        gainComboBox->setMinimumSize(QSize(45, 25));
        gainComboBox->setMaximumSize(QSize(45, 25));
        gainComboBox->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_9->addWidget(gainComboBox);


        horizontalLayout_8->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(2, -1, -1, -1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(71, 21));
        label_2->setMaximumSize(QSize(71, 21));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_2);

        modeDetectorComboBox = new QComboBox(groupBox_2);
        modeDetectorComboBox->setObjectName(QStringLiteral("modeDetectorComboBox"));
        modeDetectorComboBox->setMinimumSize(QSize(85, 23));
        modeDetectorComboBox->setMaximumSize(QSize(85, 23));

        horizontalLayout_4->addWidget(modeDetectorComboBox);


        horizontalLayout_11->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(51, 25));
        label_9->setMaximumSize(QSize(51, 25));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_9);

        frameSpinBox = new QDoubleSpinBox(groupBox_2);
        frameSpinBox->setObjectName(QStringLiteral("frameSpinBox"));
        frameSpinBox->setMinimumSize(QSize(60, 25));
        frameSpinBox->setMaximumSize(QSize(60, 25));
        frameSpinBox->setMaximum(15);
        frameSpinBox->setSingleStep(0.1);

        horizontalLayout_2->addWidget(frameSpinBox);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(31, 25));
        label_6->setMaximumSize(QSize(31, 25));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);


        horizontalLayout_11->addLayout(horizontalLayout_2);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(71, 25));
        label_13->setMaximumSize(QSize(71, 25));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_13);

        exposureSpinBox = new QDoubleSpinBox(groupBox_2);
        exposureSpinBox->setObjectName(QStringLiteral("exposureSpinBox"));
        exposureSpinBox->setMinimumSize(QSize(60, 25));
        exposureSpinBox->setMaximumSize(QSize(60, 25));

        horizontalLayout_14->addWidget(exposureSpinBox);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(21, 25));
        label_14->setMaximumSize(QSize(21, 25));
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_14);


        horizontalLayout_11->addLayout(horizontalLayout_14);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMinimumSize(QSize(71, 25));
        label_21->setMaximumSize(QSize(71, 25));
        label_21->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_21);

        rSpeedSpinBox = new QDoubleSpinBox(groupBox_2);
        rSpeedSpinBox->setObjectName(QStringLiteral("rSpeedSpinBox"));
        rSpeedSpinBox->setMinimumSize(QSize(61, 25));
        rSpeedSpinBox->setMaximumSize(QSize(51, 25));

        horizontalLayout_12->addWidget(rSpeedSpinBox);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMinimumSize(QSize(31, 25));
        label_22->setMaximumSize(QSize(31, 25));
        label_22->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_22);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(71, 25));
        label_23->setMaximumSize(QSize(71, 25));
        label_23->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_23);

        rMoveSpinBox = new QDoubleSpinBox(groupBox_2);
        rMoveSpinBox->setObjectName(QStringLiteral("rMoveSpinBox"));
        rMoveSpinBox->setMinimumSize(QSize(61, 25));
        rMoveSpinBox->setMaximumSize(QSize(61, 25));

        horizontalLayout_12->addWidget(rMoveSpinBox);

        label_24 = new QLabel(groupBox_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(21, 25));
        label_24->setMaximumSize(QSize(21, 25));
        label_24->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_24);


        verticalLayout_2->addLayout(horizontalLayout_12);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(CommonDevice);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(1);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(25, 25));
        label_16->setMaximumSize(QSize(25, 25));

        horizontalLayout_7->addWidget(label_16);

        zhouComboBox = new QComboBox(groupBox_3);
        zhouComboBox->setObjectName(QStringLiteral("zhouComboBox"));
        zhouComboBox->setMinimumSize(QSize(45, 25));
        zhouComboBox->setMaximumSize(QSize(45, 25));
        zhouComboBox->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_7->addWidget(zhouComboBox);

        zSpeedSpinBox = new QDoubleSpinBox(groupBox_3);
        zSpeedSpinBox->setObjectName(QStringLiteral("zSpeedSpinBox"));
        zSpeedSpinBox->setMinimumSize(QSize(61, 25));
        zSpeedSpinBox->setMaximumSize(QSize(61, 25));
        zSpeedSpinBox->setMaximum(600);

        horizontalLayout_7->addWidget(zSpeedSpinBox);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(41);
        sizePolicy2.setVerticalStretch(25);
        sizePolicy2.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy2);
        label_11->setMinimumSize(QSize(41, 25));
        label_11->setMaximumSize(QSize(31, 25));

        horizontalLayout_7->addWidget(label_11);

        zMoveSpinBox = new QSpinBox(groupBox_3);
        zMoveSpinBox->setObjectName(QStringLiteral("zMoveSpinBox"));
        zMoveSpinBox->setMinimumSize(QSize(55, 25));
        zMoveSpinBox->setMaximumSize(QSize(55, 25));

        horizontalLayout_7->addWidget(zMoveSpinBox);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMinimumSize(QSize(31, 25));
        label_17->setMaximumSize(QSize(31, 25));

        horizontalLayout_7->addWidget(label_17);

        zNegativeBtn = new QPushButton(groupBox_3);
        zNegativeBtn->setObjectName(QStringLiteral("zNegativeBtn"));
        zNegativeBtn->setMinimumSize(QSize(50, 25));
        zNegativeBtn->setMaximumSize(QSize(50, 25));

        horizontalLayout_7->addWidget(zNegativeBtn);

        zPositiveBtn = new QPushButton(groupBox_3);
        zPositiveBtn->setObjectName(QStringLiteral("zPositiveBtn"));
        zPositiveBtn->setMinimumSize(QSize(50, 25));
        zPositiveBtn->setMaximumSize(QSize(50, 25));

        horizontalLayout_7->addWidget(zPositiveBtn);

        stopBtn = new QPushButton(groupBox_3);
        stopBtn->setObjectName(QStringLiteral("stopBtn"));
        stopBtn->setMinimumSize(QSize(60, 25));
        stopBtn->setMaximumSize(QSize(60, 25));

        horizontalLayout_7->addWidget(stopBtn);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout_3->addWidget(groupBox_3);

        verticalLayout_3->setStretch(0, 2);
        verticalLayout_3->setStretch(1, 3);
        verticalLayout_3->setStretch(2, 1);

        retranslateUi(CommonDevice);

        trigComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CommonDevice);
    } // setupUi

    void retranslateUi(QWidget *CommonDevice)
    {
        CommonDevice->setWindowTitle(QApplication::translate("CommonDevice", "CommonDevice", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("CommonDevice", "TextLabel", Q_NULLPTR));
        openXRayBtn->setText(QApplication::translate("CommonDevice", "ON", Q_NULLPTR));
        closeXRayBtn->setText(QApplication::translate("CommonDevice", "OFF", Q_NULLPTR));
        label_4->setText(QApplication::translate("CommonDevice", "Voltage\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("CommonDevice", "kV", Q_NULLPTR));
        label_5->setText(QApplication::translate("CommonDevice", "Current\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("CommonDevice", "uA", Q_NULLPTR));
        label_8->setText(QApplication::translate("CommonDevice", "Mode\357\274\232", Q_NULLPTR));
        modeComboBox->clear();
        modeComboBox->insertItems(0, QStringList()
         << QApplication::translate("CommonDevice", "large", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "medium", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "small", Q_NULLPTR)
        );
        groupBox_2->setTitle(QString());
        startPulseBtn->setText(QApplication::translate("CommonDevice", "\350\277\236\347\273\255\345\217\226\345\233\276", Q_NULLPTR));
        stopPulseBtn->setText(QApplication::translate("CommonDevice", "\345\201\234\346\255\242\345\217\226\345\233\276", Q_NULLPTR));
        getPicBtn->setText(QApplication::translate("CommonDevice", "\346\250\241\345\274\217\345\217\226\345\233\276", Q_NULLPTR));
        label_3->setText(QApplication::translate("CommonDevice", "\350\247\246\345\217\221\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        trigComboBox->clear();
        trigComboBox->insertItems(0, QStringList()
         << QApplication::translate("CommonDevice", "\345\206\205\350\247\246\345\217\221", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "\345\244\226\350\247\246\345\217\221", Q_NULLPTR)
        );
        label_15->setText(QApplication::translate("CommonDevice", "\345\242\236\347\233\212\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        gainComboBox->clear();
        gainComboBox->insertItems(0, QStringList()
         << QApplication::translate("CommonDevice", "4", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "5", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "6", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "7", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("CommonDevice", "\345\233\276\345\203\217\345\260\272\345\257\270\357\274\232", Q_NULLPTR));
        modeDetectorComboBox->clear();
        modeDetectorComboBox->insertItems(0, QStringList()
         << QApplication::translate("CommonDevice", "704*704", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "1408*1408", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "2816*2816", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("CommonDevice", "\345\270\247  \347\216\207\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("CommonDevice", " \345\270\247/s", Q_NULLPTR));
        label_13->setText(QApplication::translate("CommonDevice", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_14->setText(QApplication::translate("CommonDevice", " ms", Q_NULLPTR));
        label_21->setText(QApplication::translate("CommonDevice", "\350\275\254\345\217\260\351\200\237\345\272\246\357\274\232", Q_NULLPTR));
        label_22->setText(QApplication::translate("CommonDevice", "rad/s", Q_NULLPTR));
        label_23->setText(QApplication::translate("CommonDevice", "\350\275\254\345\217\260\347\247\273\345\212\250\357\274\232", Q_NULLPTR));
        label_24->setText(QApplication::translate("CommonDevice", "rad", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_16->setText(QApplication::translate("CommonDevice", "\350\275\264\357\274\232", Q_NULLPTR));
        zhouComboBox->clear();
        zhouComboBox->insertItems(0, QStringList()
         << QApplication::translate("CommonDevice", "X", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "Y", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "Z", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "R", Q_NULLPTR)
         << QApplication::translate("CommonDevice", "T", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("CommonDevice", "mm/s", Q_NULLPTR));
        label_17->setText(QApplication::translate("CommonDevice", "mm", Q_NULLPTR));
        zNegativeBtn->setText(QApplication::translate("CommonDevice", "<<", Q_NULLPTR));
        zPositiveBtn->setText(QApplication::translate("CommonDevice", ">>", Q_NULLPTR));
        stopBtn->setText(QApplication::translate("CommonDevice", "\345\201\234\346\255\242", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommonDevice: public Ui_CommonDevice {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMONDEVICE_H
