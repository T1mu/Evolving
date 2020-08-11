#ifndef DRAGCHARTSIGLETON_H
#define DRAGCHARTSIGLETON_H

#include <QWidget>
#include <QtCharts/QtCharts>
#include <QDebug>
#include "transparent.h"

using namespace QtCharts;
namespace Ui {
class dragChartSigleton;
}
struct axisInfo{
    int minX;
    int maxX;
    int minY;
    int maxY;
};

class dragChartSigleton : public QWidget
{
    Q_OBJECT

public:
    explicit dragChartSigleton(QWidget *parent = 0);
    ~dragChartSigleton();
    void initChart();
    //接口:设置图标横纵坐标轴的范围
    void setAxisRange(const qreal Xmin,
                      const qreal Xmax,
                      const qreal Ymin,
                      const qreal Ymax);
private:
    Ui::dragChartSigleton *ui;
    //
    Transparent* trans;
    //图标相关
    QChart *chart;
    QChartView *view;
    QValueAxis* axisX;
    QValueAxis* axisY;

};

#endif // DRAGCHARTSIGLETON_H
