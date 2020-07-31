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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_canvas
{
public:
    QLabel *label;

    void setupUi(QWidget *canvas)
    {
        if (canvas->objectName().isEmpty())
            canvas->setObjectName(QStringLiteral("canvas"));
        canvas->resize(910, 910);
        label = new QLabel(canvas);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 890, 911, 20));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QLatin1String("background-color: rgba(0, 0, 0, 100);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(canvas);

        QMetaObject::connectSlotsByName(canvas);
    } // setupUi

    void retranslateUi(QWidget *canvas)
    {
        canvas->setWindowTitle(QApplication::translate("canvas", "canvas", Q_NULLPTR));
        label->setText(QApplication::translate("canvas", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class canvas: public Ui_canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
