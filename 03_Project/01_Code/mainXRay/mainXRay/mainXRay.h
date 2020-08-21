#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainXRay.h"
#include "../ui/canvas.h"
#include "../ui/dragchartsigleton.h"
#include "../ui/transparent.h"
#include "../ui/motorControl.h"
class mainXRay : public QMainWindow
{
	Q_OBJECT

public:
	mainXRay(QWidget *parent = Q_NULLPTR);
	//初始化控件摆放位置
	void initUI();
	void initConnect();


private:
	Ui::mainXRayClass ui;
	canvas *m_canvs;
	dragChartSigleton *m_dragChart;
	motorControl *m_motorControl;
};
