/********************************************************************************
** Form generated from reading UI file 'calibration.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBRATION_H
#define UI_CALIBRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_calibration
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *ulabel_3;
    QLabel *vlabel_3;
    QLabel *RFIlabel_3;
    QLabel *RFDlabel_3;

    void setupUi(QWidget *calibration)
    {
        if (calibration->objectName().isEmpty())
            calibration->setObjectName(QStringLiteral("calibration"));
        calibration->resize(1224, 921);
        pushButton = new QPushButton(calibration);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1110, 490, 75, 23));
        label = new QLabel(calibration);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 845, 845));
        groupBox = new QGroupBox(calibration);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1100, 100, 111, 291));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ulabel_3 = new QLabel(groupBox);
        ulabel_3->setObjectName(QStringLiteral("ulabel_3"));

        verticalLayout_3->addWidget(ulabel_3);

        vlabel_3 = new QLabel(groupBox);
        vlabel_3->setObjectName(QStringLiteral("vlabel_3"));

        verticalLayout_3->addWidget(vlabel_3);

        RFIlabel_3 = new QLabel(groupBox);
        RFIlabel_3->setObjectName(QStringLiteral("RFIlabel_3"));

        verticalLayout_3->addWidget(RFIlabel_3);

        RFDlabel_3 = new QLabel(groupBox);
        RFDlabel_3->setObjectName(QStringLiteral("RFDlabel_3"));

        verticalLayout_3->addWidget(RFDlabel_3);


        retranslateUi(calibration);

        QMetaObject::connectSlotsByName(calibration);
    } // setupUi

    void retranslateUi(QWidget *calibration)
    {
        calibration->setWindowTitle(QApplication::translate("calibration", "calibration", Q_NULLPTR));
        pushButton->setText(QApplication::translate("calibration", "PushButton", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("calibration", "u v RFI RFD", Q_NULLPTR));
        ulabel_3->setText(QApplication::translate("calibration", "0.0", Q_NULLPTR));
        vlabel_3->setText(QApplication::translate("calibration", "0.0", Q_NULLPTR));
        RFIlabel_3->setText(QApplication::translate("calibration", "0.0", Q_NULLPTR));
        RFDlabel_3->setText(QApplication::translate("calibration", "0.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class calibration: public Ui_calibration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBRATION_H
