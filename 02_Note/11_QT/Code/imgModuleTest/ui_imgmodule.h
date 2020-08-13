/********************************************************************************
** Form generated from reading UI file 'imgmodule.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMGMODULE_H
#define UI_IMGMODULE_H

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

class Ui_ImgModule
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImgModule)
    {
        if (ImgModule->objectName().isEmpty())
            ImgModule->setObjectName(QStringLiteral("ImgModule"));
        ImgModule->resize(1123, 616);
        centralWidget = new QWidget(ImgModule);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ImgModule->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImgModule);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 23));
        ImgModule->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImgModule);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImgModule->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImgModule);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImgModule->setStatusBar(statusBar);

        retranslateUi(ImgModule);

        QMetaObject::connectSlotsByName(ImgModule);
    } // setupUi

    void retranslateUi(QMainWindow *ImgModule)
    {
        ImgModule->setWindowTitle(QApplication::translate("ImgModule", "ImgModule", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ImgModule: public Ui_ImgModule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMGMODULE_H
