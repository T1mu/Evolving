#include "histgraychart.h"
#include "ui_histgraychart.h"

histGrayChart::histGrayChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::histGrayChart)
{
    ui->setupUi(this);
}

histGrayChart::~histGrayChart()
{
    delete ui;
}
