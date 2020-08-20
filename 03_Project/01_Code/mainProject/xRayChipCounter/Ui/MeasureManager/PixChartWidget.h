#ifndef PIXCHARTWIDGET_H
#define PIXCHARTWIDGET_H

#include <QWidget>
#include "ui_PixChartWidget.h"
#include "ImgPixChart.h"
class PixChartWidget : public QWidget
{
	Q_OBJECT

public:
	PixChartWidget(QWidget *parent = 0);
	~PixChartWidget();
	void updateChart(QVector<QPoint> vec);
private:
	Ui::PixChartWidget ui;
	ImgPixChart* m_chart;
};

#endif // PIXCHARTWIDGET_H
