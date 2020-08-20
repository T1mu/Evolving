/********************************************************************************
** Form generated from reading UI file 'MenuWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWIDGET_H
#define UI_MENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuWidget
{
public:
    QAction *newExpAction;
    QAction *openExpAction;
    QAction *saveExpAction;
    QAction *closeAction;
    QAction *helpFCSAction;
    QAction *openHelpFileAction;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *MenuWidget)
    {
        if (MenuWidget->objectName().isEmpty())
            MenuWidget->setObjectName(QStringLiteral("MenuWidget"));
        MenuWidget->resize(669, 22);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MenuWidget->sizePolicy().hasHeightForWidth());
        MenuWidget->setSizePolicy(sizePolicy);
        MenuWidget->setMaximumSize(QSize(16777215, 22));
        MenuWidget->setStyleSheet(QStringLiteral(""));
        newExpAction = new QAction(MenuWidget);
        newExpAction->setObjectName(QStringLiteral("newExpAction"));
        openExpAction = new QAction(MenuWidget);
        openExpAction->setObjectName(QStringLiteral("openExpAction"));
        saveExpAction = new QAction(MenuWidget);
        saveExpAction->setObjectName(QStringLiteral("saveExpAction"));
        closeAction = new QAction(MenuWidget);
        closeAction->setObjectName(QStringLiteral("closeAction"));
        helpFCSAction = new QAction(MenuWidget);
        helpFCSAction->setObjectName(QStringLiteral("helpFCSAction"));
        openHelpFileAction = new QAction(MenuWidget);
        openHelpFileAction->setObjectName(QStringLiteral("openHelpFileAction"));
        horizontalLayout_2 = new QHBoxLayout(MenuWidget);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(MenuWidget);

        QMetaObject::connectSlotsByName(MenuWidget);
    } // setupUi

    void retranslateUi(QWidget *MenuWidget)
    {
        MenuWidget->setWindowTitle(QApplication::translate("MenuWidget", "MenuWidget", Q_NULLPTR));
        newExpAction->setText(QApplication::translate("MenuWidget", "\346\226\260\345\273\272\345\256\236\351\252\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        newExpAction->setToolTip(QApplication::translate("MenuWidget", "\346\226\260\345\273\272\345\256\236\351\252\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        openExpAction->setText(QApplication::translate("MenuWidget", "\346\211\223\345\274\200\345\256\236\351\252\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        openExpAction->setToolTip(QApplication::translate("MenuWidget", "\346\211\223\345\274\200\345\256\236\351\252\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveExpAction->setText(QApplication::translate("MenuWidget", "\344\277\235\345\255\230\345\256\236\351\252\214", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveExpAction->setToolTip(QApplication::translate("MenuWidget", "\344\277\235\345\255\230\345\256\236\351\252\214", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        closeAction->setText(QApplication::translate("MenuWidget", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        closeAction->setToolTip(QApplication::translate("MenuWidget", "\345\205\263\351\227\255\350\275\257\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        helpFCSAction->setText(QApplication::translate("MenuWidget", "\345\205\263\344\272\216FCS", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        helpFCSAction->setToolTip(QApplication::translate("MenuWidget", "\345\205\263\344\272\216FCS", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        openHelpFileAction->setText(QApplication::translate("MenuWidget", "\345\270\256\345\212\251\346\226\207\346\241\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        openHelpFileAction->setToolTip(QApplication::translate("MenuWidget", "\345\270\256\345\212\251\346\226\207\346\241\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class MenuWidget: public Ui_MenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWIDGET_H
