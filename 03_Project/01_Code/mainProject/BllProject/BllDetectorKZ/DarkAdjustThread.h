#ifndef DARKADJUSTTHREAD_H
#define DARKADJUSTTHREAD_H

#include <QThread>
#include "../bllproject_global.h"
#include "../../DetectorKZ/DetectorProjectKZ.h"

#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/DetectorKZ.lib")
#else  
#pragma  comment(lib,"../x64/Release/DetectorKZ.lib")
#endif

class BLLPROJECT_EXPORT DarkAdjustThread : public QThread
{
	Q_OBJECT

public:
	DarkAdjustThread(QObject *parent);
	~DarkAdjustThread();
	void run();
	void startThread();//�����߳�
	void stopThread();//�˳��߳�
	int getStatus();//��ȡֹͣ��־λ
	int getProgress();//��ȡ��ǰ����ֵ
private:
	DetectorProjectKZ* m_detectorKZ;
	int m_status = 0;//ֹͣ��־λ
	int progressValue = 0;//��ǰ����ֵ
};

#endif // DARKADJUSTTHREAD_H
