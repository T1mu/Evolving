#include "PixChartWidget.h"

PixChartWidget::PixChartWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_chart = new ImgPixChart();
	ui.h1->addWidget(m_chart);
}

PixChartWidget::~PixChartWidget()
{

}
void PixChartWidget::updateChart(QVector<QPoint> vec){
	m_chart->setEnabled(true);
	m_chart->updateCurve(vec);
}