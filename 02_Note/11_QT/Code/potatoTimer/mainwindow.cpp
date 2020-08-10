#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUi();
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::iniUi()
{
    statuWorkTimeLab = new QLabel(("工作时间:"),this);
    statuSleepTimeLab = new QLabel(("休息时间:"),this);
    statuRemainTimeLab = new QLabel(("剩余时间:"),this);
    ui->statusbar->addWidget(statuSleepTimeLab);
    ui->statusbar->addWidget(statuWorkTimeLab);
    ui->statusbar->addWidget(statuRemainTimeLab);
}

