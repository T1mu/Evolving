#include "dragchartsigleton.h"
#include "ui_dragchartsigleton.h"

dragChartSigleton::dragChartSigleton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dragChartSigleton)
{
    ui->setupUi(this);
    chart = new QChart();
    view = new QChartView(chart,this);
    view->setFixedSize(this->size());
    initChart();

    trans = new Transparent(this);
    trans->setFixedSize(this->size());
}

dragChartSigleton::~dragChartSigleton()
{
    delete ui;
}

void dragChartSigleton::initChart()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
    axisX=new QValueAxis();
    axisY=new QValueAxis();
    axisX->setLabelFormat("%.0f");
    axisY->setLabelFormat("%.0f");
    axisX->setRange(0,65535);
    axisY->setRange(0,255);
    axisX->setTickCount(8);
    axisX->setMinorTickCount(5);
    axisY->setMinorTickCount(1);
    chart->setAxisX(axisX);
    chart->setAxisY(axisY);
    chart->setContentsMargins(-30,-40,-30,-30);
}

void dragChartSigleton::setAxisRange(const qreal Xmin, const qreal Xmax, const qreal Ymin, const qreal Ymax)
{
    if(Xmin<Xmax)
        axisX->setRange(Xmin, Xmax);
    if(Ymin<Ymin)
        axisY->setRange(Ymin, Ymax);
}



