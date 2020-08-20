#include "DarkAdjustBar.h"

DarkAdjustBar::DarkAdjustBar(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_darkAdjustThread = new DarkAdjustThread(NULL);
	m_darkAdjustThread->startThread();
	m_time = startTimer(300);
}

DarkAdjustBar::~DarkAdjustBar()
{

}

void DarkAdjustBar::timerEvent(QTimerEvent* event){
	if (event->timerId() == m_time){
		int status = m_darkAdjustThread->getStatus();
		int progress = m_darkAdjustThread->getProgress();
		ui.progressBar->setValue(progress);
		if (status == 1){
			m_darkAdjustThread->stopThread();
			delete m_darkAdjustThread;
			killTimer(m_time);
			this->close();
		}
	}
}