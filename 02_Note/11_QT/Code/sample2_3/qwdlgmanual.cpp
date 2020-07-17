#include "qwdlgmanual.h"
#include <QDebug>
QWDlgManual::QWDlgManual(QWidget *parent)
    : QDialog(parent)
{
    iniUI();
    iniSignalSlots();
    setWindowTitle("Form created mannually手工创建");
}

QWDlgManual::~QWDlgManual()
{
}

void QWDlgManual::iniUI()
{
    //创建 Underline，Italic，Bold 3个CheckBox，并水平布局
    chkBoxUnder=new QCheckBox(tr("Underline"));
    chkBoxBold=new QCheckBox(tr("Bold"));
    chkBoxItalic=new QCheckBox(tr("Italic"));
    QHBoxLayout *HLay1=new QHBoxLayout;
    HLay1->addWidget(chkBoxUnder);
    HLay1->addWidget(chkBoxBold);
    HLay1->addWidget(chkBoxItalic);
    //创建 Black\Red\Blue 3个RadioButton，并水平布局
    rBtnBlack=new QRadioButton(tr("Black"));
    rBtnRed=new QRadioButton(tr("Red"));
    rBtnBlue=new QRadioButton(tr("Blue"));
    QHBoxLayout *HLay2=new QHBoxLayout;
    HLay2->addWidget(rBtnRed);
    HLay2->addWidget(rBtnBlue);
    HLay2->addWidget(rBtnBlack);
    //创建 确定、取消、退出 3个PushButton，并水平布局
    btnOK = new QPushButton(tr("确定"));
    btnCancel = new QPushButton(tr("取消"));
    btnClose = new QPushButton(tr("退出"));
    QHBoxLayout *HLay3=new QHBoxLayout;
    HLay3->addStretch();
    HLay3->addWidget(btnOK);
    HLay3->addStretch();
    HLay3->addWidget(btnCancel);
    HLay3->addStretch();
    HLay3->addWidget(btnClose);
    //创建 文本框并设置初始字体
    txtEdit=new QPlainTextEdit;
    txtEdit->setPlainText("Halo Totott\n手工创建");
    //创建 垂直布局并设置为主布局
    QVBoxLayout *VLay=new QVBoxLayout;
    VLay->addLayout(HLay1);
    VLay->addLayout(HLay2);
    VLay->addWidget(txtEdit);
    VLay->addLayout(HLay3);
    setLayout(VLay);
}

void QWDlgManual::iniSignalSlots()
{
    //三个颜色的QRadioButton的clicked()信号与setTextFontColor()槽函数关联
    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    //三个设置QCheckbox组件与对应的槽函数连接
    connect(chkBoxBold,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxBold(bool)));
    connect(chkBoxUnder,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxUnder(bool)));
    connect(chkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_chkBoxItalic(bool)));
    //三个按钮的信号与对应的槽函数连接
    connect(btnOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(btnCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(btnClose,SIGNAL(clicked()),this,SLOT(close()));
}

void QWDlgManual::on_chkBoxUnder(bool checked)
{
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
    qDebug("yes");
}

void QWDlgManual::on_chkBoxItalic(bool checked)
{
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxBold(bool checked)
{
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::setTextFontColor()
{
    QPalette plet=txtEdit->palette();
    if(rBtnRed->isChecked()){
        plet.setColor(QPalette::Text,Qt::red);
    }else if(rBtnBlue->isChecked()){
        plet.setColor(QPalette::Text,Qt::blue);
    }else if(rBtnBlack->isChecked()){
        plet.setColor(QPalette::Text,Qt::black);
    }
    txtEdit->setPalette(plet);
}

