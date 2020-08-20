#include "DetectorProjectKZ.h"

DetectorProjectKZ::DetectorProjectKZ(QObject *parent)
	: QObject(parent)
{

}

DetectorProjectKZ::~DetectorProjectKZ()
{

}

int DetectorProjectKZ::connectKZ()
{
	int errCode = CR_Connect(cDETR_IDX);
	return errCode;
}

int DetectorProjectKZ::disconnectKZ()
{
	int errCode = CR_Disconnect(cDETR_IDX);
	return errCode;
}

int DetectorProjectKZ::setModeKZ(int modeIndex, float pFrameRate, int pExposureTime, int nTrigType, int nGainLevel)
{
	CR_ResetDetector(cDETR_IDX, false);
	CR_ModeInfo oModeInfos[16];
	int nModeNum = 0;
	CR_GetApplicationMode(cDETR_IDX, oModeInfos, &nModeNum);
	int errCode = CR_SetApplicationModeWithParam(cDETR_IDX, modeIndex, &pFrameRate, &pExposureTime, nTrigType, nGainLevel);
	emit sendModeParamSignal(pFrameRate, pExposureTime);
	pCallback = new CCallbackImp();
	return errCode;
}

void DetectorProjectKZ::darkAdjustKZ()
{
	CCallbackImp* pCallbackImp = new CCallbackImp();
	CR_RegisterEventCallback(cDETR_IDX, pCallbackImp);
	CR_StartDarkCalibration(cDETR_IDX);
	CR_CalibrationInfo calProgInfo;
	CR_QueryCalibrationStatus(cDETR_IDX, &calProgInfo);
	int nCurrFrmNum = 0;
	int nPrevFrmNum = nCurrFrmNum;
	while (-1 == calProgInfo.nResult)
	{
		if (nCurrFrmNum > nPrevFrmNum)
		{
			nPrevFrmNum = nCurrFrmNum;
			progressValue = calProgInfo.nCurrentFrameNum;
			//qDebug() << "Gain  calibration  progress:  " << calProgInfo.nCurrentFrameNum << "  /  " << calProgInfo.nTotalFrameNum << endl;;
		}
		nCurrFrmNum = calProgInfo.nCurrentFrameNum;
		CR_QueryCalibrationStatus(cDETR_IDX, &calProgInfo);
		Sleep(50);
	}
	Sleep(1000);

	delete pCallbackImp;
	pCallbackImp = nullptr;
	m_status = 1;
}

void DetectorProjectKZ::gainAdjustKZ()
{
	CCallbackImp* pCallbackImp = new CCallbackImp();
	CR_RegisterEventCallback(cDETR_IDX, pCallbackImp);

	CR_StartGainCalibration(cDETR_IDX);
	CR_CalibrationInfo calProgInfo;
	CR_QueryCalibrationStatus(cDETR_IDX, &calProgInfo);
	int nCurrFrmNum = 0;
	int nPrevFrmNum = nCurrFrmNum;
	while (-1 == calProgInfo.nResult)
	{
		if (nCurrFrmNum > nPrevFrmNum)
		{
			nPrevFrmNum = nCurrFrmNum;
			progressValue = calProgInfo.nCurrentFrameNum;
			qDebug() << "Gain  calibration  progress:  " << calProgInfo.nCurrentFrameNum << "  /  " << calProgInfo.nTotalFrameNum << endl;;
		}
		nCurrFrmNum = calProgInfo.nCurrentFrameNum;

		CR_QueryCalibrationStatus(cDETR_IDX, &calProgInfo);
		Sleep(50);
	}
	Sleep(1000);

	delete pCallbackImp;
	pCallbackImp = nullptr;
	m_status = 1;
}

int DetectorProjectKZ::getProgress(){
	return progressValue;
}

int DetectorProjectKZ::getStatus(){
	return m_status;
}
