#ifndef STATEWIDGET_H
#define STATEWIDGET_H

#include <QWidget>
#include "ui_StateWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  
#include "../BllProject/BllDataFlow.h"
//#include "../../../BllProject/BllDetector/BllDetector.h"
class StateWidget : public QWidget
{
	Q_OBJECT

public:
	StateWidget(QWidget *parent = 0);
	~StateWidget();
	
private slots:
	void on_opentubeBtn_clicked();
	void on_opendoorBtn_clicked();
	void startSequenceSlot();
	//getPos_ValueSignal(int, int, int)
	void getPos_ValueSlots(int, int, int);
private:
	Ui::StateWidget ui;
	bool tubeopenEnable;
	bool doorstate;
	//BllDetector* m_blldetector;
	BllDataFlow* m_blldata;
};

#endif // STATEWIDGET_H
