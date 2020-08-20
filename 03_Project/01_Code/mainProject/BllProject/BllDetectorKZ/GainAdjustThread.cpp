#include "GainAdjustThread.h"

GainAdjustThread::GainAdjustThread(QObject *parent)
	: QThread(parent)
{
	m_detectorKZ = new DetectorProjectKZ(NULL);
}

GainAdjustThread::~GainAdjustThread()
{

}

void GainAdjustThread::startThread()
{
	start();
}

void GainAdjustThread::stopThread()
{
	quit();
	if (this->isRunning()){
		wait();
	}
}

int GainAdjustThread::getProgress(){
	progressValue = m_detectorKZ->getProgress();
	return progressValue;
}

int GainAdjustThread::getStatus(){
	m_status = m_detectorKZ->getStatus();
	return m_status;
}

void GainAdjustThread::run()
{
	m_detectorKZ->gainAdjustKZ();

}