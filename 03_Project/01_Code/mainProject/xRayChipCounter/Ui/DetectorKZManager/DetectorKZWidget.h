#ifndef DETECTORKZWIDGET_H
#define DETECTORKZWIDGET_H

#include <QWidget>
#include <QMessageBox>
#include "ui_DetectorKZWidget.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#include "../../BllProject/BllDataFlow.h"
#include "DarkAdjustBar.h"
#include "GainAdjustBar.h"

//#include "../Library/MyHelper.h"
//#include "../dealimage/dealimage.h"
#include "ImageCorrect.h"

//#include "../../BllProject/BllMotor/BllMotor.h"
#include <qdebug.h>
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
#pragma execution_character_set("utf-8")

class DetectorKZWidget : public QWidget
{
	Q_OBJECT
	public slots:
	void frameLimitSlot();
	void on_connectDetectorBtn_clicked();
	void on_setModeBtn_clicked();
	void on_darkAdjustBtn_clicked();
	void on_gainAdjustBtn_clicked();
	void on_getPicBtn_clicked();
	//void on_stopGetPicBtn_clicked();
	void on_startPulseBtn_clicked();
	void on_stopPulseBtn_clicked();
	void receiveModeParamSlot(float,int);
	void receiveNumSlot(int);
	void receiveStopSlot();
	//void dealcurrentIndexChanged(int);
	void dealvalueChanged(double);


public:
	DetectorKZWidget(QWidget *parent = 0);
	~DetectorKZWidget();

private:
	Ui::DetectorKZWidget ui;
	BllDetectorKZ* m_bllDetectorKZ;
	BllDataFlow* m_bllDataFlow;
	DarkAdjustBar* m_darkAdjustBar;
	GainAdjustBar* m_gainAdjustBar;
	const int cDETR_INX = 1;//探测器编号
	const int cFRM_HEADER_SIZE = 64;//校验
	//dealimage image;
	ImageCorrect *calibrationUI;

	//标志位
	int setModeBtnFlag = 0;
	int connectDetectorBtnFlag = 0;
	MotorProject *m_motor;

};

#endif // DETECTORKZWIDGET_H
