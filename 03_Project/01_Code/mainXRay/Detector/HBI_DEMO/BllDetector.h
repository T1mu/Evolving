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

//ͼ�񻵵�
#define		MAX_BAD_POINT	                            3072        // ƽ�廵��
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


	//CC ���ӵĺ���
	void SaveDetOffsetCalibration();
	void DoDetectorOffsetCalibrate(unsigned short * pImage);
	void writeFile(const int array[], int size);
	void readFile();
	void writeImgFile(const unsigned short array[], int size);

	void readImgFile(int row, int col, int size);
	
private:
	Ui::HBI_DEMOClass ui;
	int                    nDevNum;                            // ö���豸
	FPD_DEVICE             arrDev[MAX_FPD_DEV_NUM];

	int                    fpdid;                              // ��ǰ�豸
	void*                  m_pFpd;                             // fpd sdk������		
	char                   m_path[MAX_PATH];                   // ����·��
	FPD_AQC_MODE           aqc_mode;                           // �ɼ�ģʽ�Ͳ�������֡�ɼ�����֡�ɼ��Լ��Ƿ��ù̼��Դ���У����

	int                    m_mImageWidth;                      // ͼ��ֱ���
	int                    m_mImageHeight;
	int                    m_mImageSize;

	unsigned short*        m_pImageBuf;                        // ��֡ͼ������
	DWORD*				   m_pImageNBuf;                       // ��֡ƽ��ͼ������

	unsigned short*		   m_pOffsetImgBuf;                    // ����У��ͼ������
	unsigned short*		   m_pGainImgBuf;                      // ����У��ͼ������
	unsigned short*        m_pOffsetBuf;
	double*                m_pGainBuf;
	unsigned short         m_iBaseLine;                        // У����׼ֵ
	int					   m_iAdjustSubLine;                   // ���ߵ���
	int					   m_iAdjustSubPoint;                  // �������
	KCC_BAD_POINT_STRUCT   m_pBadPoint;                        // �������ݽṹ

	bool                   m_bConnect;                         // ���ӳɹ���־
	bool                   m_bStart;                           // ��ʼ��ͼ��־
	bool                   m_bCapture;                         // ���вɼ���־
	bool                   m_bOffsetCalibration;               // ����У��
	bool                   m_bGainCalibration;                 // ����У��
	bool                   m_bBadPointCalibration;             // ����У��
	CAPTURE_TYPE           m_nCaptureType;	                   // �ɼ�����

	int                    m_iCaptureIndex;                    // ͼ��֡���
	int                    m_iCaptureFrame;                    // ͼ��֡��

	void*                  m_pParentWnd;                       // �ص�������
	KCDetCaptureCallback   m_pFuncCallback;                    // �ص�����	
	HWND				   m_hWndRcvCalMsg;                    // ����У����Ϣ����	

	//CKCIniFile			   m_inf;                              // ��������������������У����Ϣ


	bool m_bFirstFrameFlag;
	int m_iFirstFrameIndex;
	bool m_bGetImage;
	QString temptime;
	QDir localD;
	QString resultImgPath;
};

#endif // HBI_DEMO_H
