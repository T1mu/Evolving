#ifndef HISTGRAYCHART_H
#define HISTGRAYCHART_H

#include <QWidget>
#include <QtCharts>
#include <QChartView>
#include <opencv.hpp>
#include <opencv2/opencv.hpp>
#include <QMessageBox>

#pragma execution_character_set("utf-8")

namespace Ui {
class histGrayChart;
}

using namespace QtCharts;
using namespace cv;

class histGrayChart : public QWidget
{
    Q_OBJECT

public:
    explicit histGrayChart(QWidget *parent = 0);
    ~histGrayChart();
    void initChart();

    //Mat接口
    void setMat(const Mat &mat);
    void setMat(const QString &path);

    //Mat getHist(const Mat &mat);        //计算直方图Mat并返回

private:
    Ui::histGrayChart *ui;
    Mat m_src_Mat;

};

#endif // HISTGRAYCHART_H
