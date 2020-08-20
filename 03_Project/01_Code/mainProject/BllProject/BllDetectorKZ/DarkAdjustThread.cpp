#include "DarkAdjustThread.h"

DarkAdjustThread::DarkAdjustThread(QObject *parent)
	: QThread(parent)
{
	m_detectorKZ = new DetectorProjectKZ(NULL);
}

DarkAdjustThread::~DarkAdjustThread()
{

}

void DarkAdjustThread::startThread()
{
	start();
}

void DarkAdjustThread::stopThread()
{
	quit();
	if (this->isRunning()){
		wait();
	}
}

int DarkAdjustThread::getProgress(){
	progressValue = m_detectorKZ->getProgress();
	return progressValue;
}

int DarkAdjustThread::getStatus(){
	m_status = m_detectorKZ->getStatus();
	return m_status;
}

void DarkAdjustThread::run()
{
	m_detectorKZ->darkAdjustKZ();

}