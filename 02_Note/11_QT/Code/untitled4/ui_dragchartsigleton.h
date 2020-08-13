/********************************************************************************
** Form generated from reading UI file 'dragchartsigleton.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRAGCHARTSIGLETON_H
#define UI_DRAGCHARTSIGLETON_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dragChartSigleton
{
public:

    void setupUi(QWidget *dragChartSigleton)
    {
        if (dragChartSigleton->objectName().isEmpty())
            dragChartSigleton->setObjectName(QStringLiteral("dragChartSigleton"));
        dragChartSigleton->resize(414, 199);

        retranslateUi(dragChartSigleton);

        QMetaObject::connectSlotsByName(dragChartSigleton);
    } // setupUi

    void retranslateUi(QWidget *dragChartSigleton)
    {
        dragChartSigleton->setWindowTitle(QApplication::translate("dragChartSigleton", "dragChartSigleton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dragChartSigleton: public Ui_dragChartSigleton {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRAGCHARTSIGLETON_H
