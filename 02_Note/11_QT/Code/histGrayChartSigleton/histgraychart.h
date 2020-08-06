#ifndef HISTGRAYCHART_H
#define HISTGRAYCHART_H

#include <QWidget>

namespace Ui {
class histGrayChart;
}

class histGrayChart : public QWidget
{
    Q_OBJECT

public:
    explicit histGrayChart(QWidget *parent = 0);
    ~histGrayChart();

private:
    Ui::histGrayChart *ui;
};

#endif // HISTGRAYCHART_H
