#include "BllDetectorKZ.h"
#include <QDebug>
BllDetectorKZ::BllDetectorKZ(QObject *parent)
	: QObject(parent)
{
	m_detectorKZ = new DetectorProjectKZ(NULL);
	m_detectorThread = DetectorThread::instance();
	connect(m_detectorThread, SIGNAL(sendImgSignal(int,int)), this, SIGNAL(returnImgSignal(int,int)));
	connect(m_detectorKZ, SIGNAL(sendModeParamSignal(float,int)), this, SIGNAL(returnModeParamSignal(float,int)));
	connect(m_detectorThread, SIGNAL(sendNumSignal(int)), this, SIGNAL(returnNumSignal(int)));
	connect(m_detectorThread, SIGNAL(sendStopSignal()), this, SIGNAL(returnStopSignal()));
	connect(m_detectorThread, SIGNAL(sendPaintGraySignal()), this, SIGNAL(returnPaintGraySignal()));
	connect(m_detectorThread, SIGNAL(sendResetSignal()), this, SIGNAL(returnResetSignal()));
	connect(m_detectorThread, SIGNAL(sendAdjustSignal(int)), this, SIGNAL(returnAdjustSignal(int)));
	
}

int BllDetectorKZ::ImageSizeRow = 704;
int BllDetectorKZ::ImageSizeCol = 704;
bool BllDetectorKZ::ifSizeChange = false;
quint16* BllDetectorKZ::m_img = 0;

BllDetectorKZ::~BllDetectorKZ()
{

}

BllDetectorKZ* BllDetectorKZ::m_instance = 0;

bool BllDetectorKZ::connectBll()
{
	int errCode = m_detectorKZ->connectKZ();
	if (errCode / 100000 < 3)
	{		
		return true;
	}
	else
	{
		return false;
	}
}

bool BllDetectorKZ::disconnectBll()
{
	int errCode = m_detectorKZ->disconnectKZ();
	if (errCode / 100000 < 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BllDetectorKZ::setModeBll(int modeIndex, float pFrameRate, int pExposureTime, int nTrigType, int nGainLevel)
{
	int errCode = m_detectorKZ->setModeKZ(modeIndex, pFrameRate, pExposureTime, nTrigType, nGainLevel);
	
	if (errCode / 100000 < 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BllDetectorKZ::startPulse(int idx, int num, double tgvel, long dist, unsigned short a, unsigned short b, double f)
{
	m_detectorThread->setSize(ImageSizeRow,ImageSizeCol);
	m_detectorThread->startThread(idx, num,tgvel,dist,a,b,f);
}

void BllDetectorKZ::stopPulse()
{
	m_detectorThread->stopThread();
}

void BllDetectorKZ::updateSize(int size)
{
	emit updateSizeSignal(size);
}

void BllDetectorKZ::resetCurve()
{
	emit resetCurveSignal();
}

void BllDetectorKZ::setLimit(int up, int down, int left, int right)
{
	emit setLimitSignal(up, down, left, right);
}

void BllDetectorKZ::lineMove(QVector<QPointF> vec)
{
	emit lineMoveSignal(vec);
}

void BllDetectorKZ::resetCurveEnable(QString min, QString max)
{
	emit resetCurveEnableSignal(min, max);
}

void BllDetectorKZ::readyAdjust(int c)
{
	emit readyAdjustSignal(c);
}

void BllDetectorKZ::pointmove(){
	emit pointmoveSignal();
}

void BllDetectorKZ::returnImg(int min, int max){
	emit returnImgSignal(min,max);
}

void BllDetectorKZ::readyAdjustpaint(int w, int c)
{
	emit readyAdjustpaintSignal(w, c);
}

void BllDetectorKZ::setLdata(int l)
{
	emit setLdataSignal(l);
}
void BllDetectorKZ::setRdata(int l)
{
	emit setRdataSignal(l);
}
void BllDetectorKZ::setMdata(int l)
{
	emit setMdataSignal(l);
}