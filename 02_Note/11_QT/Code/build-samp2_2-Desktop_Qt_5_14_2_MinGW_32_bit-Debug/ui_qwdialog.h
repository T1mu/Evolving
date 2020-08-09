/********************************************************************************
** Form generated from reading UI file 'qwdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QWDIALOG_H
#define UI_QWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QWDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbtnBlack;
    QRadioButton *rbtnRed;
    QRadioButton *rbtnBlue;
    QLabel *label;
    QPlainTextEdit *txtEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnExit;

    void setupUi(QDialog *QWDialog)
    {
        if (QWDialog->objectName().isEmpty())
            QWDialog->setObjectName(QString::fromUtf8("QWDialog"));
        QWDialog->resize(371, 335);
        horizontalLayout_4 = new QHBoxLayout(QWDialog);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        chkBoxUnder = new QCheckBox(QWDialog);
        chkBoxUnder->setObjectName(QString::fromUtf8("chkBoxUnder"));

        horizontalLayout->addWidget(chkBoxUnder);

        chkBoxItalic = new QCheckBox(QWDialog);
        chkBoxItalic->setObjectName(QString::fromUtf8("chkBoxItalic"));

        horizontalLayout->addWidget(chkBoxItalic);

        chkBoxBold = new QCheckBox(QWDialog);
        chkBoxBold->setObjectName(QString::fromUtf8("chkBoxBold"));

        horizontalLayout->addWidget(chkBoxBold);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbtnBlack = new QRadioButton(QWDialog);
        rbtnBlack->setObjectName(QString::fromUtf8("rbtnBlack"));

        horizontalLayout_2->addWidget(rbtnBlack);

        rbtnRed = new QRadioButton(QWDialog);
        rbtnRed->setObjectName(QString::fromUtf8("rbtnRed"));

        horizontalLayout_2->addWidget(rbtnRed);

        rbtnBlue = new QRadioButton(QWDialog);
        rbtnBlue->setObjectName(QString::fromUtf8("rbtnBlue"));

        horizontalLayout_2->addWidget(rbtnBlue);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(QWDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        txtEdit = new QPlainTextEdit(QWDialog);
        txtEdit->setObjectName(QString::fromUtf8("txtEdit"));
        QFont font;
        font.setPointSize(58);
        txtEdit->setFont(font);

        verticalLayout->addWidget(txtEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnOK = new QPushButton(QWDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout_3->addWidget(btnOK);

        btnCancel = new QPushButton(QWDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout_3->addWidget(btnCancel);

        btnExit = new QPushButton(QWDialog);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));

        horizontalLayout_3->addWidget(btnExit);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);

#if QT_CONFIG(shortcut)
        label->setBuddy(txtEdit);
#endif // QT_CONFIG(shortcut)

        retranslateUi(QWDialog);
        QObject::connect(btnOK, SIGNAL(clicked()), QWDialog, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), QWDialog, SLOT(reject()));
        QObject::connect(btnExit, SIGNAL(clicked()), QWDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(QWDialog);
    } // setupUi

    void retranslateUi(QDialog *QWDialog)
    {
        QWDialog->setWindowTitle(QCoreApplication::translate("QWDialog", "QWDialog", nullptr));
        chkBoxUnder->setText(QCoreApplication::translate("QWDialog", "\344\270\213\345\210\222\347\272\277", nullptr));
        chkBoxItalic->setText(QCoreApplication::translate("QWDialog", "\346\226\234\344\275\223", nullptr));
        chkBoxBold->setText(QCoreApplication::translate("QWDialog", "\347\262\227\344\275\223", nullptr));
        rbtnBlack->setText(QCoreApplication::translate("QWDialog", "\351\273\221", nullptr));
        rbtnRed->setText(QCoreApplication::translate("QWDialog", "\347\272\242", nullptr));
        rbtnBlue->setText(QCoreApplication::translate("QWDialog", "\350\223\235", nullptr));
        label->setText(QCoreApplication::translate("QWDialog", "\346\226\207\346\234\254\347\274\226\350\276\221\345\231\250(&E)", nullptr));
        txtEdit->setPlainText(QCoreApplication::translate("QWDialog", "HaloToto", nullptr));
        btnOK->setText(QCoreApplication::translate("QWDialog", "\347\241\256\345\256\232", nullptr));
        btnCancel->setText(QCoreApplication::translate("QWDialog", "\345\217\226\346\266\210", nullptr));
        btnExit->setText(QCoreApplication::translate("QWDialog", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QWDialog: public Ui_QWDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QWDIALOG_H
