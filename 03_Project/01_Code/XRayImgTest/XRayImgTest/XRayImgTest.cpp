#include "XRayImgTest.h"

XRayImgTest::XRayImgTest(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}

void XRayImgTest::initUI()
{
	this->showFullScreen();
	canvs = new canvas(this);
	dragChart = new dragChartSigleton(this);
	canvs->show();
	dragChart->show();
	canvs->setGeometry(10, 10, canvs->width(), canvs->height());
	dragChart->setGeometry(canvs->pos().x() + canvs->width() + 10, canvs->pos().y(), dragChart->width(), dragChart->height());

}
