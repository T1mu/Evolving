/********************************************************************************
** Form generated from reading UI file 'dragzoom.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGZOOM_H
#define UI_DRAGZOOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DragZoom
{
public:

    void setupUi(QWidget *DragZoom)
    {
        if (DragZoom->objectName().isEmpty())
            DragZoom->setObjectName(QStringLiteral("DragZoom"));
        DragZoom->resize(1091, 671);

        retranslateUi(DragZoom);

        QMetaObject::connectSlotsByName(DragZoom);
    } // setupUi

    void retranslateUi(QWidget *DragZoom)
    {
        DragZoom->setWindowTitle(QApplication::translate("DragZoom", "DragZoom", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DragZoom: public Ui_DragZoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGZOOM_H
