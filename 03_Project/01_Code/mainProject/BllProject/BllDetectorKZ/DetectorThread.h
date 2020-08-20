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
	void setGoOn(bool on);	//����ѭ����ȡ��ǩ

	void startThread(int, int, double, long, unsigned short, unsigned short, double);//�����߳�
	void stopThread();		//�˳��߳�
	void setSize(int, int);

	//����
	static DetectorThread* instance()
	{
		static QMutex mutex;//ֻ��ʼ��һ�Σ��´ε������ϴε�ֵ
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

	void sendFirstCalibrationPicSignal(Mat);//��ʾ��һ��ͼ

	void sendEachCalibrationPicSignal(Mat);//��ʾÿ��ͼ

private:
	bool m_goOn;//������־
	QMutex mutex;//������
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
