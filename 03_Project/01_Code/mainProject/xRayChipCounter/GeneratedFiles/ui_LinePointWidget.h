/********************************************************************************
** Form generated from reading UI file 'LinePointWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINEPOINTWIDGET_H
#define UI_LINEPOINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinePointWidget
{
public:

    void setupUi(QWidget *LinePointWidget)
    {
        if (LinePointWidget->objectName().isEmpty())
            LinePointWidget->setObjectName(QStringLiteral("LinePointWidget"));
        LinePointWidget->resize(400, 300);

        retranslateUi(LinePointWidget);

        QMetaObject::connectSlotsByName(LinePointWidget);
    } // setupUi

    void retranslateUi(QWidget *LinePointWidget)
    {
        LinePointWidget->setWindowTitle(QApplication::translate("LinePointWidget", "LinePointWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LinePointWidget: public Ui_LinePointWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINEPOINTWIDGET_H
