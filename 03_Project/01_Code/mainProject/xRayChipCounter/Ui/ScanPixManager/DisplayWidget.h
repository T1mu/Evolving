#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QWidget>
#include "ui_DisplayWidget.h"
#include "../BllProject/BllDataFlow.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>  
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  
using namespace cv;
class DisplayWidget : public QWidget
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = 0);
	~DisplayWidget();
	void iniData();
private slots:
	void setMulSlot(int);
	void returnPosSlot(QPoint);
	void getPosPixEnableSlot(bool);
protected:
	virtual void resizeEvent(QResizeEvent * event);
	virtual void  paintEvent(QPaintEvent* event);
private:
	Ui::DisplayWidget ui;
	int m_mul;
	BllDataFlow* m_bllDataFlow;
	QImage m_imgdata;
	Mat m_srcdata;
	QImage m_img;
	QPoint m_tempP;
	QPoint m_top;
	QPoint m_bottom;
};

#endif // DISPLAYWIDGET_H
