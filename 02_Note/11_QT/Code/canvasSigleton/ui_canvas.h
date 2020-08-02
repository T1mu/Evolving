/********************************************************************************
** Form generated from reading UI file 'canvas.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_canvas
{
public:
    QLabel *label;
    QPushButton *helpBtn;
    QLabel *ShortCutTipsLab;

    void setupUi(QWidget *canvas)
    {
        if (canvas->objectName().isEmpty())
            canvas->setObjectName(QStringLiteral("canvas"));
        canvas->resize(910, 910);
        label = new QLabel(canvas);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 890, 911, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QLatin1String("background-color: rgba(100, 100, 100, 200);\n"
"color: rgb(255, 255, 255, 250);"));
        helpBtn = new QPushButton(canvas);
        helpBtn->setObjectName(QStringLiteral("helpBtn"));
        helpBtn->setGeometry(QRect(860, 890, 51, 23));
        helpBtn->setStyleSheet(QLatin1String("background-color: rgba(147, 147, 147, 200);\n"
"color: rgba(255, 255, 255, 200);"));
        helpBtn->setCheckable(true);
        ShortCutTipsLab = new QLabel(canvas);
        ShortCutTipsLab->setObjectName(QStringLiteral("ShortCutTipsLab"));
        ShortCutTipsLab->setGeometry(QRect(680, 700, 231, 191));
        ShortCutTipsLab->setStyleSheet(QLatin1String("background-color: rgba(147, 147, 147, 200);\n"
"color: rgb(255, 255, 255, 200);"));

        retranslateUi(canvas);

        QMetaObject::connectSlotsByName(canvas);
    } // setupUi

    void retranslateUi(QWidget *canvas)
    {
        canvas->setWindowTitle(QApplication::translate("canvas", "canvas", Q_NULLPTR));
        label->setText(QApplication::translate("canvas", "TextLabel", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        helpBtn->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        helpBtn->setText(QApplication::translate("canvas", "Help", Q_NULLPTR));
        ShortCutTipsLab->setText(QApplication::translate("canvas", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\345\212\237\350\203\275\343\200\200\343\200\200               \343\200\200\343\200\200 \346\223\215\344\275\234</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">===============================</span>"
                        "</p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\347\274\251\346\224\276 \343\200\200\343\200\200           \343\200\200\343\200\200\346\273\232\345\212\250\346\273\232\350\275\256</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\347\247\273\345\212\250        ctrl\346\214\211\344\275\217\351\274\240\346\240\207\345\267\246\351\224\256\346\213\226\345\212\250</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\345\256\236\351\231\205\345\260\272\345\257\270\346\230\276\347\244\272          ctrl+\346\225\260\345\255\2270</span></p>\n"
"<p align=\"center\" style=\" margin-top:12px; margin-bottom:12px; margin-"
                        "left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">\346\201\242\345\244\215\345\210\235\345\247\213\346\230\276\347\244\272          ctrl+\346\225\260\345\255\2271</span><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class canvas: public Ui_canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
