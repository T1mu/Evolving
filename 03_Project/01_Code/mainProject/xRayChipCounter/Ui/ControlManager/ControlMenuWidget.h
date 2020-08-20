#ifndef CONTROLMENUWIDGET_H
#define CONTROLMENUWIDGET_H

#include <QWidget>
#include "ui_ControlMenuWidget.h"
#include "MoveWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  
#include "../BllProject/BllDataFlow.h"
//#include "../../../BllProject/BllDetector/BllDetector.h"
#include "../../Library/MyHelper.h"

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>  


class ControlMenuWidget : public QWidget
{
	Q_OBJECT

public:
	ControlMenuWidget(QWidget *parent = 0);
	~ControlMenuWidget();
private slots:
	//void on_opendetectBtn_clicked();
	//void on_resetBtn_clicked();
	////void on_sequenceBtn_clicked();
	//void on_pulseBtn_clicked();
	//void on_saveBtn_clicked();

	//void on_captureBtn_clicked();
	//void returnSingleSlot();
	//void returnSequenceSlot();
	//void returnPluseSlot();

	//void on_darkCb_checked(int);
	//void on_floodCb_checked(int);
	//void on_defectCb_checked(int);

	//void datachanged(int);
private:
	Ui::ControlMenuWidget ui;
	bool detectopenEnable;
	bool pulseEnable;
	MoveWidget *m_move;
	BllDataFlow* m_blldataflow;
	//BllDetector* m_blldetector;
	
};

#endif // CONTROLMENUWIDGET_H
