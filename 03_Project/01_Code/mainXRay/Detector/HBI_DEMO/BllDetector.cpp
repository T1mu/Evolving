#include "BllDetector.h"
#include "qdebug.h"
#include <QDateTime>
#include <Qlabel>
#include <QMessageBox>
#include <QDebug>
BllDetector::BllDetector(QWidget *parent)
	: QWidget(parent)
{
	
	ui.setupUi(this);
	nDevNum = -1;
	m_pFpd = NULL;
	m_pParentWnd = NULL;

	m_mImageWidth = KCC_IMAGE_WIDTH;
	m_mImageHeight = KCC_IMAGE_HEIGHT;
	m_mImageSize = m_mImageWidth*m_mImageHeight;

	m_pImageBuf = new unsigned short[m_mImageWidth*m_mImageHeight];
	memset(m_pImageBuf, 0, m_mImageWidth*m_mImageHeight*sizeof(unsigned short));

	m_pImageNBuf = new DWORD[m_mImageWidth*m_mImageHeight];
	memset(m_pImageNBuf, 0, m_mImageWidth*m_mImageHeight*sizeof(DWORD));


	m_pOffsetImgBuf = NULL;
	m_pOffsetBuf = NULL;
	m_pGainImgBuf = NULL;
	m_pGainBuf = NULL;

	m_iBaseLine = 3072;
	m_iAdjustSubLine = 3000;
	m_iAdjustSubPoint = 24000;
	
	m_iCaptureIndex = 0;
	m_iCaptureFrame = 0;

	m_bBadPointCalibration = false;
	m_bOffsetCalibration = false;
	m_bGainCalibration = false;

	m_bConnect = false;
	m_bStart = false;
	m_bCapture = false;

	//LoadDetCalibration();
	//ResetBadPoints();
	//LoadBadPoints();
	//这一段代码是用来初始化探测器的
	//
	if (!InitDetector())
	{
		QMessageBox::information(this, "error", QString::fromLocal8Bit("平板探测器连接失败！"));
		ui.label->setText(QString::fromLocal8Bit("探测器连接失败！"));

		qDebug() << "平板探测器连接失败";
	}
	else
	{
		qDebug() << "success";
		ui.label->setText(QString::fromLocal8Bit("探测器连接成功！"));
		//InitDetector();
		
	}
}

BllDetector::~BllDetector()
{
	//如果还在工作则停止
	qDebug() << "~HBI_DEMO()-----00000000000--";
	if (m_bStart)
	{
		m_bStart = FALSE;
		StopDetector();
	}
	qDebug() << "~HBI_DEMO()-------";
	//断开连接、关闭设备
	DestroyAllDev();
	//卸除内存
	delete m_pImageBuf;
	delete m_pImageNBuf;

	if (NULL != m_pOffsetImgBuf)
	{
		delete m_pOffsetImgBuf;
		m_pOffsetImgBuf = NULL;
	}

	if (NULL != m_pOffsetBuf)
	{
		delete m_pOffsetBuf;
		m_pOffsetBuf = NULL;
	}

	if (NULL != m_pGainImgBuf)
	{
		delete m_pGainImgBuf;
		m_pGainImgBuf = NULL;
	}

	if (NULL != m_pGainBuf)
	{
		delete m_pGainBuf;
		m_pGainBuf = NULL;
	}
}

//搜寻设备ID，返回指针
void *BllDetector::FindDevHandleByDevId(int inDevId)
{
	void *ptr = NULL;
	if (inDevId < 0 || inDevId >= nDevNum || nDevNum >= MAX_FPD_DEV_NUM)
	{
		return ptr;
	}

	// 遍历查找设备句柄
	for (int i = 0; i < nDevNum; i++)
	{
		if (arrDev[i]._nDevID == inDevId)
		{
			if (arrDev[i]._pPDF != NULL)
			{
				ptr = arrDev[i]._pPDF;
			}
			break;
		}
	}

	return ptr;
}

bool BllDetector::InitDetector()
{
	// 初始化DLL资源
	int ret = HBI_EnumDev(arrDev, MAX_FPD_DEV_NUM, &nDevNum);
	if (ret != 0)
	{
		return false;
	}
	//如果实际设备数小于0
	if (nDevNum < 0)
	{
		return false;
	}

	// 获取当前模块的路径
	memset(m_path, 0x00, MAX_PATH);

	// 平板ID
	fpdid = 0;
	m_pFpd = FindDevHandleByDevId(fpdid);
	if (!m_pFpd)
	{
		return false;
	}
	else
	{
		int ret = HBI_RegEventCallBackFun(m_pFpd, handleCommandEvent, (void *)this); //注册回调函数
		ret = HBI_ConnectDetector(m_pFpd);//连接探测器
		if (ret != 0)
		{
			return false;
		}
	}

	m_bConnect = TRUE;

	return TRUE;
}

void BllDetector::StartDetector()
{
	aqc_mode.aqc_mode = DYNAMIC_ACQ_DEFAULT_MODE;
	aqc_mode.nframesum = 0;
	aqc_mode.nframeid = 0;
	aqc_mode.ngroupno = 0;
	aqc_mode.ndiscard = 0;

	unsigned char cmd = EDL_COMMON_TYPE_LIVE_ACQ;
	HandleCommand(cmd, NULL);

	m_bStart = true;

}

void BllDetector::StopDetector()
{
	unsigned char cmd = EDL_COMMON_TYPE_STOP_ACQ;
	HandleCommand(cmd, NULL);

	m_bStart = false;
}

void BllDetector::CaptureImage(int nFrame)
{
	if (!m_bConnect)
	{
		return;
	}

	m_bCapture = TRUE;
	m_iCaptureIndex = 0;

	if (nFrame == 1)
	{
		m_iCaptureFrame = 1;
		m_nCaptureType = CAPTURE_TYPE_ONE;
		qDebug() << m_nCaptureType;
	}
	else if (nFrame > 1)
	{
		m_iCaptureFrame = nFrame;
		m_nCaptureType = CAPTURE_TYPE_MORE;
		memset(m_pImageNBuf, 0, m_mImageWidth*m_mImageHeight*sizeof(DWORD));
	}
	else
	{
		m_iCaptureFrame = 0;
		m_nCaptureType = CAPTURE_TYPE_NONE;
	}
}


void BllDetector::SetCallBack(void * pOwner, KCDetCaptureCallback pFunc)
{
	m_pParentWnd = pOwner;
	m_pFuncCallback = pFunc;
}

//返回窗口句柄
void BllDetector::SetHwndRcvCalMsg(HWND hWnd)
{
	m_hWndRcvCalMsg = hWnd;
}

//实际调用平板API的函数
int BllDetector::HandleCommand(unsigned char command, RegCfgInfo *pRegCfg)
{
	qDebug() << "HandleCommand    start ";
	int ret = -1;
	if (m_pFpd == NULL)
	{
		printf("未连接状态!\n");
		return ret;
	}

	switch (command)
	{
	case EDL_COMMON_TYPE_GLOBAL_RESET:        // GlobalReset 01;重置探测器
		ret = HBI_ResetDetector(m_pFpd);
		break;
	case EDL_COMMON_TYPE_PREPARE:             // Perpare 02;准备指令
		ret = HBI_Prepare(m_pFpd);
		break;
	case EDL_COMMON_TYPE_SET_AQC_MODE:        // set aqc mode;0xFF设置采集属性
		ret = HBI_SetAqcProperty(m_pFpd, aqc_mode);
		break;
	case EDL_COMMON_TYPE_SINGLE_SHORT:        // Single Acquisition 03;单帧采集
		ret = HBI_SingleAcquisition(m_pFpd, aqc_mode);
		break;
	case EDL_COMMON_TYPE_LIVE_ACQ:            // Live Acquisition; 04;连续采集
		ret = HBI_LiveAcquisition(m_pFpd, aqc_mode);
		break;
	case EDL_COMMON_TYPE_STOP_ACQ:            // Stop Acquisition; 05;停止采集
		ret = HBI_StopAcquisition(m_pFpd);
		break;
	case EDL_COMMON_TYPE_DUMMPING:           // Dummpling 08;清空指令
		ret = HBI_Dumping(m_pFpd);
		break;
	case EDL_COMMON_TYPE_SET_ROM_PARAM_CFG:  // set System R0M Parameter Configuration;0x12
		if (pRegCfg != NULL)
			ret = HBI_SetSysParamCfg(m_pFpd, command, 1, pRegCfg);// download TI COF寄存器数据	 配置系统ROM\RAM参数	
		break;
	case EDL_COMMON_TYPE_GET_ROM_PARAM_CFG:  // get  System R0M Parameter Readback;0x13
		if (pRegCfg != NULL)
			ret = HBI_GetSysParamCfg(m_pFpd, command, 1/*, pRegCfg*/);//回读系统参数
		break;
	default:
		break;
	}

	return ret;
}

int BllDetector::handleCommandEvent(void *pObj, unsigned char command, void *buff, int len, int nId)
{
	qDebug() << "handleCommandEvent    start ";
	BllDetector *pDetDlg = (BllDetector *)pObj;

	if ((command == ECALLBACK_TYPE_SINGLE_IMAGE) || (command == ECALLBACK_TYPE_MULTIPLE_IMAGE) || (command == ECALLBACK_TYPE_ROM_UPLOAD) || (command == ECALLBACK_TYPE_RAM_UPLOAD))
	{
		if (buff == NULL || len == 0)
		{
			return 0;
		}
	}

	switch (command)
	{
	case ECALLBACK_TYPE_NET_ERR_MSG:
	case ECALLBACK_TYPE_ROM_UPLOAD:
	case ECALLBACK_TYPE_SET_CFG_OK:
	case ECALLBACK_TYPE_THREAD_EVENT:
		break;
	case ECALLBACK_TYPE_SINGLE_IMAGE:   // 单帧采集上图
	case ECALLBACK_TYPE_MULTIPLE_IMAGE: // 连续采集上图	
	{
		pDetDlg->ProcessDetectorImage((unsigned char*)buff, len);
	}
		break;
	default:
		break;
	}

	return 1;
}

void BllDetector::ProcessDetectorImage(unsigned char * pImage, int lenbuf)
{
	qDebug() << "ProcessDetectorImage    start ";
	if (pImage == NULL || lenbuf != m_mImageWidth*m_mImageHeight * 2)
	{
		return;
	}
	/*if (m_bOffsetCalibration && m_bGainCalibration && NULL != m_pGainBuf && NULL != m_pOffsetBuf  && !m_bCapture)
	{
		DoDetectorCalibrate(m_pImageBuf);
	}*/

	//CC增加的暗场校正函数，判断m_pOffsetImgBuf是否为空，判断m_bCapture是否为true然后默认做暗场校正

	memcpy(m_pImageBuf, (unsigned short*)pImage, lenbuf / 2 * sizeof(unsigned short));
	if (NULL != m_pOffsetImgBuf && m_bCapture)
	{
		qDebug() << "DoDetectorCalibrate    start ";
		DoDetectorOffsetCalibrate(m_pImageBuf);
		qDebug() << "DoDetectorCalibrate    finish ";

	}


	//输出经过帧图像
	//m_pFuncCallback(m_pParentWnd, m_pImageBuf);

	
	if (m_bCapture)
	{
		qDebug() << "ProcessDetectorImage   if  start ";
		m_iCaptureIndex++;
		qDebug() << "ProcessDetectorImage   if  m_nCaptureType is" << m_nCaptureType;
		  

		

		switch (m_nCaptureType)
		{
			qDebug() << "ProcessDetectorImage   switch  m_nCaptureType is" << m_nCaptureType;
		case CAPTURE_TYPE_NONE:
			break;
		case CAPTURE_TYPE_ONE:
		{
								 qDebug() << "ProcessDetectorImage   CAPTURE_TYPE_ONE  start ";
								 if (m_iCaptureIndex > 0)
								 {
									 
									 Mat saveImg(Size(m_mImageWidth, m_mImageHeight), CV_16U);
									 if (m_iCaptureIndex > 0)
									 {
										 FILE *fp;
										 fp = fopen("file.dat", "w");
										 for (int i = 0; i < m_mImageWidth * m_mImageHeight; i++)
										 {
											 int value = i;
											 int data = i;
											 int row = data / m_mImageHeight;
											 int col = data % m_mImageWidth;
											 fprintf(fp, "%d ", m_pImageBuf[i]);
											 saveImg.at<ushort>(row, col) = m_pImageBuf[i];
										 }
										 m_bCapture = FALSE;
										 fclose(fp);
									 }
									// writeImgFile(m_pImageBuf, m_mImageSize);
									 qDebug() << "--------------write data file done-------- ";
									 QString path = resultImgPath;
									 QString str = QString::number(123456789);
									 str.append(".tif");
									 path.append("/").append(str);
									cv::imwrite(string(path.toLocal8Bit()), saveImg);
									 m_bCapture = FALSE;
								 }

		}
			break;
		case CAPTURE_TYPE_MORE:
		{
								  if (m_iCaptureIndex>0)
								  {
									  int sum = m_mImageWidth*m_mImageHeight;
									  for (int i = 0; i<sum; i++)
									  {
										  m_pImageNBuf[i] += m_pImageBuf[i];
										  if (m_iCaptureIndex == m_iCaptureFrame)
										  {
											  m_pImageBuf[i] = (unsigned short)(m_pImageNBuf[i] / m_iCaptureFrame);
										  }
									  }

									  if (m_iCaptureIndex == m_iCaptureFrame)
									  {
										  //发送多帧采集完成消息
										  m_bCapture = FALSE;
										//  ::PostMessage(m_hWndRcvCalMsg, MSG_KCC_CAPTURE_MORE_DONE, (WPARAM)m_pImageBuf, 0);
									  }
									  else
									  {
										  //发送正在进行多帧采集消息
										 // ::PostMessage(m_hWndRcvCalMsg, MSG_KCC_CAPTURE_MORE_STATUS_CHANGE, m_iCaptureIndex, 0);
									  }
								  }
		}
			break;

		case CAPTURE_TYPE_OFFSET:
		{
						qDebug() << "ProcessDetectorImage  CAPTURE_TYPE_OFFSET start ";
									if (m_iCaptureIndex>0)
									{
										int sum = m_mImageWidth*m_mImageHeight;
										for (int i = 0; i<sum; i++)
										{
											m_pImageNBuf[i] += m_pImageBuf[i];
											if (m_iCaptureIndex == m_iCaptureFrame)
											{
												m_pImageBuf[i] = (unsigned short)(m_pImageNBuf[i] / m_iCaptureFrame);
											}
										}
										if (m_iCaptureIndex == m_iCaptureFrame)
										{
											if (NULL == m_pOffsetImgBuf)
											{
												m_pOffsetImgBuf = new unsigned short[sum];
												memset(m_pOffsetImgBuf, 0, sum*sizeof(unsigned short));
											}

											memcpy(m_pOffsetImgBuf, m_pImageBuf, sum*sizeof(unsigned short));
											SaveDetOffsetCalibration();
											//ComputeDetCalibration();
											//触发暗场校正完成消息
											m_bCapture = FALSE;
										//	::PostMessage(m_hWndRcvCalMsg, MSG_KCC_OFFSET_CAL_DONE, 0, 0);
										}
										else
										{
											//发送正在进行暗场校正消息
										//	::PostMessage(m_hWndRcvCalMsg, MSG_KCC_OFFSET_CAL_STATUS_CHANGE, m_iCaptureIndex, 0);
										}
									}

		}
			break;

		case CAPTURE_TYPE_GAIN:
		{
								  qDebug() << "ProcessDetectorImage  CAPTURE_TYPE_GAIN start ";
								  if (m_iCaptureIndex>0)
								  {
									  int sum = m_mImageWidth*m_mImageHeight;
									  for (int i = 0; i<sum; i++)
									  {
										  m_pImageNBuf[i] += m_pImageBuf[i];
										  if (m_iCaptureIndex == m_iCaptureFrame)
										  {
											  m_pImageBuf[i] = (unsigned short)(m_pImageNBuf[i] / m_iCaptureFrame);
										  }
									  }
									  if (m_iCaptureIndex == m_iCaptureFrame)
									  {
										  if (NULL == m_pGainImgBuf)
										  {
											  m_pGainImgBuf = new unsigned short[sum];
											  memset(m_pGainImgBuf, 0, sum*sizeof(unsigned short));
										  }

										  memcpy(m_pGainImgBuf, m_pImageBuf, sum*sizeof(unsigned short));
										  ComputeDetCalibration();

										  //发送亮场校正完成消息
										  m_bCapture = FALSE;
										//  ::PostMessage(m_hWndRcvCalMsg, MSG_KCC_GAIN_CAL_DONE, 0, 0);

										  m_bOffsetCalibration = TRUE;
										  m_bGainCalibration = TRUE;
									  }
									  else
									  {
										  //发送正在进行亮场校正消息
										 // ::PostMessage(m_hWndRcvCalMsg, MSG_KCC_GAIN_CAL_STATUS_CHANGE, m_iCaptureIndex, 0);
									  }
								  }
		}
			break;


		default:
			break;
		}
	}
}

void BllDetector::DestroyAllDev()
{
	//如果没有断开连接则先断开连接
	if (m_bConnect)
	{
		m_bConnect = false;
		if (m_pFpd != NULL)
		{
			HBI_DisConnectDetector(m_pFpd);
			m_pFpd = NULL;
		}
	}

	//关闭设备
	HBI_CloseAllDev(arrDev, nDevNum);
}

void BllDetector::on_captureImageBtn_clicked()
{
	resultImgPath = localD.absolutePath();
	QString str_time;
	QDateTime time = QDateTime::currentDateTime();
	str_time = time.toString("yyyy-MM-dd_hh-mm-ss");

	resultImgPath.append("/");
	QDir dir(resultImgPath);
	if (!dir.exists(str_time))
	{
		dir.mkdir(str_time);
		temptime = str_time;
	}
	resultImgPath.append(temptime);

	StartDetector();


	qDebug() << "Start capture";
	CaptureImage(1);
	qDebug() << "Done";
}

void BllDetector::on_iniBtn_clicked()
{
	InitDetector();
}

void BllDetector::on_Cbtn_clicked()
{

}
void BllDetector::StartDetectorOffsetMode()
{
	aqc_mode.aqc_mode = DYNAMIC_ACQ_DEFAULT_MODE;
	//aqc_mode.aqc_mode = DYNAMIC_ACQ_BARK_MODE;
	aqc_mode.nframesum = 0;
	aqc_mode.nframeid = 0;
	aqc_mode.ngroupno = 0;
	aqc_mode.ndiscard = 0;

	unsigned char cmd = EDL_COMMON_TYPE_LIVE_ACQ;
	HandleCommand(cmd, NULL);

	m_bStart = true;
}

void BllDetector::on_offsetBtn_clicked()
{
	qDebug() << "offsetBtn  done";
	//StartDetector();
	StartDetectorOffsetMode();
	OffsetCalibrate();
	
	qDebug() << "offsetBtn  finish";
	//SaveDetCalibration();
}
void BllDetector::on_gainBtn_clicked()
{
	qDebug() << "gainBtn  done";
	StartDetector();
	//StartDetectorOffsetMode();
	GainCalibrate();

	qDebug() << "gainBtn  finish";
	//SaveDetCalibration();
}

void BllDetector::SaveDetCalibration()
{

	FILE *fp1 = fopen("OffsetCalibration.txt", "w");

	qDebug() << "---------OffsetCalibration file  start-----";
	for (int i = 0; i < m_mImageWidth * m_mImageHeight; i++)
	{

		fprintf(fp1, "%d ", m_pOffsetImgBuf[i]);
	}
	fclose(fp1);
	qDebug() << "---------OffsetCalibration file end---------";


	FILE *fp2 = fopen("GainCalibration.txt", "w");
	qDebug() << "---------GaintCalibration file  start-----";

	for (int i = 0; i < m_mImageWidth * m_mImageHeight; i++)
	{

		fprintf(fp2, "%d ", m_pGainImgBuf[i]);
	}
	fclose(fp2);
	qDebug() << "GaintCalibration file end";


}
void BllDetector::SaveDetOffsetCalibration()
{

	FILE *fp1 = fopen("OffsetCalibration.txt", "w");
	qDebug() << "---------OffsetCalibration file  start-----";
	for (int i = 0; i < m_mImageWidth * m_mImageHeight; i++)
	{

		fprintf(fp1, "%d ", m_pOffsetImgBuf[i]);
	}
	fclose(fp1);
	qDebug() << "OffsetCalibration file end";

}


//暗场校正和亮场校正相关函数代码
void BllDetector::GainCalibrate()
{
	m_bCapture = TRUE;
	m_iCaptureIndex = 0;
	m_iCaptureFrame = 32;
	m_nCaptureType = CAPTURE_TYPE_GAIN;
	memset(m_pImageNBuf, 0, m_mImageWidth*m_mImageHeight*sizeof(DWORD));
}

void BllDetector::OffsetCalibrate()
{
	qDebug() << "OffsetCalibrate start ";
	if (!m_bConnect)
	{
		qDebug() << "m_bConnect  false";
		return;
	}
	
	m_bCapture = TRUE;
	m_bOffsetCalibration = TRUE;
	qDebug() << "m_bConnect  true";
	m_iCaptureIndex = 0;
	m_iCaptureFrame = 32;
	m_nCaptureType = CAPTURE_TYPE_OFFSET;
	qDebug() << m_nCaptureType;
	qDebug() << "CAPTURE_TYPE_OFFSET set";
	memset(m_pImageNBuf, 0, m_mImageWidth*m_mImageHeight*sizeof(DWORD));
}


void BllDetector::ComputeDetCalibration()
{
	qDebug() << "ComputeDetCalibration  start";
	//if (NULL == m_pOffsetImgBuf || NULL == m_pGainImgBuf)
	//{
	//	return;
	//}
	qDebug() << "ComputeDetCalibration  start";
	int m_iSize = KCC_IMAGE_WIDTH*KCC_IMAGE_WIDTH;
	if (NULL == m_pGainBuf)
	{
		m_pGainBuf = new double[m_iSize];
	}
	if (NULL == m_pOffsetBuf)
	{
		m_pOffsetBuf = new unsigned short[m_iSize];
	}
	memset(m_pGainBuf, 0, m_iSize*sizeof(double));
	memset(m_pOffsetBuf, 0, m_iSize*sizeof(unsigned short));

	unsigned short *p1 = m_pOffsetImgBuf;
	unsigned short *p2 = m_pGainImgBuf;
	unsigned short *pp1 = m_pOffsetBuf;
	double *pp2 = m_pGainBuf;
	int i = 0;

//	int iMidGain = m_pGainImgBuf[m_mImageHeight / 2 * m_mImageWidth + m_mImageWidth / 2];
//	int iThreshold = iMidGain / 2;

	double offsetSum = 0, gainSum = 0;
	//int iGainPointSum = 0;
	//for (i = 0; i<m_iSize; i++)
	//{
	//	offsetSum += double(*p1);
	//	if (*p2 > iThreshold)
	//	{
	//		gainSum += double(*p2);
	//		iGainPointSum++;
	//	}
	//	p1++;
	//	p2++;
	//}

	int offsetAve = int(offsetSum / m_iSize);
//	int gainAve = int(gainSum / iGainPointSum*1.1);
	p1 = m_pOffsetImgBuf;
//	p2 = m_pGainImgBuf;

//	double temp = double(gainAve - offsetAve);

	//for (i = 0; i<m_iSize; i++)
	//{
	//	*pp1 = *p1;
	//	if ((*p2 - *p1) == 0)
	//	{
	//		*pp2 = 1;
	//	}
	//	else
	//	{
	//		if (*p2>iThreshold)
	//		{
	//			*pp2 = temp / (double(*p2 - *p1));
	//		}
	//		else
	//		{
	//			*pp2 = 1;
	//		}
	//	}
	//	p1++;
	//	p2++;
	//	pp1++;
	//	pp2++;
	//}

	SaveDetCalibration();
	qDebug() << "ComputeDetCalibration success";
}


void BllDetector::DoDetectorCalibrate(unsigned short * pImage)
{

	

	int iSize = m_mImageWidth*m_mImageHeight;
	for (int i = 0; i<iSize; i++)
	{
		if (pImage[i] != 65535)
		{
			int temp = int((pImage[i] - m_pOffsetBuf[i])*m_pGainBuf[i] + m_iBaseLine);
			if (temp<0)
			{
				temp = 0;
			}
			else if (temp>65535)
			{
				temp = 65535;
			}
			pImage[i] = (unsigned short)temp;
		}
		
	}

}


void BllDetector::DoDetectorOffsetCalibrate(unsigned short * pImage)
{

	Mat saveOffseImg(Size(m_mImageWidth, m_mImageHeight), CV_16U);
	int iSize = m_mImageWidth*m_mImageHeight;
	for (int i = 0; i<iSize; i++)
	{
		if (pImage[i] != 65535)
		{
			int temp = int((pImage[i] - m_pOffsetImgBuf[i]));
			if (temp<0)
			{
				temp = 0;
			}
			else if (temp>65535)
			{
				temp = 65535;
			}
			pImage[i] = (unsigned short)temp;
		}
		int value = i;
		int data = i;
		int row = data / m_mImageHeight;
		int col = data % m_mImageWidth;
		saveOffseImg.at<ushort>(row, col) = pImage[i];
	}



	QString path = resultImgPath;
	QString str = QString::number(5555);
	str.append(".tif");
	path.append("/").append(str);
	cv::imwrite(string(path.toLocal8Bit()), saveOffseImg);

}


void BllDetector::writeFile(const int array[], int size)
{
	QFile file;
	file.setFileName("img.dat");
	bool isOk = file.open(QIODevice::WriteOnly);
	QString str = "";
	QString str1 = "";
	//处理第一行数据 第一行数据为图像第一行数据加位置信息 目前是5+5=10
	for (int i = 0; i < 10; i++)
	{
		QString ss = QString::number(array[i]) + " ";
		str1 += ss;
	}
	str1.trimmed();//除去前后空格

	str.append(str1) + "\n";


	QString ss = "";
	for (int i = 10; i < size; i++)
	{
		QString data = QString::number(array[i]) + " ";
		ss += data;
		if (i>10 && (i + 1) % 5 == 0)
		{                      //模5是图像的行数
			ss = ss.trimmed();
			str = str + "\n" + ss;
			ss = "";
		}
	}
	file.write(str.toUtf8());
	file.close();

}
void BllDetector::readFile()
{
	QFile file;
	file.setFileName("img.dat");
	bool isOk = file.open(QIODevice::ReadOnly);
	QList<QString> list;
	if (isOk)
	{
		while (file.atEnd() == false)
		{
			QString str(file.readLine());
			list.append(str);
		}
	}
	int a[20] = { 0 };//定义接收数组
	//第一行有效数据处理 
	QString firstl = list[0];
	firstl.trimmed();
	QStringList ll = firstl.split(" ");
	for (int i = 5; i < ll.size(); i++)
	{
		a[i - 5] = ll[i].toInt();
	}
	//标准数据
	for (int i = 1; i < list.size(); i++)
	{
		QStringList ll = list[i].trimmed().split(" ");
		for (int j = 0; j < ll.size(); j++)
		{
			a[i * 5 + j] = ll[j].toInt();
		}
	}
	//位置数据
	int size = 20;
	int row = 3;
	int col = 5;
	for (int i = row*col; i < size; i++)
	{
		QString ss(ll[i - size + 5]);
		a[i] = ss.toInt();
	}
	for (int i = 0; i < 20; i++)
	{
		qDebug() << "data: " << a[i];
	}
}
//输入是一个数组和大小，输出是一份写好的文件
void BllDetector::writeImgFile(const unsigned short array[], int size)
{

	qDebug() << "--------------writeImgFile data file start-------- ";
	QFile file;
	file.setFileName("img.dat");
	bool isOk = file.open(QIODevice::WriteOnly);
	if (isOk)
	{
		qDebug() << "isok:   " << isOk;
	}
	else
	{

		return;
	}
	QString str = "";

	QString ss = "";
	QList<QList<QString>> list;
	QList<QString> l;
	//qDebug() << "size: " << size;
	for (int i = 0; i < size; i++)
	{
		QString data = QString::number(array[i]) + " ";
		int row = i / 3072;
		int col = i % 3072;
		if (row > 0 && col == 0)
		{	
			list.append(l);
			l.clear();
			l.append(data);
		}
		else
		{
			l.append(data);
		}

		if (i == size - 1)
		{
			list.append(l);
		}
	}
	qDebug() << "--------------writeImgFile data file end-------- ";
	for (int i = 0; i < list.size(); i++)
	{
		int s = list[i].size();
		str = "";
		for (int j = 0; j < s; j++)
		{
			str += list[i][j];
		}
		file.write(str.toUtf8());
	}

	qDebug() << "0pos: " << list[0][0];
	
	file.close();
	qDebug() << "end-----------------";
}

//输入参数是图像的长宽换和大小，输出是一维数组
void BllDetector::readImgFile(int row, int col, int size)
{
	QFile file;
	file.setFileName("img.dat");
	bool isOk = file.open(QIODevice::ReadOnly);
	QList<QString> list;
	if (isOk)
	{
		while (file.atEnd() == false)
		{
			QString str(file.readLine());
			list.append(str);
		}
	}
	int a[20] = { 0 };//定义接收数组  建议使用size的大小
	//第一行有效数据处理 

	//标准数据
	for (int i = 0; i < list.size(); i++)
	{
		QStringList ll = list[i].trimmed().split(" ");
		for (int j = 0; j < ll.size(); j++)
		{
			a[i * col + j] = ll[j].toInt();
		}
	}
	//位置数据


	for (int i = 0; i < size; i++)
	{
		qDebug() << "data: " << a[i];
	}
}
