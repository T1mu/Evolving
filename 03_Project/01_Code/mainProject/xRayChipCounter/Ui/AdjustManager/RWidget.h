#ifndef RWIDGET_H
#define RWIDGET_H

#include <QWidget>
#include "ui_RWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class RWidget : public QWidget
{
	Q_OBJECT

public:
	RWidget(QPoint pos, int length, QWidget *parent);
	~RWidget();
	virtual void  paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	double getX();
	private slots:
	void setRdataSlot(int);
private:
	Ui::RWidget ui;
	QPoint charge;
	QPoint start;
	QPoint data;
	int height;
	BllDetectorKZ* m_bll;
signals:
	void Rmovedata(int);
};

#endif // RWIDGET_H
