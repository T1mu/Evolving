/********************************************************************************
** Form generated from reading UI file 'ToolBarWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOLBARWIDGET_H
#define UI_TOOLBARWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ToolBarWidget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QToolButton *openFileBtn;
    QToolButton *saveFileBtn;
    QFrame *line_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *paintCurveBtn;
    QToolButton *countNumBtn;
    QFrame *line_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *grayImgBtn;
    QToolButton *resultImgBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *ToolBarWidget)
    {
        if (ToolBarWidget->objectName().isEmpty())
            ToolBarWidget->setObjectName(QStringLiteral("ToolBarWidget"));
        ToolBarWidget->setEnabled(true);
        ToolBarWidget->resize(962, 50);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ToolBarWidget->sizePolicy().hasHeightForWidth());
        ToolBarWidget->setSizePolicy(sizePolicy);
        ToolBarWidget->setMinimumSize(QSize(472, 45));
        ToolBarWidget->setMaximumSize(QSize(16777215, 50));
        horizontalLayout_5 = new QHBoxLayout(ToolBarWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(ToolBarWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(40, 36));
        groupBox->setMaximumSize(QSize(70, 40));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        openFileBtn = new QToolButton(groupBox);
        openFileBtn->setObjectName(QStringLiteral("openFileBtn"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(openFileBtn->sizePolicy().hasHeightForWidth());
        openFileBtn->setSizePolicy(sizePolicy2);
        openFileBtn->setMinimumSize(QSize(25, 25));
        openFileBtn->setMaximumSize(QSize(25, 25));
        openFileBtn->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/imageHandle.png"), QSize(), QIcon::Normal, QIcon::Off);
        openFileBtn->setIcon(icon);

        horizontalLayout->addWidget(openFileBtn);

        saveFileBtn = new QToolButton(groupBox);
        saveFileBtn->setObjectName(QStringLiteral("saveFileBtn"));
        sizePolicy1.setHeightForWidth(saveFileBtn->sizePolicy().hasHeightForWidth());
        saveFileBtn->setSizePolicy(sizePolicy1);
        saveFileBtn->setMinimumSize(QSize(25, 25));
        saveFileBtn->setMaximumSize(QSize(25, 25));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/saveBtn.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveFileBtn->setIcon(icon1);

        horizontalLayout->addWidget(saveFileBtn);


        horizontalLayout_5->addWidget(groupBox);

        line_2 = new QFrame(ToolBarWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        groupBox_2 = new QGroupBox(ToolBarWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(40, 36));
        groupBox_2->setMaximumSize(QSize(70, 40));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, 3, 3, 3);
        paintCurveBtn = new QToolButton(groupBox_2);
        paintCurveBtn->setObjectName(QStringLiteral("paintCurveBtn"));
        sizePolicy1.setHeightForWidth(paintCurveBtn->sizePolicy().hasHeightForWidth());
        paintCurveBtn->setSizePolicy(sizePolicy1);
        paintCurveBtn->setMinimumSize(QSize(25, 25));
        paintCurveBtn->setMaximumSize(QSize(25, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/binary.png"), QSize(), QIcon::Normal, QIcon::Off);
        paintCurveBtn->setIcon(icon2);

        horizontalLayout_2->addWidget(paintCurveBtn);

        countNumBtn = new QToolButton(groupBox_2);
        countNumBtn->setObjectName(QStringLiteral("countNumBtn"));
        sizePolicy1.setHeightForWidth(countNumBtn->sizePolicy().hasHeightForWidth());
        countNumBtn->setSizePolicy(sizePolicy1);
        countNumBtn->setMinimumSize(QSize(25, 25));
        countNumBtn->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        countNumBtn->setIcon(icon3);
        countNumBtn->setPopupMode(QToolButton::DelayedPopup);
        countNumBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_2->addWidget(countNumBtn);


        horizontalLayout_5->addWidget(groupBox_2);

        line_3 = new QFrame(ToolBarWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_3);

        groupBox_3 = new QGroupBox(ToolBarWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMinimumSize(QSize(40, 36));
        groupBox_3->setMaximumSize(QSize(70, 40));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, 3, 3, 3);
        grayImgBtn = new QToolButton(groupBox_3);
        grayImgBtn->setObjectName(QStringLiteral("grayImgBtn"));
        sizePolicy1.setHeightForWidth(grayImgBtn->sizePolicy().hasHeightForWidth());
        grayImgBtn->setSizePolicy(sizePolicy1);
        grayImgBtn->setMinimumSize(QSize(25, 25));
        grayImgBtn->setMaximumSize(QSize(25, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/twoLayout.png"), QSize(), QIcon::Normal, QIcon::Off);
        grayImgBtn->setIcon(icon4);

        horizontalLayout_3->addWidget(grayImgBtn);

        resultImgBtn = new QToolButton(groupBox_3);
        resultImgBtn->setObjectName(QStringLiteral("resultImgBtn"));
        sizePolicy1.setHeightForWidth(resultImgBtn->sizePolicy().hasHeightForWidth());
        resultImgBtn->setSizePolicy(sizePolicy1);
        resultImgBtn->setMinimumSize(QSize(25, 25));
        resultImgBtn->setMaximumSize(QSize(25, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/width_center.png"), QSize(), QIcon::Normal, QIcon::Off);
        resultImgBtn->setIcon(icon5);
        resultImgBtn->setPopupMode(QToolButton::DelayedPopup);
        resultImgBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);

        horizontalLayout_3->addWidget(resultImgBtn);


        horizontalLayout_5->addWidget(groupBox_3);

        horizontalSpacer = new QSpacerItem(688, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        retranslateUi(ToolBarWidget);

        QMetaObject::connectSlotsByName(ToolBarWidget);
    } // setupUi

    void retranslateUi(QWidget *ToolBarWidget)
    {
        ToolBarWidget->setWindowTitle(QApplication::translate("ToolBarWidget", "ToolBarWidget", Q_NULLPTR));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        openFileBtn->setToolTip(QApplication::translate("ToolBarWidget", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        openFileBtn->setText(QApplication::translate("ToolBarWidget", "\346\211\223\345\274\200\346\226\207\344\273\266", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        saveFileBtn->setToolTip(QApplication::translate("ToolBarWidget", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        saveFileBtn->setText(QApplication::translate("ToolBarWidget", "\344\277\235\345\255\230\346\226\207\344\273\266", Q_NULLPTR));
        groupBox_2->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        paintCurveBtn->setToolTip(QApplication::translate("ToolBarWidget", "\345\257\271\346\257\224\345\272\246\350\260\203\346\225\264", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        paintCurveBtn->setText(QApplication::translate("ToolBarWidget", "\350\260\203\346\225\264", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        countNumBtn->setToolTip(QApplication::translate("ToolBarWidget", "\347\202\271\346\225\260", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        countNumBtn->setText(QApplication::translate("ToolBarWidget", "\347\202\271\346\225\260", Q_NULLPTR));
        groupBox_3->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        grayImgBtn->setToolTip(QApplication::translate("ToolBarWidget", "\346\230\276\347\244\272\347\201\260\345\272\246\345\233\276\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        grayImgBtn->setText(QApplication::translate("ToolBarWidget", "\346\230\276\347\244\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        resultImgBtn->setToolTip(QApplication::translate("ToolBarWidget", "\346\230\276\347\244\272\347\273\223\346\236\234\345\233\276\345\203\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        resultImgBtn->setText(QApplication::translate("ToolBarWidget", "\346\230\276\347\244\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ToolBarWidget: public Ui_ToolBarWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOLBARWIDGET_H
