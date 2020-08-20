/********************************************************************************
** Form generated from reading UI file 'ControlMenuWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLMENUWIDGET_H
#define UI_CONTROLMENUWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlMenuWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *darkCb;
    QCheckBox *floodCb;
    QCheckBox *defectCb;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *printBtn;
    QToolButton *saveBtn;
    QToolButton *inputBtn;
    QToolButton *outputBtn;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *opendetectBtn;
    QToolButton *captureBtn;
    QToolButton *pulseBtn;
    QComboBox *pdataCb;

    void setupUi(QWidget *ControlMenuWidget)
    {
        if (ControlMenuWidget->objectName().isEmpty())
            ControlMenuWidget->setObjectName(QStringLiteral("ControlMenuWidget"));
        ControlMenuWidget->resize(329, 255);
        ControlMenuWidget->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout_2 = new QVBoxLayout(ControlMenuWidget);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(30, -1, -1, -1);
        darkCb = new QCheckBox(ControlMenuWidget);
        darkCb->setObjectName(QStringLiteral("darkCb"));

        horizontalLayout_6->addWidget(darkCb);

        floodCb = new QCheckBox(ControlMenuWidget);
        floodCb->setObjectName(QStringLiteral("floodCb"));

        horizontalLayout_6->addWidget(floodCb);

        defectCb = new QCheckBox(ControlMenuWidget);
        defectCb->setObjectName(QStringLiteral("defectCb"));

        horizontalLayout_6->addWidget(defectCb);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        printBtn = new QToolButton(ControlMenuWidget);
        printBtn->setObjectName(QStringLiteral("printBtn"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(printBtn->sizePolicy().hasHeightForWidth());
        printBtn->setSizePolicy(sizePolicy);
        printBtn->setMinimumSize(QSize(60, 35));
        printBtn->setMaximumSize(QSize(60, 35));
        printBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/print.ico"), QSize(), QIcon::Normal, QIcon::Off);
        printBtn->setIcon(icon);
        printBtn->setIconSize(QSize(150, 30));
        printBtn->setCheckable(false);

        horizontalLayout_3->addWidget(printBtn);

        saveBtn = new QToolButton(ControlMenuWidget);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(saveBtn->sizePolicy().hasHeightForWidth());
        saveBtn->setSizePolicy(sizePolicy1);
        saveBtn->setMinimumSize(QSize(60, 30));
        saveBtn->setMaximumSize(QSize(60, 35));
        saveBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/save.ico"), QSize(), QIcon::Normal, QIcon::Off);
        saveBtn->setIcon(icon1);
        saveBtn->setIconSize(QSize(30, 28));

        horizontalLayout_3->addWidget(saveBtn);

        inputBtn = new QToolButton(ControlMenuWidget);
        inputBtn->setObjectName(QStringLiteral("inputBtn"));
        sizePolicy1.setHeightForWidth(inputBtn->sizePolicy().hasHeightForWidth());
        inputBtn->setSizePolicy(sizePolicy1);
        inputBtn->setMinimumSize(QSize(60, 35));
        inputBtn->setMaximumSize(QSize(60, 35));
        inputBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/input.ico"), QSize(), QIcon::Normal, QIcon::Off);
        inputBtn->setIcon(icon2);
        inputBtn->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(inputBtn);

        outputBtn = new QToolButton(ControlMenuWidget);
        outputBtn->setObjectName(QStringLiteral("outputBtn"));
        sizePolicy1.setHeightForWidth(outputBtn->sizePolicy().hasHeightForWidth());
        outputBtn->setSizePolicy(sizePolicy1);
        outputBtn->setMinimumSize(QSize(60, 30));
        outputBtn->setMaximumSize(QSize(60, 35));
        outputBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/output.ico"), QSize(), QIcon::Normal, QIcon::Off);
        outputBtn->setIcon(icon3);
        outputBtn->setIconSize(QSize(30, 30));

        horizontalLayout_3->addWidget(outputBtn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        opendetectBtn = new QToolButton(ControlMenuWidget);
        opendetectBtn->setObjectName(QStringLiteral("opendetectBtn"));
        sizePolicy.setHeightForWidth(opendetectBtn->sizePolicy().hasHeightForWidth());
        opendetectBtn->setSizePolicy(sizePolicy);
        opendetectBtn->setMinimumSize(QSize(60, 35));
        opendetectBtn->setMaximumSize(QSize(60, 35));
        opendetectBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/switch.ico"), QSize(), QIcon::Normal, QIcon::Off);
        opendetectBtn->setIcon(icon4);
        opendetectBtn->setIconSize(QSize(100, 30));
        opendetectBtn->setCheckable(false);

        horizontalLayout_2->addWidget(opendetectBtn);

        captureBtn = new QToolButton(ControlMenuWidget);
        captureBtn->setObjectName(QStringLiteral("captureBtn"));
        sizePolicy1.setHeightForWidth(captureBtn->sizePolicy().hasHeightForWidth());
        captureBtn->setSizePolicy(sizePolicy1);
        captureBtn->setMinimumSize(QSize(60, 30));
        captureBtn->setMaximumSize(QSize(60, 35));
        captureBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/capture.png"), QSize(), QIcon::Normal, QIcon::Off);
        captureBtn->setIcon(icon5);
        captureBtn->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(captureBtn);

        pulseBtn = new QToolButton(ControlMenuWidget);
        pulseBtn->setObjectName(QStringLiteral("pulseBtn"));
        sizePolicy1.setHeightForWidth(pulseBtn->sizePolicy().hasHeightForWidth());
        pulseBtn->setSizePolicy(sizePolicy1);
        pulseBtn->setMinimumSize(QSize(60, 35));
        pulseBtn->setMaximumSize(QSize(60, 35));
        pulseBtn->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/pulseCapture.png"), QSize(), QIcon::Normal, QIcon::Off);
        pulseBtn->setIcon(icon6);
        pulseBtn->setIconSize(QSize(30, 30));

        horizontalLayout_2->addWidget(pulseBtn);

        pdataCb = new QComboBox(ControlMenuWidget);
        pdataCb->setObjectName(QStringLiteral("pdataCb"));
        pdataCb->setMinimumSize(QSize(60, 30));
        pdataCb->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(pdataCb);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(ControlMenuWidget);

        QMetaObject::connectSlotsByName(ControlMenuWidget);
    } // setupUi

    void retranslateUi(QWidget *ControlMenuWidget)
    {
        ControlMenuWidget->setWindowTitle(QApplication::translate("ControlMenuWidget", "ControlMenuWidget", Q_NULLPTR));
        darkCb->setText(QApplication::translate("ControlMenuWidget", "Dark ", Q_NULLPTR));
        floodCb->setText(QApplication::translate("ControlMenuWidget", "Flood ", Q_NULLPTR));
        defectCb->setText(QApplication::translate("ControlMenuWidget", "Defect ", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        printBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\346\211\223\345\215\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        printBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        saveBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\345\255\230\345\202\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        inputBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\345\257\274\345\205\245", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        inputBtn->setStatusTip(QApplication::translate("ControlMenuWidget", "\350\277\236\347\273\255\351\207\207\351\233\206", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        inputBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        outputBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\345\257\274\345\207\272", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        outputBtn->setText(QString());
#ifndef QT_NO_TOOLTIP
        opendetectBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\346\211\223\345\274\200\346\216\242\346\265\213\345\231\250", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        opendetectBtn->setText(QApplication::translate("ControlMenuWidget", "\346\211\223\345\274\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        captureBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\346\212\223\345\233\276\346\250\241\345\274\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        pulseBtn->setToolTip(QApplication::translate("ControlMenuWidget", "\350\277\236\347\273\255\351\207\207\351\233\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pulseBtn->setStatusTip(QApplication::translate("ControlMenuWidget", "\350\277\236\347\273\255\351\207\207\351\233\206", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        pulseBtn->setText(QString());
        pdataCb->clear();
        pdataCb->insertItems(0, QStringList()
         << QApplication::translate("ControlMenuWidget", "live", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "2", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "4", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "8", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "16", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "32", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "64", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "128", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "256", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "512", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "1024", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "2048", Q_NULLPTR)
         << QApplication::translate("ControlMenuWidget", "4096", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class ControlMenuWidget: public Ui_ControlMenuWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLMENUWIDGET_H
