/********************************************************************************
** Form generated from reading UI file 'MeasureWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEASUREWIDGET_H
#define UI_MEASUREWIDGET_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeasureWidget
{
public:
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *openBtn;
    QComboBox *selectCb;
    QPushButton *enableBtn;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *cancelBtn;
    QPushButton *clearBtn;
    QPushButton *perdenBtn_4;
    QLabel *label;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MeasureWidget)
    {
        if (MeasureWidget->objectName().isEmpty())
            MeasureWidget->setObjectName(QStringLiteral("MeasureWidget"));
        MeasureWidget->resize(360, 897);
        groupBox_2 = new QGroupBox(MeasureWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 10, 300, 864));
        groupBox_2->setMinimumSize(QSize(300, 0));
        groupBox_2->setMaximumSize(QSize(300, 864));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        openBtn = new QPushButton(groupBox_2);
        openBtn->setObjectName(QStringLiteral("openBtn"));
        openBtn->setMinimumSize(QSize(85, 35));
        openBtn->setMaximumSize(QSize(85, 35));

        horizontalLayout_3->addWidget(openBtn);

        selectCb = new QComboBox(groupBox_2);
        selectCb->setObjectName(QStringLiteral("selectCb"));
        selectCb->setMinimumSize(QSize(85, 35));
        selectCb->setMaximumSize(QSize(85, 35));

        horizontalLayout_3->addWidget(selectCb);

        enableBtn = new QPushButton(groupBox_2);
        enableBtn->setObjectName(QStringLiteral("enableBtn"));
        enableBtn->setMinimumSize(QSize(85, 35));
        enableBtn->setMaximumSize(QSize(85, 35));
        enableBtn->setStyleSheet(QStringLiteral(""));

        horizontalLayout_3->addWidget(enableBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        cancelBtn = new QPushButton(groupBox_2);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(85, 35));
        cancelBtn->setMaximumSize(QSize(85, 35));

        horizontalLayout_4->addWidget(cancelBtn);

        clearBtn = new QPushButton(groupBox_2);
        clearBtn->setObjectName(QStringLiteral("clearBtn"));
        clearBtn->setMinimumSize(QSize(85, 35));
        clearBtn->setMaximumSize(QSize(85, 35));

        horizontalLayout_4->addWidget(clearBtn);

        perdenBtn_4 = new QPushButton(groupBox_2);
        perdenBtn_4->setObjectName(QStringLiteral("perdenBtn_4"));
        perdenBtn_4->setMinimumSize(QSize(85, 35));
        perdenBtn_4->setMaximumSize(QSize(85, 35));

        horizontalLayout_4->addWidget(perdenBtn_4);


        verticalLayout->addLayout(horizontalLayout_4);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 45));
        label->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(label);

        verticalSpacer = new QSpacerItem(20, 712, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(MeasureWidget);

        QMetaObject::connectSlotsByName(MeasureWidget);
    } // setupUi

    void retranslateUi(QWidget *MeasureWidget)
    {
        MeasureWidget->setWindowTitle(QApplication::translate("MeasureWidget", "MeasureWidget", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        openBtn->setText(QApplication::translate("MeasureWidget", "open", Q_NULLPTR));
        selectCb->clear();
        selectCb->insertItems(0, QStringList()
         << QApplication::translate("MeasureWidget", "Null", Q_NULLPTR)
         << QApplication::translate("MeasureWidget", "Line Angle", Q_NULLPTR)
         << QApplication::translate("MeasureWidget", "Perden", Q_NULLPTR)
         << QApplication::translate("MeasureWidget", "Perpen", Q_NULLPTR)
         << QApplication::translate("MeasureWidget", "Pix", Q_NULLPTR)
        );
        enableBtn->setText(QString());
        cancelBtn->setText(QApplication::translate("MeasureWidget", "cancel", Q_NULLPTR));
        clearBtn->setText(QApplication::translate("MeasureWidget", "clear", Q_NULLPTR));
        perdenBtn_4->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MeasureWidget: public Ui_MeasureWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASUREWIDGET_H
