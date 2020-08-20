/********************************************************************************
** Form generated from reading UI file 'ParaMemter.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARAMEMTER_H
#define UI_PARAMEMTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParaMemter
{
public:
    QLabel *label;
    QLabel *ulabel;
    QLabel *label_3;
    QLabel *vlabel;
    QLabel *label_5;
    QLabel *RFIlabel;
    QLabel *label_7;
    QLabel *RFDlabel;

    void setupUi(QWidget *ParaMemter)
    {
        if (ParaMemter->objectName().isEmpty())
            ParaMemter->setObjectName(QStringLiteral("ParaMemter"));
        ParaMemter->resize(435, 347);
        label = new QLabel(ParaMemter);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(78, 29, 54, 16));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setScaledContents(false);
        ulabel = new QLabel(ParaMemter);
        ulabel->setObjectName(QStringLiteral("ulabel"));
        ulabel->setGeometry(QRect(290, 29, 60, 16));
        ulabel->setFont(font);
        label_3 = new QLabel(ParaMemter);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(78, 113, 54, 16));
        label_3->setFont(font);
        vlabel = new QLabel(ParaMemter);
        vlabel->setObjectName(QStringLiteral("vlabel"));
        vlabel->setGeometry(QRect(290, 113, 60, 16));
        vlabel->setFont(font);
        label_5 = new QLabel(ParaMemter);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(78, 197, 54, 16));
        label_5->setFont(font);
        RFIlabel = new QLabel(ParaMemter);
        RFIlabel->setObjectName(QStringLiteral("RFIlabel"));
        RFIlabel->setGeometry(QRect(290, 197, 60, 16));
        RFIlabel->setFont(font);
        label_7 = new QLabel(ParaMemter);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(78, 280, 54, 16));
        label_7->setFont(font);
        RFDlabel = new QLabel(ParaMemter);
        RFDlabel->setObjectName(QStringLiteral("RFDlabel"));
        RFDlabel->setGeometry(QRect(290, 280, 60, 16));
        RFDlabel->setFont(font);

        retranslateUi(ParaMemter);

        QMetaObject::connectSlotsByName(ParaMemter);
    } // setupUi

    void retranslateUi(QWidget *ParaMemter)
    {
        ParaMemter->setWindowTitle(QApplication::translate("ParaMemter", "ParaMemter", Q_NULLPTR));
        label->setText(QApplication::translate("ParaMemter", "   u:", Q_NULLPTR));
        ulabel->setText(QApplication::translate("ParaMemter", "0.0", Q_NULLPTR));
        label_3->setText(QApplication::translate("ParaMemter", "   v:", Q_NULLPTR));
        vlabel->setText(QApplication::translate("ParaMemter", "0.0", Q_NULLPTR));
        label_5->setText(QApplication::translate("ParaMemter", "  RFI:", Q_NULLPTR));
        RFIlabel->setText(QApplication::translate("ParaMemter", "0.0", Q_NULLPTR));
        label_7->setText(QApplication::translate("ParaMemter", "  RFD:", Q_NULLPTR));
        RFDlabel->setText(QApplication::translate("ParaMemter", "0.0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ParaMemter: public Ui_ParaMemter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARAMEMTER_H
