#ifndef DETECTORTHREAD_H
#define DETECTORTHREAD_H

#include <QThread>
#include <QMutex>
#include "../bllproject_global.h"

#include "CallbackImp.h"
#include "CareRayAPIDemo.h"
#include "CareRayAPIDll.h"
#include "ICallback.h"
#include "IntlMsgAliasID.h"
#include "stdafx.h"
#include "Structure.h"
#include "targetver.h"

#include "../../xRayChipCounter/Include/Global.h"
#include "../../Motor/MotorProject.h"
//#include "calibration.h"

#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/Motor.lib")
#else  
#pragma  comment(lib,"../x64/Release/Motor.lib")
#endif

#include <iostream>
#include "../opencv2/opencv.hpp"
#include "../opencv2/highgui/highgui.hpp"
#include "../opencv2/imgproc/imgproc.hpp"
#include "../opencv2/core/core.hpp"
#include <QDir>

using namespace cv;
using namespace std;


class BLLPROJECT_EXPORT DetectorThread : public QThread
{
	Q_OBJECT

public:
	DetectorThread(QObject *parent);
	~DetectorThread();
	void run();
	void setGoOn(bool on);	//设置循环读取标签

	void startThread(int, int, double, long, unsigned short, unsigned short, double);//开启线程
	void stopThread();		//退出线程
	void setSize(int, int);

	//单例
	static DetectorThread* instance()
	{
		static QMutex mutex;//只初始化一次，下次调用是上次的值
		if (!m_instance)
		{
			QMutexLocker locker(&mutex);
			if (!m_instance)
			{
				m_instance = new DetectorThread(NULL);
			}
		}
		return m_instance;
	}

signals:
	void sendImgSignal(int,int);
	void sendNumSignal(int);
	void sendStopSignal();
	void sendPaintGraySignal();
	void sendResetSignal();
	void sendAdjustSignal(int);

	void sendMatSignal(Mat);
	void sendCenterSignal(double *);

	void sendFirstCalibrationPicSignal(Mat);//显示第一张图

	void sendEachCalibrationPicSignal(Mat);//显示每张图

private:
	bool m_goOn;//继续标志
	QMutex mutex;//互斥锁
	int row;
	int col;
	int modeIdx;
	int picNum;
	double tgvel;
	long dist;
	QDir localD;
	QString temptime;
	QString modePath;
	MotorProject* m_motor;
	static DetectorThread* m_instance;

	int ifIsCorrectMode;

	double frame;
};

#endif // DETECTORTHREAD_H
