#ifndef COMMONDEVICE_H
#define COMMONDEVICE_H

#include <QWidget>
#include "ui_CommonDevice.h"
#include "../../BllProject/BllDataFlow.h"
#include "../../BllProject/BllMotor/BllMotor.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "qserialport.h"

#pragma execution_character_set("utf-8")
class CommonDevice : public QWidget
{
	Q_OBJECT
	public slots:
	void on_stopBtn_clicked();
	void on_openXRayBtn_clicked();
	void on_closeXRayBtn_clicked();
	void getVASlot(int,int);
	void getSerialSlot(QSerialPort*,bool);

	void on_zNegativeBtn_clicked();
	void on_zPositiveBtn_clicked();

	void on_startPulseBtn_clicked();
	void on_stopPulseBtn_clicked();
	void on_getPicBtn_clicked();
	void getDetectorSetSlot(int,int,int,int);
	void getDetectorParamSlot(int, float, int, int, int, float, float);
public:
	CommonDevice(QWidget *parent = 0);
	~CommonDevice();


private:
	Ui::CommonDevice ui;
	QString filename1 = "./icon/OpenXRay.png";
	QString filename2 = "./icon/CloseXRay.png";
	QString filename3 = "./icon/StandbyON.ico";
	QString filename4 = "./icon/StandbyOFF.ico";
	QImage *img = new QImage();
	QImage *img2 = new QImage();
	int voltage = 0;
	int current = 0;

	IMC_HANDLE g_handle;//Íø¿¨¾ä±ú
	int g_naxis;//¿ØÖÆ¿¨ÖáÊý
	bool connectMotorFlag;//ÅÐ¶ÏÊÇ·ñÁ¬½ÓÍø¿¨
	BllMotor* m_bllMotor;
	BllDataFlow* m_bllDataFlow;
	BllDetectorKZ* m_bllDetectorKZ;

	bool connectDetectorFlag;
	int detectorGetPicModeIndex;
	int detectroPicNum;
	int detectorMin;
	int detectorMax;


};

#endif // COMMONDEVICE_H
