#ifndef ADJUSTWIDGET_H
#define ADJUSTWIDGET_H

#include <QWidget>
#include "ui_AdjustWidget.h"
#include "AdjustChart.h"
//#include "testWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"

class AdjustWidget : public QWidget
{
	Q_OBJECT

public:
	AdjustWidget(QWidget *parent = 0);
	~AdjustWidget();
	void deleteall();
private slots:
	void readyAdjustSlot(int);
private:
	Ui::AdjustWidget ui;
	AdjustChart* m_chart;
	BllDetectorKZ* m_bll;
	//testWidget* m_test;
};

#endif // ADJUSTWIDGET_H
