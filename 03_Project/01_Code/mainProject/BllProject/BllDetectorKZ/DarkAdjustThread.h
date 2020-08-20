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
	void startThread();//开启线程
	void stopThread();//退出线程
	int getStatus();//获取停止标志位
	int getProgress();//获取当前进度值
private:
	DetectorProjectKZ* m_detectorKZ;
	int m_status = 0;//停止标志位
	int progressValue = 0;//当前进度值
};

#endif // DARKADJUSTTHREAD_H
