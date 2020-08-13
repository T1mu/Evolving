/********************************************************************************
** Form generated from reading UI file 'union.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNION_H
#define UI_UNION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Union
{
public:

    void setupUi(QWidget *Union)
    {
        if (Union->objectName().isEmpty())
            Union->setObjectName(QStringLiteral("Union"));
        Union->resize(400, 300);

        retranslateUi(Union);

        QMetaObject::connectSlotsByName(Union);
    } // setupUi

    void retranslateUi(QWidget *Union)
    {
        Union->setWindowTitle(QApplication::translate("Union", "Union", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Union: public Ui_Union {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNION_H
