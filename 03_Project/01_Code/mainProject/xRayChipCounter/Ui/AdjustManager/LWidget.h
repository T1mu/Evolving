#ifndef LWIDGET_H
#define LWIDGET_H

#include <QWidget>
#include "ui_LWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
class LWidget : public QWidget
{
	Q_OBJECT

public:
	LWidget(QPoint pos, int length, QWidget *parent);
	~LWidget();
	virtual void  paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	double getX();

	private slots:
	void setLdataSlot(int);
private:
	Ui::LWidget ui;
	QPoint charge;
	QPoint start;
	QPoint data;
	int height;
	BllDetectorKZ* m_bll;
signals:
	void Lmovedata(int);
	
};

#endif // LWIDGET_H
