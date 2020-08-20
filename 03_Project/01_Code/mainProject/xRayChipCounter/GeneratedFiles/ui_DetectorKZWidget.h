/********************************************************************************
** Form generated from reading UI file 'DetectorKZWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETECTORKZWIDGET_H
#define UI_DETECTORKZWIDGET_H

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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DetectorKZWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *connectDetectorBtn;
    QPushButton *setModeBtn;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *trigComboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *gainComboBox;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *modeComboBox;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QDoubleSpinBox *frameSpinBox;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QDoubleSpinBox *exposureSpinBox;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QSpinBox *picNumSpinBox;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_12;
    QDoubleSpinBox *rMoveSpinBox;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_10;
    QDoubleSpinBox *rSpeedSpinBox;
    QLabel *label_15;
    QPushButton *darkAdjustBtn;
    QPushButton *gainAdjustBtn;
    QHBoxLayout *horizontalLayout_8;
    QComboBox *getPicModeComboBox;
    QPushButton *getPicBtn;
    QPushButton *startPulseBtn;
    QPushButton *stopPulseBtn;
    QLabel *label_11;
    QLabel *picNumLabel;
    QLabel *label_9;

    void setupUi(QWidget *DetectorKZWidget)
    {
        if (DetectorKZWidget->objectName().isEmpty())
            DetectorKZWidget->setObjectName(QStringLiteral("DetectorKZWidget"));
        DetectorKZWidget->resize(532, 237);
        verticalLayout = new QVBoxLayout(DetectorKZWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        connectDetectorBtn = new QPushButton(DetectorKZWidget);
        connectDetectorBtn->setObjectName(QStringLiteral("connectDetectorBtn"));
        connectDetectorBtn->setMinimumSize(QSize(71, 35));
        connectDetectorBtn->setMaximumSize(QSize(71, 35));

        horizontalLayout_5->addWidget(connectDetectorBtn);

        setModeBtn = new QPushButton(DetectorKZWidget);
        setModeBtn->setObjectName(QStringLiteral("setModeBtn"));
        setModeBtn->setMinimumSize(QSize(71, 35));
        setModeBtn->setMaximumSize(QSize(71, 35));

        horizontalLayout_5->addWidget(setModeBtn);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(DetectorKZWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(71, 25));
        label_3->setMaximumSize(QSize(71, 25));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        trigComboBox = new QComboBox(DetectorKZWidget);
        trigComboBox->setObjectName(QStringLiteral("trigComboBox"));
        trigComboBox->setMinimumSize(QSize(61, 35));
        trigComboBox->setMaximumSize(QSize(61, 35));

        horizontalLayout_3->addWidget(trigComboBox);


        horizontalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(DetectorKZWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(71, 25));
        label_2->setMaximumSize(QSize(71, 25));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        gainComboBox = new QComboBox(DetectorKZWidget);
        gainComboBox->setObjectName(QStringLiteral("gainComboBox"));
        gainComboBox->setMinimumSize(QSize(45, 35));
        gainComboBox->setMaximumSize(QSize(45, 35));
        gainComboBox->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(gainComboBox);


        horizontalLayout_5->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(DetectorKZWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(71, 21));
        label->setMaximumSize(QSize(71, 21));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label);

        modeComboBox = new QComboBox(DetectorKZWidget);
        modeComboBox->setObjectName(QStringLiteral("modeComboBox"));
        modeComboBox->setMinimumSize(QSize(85, 35));
        modeComboBox->setMaximumSize(QSize(85, 35));

        horizontalLayout_4->addWidget(modeComboBox);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(DetectorKZWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(51, 25));
        label_8->setMaximumSize(QSize(51, 25));
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_8);

        frameSpinBox = new QDoubleSpinBox(DetectorKZWidget);
        frameSpinBox->setObjectName(QStringLiteral("frameSpinBox"));
        frameSpinBox->setMinimumSize(QSize(60, 35));
        frameSpinBox->setMaximumSize(QSize(60, 35));
        frameSpinBox->setMaximum(15);
        frameSpinBox->setSingleStep(0.1);

        horizontalLayout->addWidget(frameSpinBox);

        label_6 = new QLabel(DetectorKZWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(31, 25));
        label_6->setMaximumSize(QSize(31, 25));
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_6);


        horizontalLayout_6->addLayout(horizontalLayout);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_4 = new QLabel(DetectorKZWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(71, 25));
        label_4->setMaximumSize(QSize(71, 25));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_4);

        exposureSpinBox = new QDoubleSpinBox(DetectorKZWidget);
        exposureSpinBox->setObjectName(QStringLiteral("exposureSpinBox"));
        exposureSpinBox->setMinimumSize(QSize(60, 35));
        exposureSpinBox->setMaximumSize(QSize(60, 35));

        horizontalLayout_10->addWidget(exposureSpinBox);

        label_7 = new QLabel(DetectorKZWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(21, 25));
        label_7->setMaximumSize(QSize(21, 25));
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_7);


        horizontalLayout_6->addLayout(horizontalLayout_10);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        picNumSpinBox = new QSpinBox(DetectorKZWidget);
        picNumSpinBox->setObjectName(QStringLiteral("picNumSpinBox"));
        picNumSpinBox->setMinimumSize(QSize(51, 35));
        picNumSpinBox->setMaximumSize(QSize(51, 35));
        picNumSpinBox->setMaximum(1000);
        picNumSpinBox->setValue(50);

        horizontalLayout_11->addWidget(picNumSpinBox);

        label_5 = new QLabel(DetectorKZWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(15, 25));
        label_5->setMaximumSize(QSize(15, 25));
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label_5);


        horizontalLayout_7->addLayout(horizontalLayout_11);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_12 = new QLabel(DetectorKZWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMinimumSize(QSize(40, 25));
        label_12->setMaximumSize(QSize(40, 25));
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_12);

        rMoveSpinBox = new QDoubleSpinBox(DetectorKZWidget);
        rMoveSpinBox->setObjectName(QStringLiteral("rMoveSpinBox"));
        rMoveSpinBox->setMinimumSize(QSize(60, 35));
        rMoveSpinBox->setMaximumSize(QSize(60, 35));
        rMoveSpinBox->setMaximum(360);

        horizontalLayout_14->addWidget(rMoveSpinBox);

        label_13 = new QLabel(DetectorKZWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMinimumSize(QSize(25, 25));
        label_13->setMaximumSize(QSize(25, 25));
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_14->addWidget(label_13);


        horizontalLayout_7->addLayout(horizontalLayout_14);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_10 = new QLabel(DetectorKZWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(40, 25));
        label_10->setMaximumSize(QSize(40, 25));
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_10);

        rSpeedSpinBox = new QDoubleSpinBox(DetectorKZWidget);
        rSpeedSpinBox->setObjectName(QStringLiteral("rSpeedSpinBox"));
        rSpeedSpinBox->setMinimumSize(QSize(60, 35));
        rSpeedSpinBox->setMaximumSize(QSize(60, 35));
        rSpeedSpinBox->setMaximum(1000);

        horizontalLayout_12->addWidget(rSpeedSpinBox);

        label_15 = new QLabel(DetectorKZWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(35, 25));
        label_15->setMaximumSize(QSize(35, 25));
        label_15->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_15);


        horizontalLayout_7->addLayout(horizontalLayout_12);

        darkAdjustBtn = new QPushButton(DetectorKZWidget);
        darkAdjustBtn->setObjectName(QStringLiteral("darkAdjustBtn"));
        darkAdjustBtn->setMinimumSize(QSize(60, 35));
        darkAdjustBtn->setMaximumSize(QSize(60, 35));

        horizontalLayout_7->addWidget(darkAdjustBtn);

        gainAdjustBtn = new QPushButton(DetectorKZWidget);
        gainAdjustBtn->setObjectName(QStringLiteral("gainAdjustBtn"));
        gainAdjustBtn->setMinimumSize(QSize(60, 35));
        gainAdjustBtn->setMaximumSize(QSize(60, 35));

        horizontalLayout_7->addWidget(gainAdjustBtn);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        getPicModeComboBox = new QComboBox(DetectorKZWidget);
        getPicModeComboBox->setObjectName(QStringLiteral("getPicModeComboBox"));
        getPicModeComboBox->setMinimumSize(QSize(71, 35));
        getPicModeComboBox->setMaximumSize(QSize(71, 35));

        horizontalLayout_8->addWidget(getPicModeComboBox);

        getPicBtn = new QPushButton(DetectorKZWidget);
        getPicBtn->setObjectName(QStringLiteral("getPicBtn"));
        getPicBtn->setMinimumSize(QSize(71, 35));
        getPicBtn->setMaximumSize(QSize(71, 35));

        horizontalLayout_8->addWidget(getPicBtn);

        startPulseBtn = new QPushButton(DetectorKZWidget);
        startPulseBtn->setObjectName(QStringLiteral("startPulseBtn"));
        startPulseBtn->setMinimumSize(QSize(71, 35));
        startPulseBtn->setMaximumSize(QSize(71, 35));

        horizontalLayout_8->addWidget(startPulseBtn);

        stopPulseBtn = new QPushButton(DetectorKZWidget);
        stopPulseBtn->setObjectName(QStringLiteral("stopPulseBtn"));
        stopPulseBtn->setMinimumSize(QSize(71, 35));
        stopPulseBtn->setMaximumSize(QSize(71, 35));

        horizontalLayout_8->addWidget(stopPulseBtn);

        label_11 = new QLabel(DetectorKZWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMinimumSize(QSize(71, 25));
        label_11->setMaximumSize(QSize(71, 25));
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_11);

        picNumLabel = new QLabel(DetectorKZWidget);
        picNumLabel->setObjectName(QStringLiteral("picNumLabel"));
        picNumLabel->setMinimumSize(QSize(25, 25));
        picNumLabel->setMaximumSize(QSize(25, 25));
        picNumLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(picNumLabel);

        label_9 = new QLabel(DetectorKZWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(25, 25));
        label_9->setMaximumSize(QSize(25, 25));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_9);


        verticalLayout_2->addLayout(horizontalLayout_8);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);
        verticalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(verticalLayout_2);


        retranslateUi(DetectorKZWidget);

        trigComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DetectorKZWidget);
    } // setupUi

    void retranslateUi(QWidget *DetectorKZWidget)
    {
        DetectorKZWidget->setWindowTitle(QApplication::translate("DetectorKZWidget", "DetectorKZWidget", Q_NULLPTR));
        connectDetectorBtn->setText(QApplication::translate("DetectorKZWidget", "\350\277\236\346\216\245\346\216\242\346\265\213\345\231\250", Q_NULLPTR));
        setModeBtn->setText(QApplication::translate("DetectorKZWidget", "\350\256\276\347\275\256\345\217\202\346\225\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("DetectorKZWidget", "\350\247\246\345\217\221\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        trigComboBox->clear();
        trigComboBox->insertItems(0, QStringList()
         << QApplication::translate("DetectorKZWidget", "\345\206\205\350\247\246\345\217\221", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "\345\244\226\350\247\246\345\217\221", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("DetectorKZWidget", "\345\242\236\347\233\212\347\255\211\347\272\247\357\274\232", Q_NULLPTR));
        gainComboBox->clear();
        gainComboBox->insertItems(0, QStringList()
         << QApplication::translate("DetectorKZWidget", "4", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "5", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "6", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "7", Q_NULLPTR)
        );
        label->setText(QApplication::translate("DetectorKZWidget", "\345\233\276\345\203\217\345\260\272\345\257\270\357\274\232", Q_NULLPTR));
        modeComboBox->clear();
        modeComboBox->insertItems(0, QStringList()
         << QApplication::translate("DetectorKZWidget", "704*704", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "1408*1408", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "2816*2816", Q_NULLPTR)
        );
        label_8->setText(QApplication::translate("DetectorKZWidget", "\345\270\247  \347\216\207\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("DetectorKZWidget", " \345\270\247/s", Q_NULLPTR));
        label_4->setText(QApplication::translate("DetectorKZWidget", "\346\233\235\345\205\211\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("DetectorKZWidget", " ms", Q_NULLPTR));
        label_5->setText(QApplication::translate("DetectorKZWidget", " \345\270\247", Q_NULLPTR));
        label_12->setText(QApplication::translate("DetectorKZWidget", "\350\275\254\345\212\250\357\274\232", Q_NULLPTR));
        label_13->setText(QApplication::translate("DetectorKZWidget", "rad", Q_NULLPTR));
        label_10->setText(QApplication::translate("DetectorKZWidget", "\350\275\254\351\200\237\357\274\232", Q_NULLPTR));
        label_15->setText(QApplication::translate("DetectorKZWidget", " rad/s", Q_NULLPTR));
        darkAdjustBtn->setText(QApplication::translate("DetectorKZWidget", "\346\232\227\345\234\272\346\240\241\345\207\206", Q_NULLPTR));
        gainAdjustBtn->setText(QApplication::translate("DetectorKZWidget", "\345\242\236\347\233\212\346\240\241\345\207\206", Q_NULLPTR));
        getPicModeComboBox->clear();
        getPicModeComboBox->insertItems(0, QStringList()
         << QApplication::translate("DetectorKZWidget", "\347\251\272\346\260\224\346\233\235\345\205\211", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "\345\207\240\344\275\225\346\240\241\346\255\243", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "\350\277\236\347\273\255\351\207\207\351\233\206", Q_NULLPTR)
         << QApplication::translate("DetectorKZWidget", "\346\255\245\350\277\233\351\207\207\351\233\206", Q_NULLPTR)
        );
        getPicBtn->setText(QApplication::translate("DetectorKZWidget", "\346\250\241\345\274\217\345\217\226\345\233\276", Q_NULLPTR));
        startPulseBtn->setText(QApplication::translate("DetectorKZWidget", "\350\277\236\347\273\255\345\217\226\345\233\276", Q_NULLPTR));
        stopPulseBtn->setText(QApplication::translate("DetectorKZWidget", "\345\201\234\346\255\242\345\217\226\345\233\276", Q_NULLPTR));
        label_11->setText(QApplication::translate("DetectorKZWidget", "\345\267\262 \351\207\207 \345\233\276\357\274\232", Q_NULLPTR));
        picNumLabel->setText(QApplication::translate("DetectorKZWidget", "0", Q_NULLPTR));
        label_9->setText(QApplication::translate("DetectorKZWidget", " \345\270\247", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DetectorKZWidget: public Ui_DetectorKZWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETECTORKZWIDGET_H
