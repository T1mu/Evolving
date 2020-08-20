/********************************************************************************
** Form generated from reading UI file 'TubeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUBEWIDGET_H
#define UI_TUBEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TubeWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QPushButton *openXRayBtn;
    QPushButton *closeXRayBtn;
    QPushButton *connectBtn;
    QComboBox *connectComboBox;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QDoubleSpinBox *voltageSpinBox;
    QLabel *label_7;
    QLabel *voltageEdit;
    QLabel *label_6;
    QLabel *label_8;
    QComboBox *modeComboBox;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QDoubleSpinBox *currentSpinBox;
    QLabel *label_10;
    QLabel *currentEdit;
    QLabel *label_9;
    QPushButton *queryBtn;
    QPushButton *modeSetBtn;
    QTextEdit *statusEdit;

    void setupUi(QWidget *TubeWidget)
    {
        if (TubeWidget->objectName().isEmpty())
            TubeWidget->setObjectName(QStringLiteral("TubeWidget"));
        TubeWidget->resize(523, 177);
        horizontalLayout = new QHBoxLayout(TubeWidget);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 5);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(TubeWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(64, 64));
        label->setMaximumSize(QSize(64, 64));

        horizontalLayout_5->addWidget(label);

        openXRayBtn = new QPushButton(TubeWidget);
        openXRayBtn->setObjectName(QStringLiteral("openXRayBtn"));
        openXRayBtn->setMinimumSize(QSize(45, 35));
        openXRayBtn->setMaximumSize(QSize(45, 35));

        horizontalLayout_5->addWidget(openXRayBtn);

        closeXRayBtn = new QPushButton(TubeWidget);
        closeXRayBtn->setObjectName(QStringLiteral("closeXRayBtn"));
        closeXRayBtn->setMinimumSize(QSize(45, 35));
        closeXRayBtn->setMaximumSize(QSize(45, 35));

        horizontalLayout_5->addWidget(closeXRayBtn);

        connectBtn = new QPushButton(TubeWidget);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setMinimumSize(QSize(35, 35));
        connectBtn->setMaximumSize(QSize(35, 35));

        horizontalLayout_5->addWidget(connectBtn);

        connectComboBox = new QComboBox(TubeWidget);
        connectComboBox->setObjectName(QStringLiteral("connectComboBox"));
        connectComboBox->setMinimumSize(QSize(61, 35));
        connectComboBox->setMaximumSize(QSize(61, 35));

        horizontalLayout_5->addWidget(connectComboBox);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(TubeWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(55, 23));
        label_4->setMaximumSize(QSize(23, 21));

        horizontalLayout_6->addWidget(label_4);

        voltageSpinBox = new QDoubleSpinBox(TubeWidget);
        voltageSpinBox->setObjectName(QStringLiteral("voltageSpinBox"));
        voltageSpinBox->setMinimumSize(QSize(51, 35));
        voltageSpinBox->setMaximumSize(QSize(51, 35));
        voltageSpinBox->setMaximum(1000);

        horizontalLayout_6->addWidget(voltageSpinBox);

        label_7 = new QLabel(TubeWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(21, 21));
        label_7->setMaximumSize(QSize(21, 21));

        horizontalLayout_6->addWidget(label_7);

        voltageEdit = new QLabel(TubeWidget);
        voltageEdit->setObjectName(QStringLiteral("voltageEdit"));
        voltageEdit->setMinimumSize(QSize(31, 21));
        voltageEdit->setMaximumSize(QSize(31, 21));

        horizontalLayout_6->addWidget(voltageEdit);

        label_6 = new QLabel(TubeWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(21, 21));
        label_6->setMaximumSize(QSize(21, 21));

        horizontalLayout_6->addWidget(label_6);

        label_8 = new QLabel(TubeWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(41, 21));
        label_8->setMaximumSize(QSize(41, 21));

        horizontalLayout_6->addWidget(label_8);

        modeComboBox = new QComboBox(TubeWidget);
        modeComboBox->setObjectName(QStringLiteral("modeComboBox"));
        modeComboBox->setMinimumSize(QSize(61, 35));
        modeComboBox->setMaximumSize(QSize(61, 35));

        horizontalLayout_6->addWidget(modeComboBox);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(TubeWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(55, 21));
        label_5->setMaximumSize(QSize(55, 21));

        horizontalLayout_7->addWidget(label_5);

        currentSpinBox = new QDoubleSpinBox(TubeWidget);
        currentSpinBox->setObjectName(QStringLiteral("currentSpinBox"));
        currentSpinBox->setMinimumSize(QSize(51, 35));
        currentSpinBox->setMaximumSize(QSize(51, 35));
        currentSpinBox->setMaximum(1000);

        horizontalLayout_7->addWidget(currentSpinBox);

        label_10 = new QLabel(TubeWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMinimumSize(QSize(21, 21));
        label_10->setMaximumSize(QSize(21, 21));

        horizontalLayout_7->addWidget(label_10);

        currentEdit = new QLabel(TubeWidget);
        currentEdit->setObjectName(QStringLiteral("currentEdit"));
        currentEdit->setMinimumSize(QSize(31, 21));
        currentEdit->setMaximumSize(QSize(31, 21));

        horizontalLayout_7->addWidget(currentEdit);

        label_9 = new QLabel(TubeWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(21, 21));
        label_9->setMaximumSize(QSize(21, 21));

        horizontalLayout_7->addWidget(label_9);

        queryBtn = new QPushButton(TubeWidget);
        queryBtn->setObjectName(QStringLiteral("queryBtn"));
        queryBtn->setMinimumSize(QSize(51, 35));
        queryBtn->setMaximumSize(QSize(51, 35));

        horizontalLayout_7->addWidget(queryBtn);

        modeSetBtn = new QPushButton(TubeWidget);
        modeSetBtn->setObjectName(QStringLiteral("modeSetBtn"));
        modeSetBtn->setMinimumSize(QSize(71, 35));
        modeSetBtn->setMaximumSize(QSize(71, 35));

        horizontalLayout_7->addWidget(modeSetBtn);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout->addLayout(verticalLayout_2);

        statusEdit = new QTextEdit(TubeWidget);
        statusEdit->setObjectName(QStringLiteral("statusEdit"));

        horizontalLayout->addWidget(statusEdit);

        horizontalLayout->setStretch(0, 8);
        horizontalLayout->setStretch(1, 2);

        retranslateUi(TubeWidget);

        QMetaObject::connectSlotsByName(TubeWidget);
    } // setupUi

    void retranslateUi(QWidget *TubeWidget)
    {
        TubeWidget->setWindowTitle(QApplication::translate("TubeWidget", "TubeWidget", Q_NULLPTR));
        label->setText(QApplication::translate("TubeWidget", "TextLabel", Q_NULLPTR));
        openXRayBtn->setText(QApplication::translate("TubeWidget", "ON", Q_NULLPTR));
        closeXRayBtn->setText(QApplication::translate("TubeWidget", "OFF", Q_NULLPTR));
        connectBtn->setText(QString());
        label_4->setText(QApplication::translate("TubeWidget", "Voltage\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("TubeWidget", "kV", Q_NULLPTR));
        voltageEdit->setText(QApplication::translate("TubeWidget", "0.00", Q_NULLPTR));
        label_6->setText(QApplication::translate("TubeWidget", "kV", Q_NULLPTR));
        label_8->setText(QApplication::translate("TubeWidget", "Mode\357\274\232", Q_NULLPTR));
        modeComboBox->clear();
        modeComboBox->insertItems(0, QStringList()
         << QApplication::translate("TubeWidget", "large", Q_NULLPTR)
         << QApplication::translate("TubeWidget", "medium", Q_NULLPTR)
         << QApplication::translate("TubeWidget", "small", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("TubeWidget", "Current\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("TubeWidget", "uA", Q_NULLPTR));
        currentEdit->setText(QApplication::translate("TubeWidget", "0.00", Q_NULLPTR));
        label_9->setText(QApplication::translate("TubeWidget", "uA", Q_NULLPTR));
        queryBtn->setText(QApplication::translate("TubeWidget", "Query", Q_NULLPTR));
        modeSetBtn->setText(QApplication::translate("TubeWidget", "Mode Set", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TubeWidget: public Ui_TubeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUBEWIDGET_H
