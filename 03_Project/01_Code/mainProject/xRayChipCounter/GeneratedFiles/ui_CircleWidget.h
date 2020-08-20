/********************************************************************************
** Form generated from reading UI file 'CircleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCLEWIDGET_H
#define UI_CIRCLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CircleWidget
{
public:

    void setupUi(QWidget *CircleWidget)
    {
        if (CircleWidget->objectName().isEmpty())
            CircleWidget->setObjectName(QStringLiteral("CircleWidget"));
        CircleWidget->resize(400, 300);

        retranslateUi(CircleWidget);

        QMetaObject::connectSlotsByName(CircleWidget);
    } // setupUi

    void retranslateUi(QWidget *CircleWidget)
    {
        CircleWidget->setWindowTitle(QApplication::translate("CircleWidget", "CircleWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CircleWidget: public Ui_CircleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLEWIDGET_H
