#ifndef BLLDATAFLOW_H
#define BLLDATAFLOW_H

#include <QObject>
#include <QDialog>
#include "bllproject_global.h"
#include "../xRayChipCounter/Library/Global.h"
#include <QPoint>
#include <QVector>
#include <QPointF>
#include <QMap>
#include <omp.h> 
#include <QDebug>
#include <QSerialPort>
//#include <vector>
//using namespace std;

class BLLPROJECT_EXPORT BllDataFlow : public QObject
{
	Q_OBJECT

public:
	explicit BllDataFlow(QObject *parent=0);
	~BllDataFlow();
	//窗宽
	int m_grayWidth;
	//窗位
	int m_grayCenter;
	//点数结果
	int m_resultNum;
	//多帧图像数据
	static qint16* multiImg;
	static int multiImg_SizeRow;
	static int multiImg_SizeCol;
	static int multiImg_Num;
	static bool ifSizeChange;

private:

	//单例化类
	static BllDataFlow* m_instance;
	//原始图像数据
	static quint16* m_img;
	//点数结果图像
	static uchar* m_resultImg;

	static int SizeRow;
	static int SizeCol;

	bool m_bllMotorFlag;
	bool m_bllDetectorFlag;
	//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
	int zoomMul;
	bool zoomFlag;
	//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++

public:
	static BllDataFlow* instance()
	{
		static QMutex mutex;
		if (!m_instance) {
			QMutexLocker locker(&mutex);
			if (!m_instance) {
				m_instance = new BllDataFlow();
			}
		}
		return m_instance;
	}

	//设置多帧图像大小
	static void setMultiImgSize(int row, int col ,int num)
	{
		multiImg_SizeRow = row;
		multiImg_SizeCol = col;
		multiImg_Num = num;
	}
	//图像大小改变
	static void setIfSizeChange()
	{
		ifSizeChange = true;
	}

	static qint16* getMultiImg()
	{
		static QMutex mutex;
		//ifSizeChange为true表示图像行列值已改变
		if (!multiImg || ifSizeChange)
		{
			QMutexLocker locker(&mutex);
			if (!multiImg)
			{
				multiImg = new qint16[multiImg_SizeRow * multiImg_SizeCol * multiImg_Num]();
			}
			if (ifSizeChange)
			{
				multiImg = new qint16[multiImg_SizeRow * multiImg_SizeCol * multiImg_Num]();
				ifSizeChange = false;
			}
		}

		return multiImg;
	}

	static void setImageSize(int row, int col)
	{
		SizeRow = row;
		SizeCol = col;
	}

	//窗宽窗位调整
	static void converToGray(quint16* inputImg, uchar* ucharImg, int windowWidth, int windowCenter)
	{
		for (int i = 0; i < SizeRow * SizeCol; i++)
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
	//窗宽窗位调整（三维切片）
	static void converToGrayTest(qint16* inputImg, uchar* ucharImg, int windowWidth, int windowCenter)
	{
		for (int i = 0; i < multiImg_SizeRow * multiImg_SizeCol; i++)
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
	//将16位原始图像转换成8位灰度图像(三维切片)
	static void converTo8bitGrayimgTest(qint16* inputImg, uchar* ucharImg)
	{
		for (int i = 0; i < 512 * 512; i++)
		{
			ucharImg[i] = 0;
			ucharImg[i] = (int)(inputImg[i] / 255);

		}
	}
	
   //将16位原始图像转换成8位灰度图像
	static void converTo8bitGrayimg(quint16* inputImg, uchar* ucharImg)
	{
		for (int i = 0; i < SizeRow * SizeCol; i++)
		{
			ucharImg[i] = 0;
			ucharImg[i] = (int)(inputImg[i] / 255);

		}
	}

	//灰度曲线调整
	static void moveTochangeGrayImg(quint16* inputImg, uchar* ucharImg, QVector<QPointF> vec)
	{

		int xmin = vec[0].x();
		int size = vec.size();
		int xmax = vec[size - 1].x();

		int setX[20];
		int setY[20];
		int setValue[65535];
		for (int i = 0; i < vec.size(); i++)
		{
			setX[i] = vec[i].x();
			setY[i] = vec[i].y();
		}
		for (int i = 0; i < size - 1; i++)
		{
			int minxvalue = setX[i];
			int maxxvalue = setX[i + 1];
			int distance = maxxvalue - minxvalue;
			int ymin = setY[i];
			int ymax = setY[i + 1];
			if (distance != 0)
			{
				for (int i = minxvalue; i <= maxxvalue; i++)
				{
					double y = (i - minxvalue)*(ymax - ymin) / distance;
					double yvalue = y + ymin;
					setValue[i] = (int)yvalue;
				}
			}
		}

		for (int i = 0; i < SizeRow * SizeRow; i++)
		{

			int data = inputImg[i];

			if (data < xmin)
			{
				ucharImg[i] = 0;
			}
			if (data>xmax)
			{
				ucharImg[i] = 255;
			}

			int yvalue = setValue[data];
			ucharImg[i] = yvalue;
		}

	
	}
	void setMovePoint(QPoint p);
	void ResetPoint(QPoint p);


	void updateGrayImg();
	void readyGrayCurve();

	void DisplaySelsectText(QString, int);
	void removeNumberText(QString, int);
	void setBlursize(int ,int);
	void LightContrastChange(int, int);

	//qchart





	//--------------测绘工具-------------//
	//line
	void setLineEnable();
	void setRectEnable(int, int);
	void LinepointMove(int lineOrder, int flag, QPoint pos);
	void Rectvaluechange(int, int);
	void LineMoveChangePoint(int, int, QPoint);
	void updateLinepointSerial(int);
	void iniLineLimit(int, int);
	//rect
	void setRectEnable();
	void RectPointMove(int, QPoint);
	void iniRectPoint(QPoint, QPoint, QPoint, QPoint, int);
	void RectPointReadytoMove(int, int, QPoint);
	void RectMovepoints(int, int, int, int, int);
	void setRectPointMoveLimit(int, int, QPoint);
	void getRectPointMoveLimit(int, int, int, int, int, int, QPoint);
	void iniDisplayLimittest(int, int);
	void RectMovePoints(int, int, QPoint);
	void updateRectSerial(int);
	void updateRectPointsSerial(int);
	//circle
	void setCircleEnable();
	void setRadious(int);
	void RadiousChanged(int);
	void updateCircleSerial(int);
	//cancel
	void setCancelEnable();
	void cancelShape();
	void cancelCircle(int);
	void cancelRect(int);
	void unableCancelShape();
	//tool
	void getPos();
	void getPosCancel();
	void getPos_Value(int, int, int);
	//--------------测绘工具-------------//

	void openAdjust(int);
	void closeAdjust();

	void sendTwoDim();
	void sendThreeDim();
	void sendMeasure();
	void sendPaint();
	void sendAdjust();
	void sendHardware();
	void sendFile();
	void sendData();

	void sendThreeDimPic();

	void sendVA(int,int);
	void sendSerial(QSerialPort*, bool);

	void setMotorFlagTrue();
	void setMotorFlagFalse();
	bool getMotorFlag();

	void setDetectorFlagTrue();
	void setDetectorFlagFalse();
	bool getDetectorFlag();

	void sendDetectorSet(int,int,int,int);
	void sendDetectorParam(int, float, int, int, int, float, float);

	void sendOpenRawSignal(std::string);



	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
	void setDisenable();
	void setLineAngleEnable();
	void setperpenEnable();
	void setperdenEnable();
	void setpixEnable();
	void setMoveLimit();
	void setLaMove(ShapeMode, int, int);
	void cancelMoveLimit();
	void cancelMeasureShape();
	void clearShape();
	void setlaCancel(int);
	void setPmove(ShapeMode, int, int);
	void setPcancel(ShapeMode, int);
	void setPixRelease();
	//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++

	//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
	void setMul(int);
	void getPosPixEnable(bool);
	void sendPosSignal(QPoint);
	void sendIfMove(bool);
	//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++
signals:

	void openRawSignal(std::string);

	void twoDimSignal();
	void threeDimSignal();
	void measureSignal();
	void paintSignal();
	void adjustSignal();
	void hardwareSignal();
	void fileSignal();
	void dataSignal();

	void threeDimPicSignal();

	void VASignal(int, int);
	void serialSignal(QSerialPort*, bool);

   void updateGrayImgSignal();
   void readyGrayCurveSignal();


   void MovePointSignal(QPoint);
   void MoveResetSignal(QPoint);


   void DisplaySelsectTextSignal(QString, int);
   void removeNumberTextSignal(QString, int);
   void setBlursizeSignal(int, int);
   void LightContrastChangeSignal(int, int);
   //--------------测绘工具-------------start//
   //lineSignal
   void setLineEnableSignal();
   void setRectEnableSignal(int, int);
   void LinepointMoveSignal(int lineOrder, int flag, QPoint pos);
   void RectvaluechangeSignal(int, int);
   void LineMoveChangePointSignal(int, int, QPoint);
   void updateLinepointSerialSignal(int);
   void iniLineLimitSignal(int, int);
   //rectSignal
   void setRectEnableSignal();
   void iniRectPointSignal(QPoint, QPoint, QPoint, QPoint, int);
   void RectPointReadytoMoveSignal(int, int, QPoint);
   void RectMovepointsSignal(int, int, int, int, int);
   void setRectPointMoveLimitSignal(int, int, QPoint);
   void getRectPointMoveLimitSignal(int, int, int, int, int, int, QPoint);
   void iniDisplayLimitSignaltest(int, int);
   void RectMovePointsSignal(int, int, QPoint);
   void updateRectSerialSignal(int);
   void updateRectPointsSerialSignal(int);
   //circleSignal
   void setCircleEnableSignal();
   void setRadiousSignal(int);
   void RadiousChangedSignal(int);
   void updateCircleSerialSignal(int);
   //cancelSignal
   void setCancelEnableSignal();
   void cancelShapeSignal();
   void cancelCircleSignal(int);
   void cancelRectSignal(int);
   void unableCancelShapeSignal();
   //--------------测绘工具-------------end//


   void getPosSignal();
   void getPosCancelSignal();
   void getPos_ValueSignal(int, int, int);


   void closeAdjustSignal();
   void openAdjustSignal(int);

   void detectorSetSignal(int,int,int,int);
   void detectorParamSignal(int,float,int,int,int,float,float);


   //++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
   void setDisenableSignal();
   void setLineAngleEnableSignal();
   void setperpenEnableSignal();
   void setperdenEnableSignal();
   void setpixEnableSignal();
   void setMoveLimitSignal();
   void setLaMoveSignal(ShapeMode, int, int);
   void cancelMoveLimitSignal();
   void cancelMeasureShapeSignal();
   void clearShapeSignal();
   void setlaCancelSignal(int);

   void setPmoveSignal(ShapeMode, int, int);
   void setPcancelSignal(ShapeMode, int);
   void setPixReleaseSignal();


   //++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++++++++++++




   //++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++

   void setMulSignal(int);
   void getPosPixEnableSignal(bool);
   void returnPosSignal(QPoint);
   void ifMouseMoveSignal(bool);
   //++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++

};

#endif // BLLDATAFLOW_H
