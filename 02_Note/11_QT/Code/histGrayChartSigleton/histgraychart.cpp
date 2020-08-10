#include "histgraychart.h"
#include "ui_histgraychart.h"

histGrayChart::histGrayChart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::histGrayChart)
{
    ui->setupUi(this);
    initChart();
    setMat("C:\\28.tif");
    //Mat hist = getHist(m_src_Mat);
}

histGrayChart::~histGrayChart()
{
    delete ui;
}

void histGrayChart::initChart()
{
    QChartView *chartView=new QChartView(this);
    chartView->setMinimumSize(this->size());
    QChart *chart = new QChart();
    chart->setTitle("灰度直方图");
    chartView->setChart(chart);
    chartView->setRubberBand(QChartView::RectangleRubberBand);

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    series0->setName("Sin");
    series1->setName("Cos");
    chart->addSeries(series0);
    chart->addSeries(series1);

    qreal t=0,y1,y2,intv=0.1;
    int cnt = 100;
    for(int i=0;i<cnt;i++){
        y1=qSin(t);
        series0->append(t,y1);
        y2=qSin(t+20);
        series1->append(t,y2);
        t+=intv;
    }

    QValueAxis *axisX = new QValueAxis;
    axisX->setRange(0,10);
    axisX->setTitleText("time(secs)");

    QValueAxis *axisY = new QValueAxis;
    axisY->setRange(-2,2);
    axisY->setTitleText("value");

    chart->setAxisX(axisX,series0);
    chart->setAxisY(axisY,series0);
    chart->setAxisX(axisX,series1);
    chart->setAxisY(axisY,series1);
}

void histGrayChart::setMat(const Mat &mat)
{
    if (!mat.data)
    {
        QMessageBox mesg;
        mesg.warning(this, "histGrayChart::setMat SetMat_WARNING", "mat.data is EMPTY!");
    }else{
        m_src_Mat = mat;
    }
}

void histGrayChart::setMat(const QString &path)
{
    Mat mat =imread(path.toStdString(), CV_LOAD_IMAGE_UNCHANGED);
    if (!mat.data)
    {
        QMessageBox mesg;
        mesg.warning(this, "histGrayChart::setMat SetMat_WARNING", "mat.data is EMPTY!");
    }else{
        m_src_Mat = mat;
    }
}





