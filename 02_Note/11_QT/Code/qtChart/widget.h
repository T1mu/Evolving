#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtCharts>
#include <QPaintEvent>
#include <opencv.hpp>
#include <opencv2/opencv.hpp>

//实现 灰度图
using namespace QtCharts;
using namespace cv;
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void createCharts();
    void paintEvent(QPaintEvent *event);
    void testHist();
    Mat mat2Hist(const Mat &src);
private:
    Mat m_HistMat;
    Ui::Widget *ui;
    QPointF *m_begin=new QPointF(0,0);
    QPointF *m_end=new QPointF(65535,255);
    Mat hist;
};

#endif // WIDGET_H
