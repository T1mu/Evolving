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
void enqueue(char* buffer, int length);//进栈



extern "C" DETECTOR_EXPORT void dequeue(char* buffer, int length);//出栈
extern "C" DETECTOR_EXPORT void S_SetSaveTag(bool save);//连续保存
extern "C" DETECTOR_EXPORT void S_SetCorrectionOption(quint16 correctionOption);//校正类型
extern "C" DETECTOR_EXPORT void S_loadCorrectImage();//载入




void readBufferLive(int fc, quint16 bufNum, DexelaDetector* m_det);//连续采集，读取每一帧
void correctImage(DexImage &input);//校正

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
	
	//查询设备数量
	int enumerateDevices();
	
	//设置当前可以用平板探测器
	int setDevice(int num = 0);
	
	//打开探测器
	bool openDetector(int num = 0);
	//关闭当前探测器
	void closeDetector();
	//配置探测器
	void initDetector();
	
	//设置曝光时间/帧
	void setExposureTime(float exposureTime);
	
	//设置曝光模式
	void setExposureMode(ExposureModes expMode);
	
	//抓图，并自动触发探测器曝光
	void snap(int buffer, int timeout);
	
	//读取指定内存数据
	void readBuffer(int bufNum, quint16* buffer);

	//开启pulse采集模式
	void startPulseLive();
	//关闭pulse采集模式
	void stopPulseLive();


	//开启sequence连续采集模式
	void startSequenceLive(int* p_startCount, int* p_exposures, float* exposure_time );
	//停止sequence连续采集模式
	void stopSequenceLive();
	//读取连续采集模式的数据
	void readSequenceBufferLive(int startCount, int exposures, quint16* buffer);
	//返回当前缓冲区已经捕获的帧数
	int getFieldCount();
	
	bool isConnected();
	void checkForCallbackError();
	void checkForLiveError();

	void setDarkCorrection();
	void setFloodCorrection();
	void setDefectCorrection();
	void resetCorrection();


private:
	BusScanner m_scanner;//平板驱动
	DexelaDetector* m_det;//探测器句柄
	bool m_saveTag;//是否连续保存
	QDir d;

};

#endif // DETECTORPROJECT_H
