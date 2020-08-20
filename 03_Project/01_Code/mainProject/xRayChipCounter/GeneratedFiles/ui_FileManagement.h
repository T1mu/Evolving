/********************************************************************************
** Form generated from reading UI file 'FileManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEMANAGEMENT_H
#define UI_FILEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileManagement
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QTreeView *treeView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *openFileBtn;
    QPushButton *removeFileBtn;
    QPushButton *createFileBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FileManagement)
    {
        if (FileManagement->objectName().isEmpty())
            FileManagement->setObjectName(QStringLiteral("FileManagement"));
        FileManagement->resize(500, 807);
        FileManagement->setMinimumSize(QSize(500, 0));
        FileManagement->setMaximumSize(QSize(500, 9999));
        verticalLayout = new QVBoxLayout(FileManagement);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        treeView = new QTreeView(FileManagement);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setMinimumSize(QSize(0, 800));

        verticalLayout->addWidget(treeView);

        widget = new QWidget(FileManagement);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(221, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        openFileBtn = new QPushButton(widget);
        openFileBtn->setObjectName(QStringLiteral("openFileBtn"));
        openFileBtn->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(openFileBtn);

        removeFileBtn = new QPushButton(widget);
        removeFileBtn->setObjectName(QStringLiteral("removeFileBtn"));
        removeFileBtn->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(removeFileBtn);

        createFileBtn = new QPushButton(widget);
        createFileBtn->setObjectName(QStringLiteral("createFileBtn"));
        createFileBtn->setMinimumSize(QSize(80, 30));

        horizontalLayout->addWidget(createFileBtn);


        verticalLayout->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FileManagement);

        QMetaObject::connectSlotsByName(FileManagement);
    } // setupUi

    void retranslateUi(QWidget *FileManagement)
    {
        FileManagement->setWindowTitle(QApplication::translate("FileManagement", "FileManagement", Q_NULLPTR));
        openFileBtn->setText(QApplication::translate("FileManagement", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
        removeFileBtn->setText(QApplication::translate("FileManagement", "\345\210\240\351\231\244\346\226\207\344\273\266", Q_NULLPTR));
        createFileBtn->setText(QApplication::translate("FileManagement", "\345\210\233\345\273\272\346\226\260\346\226\207\344\273\266\345\244\271", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FileManagement: public Ui_FileManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEMANAGEMENT_H
