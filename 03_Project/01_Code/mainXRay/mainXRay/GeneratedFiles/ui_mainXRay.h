/********************************************************************************
** Form generated from reading UI file 'mainXRay.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINXRAY_H
#define UI_MAINXRAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainXRayClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mainXRayClass)
    {
        if (mainXRayClass->objectName().isEmpty())
            mainXRayClass->setObjectName(QStringLiteral("mainXRayClass"));
        mainXRayClass->resize(600, 400);
        menuBar = new QMenuBar(mainXRayClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        mainXRayClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(mainXRayClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainXRayClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(mainXRayClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mainXRayClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(mainXRayClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        mainXRayClass->setStatusBar(statusBar);

        retranslateUi(mainXRayClass);

        QMetaObject::connectSlotsByName(mainXRayClass);
    } // setupUi

    void retranslateUi(QMainWindow *mainXRayClass)
    {
        mainXRayClass->setWindowTitle(QApplication::translate("mainXRayClass", "mainXRay", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class mainXRayClass: public Ui_mainXRayClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINXRAY_H
