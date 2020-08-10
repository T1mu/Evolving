#include "widget.h"
#include "ui_widget.h"
#include "iostream"
#include <QDebug>
using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    testHist();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createCharts()
{
    QChartView *chartView = new QChartView(this);
    QChart *chart = new QChart();
    chart->setTitle(QString("灰度映射"));
    chartView->setChart(chart);
    chartView->setMinimumSize(this->width(),this->height());
    QLineSeries *series0 = new QLineSeries;
    series0->setName("Gray");
    chart->addSeries(series0);
    series0->append(*m_begin);
    series0->append(*m_end);

    QValueAxis *axisX = new QValueAxis;//x轴
    axisX->setRange(0,65535);
    axisX->setTickCount(9);
    axisX->setTitleText("GrayValue");

    QValueAxis *axisY = new QValueAxis;//y轴
    axisY->setRange(0,255);

    axisY->setTitleText("GrayValue");

    chart->setAxisX(axisX,series0);
    chart->setAxisY(axisY,series0);
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);				//抗锯齿和使用平滑转换算法

    painter.setPen(QPen(Qt::black, 1));                                                             //设置画笔形式
    painter.drawRect(10, 10, 340, 140);                                                             //初始化坐标信息
    painter.drawText(3, 157, QString("0"));
    painter.drawText(355, 157, QString("65535"));
    painter.drawText(0, 8, QString("255"));

    float *pt=hist.ptr<float>(0);
    for(int i = 0;i<=330;++i){
        if(pt[i]<0)
            pt[i]=0;
        painter.drawLine(10+i,150,10+i,150-pt[i]*130/637433);
    }
}

void Widget::testHist()
{
    //0表示将图像转换为灰度再返回
    Mat srcImage = imread("D:\\2020.6.3\\xRayChipCounter\\mode2\\2020-06-08_09-52-29\\37.tif",
                          CV_LOAD_IMAGE_UNCHANGED);
    hist = mat2Hist(srcImage);
    //Mat dstImage(size, size, CV_8U, Scalar(0));
    //获取最大值和最小值
    double minValue = 0;
    double maxValue = 0;
    minMaxLoc(hist,&minValue, &maxValue, 0, 0);  //  在cv中用的是cvGetMinMaxHistValue
    qDebug()<<"maxValue:"<<maxValue;
    qDebug()<<"size:"<<hist.rows;
    float* pt = hist.ptr<float>(0);
    qDebug()<<pt[0];
//    for(int i = 0;i<=10 ;i++){
//        qDebug()<<pt[i];
//    }
    //绘制出直方图
    //saturate_cast函数的作用即是：当运算完之后，结果为负，则转为0，结果超出255，则为255。
//    int hpt = saturate_cast<int>(0.9 * size);
//    for(int i = 0; i < 340; i++)
//    {
//        float binValue = hist.at<float>(i);           //   注意hist中是float类型
//        //拉伸到0-max
//        int realValue = saturate_cast<int>(binValue * hpt/maxValue);
//        line(dstImage,Point(i, size - 1),Point(i, size - realValue),Scalar(255));
//    }
//    imshow("1D", dstImage);
//    waitKey(0);
}

Mat Widget::mat2Hist(const Mat &src)
{
    if(!src.data) {
        cout << "fail to load image" << endl;
    }
    //定义变量
    Mat dstHist ;
    int dims = 1;
    float hranges[] = {0, 65536};
    const float *ranges[] = {hranges};   // 这里需要为const类型
    int size = 330;
    int channels = 0;
    //计算图像的直方图
    calcHist(&src, 1, &channels, Mat(), dstHist, dims, &size, ranges);
    return dstHist;
}


