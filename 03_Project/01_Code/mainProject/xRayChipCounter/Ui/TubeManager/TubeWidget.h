#ifndef TUBEWIDGET_H
#define TUBEWIDGET_H

#include <QWidget>
#include <windows.h>
#include "ui_TubeWidget.h"

#include "qpixmap.h"
#include "qserialportinfo.h"
#include "qserialport.h"
#include "../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
class TubeWidget : public QWidget
{
	Q_OBJECT

	public slots:
	void on_clearBtn_clicked();
	void on_connectBtn_clicked();
	void on_modeSetBtn_clicked();
	void on_openXRayBtn_clicked();
	void on_closeXRayBtn_clicked();
	void on_queryBtn_clicked();
	void Read_Data();
public:
	TubeWidget(QWidget *parent = 0);
	~TubeWidget();
	static QSerialPort* m_serialport()
	{
		static QMutex mutex;//只初始化一次，下次调用是上次的值
		if (!serialPort)
		{
			QMutexLocker locker(&mutex);
			if (!serialPort)
			{
				serialPort = new QSerialPort();
			}
		}
		return serialPort;
	}
	void checkSerialPort();
   
private:
	Ui::TubeWidget ui;
	static QSerialPort *serialPort;
	QByteArray bufTemp;
	QByteArray buf1;
	QByteArray buf2;
	int lsize = 0;
	QString serialPortName[5];
	bool ifCon = true;
	QString filename1 = "./icon/OpenXRay.png";
	QString filename2 = "./icon/CloseXRay.png";
	QString filename3 = "./icon/StandbyON.ico";
	QString filename4 = "./icon/StandbyOFF.ico";
	QImage *img = new QImage();
	QImage *img2 = new QImage();
	BllDataFlow* m_bllDataFlow;
	bool connectFlag;//判断串口是否连接
	
};

#endif // TUBEWIDGET_H
