/********************************************************************************
** Form generated from reading UI file 'calibration_test1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_TEST1_H
#define UI_CALIBRATION_TEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calibration_test1Class
{
public:
    QPushButton *btn_threshold;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *ulabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *vlabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *RFIlabel;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QLabel *RFDlabel;
    QLabel *label;
    QSlider *threshSlider;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *threshValue;

    void setupUi(QWidget *calibration_test1Class)
    {
        if (calibration_test1Class->objectName().isEmpty())
            calibration_test1Class->setObjectName(QStringLiteral("calibration_test1Class"));
        calibration_test1Class->resize(1123, 892);
        btn_threshold = new QPushButton(calibration_test1Class);
        btn_threshold->setObjectName(QStringLiteral("btn_threshold"));
        btn_threshold->setEnabled(true);
        btn_threshold->setGeometry(QRect(900, 440, 91, 23));
        btn_threshold->setCheckable(false);
        btn_threshold->setChecked(false);
        groupBox = new QGroupBox(calibration_test1Class);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(850, 240, 201, 191));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        ulabel = new QLabel(groupBox);
        ulabel->setObjectName(QStringLiteral("ulabel"));

        horizontalLayout->addWidget(ulabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        vlabel = new QLabel(groupBox);
        vlabel->setObjectName(QStringLiteral("vlabel"));

        horizontalLayout_2->addWidget(vlabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        RFIlabel = new QLabel(groupBox);
        RFIlabel->setObjectName(QStringLiteral("RFIlabel"));

        horizontalLayout_3->addWidget(RFIlabel);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_4->addWidget(label_7);

        RFDlabel = new QLabel(groupBox);
        RFDlabel->setObjectName(QStringLiteral("RFDlabel"));

        horizontalLayout_4->addWidget(RFDlabel);


        verticalLayout->addLayout(horizontalLayout_4);

        label = new QLabel(calibration_test1Class);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 845, 845));
        threshSlider = new QSlider(calibration_test1Class);
        threshSlider->setObjectName(QStringLiteral("threshSlider"));
        threshSlider->setGeometry(QRect(860, 130, 231, 22));
        threshSlider->setMaximum(65535);
        threshSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(calibration_test1Class);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(870, 100, 71, 16));
        label_4 = new QLabel(calibration_test1Class);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(870, 160, 71, 16));
        label_8 = new QLabel(calibration_test1Class);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(1070, 160, 31, 16));
        threshValue = new QLabel(calibration_test1Class);
        threshValue->setObjectName(QStringLiteral("threshValue"));
        threshValue->setGeometry(QRect(940, 100, 54, 12));

        retranslateUi(calibration_test1Class);

        QMetaObject::connectSlotsByName(calibration_test1Class);
    } // setupUi

    void retranslateUi(QWidget *calibration_test1Class)
    {
        calibration_test1Class->setWindowTitle(QApplication::translate("calibration_test1Class", "calibration_test1", Q_NULLPTR));
        btn_threshold->setText(QApplication::translate("calibration_test1Class", "\347\241\256\345\256\232\346\211\200\351\200\211\350\214\203\345\233\264", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("calibration_test1Class", "\346\240\241\345\207\206\345\217\202\346\225\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("calibration_test1Class", "u", Q_NULLPTR));
        ulabel->setText(QApplication::translate("calibration_test1Class", "0.0", Q_NULLPTR));
        label_6->setText(QApplication::translate("calibration_test1Class", "v", Q_NULLPTR));
        vlabel->setText(QApplication::translate("calibration_test1Class", "0.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("calibration_test1Class", "RFI", Q_NULLPTR));
        RFIlabel->setText(QApplication::translate("calibration_test1Class", "0.0", Q_NULLPTR));
        label_7->setText(QApplication::translate("calibration_test1Class", "RFD", Q_NULLPTR));
        RFDlabel->setText(QApplication::translate("calibration_test1Class", "0.0", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("calibration_test1Class", "\350\260\203\346\225\264\351\230\210\345\200\274", Q_NULLPTR));
        label_4->setText(QApplication::translate("calibration_test1Class", "0", Q_NULLPTR));
        label_8->setText(QApplication::translate("calibration_test1Class", "65535", Q_NULLPTR));
        threshValue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class calibration_test1Class: public Ui_calibration_test1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_TEST1_H
