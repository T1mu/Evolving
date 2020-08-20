#include "GainAdjustBar.h"

GainAdjustBar::GainAdjustBar(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_gainAdjustThread = new GainAdjustThread(NULL);
	m_gainAdjustThread->startThread();
	m_time = startTimer(300);
}

GainAdjustBar::~GainAdjustBar()
{

}

void GainAdjustBar::timerEvent(QTimerEvent* event){
	if (event->timerId() == m_time){
		int status = m_gainAdjustThread->getStatus();
		int progress = m_gainAdjustThread->getProgress();
		ui.progressBar->setValue(progress);
		if (status == 1){
			m_gainAdjustThread->stopThread();
			delete m_gainAdjustThread;
			killTimer(m_time);
			this->close();
		}
	}
}