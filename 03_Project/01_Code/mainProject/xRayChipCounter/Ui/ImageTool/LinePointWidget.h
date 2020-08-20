#ifndef LINEPOINTWIDGET_H
#define LINEPOINTWIDGET_H

#include <QWidget>
#include "ui_LinePointWidget.h"
#include "../../Library/MyHelper.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"
class LinePointWidget : public QWidget
{
	Q_OBJECT

public:
	LinePointWidget(QPoint &pos = QPoint(0, 0), int serial = 0, int flags = 0, QWidget *parent = 0);
	~LinePointWidget();
	QPoint getPos();
	void judgeOver(QPoint &p);
protected:

	virtual void mousePressEvent(QMouseEvent * event);
	virtual void paintEvent(QPaintEvent* event);
	virtual void mouseMoveEvent(QMouseEvent * event);
	private slots:
	void pointChangeSlot(int);
	void LineMoveChangePointSlot(int, int, QPoint);
	void updateLinepointSerialSlot(int);
	void iniLineLimitSlot(int, int);
private:
	Ui::LinePointWidget ui;
	QPoint m_position;//µ±«∞Œª÷√
	QPoint position;
	QPoint charge;
	int order;
	int flag;
	BllDataFlow *m_bll;
	int widthLimit;
	int heightLimit;
};

#endif // LINEPOINTWIDGET_H
