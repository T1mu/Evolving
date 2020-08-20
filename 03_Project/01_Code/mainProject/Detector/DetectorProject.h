#ifndef DETECTORPROJECT_H
#define DETECTORPROJECT_H


#include "detector_global.h"
#include <QObject>
#include "DexelaDetector.h"
#include "BusScanner.h"
#include "DexImage.h"
#include "DexelaException.h"
#include "CCycleBuffer.h"
#include <QDir>
#include <QDateTime>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
void myCallback(int fc, int buf, DexelaDetector* det);
void enqueue(char* buffer, int length);//��ջ



extern "C" DETECTOR_EXPORT void dequeue(char* buffer, int length);//��ջ
extern "C" DETECTOR_EXPORT void S_SetSaveTag(bool save);//��������
extern "C" DETECTOR_EXPORT void S_SetCorrectionOption(quint16 correctionOption);//У������
extern "C" DETECTOR_EXPORT void S_loadCorrectImage();//����




void readBufferLive(int fc, quint16 bufNum, DexelaDetector* m_det);//�����ɼ�����ȡÿһ֡
void correctImage(DexImage &input);//У��

struct CBdata
{
	std::string callbackString;
	int callbackInt;
	float callbackFloat;
};

class DETECTOR_EXPORT DetectorProject : public QObject
{
	Q_OBJECT

public:
	DetectorProject(QObject *parent=0);
	~DetectorProject();
	
	//��ѯ�豸����
	int enumerateDevices();
	
	//���õ�ǰ������ƽ��̽����
	int setDevice(int num = 0);
	
	//��̽����
	bool openDetector(int num = 0);
	//�رյ�ǰ̽����
	void closeDetector();
	//����̽����
	void initDetector();
	
	//�����ع�ʱ��/֡
	void setExposureTime(float exposureTime);
	
	//�����ع�ģʽ
	void setExposureMode(ExposureModes expMode);
	
	//ץͼ�����Զ�����̽�����ع�
	void snap(int buffer, int timeout);
	
	//��ȡָ���ڴ�����
	void readBuffer(int bufNum, quint16* buffer);

	//����pulse�ɼ�ģʽ
	void startPulseLive();
	//�ر�pulse�ɼ�ģʽ
	void stopPulseLive();


	//����sequence�����ɼ�ģʽ
	void startSequenceLive(int* p_startCount, int* p_exposures, float* exposure_time );
	//ֹͣsequence�����ɼ�ģʽ
	void stopSequenceLive();
	//��ȡ�����ɼ�ģʽ������
	void readSequenceBufferLive(int startCount, int exposures, quint16* buffer);
	//���ص�ǰ�������Ѿ������֡��
	int getFieldCount();
	
	bool isConnected();
	void checkForCallbackError();
	void checkForLiveError();

	void setDarkCorrection();
	void setFloodCorrection();
	void setDefectCorrection();
	void resetCorrection();


private:
	BusScanner m_scanner;//ƽ������
	DexelaDetector* m_det;//̽�������
	bool m_saveTag;//�Ƿ���������
	QDir d;

};

#endif // DETECTORPROJECT_H
