/********************************************************************************
** Form generated from reading UI file 'ProcessWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROCESSWIDGET_H
#define UI_PROCESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProcessWidget
{
public:
    QHBoxLayout *horizontalLayout_6;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QComboBox *GaussianBlur;
    QPushButton *GaussianBlurBtn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *blur;
    QPushButton *blurBtn;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *medianBlur;
    QPushButton *medianBlurBtn;
    QHBoxLayout *horizontalLayout;
    QLabel *label_15;
    QSlider *light;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QSlider *contrast;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *circleBtn;
    QSpinBox *radious;
    QPushButton *okBtn;
    QHBoxLayout *horizontalLayout_22;
    QPushButton *lineBtn;
    QPushButton *rectBtn;
    QPushButton *cancelBtn;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *posBtn;
    QPushButton *posBtn_3;
    QPushButton *posBtn2;

    void setupUi(QWidget *ProcessWidget)
    {
        if (ProcessWidget->objectName().isEmpty())
            ProcessWidget->setObjectName(QStringLiteral("ProcessWidget"));
        ProcessWidget->resize(300, 270);
        ProcessWidget->setMinimumSize(QSize(300, 270));
        ProcessWidget->setMaximumSize(QSize(600, 666));
        horizontalLayout_6 = new QHBoxLayout(ProcessWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(ProcessWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(label);

        GaussianBlur = new QComboBox(groupBox);
        GaussianBlur->setObjectName(QStringLiteral("GaussianBlur"));
        sizePolicy.setHeightForWidth(GaussianBlur->sizePolicy().hasHeightForWidth());
        GaussianBlur->setSizePolicy(sizePolicy);
        GaussianBlur->setMinimumSize(QSize(50, 0));
        GaussianBlur->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(GaussianBlur);

        GaussianBlurBtn = new QPushButton(groupBox);
        GaussianBlurBtn->setObjectName(QStringLiteral("GaussianBlurBtn"));
        sizePolicy.setHeightForWidth(GaussianBlurBtn->sizePolicy().hasHeightForWidth());
        GaussianBlurBtn->setSizePolicy(sizePolicy);
        GaussianBlurBtn->setMinimumSize(QSize(50, 0));
        GaussianBlurBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_3->addWidget(GaussianBlurBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_2);

        blur = new QComboBox(groupBox);
        blur->setObjectName(QStringLiteral("blur"));
        sizePolicy.setHeightForWidth(blur->sizePolicy().hasHeightForWidth());
        blur->setSizePolicy(sizePolicy);
        blur->setMinimumSize(QSize(50, 0));
        blur->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(blur);

        blurBtn = new QPushButton(groupBox);
        blurBtn->setObjectName(QStringLiteral("blurBtn"));
        sizePolicy.setHeightForWidth(blurBtn->sizePolicy().hasHeightForWidth());
        blurBtn->setSizePolicy(sizePolicy);
        blurBtn->setMinimumSize(QSize(50, 0));
        blurBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(blurBtn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(50, 0));
        label_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(label_3);

        medianBlur = new QComboBox(groupBox);
        medianBlur->setObjectName(QStringLiteral("medianBlur"));
        sizePolicy.setHeightForWidth(medianBlur->sizePolicy().hasHeightForWidth());
        medianBlur->setSizePolicy(sizePolicy);
        medianBlur->setMinimumSize(QSize(50, 0));
        medianBlur->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(medianBlur);

        medianBlurBtn = new QPushButton(groupBox);
        medianBlurBtn->setObjectName(QStringLiteral("medianBlurBtn"));
        sizePolicy.setHeightForWidth(medianBlurBtn->sizePolicy().hasHeightForWidth());
        medianBlurBtn->setSizePolicy(sizePolicy);
        medianBlurBtn->setMinimumSize(QSize(50, 0));
        medianBlurBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_4->addWidget(medianBlurBtn);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(50, 0));
        label_15->setMaximumSize(QSize(50, 16777215));

        horizontalLayout->addWidget(label_15);

        light = new QSlider(groupBox);
        light->setObjectName(QStringLiteral("light"));
        sizePolicy.setHeightForWidth(light->sizePolicy().hasHeightForWidth());
        light->setSizePolicy(sizePolicy);
        light->setMinimumSize(QSize(130, 0));
        light->setMaximumSize(QSize(130, 16777215));
        light->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(light);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(50, 0));
        label_9->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_11->addWidget(label_9);

        contrast = new QSlider(groupBox);
        contrast->setObjectName(QStringLiteral("contrast"));
        sizePolicy.setHeightForWidth(contrast->sizePolicy().hasHeightForWidth());
        contrast->setSizePolicy(sizePolicy);
        contrast->setMinimumSize(QSize(100, 0));
        contrast->setMaximumSize(QSize(130, 16777215));
        contrast->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(contrast);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        circleBtn = new QPushButton(groupBox);
        circleBtn->setObjectName(QStringLiteral("circleBtn"));
        sizePolicy.setHeightForWidth(circleBtn->sizePolicy().hasHeightForWidth());
        circleBtn->setSizePolicy(sizePolicy);
        circleBtn->setMinimumSize(QSize(50, 0));
        circleBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_21->addWidget(circleBtn);

        radious = new QSpinBox(groupBox);
        radious->setObjectName(QStringLiteral("radious"));
        sizePolicy.setHeightForWidth(radious->sizePolicy().hasHeightForWidth());
        radious->setSizePolicy(sizePolicy);
        radious->setMinimumSize(QSize(50, 0));
        radious->setMaximumSize(QSize(50, 16777215));
        radious->setValue(40);

        horizontalLayout_21->addWidget(radious);

        okBtn = new QPushButton(groupBox);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        sizePolicy.setHeightForWidth(okBtn->sizePolicy().hasHeightForWidth());
        okBtn->setSizePolicy(sizePolicy);
        okBtn->setMinimumSize(QSize(50, 0));
        okBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_21->addWidget(okBtn);


        verticalLayout->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(0);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        lineBtn = new QPushButton(groupBox);
        lineBtn->setObjectName(QStringLiteral("lineBtn"));
        sizePolicy.setHeightForWidth(lineBtn->sizePolicy().hasHeightForWidth());
        lineBtn->setSizePolicy(sizePolicy);
        lineBtn->setMinimumSize(QSize(50, 0));
        lineBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_22->addWidget(lineBtn);

        rectBtn = new QPushButton(groupBox);
        rectBtn->setObjectName(QStringLiteral("rectBtn"));
        sizePolicy.setHeightForWidth(rectBtn->sizePolicy().hasHeightForWidth());
        rectBtn->setSizePolicy(sizePolicy);
        rectBtn->setMinimumSize(QSize(50, 0));
        rectBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_22->addWidget(rectBtn);

        cancelBtn = new QPushButton(groupBox);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        sizePolicy.setHeightForWidth(cancelBtn->sizePolicy().hasHeightForWidth());
        cancelBtn->setSizePolicy(sizePolicy);
        cancelBtn->setMinimumSize(QSize(50, 0));
        cancelBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_22->addWidget(cancelBtn);


        verticalLayout->addLayout(horizontalLayout_22);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        posBtn = new QPushButton(groupBox);
        posBtn->setObjectName(QStringLiteral("posBtn"));
        sizePolicy.setHeightForWidth(posBtn->sizePolicy().hasHeightForWidth());
        posBtn->setSizePolicy(sizePolicy);
        posBtn->setMinimumSize(QSize(50, 0));
        posBtn->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(posBtn);

        posBtn_3 = new QPushButton(groupBox);
        posBtn_3->setObjectName(QStringLiteral("posBtn_3"));
        sizePolicy.setHeightForWidth(posBtn_3->sizePolicy().hasHeightForWidth());
        posBtn_3->setSizePolicy(sizePolicy);
        posBtn_3->setMinimumSize(QSize(50, 0));
        posBtn_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(posBtn_3);

        posBtn2 = new QPushButton(groupBox);
        posBtn2->setObjectName(QStringLiteral("posBtn2"));
        sizePolicy.setHeightForWidth(posBtn2->sizePolicy().hasHeightForWidth());
        posBtn2->setSizePolicy(sizePolicy);
        posBtn2->setMinimumSize(QSize(50, 0));
        posBtn2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(posBtn2);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_6->addWidget(groupBox);


        retranslateUi(ProcessWidget);

        QMetaObject::connectSlotsByName(ProcessWidget);
    } // setupUi

    void retranslateUi(QWidget *ProcessWidget)
    {
        ProcessWidget->setWindowTitle(QApplication::translate("ProcessWidget", "ProcessWidget", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("ProcessWidget", "\351\253\230\346\226\257\346\273\244\346\263\242", Q_NULLPTR));
        GaussianBlurBtn->setText(QApplication::translate("ProcessWidget", "ok", Q_NULLPTR));
        label_2->setText(QApplication::translate("ProcessWidget", "\345\235\207\345\200\274\346\273\244\346\263\242", Q_NULLPTR));
        blurBtn->setText(QApplication::translate("ProcessWidget", "ok", Q_NULLPTR));
        label_3->setText(QApplication::translate("ProcessWidget", "\344\270\255\345\200\274\346\273\244\346\263\242", Q_NULLPTR));
        medianBlurBtn->setText(QApplication::translate("ProcessWidget", "ok", Q_NULLPTR));
        label_15->setText(QApplication::translate("ProcessWidget", "  \344\272\256\345\272\246\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("ProcessWidget", "\345\257\271\346\257\224\345\272\246\357\274\232", Q_NULLPTR));
        circleBtn->setText(QApplication::translate("ProcessWidget", "circle", Q_NULLPTR));
        okBtn->setText(QApplication::translate("ProcessWidget", "ok", Q_NULLPTR));
        lineBtn->setText(QApplication::translate("ProcessWidget", "line", Q_NULLPTR));
        rectBtn->setText(QApplication::translate("ProcessWidget", "rect", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("ProcessWidget", "cancel", Q_NULLPTR));
        posBtn->setText(QApplication::translate("ProcessWidget", "pos", Q_NULLPTR));
        posBtn_3->setText(QString());
        posBtn2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ProcessWidget: public Ui_ProcessWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROCESSWIDGET_H
