#ifndef GRAYCURVECHART_H
#define GRAYCURVECHART_H

#include <QWidget>
#include <QDebug>
#include "ui_GrayCurveChart.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  
#include "../BllProject/BllDataFlow.h"
#include "../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class GrayCurveChart : public QWidget
{
	Q_OBJECT

public:
	GrayCurveChart(QWidget *parent = 0);
	~GrayCurveChart();
	private slots:
	void on_resetCurveBtn_clicked();
	void resetCurveEnableSlot(QString, QString);
private:
	Ui::GrayCurveChart ui;
	BllDetectorKZ* m_blldetector;
};

#endif // GRAYCURVECHART_H
