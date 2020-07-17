#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QLayout>
#include <QPushButton>
class QWDlgManual : public QDialog
{
    Q_OBJECT

public:
    QWDlgManual(QWidget *parent = nullptr);
    ~QWDlgManual();
private:

    QCheckBox *chkBoxUnder;
    QCheckBox *chkBoxItalic;
    QCheckBox *chkBoxBold;
    QRadioButton *rBtnBlack;
    QRadioButton *rBtnRed;
    QRadioButton *rBtnBlue;
    QPlainTextEdit *txtEdit;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QPushButton *btnClose;          //声明各个组件的指针变量

    void iniUI();                   //因为没有自动生成form，所以要手动创建所有界面组件
    void iniSignalSlots();          //完成信号和槽函数的关联
private slots:
    void on_chkBoxUnder(bool checked);
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    void setTextFontColor();
};
#endif // QWDLGMANUAL_H
