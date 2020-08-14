#pragma once

#include <QtWidgets/QWidget>
#include "ui_XRayImgTest.h"
#include "canvas.h"
#include "dragchartsigleton.h"
#include "transparent.h"

class XRayImgTest : public QWidget
{
	Q_OBJECT

public:
	XRayImgTest(QWidget *parent = Q_NULLPTR);

	//初始化控件摆放位置
	void initUI();
	void initConnect();
private:
	Ui::XRayImgTestClass ui;
	canvas *canvs;
	dragChartSigleton *dragChart;
};
