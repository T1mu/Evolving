/********************************************************************************
** Form generated from reading UI file 'dealimage.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALIMAGE_H
#define UI_DEALIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dealimage
{
public:
    QGroupBox *groupBox;
    QGridLayout *gridLayout_13;
    QLabel *label;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_14;
    QLabel *label_23;
    QLabel *ulabel;
    QLabel *label_24;
    QLabel *vlabel;
    QLabel *label_25;
    QLabel *RFIlabel;
    QLabel *label_26;
    QLabel *RFDlabel;

    void setupUi(QWidget *dealimage)
    {
        if (dealimage->objectName().isEmpty())
            dealimage->setObjectName(QStringLiteral("dealimage"));
        dealimage->resize(858, 529);
        groupBox = new QGroupBox(dealimage);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 531, 461));
        gridLayout_13 = new QGridLayout(groupBox);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_13->addWidget(label, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(dealimage);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(540, 10, 311, 171));
        gridLayout_14 = new QGridLayout(groupBox_4);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_14->addWidget(label_23, 0, 0, 1, 1);

        ulabel = new QLabel(groupBox_4);
        ulabel->setObjectName(QStringLiteral("ulabel"));
        ulabel->setScaledContents(true);

        gridLayout_14->addWidget(ulabel, 0, 1, 1, 1);

        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_14->addWidget(label_24, 1, 0, 1, 1);

        vlabel = new QLabel(groupBox_4);
        vlabel->setObjectName(QStringLiteral("vlabel"));
        vlabel->setScaledContents(true);

        gridLayout_14->addWidget(vlabel, 1, 1, 1, 1);

        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_14->addWidget(label_25, 2, 0, 1, 1);

        RFIlabel = new QLabel(groupBox_4);
        RFIlabel->setObjectName(QStringLiteral("RFIlabel"));
        RFIlabel->setScaledContents(true);

        gridLayout_14->addWidget(RFIlabel, 2, 1, 1, 1);

        label_26 = new QLabel(groupBox_4);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_14->addWidget(label_26, 3, 0, 1, 1);

        RFDlabel = new QLabel(groupBox_4);
        RFDlabel->setObjectName(QStringLiteral("RFDlabel"));
        RFDlabel->setScaledContents(true);

        gridLayout_14->addWidget(RFDlabel, 3, 1, 1, 1);


        retranslateUi(dealimage);

        QMetaObject::connectSlotsByName(dealimage);
    } // setupUi

    void retranslateUi(QWidget *dealimage)
    {
        dealimage->setWindowTitle(QApplication::translate("dealimage", "dealimage", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QString());
        groupBox_4->setTitle(QApplication::translate("dealimage", "\346\240\241\345\207\206\345\217\202\346\225\260", Q_NULLPTR));
        label_23->setText(QApplication::translate("dealimage", "        u:", Q_NULLPTR));
        ulabel->setText(QApplication::translate("dealimage", "0.0", Q_NULLPTR));
        label_24->setText(QApplication::translate("dealimage", "        v:", Q_NULLPTR));
        vlabel->setText(QApplication::translate("dealimage", "0.0", Q_NULLPTR));
        label_25->setText(QApplication::translate("dealimage", "       RFI:", Q_NULLPTR));
        RFIlabel->setText(QApplication::translate("dealimage", "0.0", Q_NULLPTR));
        label_26->setText(QApplication::translate("dealimage", "       RFD:", Q_NULLPTR));
        RFDlabel->setText(QApplication::translate("dealimage", "0.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dealimage: public Ui_dealimage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALIMAGE_H
