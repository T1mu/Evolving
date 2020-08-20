#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QWidget>
#include "ui_CircleWidget.h"
#include "../../Library/MyHelper.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"
class CircleWidget : public QWidget
{
	Q_OBJECT

public:
	CircleWidget(QPoint &pos = QPoint(0, 0), int serial = 0, int r = 0, QWidget *parent = 0);
	~CircleWidget();
	void resizeWidget();
protected:

	virtual void mousePressEvent(QMouseEvent * event);
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	private slots:
	void RadiousChangedSlot(int);
	void cancelShapeSlot();
	void updateCircleSerialSlot(int);
	void unableCancelShapeSlot();
private:
	Ui::CircleWidget ui;
	int radious;
	int width;
	int height;
	QPoint position;
	QPoint charge;
	QPoint leftTop;
	int circleSerial;
	BllDataFlow* m_bll;
	QPoint tmpPos;
	bool cancelCircleEnable;
};

#endif // CIRCLEWIDGET_H
