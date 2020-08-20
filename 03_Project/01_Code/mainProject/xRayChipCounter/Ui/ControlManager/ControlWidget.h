#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <QWidget>
#include "ui_ControlWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  
#include "../BllProject/BllDataFlow.h"
class ControlWidget : public QWidget
{
	Q_OBJECT

public:
	ControlWidget(QWidget *parent = 0);
	~ControlWidget();
protected:

	///鼠标按下事件
	virtual void mousePressEvent(QMouseEvent * event);
private:
	Ui::ControlWidget ui;
	BllDataFlow* m_bllDataFlow;
};

#endif // CONTROLWIDGET_H
