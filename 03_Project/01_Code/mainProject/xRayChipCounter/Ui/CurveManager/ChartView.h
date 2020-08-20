#ifndef CHARTVIEW_H
#define CHARTVIEW_H
//#include <vector>;
//using namespace std;
#include <QChartView>
#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
//QSplineSeries
#include <QtCharts/QSplineSeries>
//QAreaSeries
#include <QtCharts/QAreaSeries>
#include <QtCharts/QScatterSeries>


#include "PointWidget.h"

//#include "../AdjustManager/AdjustWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"

using namespace QtCharts;



class ChartView : public QChartView
{
	Q_OBJECT

public:
	ChartView(QWidget *parent = 0);
	~ChartView();
	void pointsToline(QPointF p1, QPointF p2, double &k, double &c);
	void updaLinedata(QPointF);
	bool judgehoveredLine(QPointF);
	bool judgehoveredPoint(QPointF);
	void setCurve();
	void setPointMovelimit();
protected:

	virtual void mousePressEvent(QMouseEvent *event);

	virtual void mouseMoveEvent(QMouseEvent *event);

	virtual void mouseReleaseEvent(QMouseEvent *event);

private slots:
	void resetSlot();
	void pointmoveSlot();
	/*void openAdjustSlot();
	void closeAdjustSlot();*/

private:
	QLineSeries *seriesx;
	QLineSeries *seriesx2;
	QValueAxis *axisx;
	QValueAxis *axisy;
	QAreaSeries *areaSeries;
	QAreaSeries *areaSeries2;
	bool linemoveEnable;
	bool hoveredLine;
	QVector<QPointF> temp;
	int maxx;
	int minx;
	QPointF judge;
	BllDetectorKZ* m_bll;
	QVector<PointWidget*> vectPoint;
	int limit_up;
	int limit_down;
	int limit_left;
	int limit_right;
	//AdjustWidget* m_adjust;
};

#endif // CHARTVIEW_H
