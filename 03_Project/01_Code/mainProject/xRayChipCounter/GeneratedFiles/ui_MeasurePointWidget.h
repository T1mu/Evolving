/********************************************************************************
** Form generated from reading UI file 'MeasurePointWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEASUREPOINTWIDGET_H
#define UI_MEASUREPOINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeasurePointWidget
{
public:

    void setupUi(QWidget *MeasurePointWidget)
    {
        if (MeasurePointWidget->objectName().isEmpty())
            MeasurePointWidget->setObjectName(QStringLiteral("MeasurePointWidget"));
        MeasurePointWidget->resize(400, 300);

        retranslateUi(MeasurePointWidget);

        QMetaObject::connectSlotsByName(MeasurePointWidget);
    } // setupUi

    void retranslateUi(QWidget *MeasurePointWidget)
    {
        MeasurePointWidget->setWindowTitle(QApplication::translate("MeasurePointWidget", "MeasurePointWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MeasurePointWidget: public Ui_MeasurePointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASUREPOINTWIDGET_H
