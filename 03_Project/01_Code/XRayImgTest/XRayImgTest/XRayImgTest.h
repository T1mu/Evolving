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

	//��ʼ���ؼ��ڷ�λ��
	void initUI();
private:
	Ui::XRayImgTestClass ui;
	canvas *canvs;
	dragChartSigleton *dragChart;
};
