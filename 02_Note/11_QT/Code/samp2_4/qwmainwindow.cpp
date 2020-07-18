#include "qwmainwindow.h"
#include "ui_qwmainwindow.h"
#include <QDebug>
QWMainWindow::QWMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QWMainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}

QWMainWindow::~QWMainWindow()
{
    delete ui;
}

void QWMainWindow::iniUI()
{
    fLabCurFile=new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusbar->addWidget(fLabCurFile);

    progressBar1=new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar1);

    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMaximumWidth(50);
    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体"));
    comboFont = new QFontComboBox;
    comboFont->setMaximumWidth(50);
    ui->toolBar->addWidget(comboFont);

    setCentralWidget(ui->txtEdit);
}

void QWMainWindow::iniSignalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),this,SLOT(on_spinFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
}

void QWMainWindow::on_actionbold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWindow::on_actionItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontItalic(checked);
    else
        fmt.setFontItalic(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}


void QWMainWindow::on_actionUnderLine_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWindow::on_txtEdit_copyAvailable(bool b)
{
    ui->actioncopy->setEnabled(b);
    ui->actionpaste->setEnabled(ui->txtEdit->canPaste());
}

void QWMainWindow::on_txtEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->txtEdit->currentCharFormat();
    ui->actionItalic->setChecked(fmt.fontItalic());
    ui->actionbold->setChecked(fmt.font().bold());
    ui->actionUnderLine->setChecked(fmt.fontUnderline());
}

void QWMainWindow::on_spinFontSize_valueChanged(int aFontSize)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);            //设置字体大小
    ui->txtEdit->mergeCurrentCharFormat(fmt);   //融合字体设置到txtEdit
    progressBar1->setValue(aFontSize);
}

void QWMainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);                    //设置字体
    ui->txtEdit->mergeCurrentCharFormat(fmt);   //融合字体设置到txtEdit
}
