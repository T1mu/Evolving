#ifndef RECTWIDGET_H
#define RECTWIDGET_H

#include <QWidget>
#include "ui_RectWidget.h"
#include "../../Library/MyHelper.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"
class RectWidget : public QWidget
{
	Q_OBJECT

public:
	RectWidget(QPoint &pos = QPoint(0, 0), int serial = 0, QWidget *parent = 0);
	~RectWidget();
	void resizeWidget(int w, int h);
protected:

	virtual void mousePressEvent(QMouseEvent * event);
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	private slots:
	void RectPointReadytoMoveSlot(int, int, QPoint);
	void setRectPointMoveLimitSlot(int, int, QPoint);
	void iniDisplayLimitSlot(int, int);
	void cancelShapeSlot();
	void updateRectSerialSlot(int);
	void unableCancelShapeSlot();
private:
	Ui::RectWidget ui;
	QPoint leftTop;
	QPoint rightTop;
	QPoint leftBottom;
	QPoint rightBottom;
	QPoint middle;
	QPoint position;
	QPoint charge;;
	int width;
	int height;
	int widthLimit;
	int heightLimit;
	/*Rect* leftRect;
	Rect* rightRect;*/
	BllDataFlow* m_bll;
	int order;
	QPoint tmp;
	bool cancelRectEnable;
};

#endif // RECTWIDGET_H
