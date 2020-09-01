#ifndef HBI_DEMO_H
#define HBI_DEMO_H

#include <QtWidgets/QWidget>
#include "ui_HBI_DEMO.h"
#include "HBI_DLL/INCLUDES/HbFpdDll.h"
#include "KCBaseParameters.h"
#include "Windows.h"
#include "Shlwapi.h"
#include <iostream>
#include "../opencv2/opencv.hpp"
#include "../opencv2/highgui/highgui.hpp"
#include "../opencv2/imgproc/imgproc.hpp"
#include "../opencv2/core/core.hpp"
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>
#include <QDebug>
#include <QDataStream>


using namespace cv;
using namespace std;

//图像坏点
#define		MAX_BAD_POINT	                            3072        // 平板坏点
#define		MAX_BAD_ROW		                            50

typedef void (WINAPI *KCDetCaptureCallback)(void* pOwner, unsigned short* pBuf);

class BllDetector : public QWidget
{
	Q_OBJECT
	public slots:
	void on_captureImageBtn_clicked();
	void on_iniBtn_clicked();
	void on_Cbtn_clicked();
	void on_offsetBtn_clicked();
	void on_gainBtn_clicked();
public:
	BllDetector(QWidget *parent = 0);
	~BllDetector();
	
	void *FindDevHandleByDevId(int inDevId);
	void DestroyAllDev();

	static int handleCommandEvent(void *pObj, unsigned char command, void *buff, int len, int nId);
	int HandleCommand(unsigned char command, RegCfgInfo *pRegCfg);
	void SetCallBack(void * pOwner, KCDetCaptureCallback pFunc);
	void SetHwndRcvCalMsg(HWND hWnd);

	void ProcessDetectorImage(unsigned char * pImage, int lenbuf);

	void ImageDirection(unsigned short* pImage);

	void DoDetectorCalibrate(unsigned short * pImage);
	void DoBadpointCalibrate(unsigned short * pImage);

	void ComputeDetCalibration();

	bool GetBadpoint(int iType, unsigned long data);
	void AddBadpoint(int iType, unsigned long data);
	void FindBadPoints(unsigned short* pImage);
	void ResetBadPoints();

	void SaveBadPoints();
	void LoadBadPoints();
	void LoadDetCalibration();
	void SaveDetCalibration();

	bool InitDetector();
	void StartDetector();
	void StopDetector();
	void CaptureImage(int nFrame);
	void OffsetCalibrate();
	void GainCalibrate();
	void BadpointCalibrate();
	void StartDetectorOffsetMode();


	//CC 增加的函数
	void SaveDetOffsetCalibration();
	void DoDetectorOffsetCalibrate(unsigned short * pImage);
	void writeFile(const int array[], int size);
	void readFile();
	void writeImgFile(const unsigned short array[], int size);

	void readImgFile(int row, int col, int size);
	
private:
	Ui::HBI_DEMOClass ui;
	int                    nDevNum;                            // 枚举设备
	FPD_DEVICE             arrDev[MAX_FPD_DEV_NUM];

	int                    fpdid;                              // 当前设备
	void*                  m_pFpd;                             // fpd sdk对象句柄		
	char                   m_path[MAX_PATH];                   // 工作路径
	FPD_AQC_MODE           aqc_mode;                           // 采集模式和参数，单帧采集、多帧采集以及是否用固件自带的校正等

	int                    m_mImageWidth;                      // 图像分辨率
	int                    m_mImageHeight;
	int                    m_mImageSize;

	unsigned short*        m_pImageBuf;                        // 单帧图像数据
	DWORD*				   m_pImageNBuf;                       // 多帧平均图像数据

	unsigned short*		   m_pOffsetImgBuf;                    // 暗场校正图像数据
	unsigned short*		   m_pGainImgBuf;                      // 亮场校正图像数据
	unsigned short*        m_pOffsetBuf;
	double*                m_pGainBuf;
	unsigned short         m_iBaseLine;                        // 校正基准值
	int					   m_iAdjustSubLine;                   // 坏线调整
	int					   m_iAdjustSubPoint;                  // 坏点调整
	KCC_BAD_POINT_STRUCT   m_pBadPoint;                        // 坏点数据结构

	bool                   m_bConnect;                         // 连接成功标志
	bool                   m_bStart;                           // 开始上图标志
	bool                   m_bCapture;                         // 进行采集标志
	bool                   m_bOffsetCalibration;               // 暗场校正
	bool                   m_bGainCalibration;                 // 亮场校正
	bool                   m_bBadPointCalibration;             // 坏点校正
	CAPTURE_TYPE           m_nCaptureType;	                   // 采集类型

	int                    m_iCaptureIndex;                    // 图像帧序号
	int                    m_iCaptureFrame;                    // 图像帧数

	void*                  m_pParentWnd;                       // 回调主窗口
	KCDetCaptureCallback   m_pFuncCallback;                    // 回调函数	
	HWND				   m_hWndRcvCalMsg;                    // 接收校正信息窗口	

	//CKCIniFile			   m_inf;                              // 保存亮场、暗场、坏点校正信息


	bool m_bFirstFrameFlag;
	int m_iFirstFrameIndex;
	bool m_bGetImage;
	QString temptime;
	QDir localD;
	QString resultImgPath;
};

#endif // HBI_DEMO_H
