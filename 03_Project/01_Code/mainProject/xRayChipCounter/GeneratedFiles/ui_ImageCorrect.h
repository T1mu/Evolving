/********************************************************************************
** Form generated from reading UI file 'ImageCorrect.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGECORRECT_H
#define UI_IMAGECORRECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageCorrect
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLabel *ulabel_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLabel *vlabel_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLabel *RFIlabel_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_10;
    QLabel *RFDlabel_2;
    QPushButton *startBtn;
    QPushButton *collectBtn;

    void setupUi(QWidget *ImageCorrect)
    {
        if (ImageCorrect->objectName().isEmpty())
            ImageCorrect->setObjectName(QStringLiteral("ImageCorrect"));
        ImageCorrect->resize(1110, 854);
        label = new QLabel(ImageCorrect);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 845, 845));
        groupBox = new QGroupBox(ImageCorrect);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(880, 150, 221, 321));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        ulabel_2 = new QLabel(groupBox);
        ulabel_2->setObjectName(QStringLiteral("ulabel_2"));

        horizontalLayout_5->addWidget(ulabel_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_6->addWidget(label_8);

        vlabel_2 = new QLabel(groupBox);
        vlabel_2->setObjectName(QStringLiteral("vlabel_2"));

        horizontalLayout_6->addWidget(vlabel_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_7->addWidget(label_9);

        RFIlabel_2 = new QLabel(groupBox);
        RFIlabel_2->setObjectName(QStringLiteral("RFIlabel_2"));

        horizontalLayout_7->addWidget(RFIlabel_2);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_8->addWidget(label_10);

        RFDlabel_2 = new QLabel(groupBox);
        RFDlabel_2->setObjectName(QStringLiteral("RFDlabel_2"));

        horizontalLayout_8->addWidget(RFDlabel_2);


        verticalLayout_2->addLayout(horizontalLayout_8);

        startBtn = new QPushButton(ImageCorrect);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setEnabled(true);
        startBtn->setGeometry(QRect(960, 600, 91, 23));
        startBtn->setCheckable(false);
        startBtn->setChecked(false);
        collectBtn = new QPushButton(ImageCorrect);
        collectBtn->setObjectName(QStringLiteral("collectBtn"));
        collectBtn->setGeometry(QRect(960, 570, 91, 23));

        retranslateUi(ImageCorrect);

        QMetaObject::connectSlotsByName(ImageCorrect);
    } // setupUi

    void retranslateUi(QWidget *ImageCorrect)
    {
        ImageCorrect->setWindowTitle(QApplication::translate("ImageCorrect", "ImageCorrect", Q_NULLPTR));
        label->setText(QString());
        groupBox->setTitle(QApplication::translate("ImageCorrect", "\346\240\241\345\207\206\345\217\202\346\225\260", Q_NULLPTR));
        label_3->setText(QApplication::translate("ImageCorrect", "u", Q_NULLPTR));
        ulabel_2->setText(QApplication::translate("ImageCorrect", "0.0", Q_NULLPTR));
        label_8->setText(QApplication::translate("ImageCorrect", "v", Q_NULLPTR));
        vlabel_2->setText(QApplication::translate("ImageCorrect", "0.0", Q_NULLPTR));
        label_9->setText(QApplication::translate("ImageCorrect", "RFI", Q_NULLPTR));
        RFIlabel_2->setText(QApplication::translate("ImageCorrect", "0.0", Q_NULLPTR));
        label_10->setText(QApplication::translate("ImageCorrect", "RFD", Q_NULLPTR));
        RFDlabel_2->setText(QApplication::translate("ImageCorrect", "0.0", Q_NULLPTR));
        startBtn->setText(QApplication::translate("ImageCorrect", "\345\274\200\345\247\213\346\240\241\346\255\243", Q_NULLPTR));
        collectBtn->setText(QApplication::translate("ImageCorrect", "\345\274\200\345\247\213\351\207\207\351\233\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImageCorrect: public Ui_ImageCorrect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGECORRECT_H
