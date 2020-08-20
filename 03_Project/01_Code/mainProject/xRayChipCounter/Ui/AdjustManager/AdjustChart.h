#ifndef ADJUSTCHART_H
#define ADJUSTCHART_H

#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
//QSplineSeries
#include <QtCharts/QSplineSeries>
//QAreaSeries
#include <QtCharts/QAreaSeries>
#include <QtCharts/QScatterSeries>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/core/core.hpp> 
//#include <vector>;
//#include "blldata.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"

#include <QVector>
#include "LWidget.h"
#include "RWidget.h"
#include "MWidget.h"
//using namespace std;
//using namespace cv;
using namespace QtCharts;

class AdjustChart : public QChartView
{
	Q_OBJECT

public:
	AdjustChart(QWidget *parent=0);
	~AdjustChart();
	void setCurve(int);
	void setLineHeight();
	void transPos(int l, int r);
private slots:
	void LmoveSlot(int);
	void RmoveSlot(int);
	void MmoveSlot(int);
private:
	QLineSeries *seriesx;
	//QLineSeries *seriesx2;
	QValueAxis *axisx;
	QValueAxis *axisy;
	QAreaSeries *areaSeries;
	//QChart* chart;
	int maxx;
	int minx;
	BllDetectorKZ* m_bll;
	int up;
	int down;
	int left;
	int right;
	int lineHight;
	/*LWidget *ll;
	RWidget *rr;
	MWidget *mm;*/
	int countp;

	QVector<LWidget*> vecl;
	QVector<RWidget*> vecr;
	QVector<MWidget*> vecm;
};

#endif // ADJUSTCHART_H
