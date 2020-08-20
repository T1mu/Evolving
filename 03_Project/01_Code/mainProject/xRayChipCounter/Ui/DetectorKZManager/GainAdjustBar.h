#ifndef GAINADJUSTBAR_H
#define GAINADJUSTBAR_H

#include <QWidget>
#include "ui_GainAdjustBar.h"
#include "../../BllProject/BllDetectorKZ/GainAdjustThread.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
class GainAdjustBar : public QWidget
{
	Q_OBJECT

public:
	GainAdjustBar(QWidget *parent = 0);
	~GainAdjustBar();
	virtual void timerEvent(QTimerEvent* event);
private:
	Ui::GainAdjustBar ui;
	GainAdjustThread* m_gainAdjustThread;

	int m_time;
};

#endif // GAINADJUSTBAR_H
