#ifndef SCANPIXWIDGET_H
#define SCANPIXWIDGET_H

#include <QWidget>
#include "ui_ScanPixWidget.h"
#include "../../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 

class ScanPixWidget : public QWidget
{
	Q_OBJECT

public:
	ScanPixWidget(QWidget *parent = 0);
	~ScanPixWidget();
private slots:
	void valueChangeSlot(int);
	void stateChangeSlot(int);
	
private:
	Ui::ScanPixWidget ui;
	BllDataFlow* m_bllDataFlow;
	int mul;
	
};

#endif // SCANPIXWIDGET_H
