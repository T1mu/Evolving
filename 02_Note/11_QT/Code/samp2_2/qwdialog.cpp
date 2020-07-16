#include "qwdialog.h"
#include "ui_qwdialog.h"

QWDialog::QWDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::QWDialog)
{
    ui->setupUi(this);
    connect(ui->rbtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rbtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(ui->rbtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

QWDialog::~QWDialog()
{
    delete ui;
}


void QWDialog::on_chkBoxUnder_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setUnderline(checked);
    ui->txtEdit->setFont(font);
}

void QWDialog::on_chkBoxItalic_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setItalic(checked);
    ui->txtEdit->setFont(font);
}

void QWDialog::on_chkBoxBold_clicked(bool checked)
{
    QFont font=ui->txtEdit->font();
    font.setBold(checked);
    ui->txtEdit->setFont(font);
}

void QWDialog::setTextFontColor()
{
    QPalette plet = ui->txtEdit->palette();
    if(ui->rbtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(ui->rbtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else if(ui->rbtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    ui->txtEdit->setPalette(plet);
}
