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


//����ģʽ��ز���
struct modeParam{
	int picSize;//ͼ��ߴ�
	int modeIndex;//̽�������
	float pFrameRate;//֡��
	int pExposureTime;//�ع�ʱ��
	int nTrigType;//����ģʽ
	int nGainLevel;//����ȼ�
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
	int getProgress();					//��ȡ��ǰ����ֵ
	int getStatus();					//��ȡֹͣ��־λ
	CCallbackImp*  pCallback;
private:
	//QDir localD;//�ļ������
	const int cDETR_IDX = 1;			//̽�������
	const int cFRM_HEADER_SIZE = 64;	//У��
	int progressValue = 0;				//��ǰ����ֵ
	int m_status = 0;					//ֹͣ��־λ
	modeParam* modeParam;
};

#endif // DETECTORPROJECTKZ_H
