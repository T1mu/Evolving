#ifndef BLLDETECTORKZ_H
#define BLLDETECTORKZ_H

#include <QObject>
#include <QDir>
#include "DarkAdjustThread.h"
#include "../bllproject_global.h"
#include "../../DetectorKZ/DetectorProjectKZ.h"
#include "DetectorThread.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/DetectorKZ.lib")
#else  
#pragma  comment(lib,"../x64/Release/DetectorKZ.lib")
#endif



class BLLPROJECT_EXPORT BllDetectorKZ : public QObject
{
	Q_OBJECT
signals :
	void returnImgSignal(int, int);
	void updateSizeSignal(int);
	void returnModeParamSignal(float, int);
	void returnNumSignal(int);
	void returnStopSignal();
	void resetCurveSignal();
	void pointmoveSignal();
	void setLimitSignal(int, int, int, int);
	void lineMoveSignal(QVector<QPointF>);
	void resetCurveEnableSignal(QString, QString);
	void readyAdjustSignal(int);
	void readyAdjustpaintSignal(int, int);
	void returnPaintGraySignal();
	void returnResetSignal();
	void setLdataSignal(int);
	void setRdataSignal(int);
	void setMdataSignal(int);
	//void closeAdjustSignal();
	//void openAdjustSignal(int);
	void returnAdjustSignal(int);

public:

	static BllDetectorKZ* instance()
	{
		static QMutex mutex;//只初始化一次，下次调用是上次的值
		if (!m_instance) {
			QMutexLocker locker(&mutex);
			if (!m_instance) {
				m_instance = new BllDetectorKZ();
			}
		}
		return m_instance;
	}

	static quint16* getSingleImg()
	{
		static QMutex mutex;
		//ifSizeChange为true表示图像行列值已改变
		if (!m_img||ifSizeChange) {
			QMutexLocker locker(&mutex);
			if (!m_img) {
				m_img = new quint16[ImageSizeRow *ImageSizeCol]();
			}
			if (ifSizeChange){
				m_img = new quint16[ImageSizeRow *ImageSizeCol]();
				ifSizeChange = false;
			}
		}
		return m_img;
	}

	static void converToGray(quint16* inputImg, uchar* ucharImg, int windowWidth, int windowCenter)
	{
		for (int i = 0; i < ImageSizeRow * ImageSizeCol; i++)
		{
			ucharImg[i] = 0;
			if (inputImg[i] < (windowCenter - windowWidth / 2))
			{
				ucharImg[i] = 0;
			}
			else if (inputImg[i] >= (windowCenter - windowWidth / 2) && inputImg[i] <= (windowCenter + windowWidth / 2))
			{
				ucharImg[i] = (int)(255 / (double)windowWidth*(inputImg[i] + windowWidth / 2 - windowCenter));
			}
			else if (inputImg[i] >= (windowCenter + windowWidth / 2))
			{
				ucharImg[i] = 255;
			}
		}
	}

	bool connectBll();
	bool disconnectBll();
	bool setModeBll(int, float, int, int, int);
	static void setIfSizeChange()
	{
		ifSizeChange = true;
	}
	static void setImageSize(int row, int col)
	{
		ImageSizeRow = row;
		ImageSizeCol = col;
	}
	void startPulse(int, int, double, long, unsigned short, unsigned short, double);
	void stopPulse();
	static int returnSize()
	{
		return ImageSizeRow;
	}
	void updateSize(int);
	void resetCurve();
	void setLimit(int, int, int, int);
	void lineMove(QVector<QPointF>);
	void resetCurveEnable(QString, QString);
	void readyAdjust(int);
	void pointmove();
	void returnImg(int,int);
	void readyAdjustpaint(int, int);
	void setLdata(int);
	void setRdata(int);
	void setMdata(int);
	//void openAdjust(int);
	//void closeAdjust();
private:
	explicit BllDetectorKZ(QObject *parent = 0);
	~BllDetectorKZ();
	QDir localD;//文件夹相关
	static int ImageSizeRow;
	static int ImageSizeCol;
	static bool ifSizeChange;
	static quint16* m_img;
	static BllDetectorKZ* m_instance;
	DetectorProjectKZ* m_detectorKZ;
	DetectorThread* m_detectorThread;
};

#endif // BLLDETECTORKZ_H
