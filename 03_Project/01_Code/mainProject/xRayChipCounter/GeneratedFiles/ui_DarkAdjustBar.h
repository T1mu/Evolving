/********************************************************************************
** Form generated from reading UI file 'DarkAdjustBar.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DARKADJUSTBAR_H
#define UI_DARKADJUSTBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DarkAdjustBar
{
public:
    QLabel *label;
    QProgressBar *progressBar;

    void setupUi(QWidget *DarkAdjustBar)
    {
        if (DarkAdjustBar->objectName().isEmpty())
            DarkAdjustBar->setObjectName(QStringLiteral("DarkAdjustBar"));
        DarkAdjustBar->resize(400, 172);
        label = new QLabel(DarkAdjustBar);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 40, 181, 31));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(DarkAdjustBar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(90, 90, 251, 23));
        progressBar->setMaximum(16);
        progressBar->setValue(-1);

        retranslateUi(DarkAdjustBar);

        QMetaObject::connectSlotsByName(DarkAdjustBar);
    } // setupUi

    void retranslateUi(QWidget *DarkAdjustBar)
    {
        DarkAdjustBar->setWindowTitle(QApplication::translate("DarkAdjustBar", "\346\232\227\345\234\272\346\240\241\345\207\206", Q_NULLPTR));
        label->setText(QApplication::translate("DarkAdjustBar", "\346\240\241\345\207\206\344\270\255\357\274\214\350\257\267\347\250\215\347\255\211\343\200\202\343\200\202\343\200\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DarkAdjustBar: public Ui_DarkAdjustBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DARKADJUSTBAR_H
