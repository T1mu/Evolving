#ifndef LAPOINTWIDGET_H
#define LAPOINTWIDGET_H

#include <QWidget>
#include "ui_LAPointWidget.h"
#include "../../Library/Global.h"
#include "../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 

class LAPointWidget : public QWidget
{
	Q_OBJECT

public:
	LAPointWidget(ShapeMode shape, QPoint pos, int flag,int order,QWidget *parent = 0);
	~LAPointWidget();
	QPoint getPos();
	void updateDeleteCursor();
	void updateOrder(int);
protected:
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void paintEvent(QPaintEvent* event);
	
private:
	Ui::LAPointWidget ui;
	QPoint m_pos;
	QPoint m_charge;
	int m_flag;
	int m_order;
	bool m_cancelEnable;
	BllDataFlow* m_bllDataFlow;
	ShapeMode m_shape;
};

#endif // LAPOINTWIDGET_H
