#ifndef RECTPOINTWIDGET_H
#define RECTPOINTWIDGET_H

#include <QWidget>
#include "ui_RectPointWidget.h"
#include "../../Library/MyHelper.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"
class RectPointWidget : public QWidget
{
	Q_OBJECT

public:
	RectPointWidget(QPoint &pos = QPoint(0, 0), int serial = 0, int lines = 100, QWidget *parent = 0);
	~RectPointWidget();
	void judgeOver(QPoint, int, int, int, int);
protected:

	virtual void mousePressEvent(QMouseEvent * event);
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	private slots:
	void RectMovepointsSlot(int, int, int, int, int);

	void getRectPointMoveLimitSlot(int, int, int, int, int, int, QPoint);
	void RectMovePointsSlot(int, int, QPoint);
	void updateRectPointsSerialSlot(int);
private:
	Ui::RectPointWidget ui;
	QPoint position;
	QPoint charge;
	int Porder;
	int lineSerial;
	BllDataFlow* m_bll;
};

#endif // RECTPOINTWIDGET_H
