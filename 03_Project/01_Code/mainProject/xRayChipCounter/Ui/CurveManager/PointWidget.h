#ifndef POINTWIDGET_H
#define POINTWIDGET_H

#include <QWidget>
#include "ui_PointWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class PointWidget : public QWidget
{
	Q_OBJECT

public:
	PointWidget(QPoint &pos = QPoint(0, 0), QWidget *parent = 0, int flag = 100);
	~PointWidget();
	QPoint getpos();
	void judgemove(QPoint& pos);
protected:


	virtual void mousePressEvent(QMouseEvent * event);
	virtual void  paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
private slots:
	void setLimitSlot(int, int, int, int);
private:
	Ui::PointWidget ui;
	QPoint m_position;//µ±«∞Œª÷√
	QPoint position;
	QPoint charge;
	int order;
	BllDetectorKZ* m_bll;
	int limit_up;
	int limit_down;
	int limit_left;
	int limit_right;
};

#endif // POINTWIDGET_H
