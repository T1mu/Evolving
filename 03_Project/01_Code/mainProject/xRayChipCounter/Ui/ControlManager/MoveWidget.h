#ifndef MOVEWIDGET_H
#define MOVEWIDGET_H

#include <QWidget>
#include "ui_MoveWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif  
#include "../BllProject/BllDataFlow.h"
class MoveWidget : public QWidget
{
	Q_OBJECT

public:
	MoveWidget(QPoint &pos, QWidget *parent = 0);
	~MoveWidget();
	
protected:

	///鼠标按下事件
	//virtual void mousePressEvent(QMouseEvent * event);
	virtual void  paintEvent(QPaintEvent* event);
	/*virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);*/
private slots:
	void MoveToPosSlot(QPoint);
	void MoveResetSlot(QPoint);
private:
	Ui::MoveWidget ui;
	QPoint endPoint;
	QPoint charge;
	QPoint m_position;//当前位置
	BllDataFlow* m_blldataflow;
};

#endif // MOVEWIDGET_H
