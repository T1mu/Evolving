#include "dragchartsigleton.h"
#include "ui_dragchartsigleton.h"

dragChartSigleton::dragChartSigleton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dragChartSigleton)
{
    ui->setupUi(this);
}

dragChartSigleton::~dragChartSigleton()
{
    delete ui;
}
