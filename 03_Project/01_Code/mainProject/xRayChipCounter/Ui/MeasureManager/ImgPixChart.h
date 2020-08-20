#ifndef IMGPIXCHART_H
#define IMGPIXCHART_H

#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
//QSplineSeries
#include <QtCharts/QSplineSeries>
//QAreaSeries
#include <QtCharts/QAreaSeries>
#include <QtCharts/QScatterSeries>
#include <Algorithm>
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
using namespace QtCharts;
using namespace std;
class ImgPixChart : public QChartView
{
	Q_OBJECT

public:
	ImgPixChart(QWidget *parent=0);
	~ImgPixChart();
	void updateCurve(QVector<QPoint> vec);
private:
	QLineSeries *seriesx;
	QValueAxis *axisx;
	QValueAxis *axisy;
	
};

#endif // IMGPIXCHART_H
