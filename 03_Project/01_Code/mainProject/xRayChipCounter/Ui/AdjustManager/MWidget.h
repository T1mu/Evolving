#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>
#include "ui_MWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class MWidget : public QWidget
{
	Q_OBJECT

public:
	MWidget(QPoint pos, int length, QWidget *parent);
	~MWidget();
	virtual void  paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	double getX();
	private slots:
	void setMdataSlot(int);
private:
	Ui::MWidget ui;
	QPoint charge;
	QPoint start;
	QPoint data;
	int height;
	BllDetectorKZ* m_bll;
signals:
	void Mmovedata(int);
};

#endif // MWIDGET_H
