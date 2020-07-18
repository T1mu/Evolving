/********************************************************************************
** Form generated from reading UI file 'qwmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWMAINWINDOW_H
#define UI_QWMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QWMainWindow
{
public:
    QAction *actionnew;
    QAction *actionopen;
    QAction *actionexit;
    QAction *actioncopy;
    QAction *actionpaste;
    QAction *actionclear;
    QAction *actionbold;
    QAction *actionItalic;
    QAction *actionUnderLine;
    QAction *actionLabel;
    QWidget *centralwidget;
    QTextEdit *txtEdit;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *QWMainWindow)
    {
        if (QWMainWindow->objectName().isEmpty())
            QWMainWindow->setObjectName(QString::fromUtf8("QWMainWindow"));
        QWMainWindow->resize(510, 373);
        actionnew = new QAction(QWMainWindow);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionnew->setIcon(icon);
        actionopen = new QAction(QWMainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionopen->setIcon(icon1);
        actionexit = new QAction(QWMainWindow);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionexit->setIcon(icon2);
        actioncopy = new QAction(QWMainWindow);
        actioncopy->setObjectName(QString::fromUtf8("actioncopy"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncopy->setIcon(icon3);
        actionpaste = new QAction(QWMainWindow);
        actionpaste->setObjectName(QString::fromUtf8("actionpaste"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionpaste->setIcon(icon4);
        actionclear = new QAction(QWMainWindow);
        actionclear->setObjectName(QString::fromUtf8("actionclear"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionclear->setIcon(icon5);
        actionbold = new QAction(QWMainWindow);
        actionbold->setObjectName(QString::fromUtf8("actionbold"));
        actionbold->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionbold->setIcon(icon6);
        actionItalic = new QAction(QWMainWindow);
        actionItalic->setObjectName(QString::fromUtf8("actionItalic"));
        actionItalic->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionItalic->setIcon(icon7);
        actionUnderLine = new QAction(QWMainWindow);
        actionUnderLine->setObjectName(QString::fromUtf8("actionUnderLine"));
        actionUnderLine->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUnderLine->setIcon(icon8);
        actionLabel = new QAction(QWMainWindow);
        actionLabel->setObjectName(QString::fromUtf8("actionLabel"));
        actionLabel->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/show.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLabel->setIcon(icon9);
        centralwidget = new QWidget(QWMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        txtEdit = new QTextEdit(centralwidget);
        txtEdit->setObjectName(QString::fromUtf8("txtEdit"));
        txtEdit->setGeometry(QRect(50, 30, 341, 251));
        QWMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QWMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 510, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        QWMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(QWMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QWMainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(QWMainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        QWMainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actionnew);
        menu->addAction(actionopen);
        menu->addSeparator();
        menu->addAction(actionexit);
        menu_2->addAction(actioncopy);
        menu_2->addAction(actionpaste);
        menu_2->addSeparator();
        menu_2->addAction(actionclear);
        menu_3->addAction(actionbold);
        menu_3->addAction(actionItalic);
        menu_3->addAction(actionUnderLine);
        menu_3->addSeparator();
        menu_3->addAction(actionLabel);
        toolBar->addAction(actionnew);
        toolBar->addAction(actionopen);
        toolBar->addAction(actionexit);
        toolBar->addSeparator();
        toolBar->addAction(actioncopy);
        toolBar->addAction(actionpaste);
        toolBar->addAction(actionclear);
        toolBar->addSeparator();
        toolBar->addAction(actionbold);
        toolBar->addAction(actionItalic);
        toolBar->addAction(actionUnderLine);
        toolBar->addAction(actionLabel);

        retranslateUi(QWMainWindow);
        QObject::connect(actioncopy, SIGNAL(triggered()), txtEdit, SLOT(copy()));
        QObject::connect(actionexit, SIGNAL(triggered()), QWMainWindow, SLOT(close()));
        QObject::connect(actionpaste, SIGNAL(triggered()), txtEdit, SLOT(paste()));
        QObject::connect(actionclear, SIGNAL(triggered()), txtEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(QWMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QWMainWindow)
    {
        QWMainWindow->setWindowTitle(QCoreApplication::translate("QWMainWindow", "QWMainWindow", nullptr));
        actionnew->setText(QCoreApplication::translate("QWMainWindow", "\346\226\260\345\273\272", nullptr));
#if QT_CONFIG(shortcut)
        actionnew->setShortcut(QCoreApplication::translate("QWMainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionopen->setText(QCoreApplication::translate("QWMainWindow", "\346\211\223\345\274\200", nullptr));
#if QT_CONFIG(shortcut)
        actionopen->setShortcut(QCoreApplication::translate("QWMainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionexit->setText(QCoreApplication::translate("QWMainWindow", "\351\200\200\345\207\272", nullptr));
        actioncopy->setText(QCoreApplication::translate("QWMainWindow", "\345\244\215\345\210\266", nullptr));
        actionpaste->setText(QCoreApplication::translate("QWMainWindow", "\347\262\230\350\264\264", nullptr));
        actionclear->setText(QCoreApplication::translate("QWMainWindow", "\346\270\205\347\251\272", nullptr));
        actionbold->setText(QCoreApplication::translate("QWMainWindow", "\347\262\227\344\275\223", nullptr));
        actionItalic->setText(QCoreApplication::translate("QWMainWindow", "\346\226\234\344\275\223", nullptr));
        actionUnderLine->setText(QCoreApplication::translate("QWMainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
        actionLabel->setText(QCoreApplication::translate("QWMainWindow", "\346\230\276\347\244\272\345\267\245\345\205\267\346\240\217\346\226\207\345\255\227\346\240\207\347\255\276", nullptr));
        menu->setTitle(QCoreApplication::translate("QWMainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("QWMainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("QWMainWindow", "\346\240\274\345\274\217", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("QWMainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWMainWindow: public Ui_QWMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWMAINWINDOW_H
