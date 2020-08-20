#ifndef MAINWIDGETDISPLAY_H
#define MAINWIDGETDISPLAY_H

#include <QWidget>
#include <QFileDialog>
#include "ui_MainWidgetDisplay.h"
#include "../../BllProject/BllDataFlow.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>  
class MainWidgetDisplay : public QWidget
{
	Q_OBJECT
	public slots:
	void receiveTwoDimSlot();
	void receiveThreeDimSlot();
	void receiveMeasureSlot();
	void receivePaintSlot();
	void receiveAdjustSlot();
	void receiveHardwareSlot();
	void receiveFileSlot();
	void receiveDataSlot();
public:
	MainWidgetDisplay(QWidget *parent = 0);
	~MainWidgetDisplay();

private:
	Ui::MainWidgetDisplay ui;
	BllDataFlow* m_bllDataFlow;
	BllDetectorKZ* m_bll;
	cv::Mat srcimg;
};

#endif // MAINWIDGETDISPLAY_H
