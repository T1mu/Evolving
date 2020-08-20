#ifndef LINE_H
#define LINE_H

#include <QObject>
#include <QPointF>
#include <QVector>
#include "../../Library/MyHelper.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"
class Line : public QObject
{
	Q_OBJECT

public:
	Line(int order = 0, QObject *parent = 0);
	~Line();
	QVector<QPointF> getLinePoint();
	QVector<QPointF> getVLinePoint();
	void setPoint(QPointF s, QPointF e);
	QPointF getStartP();
	QPointF getEndP();
	void calK_B_VK(QPointF s, QPointF e);
	void calD();
	void calPoint(int multiple);
	void calVPoint(double x, double y);
	void updateDate(QPointF s, QPointF e);
	void appenVlinePoint(double x, double y);
	void updateSerial();
	double getK();
	double getB();
	double getDistance();
	double getRealD();
private:
	QPointF startp;
	QPointF endp;
	QVector<QPointF> vec_line;
	QVector<QPointF> vec_Vline;
	double k;
	double b;
	double vk;
	int serial;
	double distance;
	double xvalue;
	double yvalue;
	double realD;
	BllDataFlow* m_bll;
};

#endif // LINE_H
