#ifndef DETECTORPROJECTKZ_H
#define DETECTORPROJECTKZ_H

#include <QObject>
#include <qdebug.h>
#include "detectorkz_global.h"
#include "Windows.h"
#include "CallbackImp.h"
#include "CareRayAPIDemo.h"
#include "CareRayAPIDll.h"
#include "ICallback.h"
#include "IntlMsgAliasID.h"
#include "stdafx.h"
#include "Structure.h"
#include "targetver.h"


//工作模式相关参数
struct modeParam{
	int picSize;//图像尺寸
	int modeIndex;//探测器编号
	float pFrameRate;//帧率
	int pExposureTime;//曝光时间
	int nTrigType;//触发模式
	int nGainLevel;//增益等级
};

class DETECTORKZ_EXPORT DetectorProjectKZ : public QObject
{
	Q_OBJECT
signals:
	void sendModeParamSignal(float , int);
public:
	DetectorProjectKZ(QObject *parent);
	~DetectorProjectKZ();
	int connectKZ();
	int disconnectKZ();
	int setModeKZ(int,float,int,int,int);
	void darkAdjustKZ();
	void gainAdjustKZ();
	int getProgress();					//获取当前进度值
	int getStatus();					//获取停止标志位
	CCallbackImp*  pCallback;
private:
	//QDir localD;//文件夹相关
	const int cDETR_IDX = 1;			//探测器编号
	const int cFRM_HEADER_SIZE = 64;	//校验
	int progressValue = 0;				//当前进度值
	int m_status = 0;					//停止标志位
	modeParam* modeParam;
};

#endif // DETECTORPROJECTKZ_H
