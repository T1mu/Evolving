/********************************************************************************
** Form generated from reading UI file 'histgraychart.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTGRAYCHART_H
#define UI_HISTGRAYCHART_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_histGrayChart
{
public:

    void setupUi(QWidget *histGrayChart)
    {
        if (histGrayChart->objectName().isEmpty())
            histGrayChart->setObjectName(QStringLiteral("histGrayChart"));
        histGrayChart->resize(752, 450);

        retranslateUi(histGrayChart);

        QMetaObject::connectSlotsByName(histGrayChart);
    } // setupUi

    void retranslateUi(QWidget *histGrayChart)
    {
        histGrayChart->setWindowTitle(QApplication::translate("histGrayChart", "histGrayChart", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class histGrayChart: public Ui_histGrayChart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTGRAYCHART_H
