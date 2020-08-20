/********************************************************************************
** Form generated from reading UI file 'MWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MWIDGET_H
#define UI_MWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MWidget
{
public:

    void setupUi(QWidget *MWidget)
    {
        if (MWidget->objectName().isEmpty())
            MWidget->setObjectName(QStringLiteral("MWidget"));
        MWidget->resize(400, 300);

        retranslateUi(MWidget);

        QMetaObject::connectSlotsByName(MWidget);
    } // setupUi

    void retranslateUi(QWidget *MWidget)
    {
        MWidget->setWindowTitle(QApplication::translate("MWidget", "MWidget", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MWidget: public Ui_MWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MWIDGET_H
