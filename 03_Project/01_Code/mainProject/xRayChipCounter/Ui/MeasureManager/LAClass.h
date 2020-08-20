#ifndef LACLASS_H
#define LACLASS_H

#include <QObject>
#include <QPoint>
#include "../../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
class LAClass : public QObject
{
	Q_OBJECT

public:
	LAClass(int order,QObject *parent=0);
	~LAClass();
	void updataPos(QPoint, QPoint);
	void calData(QPoint, QPoint);
	QPoint getThree();
	QPoint getOne();
	QPoint getTwo();

	void calAg(QPoint,QPoint,QPoint);
	double getAg();
	double getDis();
	void updateOrder(int);
private:
	QPoint m_one;
	QPoint m_two;
	QPoint m_three;
	double m_k;
	double m_vk;
	double m_b;
	double m_ag;
	double m_dis;
	int m_order;
};

#endif // LACLASS_H
