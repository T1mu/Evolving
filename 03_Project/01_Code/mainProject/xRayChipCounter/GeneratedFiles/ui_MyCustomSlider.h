/********************************************************************************
** Form generated from reading UI file 'MyCustomSlider.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCUSTOMSLIDER_H
#define UI_MYCUSTOMSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_MyCustomSlider
{
public:

    void setupUi(QSlider *MyCustomSlider)
    {
        if (MyCustomSlider->objectName().isEmpty())
            MyCustomSlider->setObjectName(QStringLiteral("MyCustomSlider"));
        MyCustomSlider->resize(400, 300);

        retranslateUi(MyCustomSlider);

        QMetaObject::connectSlotsByName(MyCustomSlider);
    } // setupUi

    void retranslateUi(QSlider *MyCustomSlider)
    {
        MyCustomSlider->setWindowTitle(QApplication::translate("MyCustomSlider", "MyCustomSlider", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyCustomSlider: public Ui_MyCustomSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCUSTOMSLIDER_H
