#ifndef DARKADJUSTBAR_H
#define DARKADJUSTBAR_H

#include <QWidget>
#include "ui_DarkAdjustBar.h"
#include "../../BllProject/BllDetectorKZ/DarkAdjustThread.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
class DarkAdjustBar : public QWidget
{
	Q_OBJECT

public:
	DarkAdjustBar(QWidget *parent = 0);
	~DarkAdjustBar();
	virtual void timerEvent(QTimerEvent* event);
private:
	Ui::DarkAdjustBar ui;
	DarkAdjustThread* m_darkAdjustThread;

	int m_time;
};

#endif // DARKADJUSTBAR_H
