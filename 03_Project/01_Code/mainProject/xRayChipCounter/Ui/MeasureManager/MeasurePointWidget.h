#ifndef MEASUREPOINTWIDGET_H
#define MEASUREPOINTWIDGET_H

#include <QWidget>
#include "ui_MeasurePointWidget.h"
#include "../../Library/Global.h"
#include "../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
class MeasurePointWidget : public QWidget
{
	Q_OBJECT

public:
	MeasurePointWidget(ShapeMode shape, QPoint pos, int flag, int order, QWidget *parent = 0);
	~MeasurePointWidget();
	QPoint getPos();
	void updateDeleteCursor();
	void updateOrder(ShapeMode, int);
protected:
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void paintEvent(QPaintEvent* event);

private:
	Ui::MeasurePointWidget ui;

	QPoint m_pos;
	QPoint m_charge;
	int m_flag;
	int m_order;
	bool m_cancelEnable;
	BllDataFlow* m_bllDataFlow;
	ShapeMode m_shape;
};

#endif // MEASUREPOINTWIDGET_H
