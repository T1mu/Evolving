/********************************************************************************
** Form generated from reading UI file 'XRayImgTest.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XRAYIMGTEST_H
#define UI_XRAYIMGTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_XRayImgTestClass
{
public:

    void setupUi(QWidget *XRayImgTestClass)
    {
        if (XRayImgTestClass->objectName().isEmpty())
            XRayImgTestClass->setObjectName(QStringLiteral("XRayImgTestClass"));
        XRayImgTestClass->resize(600, 400);

        retranslateUi(XRayImgTestClass);

        QMetaObject::connectSlotsByName(XRayImgTestClass);
    } // setupUi

    void retranslateUi(QWidget *XRayImgTestClass)
    {
        XRayImgTestClass->setWindowTitle(QApplication::translate("XRayImgTestClass", "XRayImgTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class XRayImgTestClass: public Ui_XRayImgTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XRAYIMGTEST_H
