/********************************************************************************
** Form generated from reading UI file 'GainAdjustBar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAINADJUSTBAR_H
#define UI_GAINADJUSTBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GainAdjustBar
{
public:
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *GainAdjustBar)
    {
        if (GainAdjustBar->objectName().isEmpty())
            GainAdjustBar->setObjectName(QStringLiteral("GainAdjustBar"));
        GainAdjustBar->resize(400, 166);
        label = new QLabel(GainAdjustBar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 181, 31));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(GainAdjustBar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(90, 90, 251, 23));
        progressBar->setMaximum(16);
        progressBar->setValue(-1);

        retranslateUi(GainAdjustBar);

        QMetaObject::connectSlotsByName(GainAdjustBar);
    } // setupUi

    void retranslateUi(QWidget *GainAdjustBar)
    {
        GainAdjustBar->setWindowTitle(QApplication::translate("GainAdjustBar", "\345\242\236\347\233\212\346\240\241\345\207\206", Q_NULLPTR));
        label->setText(QApplication::translate("GainAdjustBar", "\346\240\241\345\207\206\344\270\255\357\274\214\350\257\267\347\250\215\347\255\211\343\200\202\343\200\202\343\200\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GainAdjustBar: public Ui_GainAdjustBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAINADJUSTBAR_H
