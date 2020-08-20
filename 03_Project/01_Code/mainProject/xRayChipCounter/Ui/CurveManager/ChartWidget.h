#ifndef CHARTWIDGET_H
#define CHARTWIDGET_H

#include <QWidget>
#include "ui_ChartWidget.h"
#include "ChartView.h"

#include "../AdjustManager/AdjustWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDataFlow.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class ChartWidget : public QWidget
{
	Q_OBJECT

public:
	ChartWidget(QWidget *parent = 0);
	~ChartWidget();
private slots:
	void readyGrayCurveSlot();
	void openAdjustSlot(int);
	void closeAdjustSlot();
private:
	Ui::ChartWidget ui;
	BllDataFlow* m_blldata;
	BllDetectorKZ* m_bll;
	ChartView* m_chart;
	AdjustWidget* m_adjust;

};

#endif // CHARTWIDGET_H
