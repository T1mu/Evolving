#ifndef PPCLASS_H
#define PPCLASS_H

#include <QObject>
#include <QPoint>
#include "../../Library/Global.h"
class PPClass : public QObject
{
	Q_OBJECT

public:
	PPClass(int order,QObject *parent=0);
	~PPClass();
	void updatePos(QPoint, QPoint, QPoint,QPoint);
	void calData();
	QPoint getOne();
	QPoint getTwo();
	QPoint getThree();
	QPoint getFour();
	QPoint getFive();
	QPoint getSix();
	QPoint getSeven();
	QPoint getEight();
	QPoint getNine();
	QPoint getTen();

	double getDis();
	double getDisV1();
	double getDisV2();
	double getLv();
	void updateOrder(int);
private:
	int m_order;
	QPoint m_one;
	QPoint m_two;
	QPoint m_three;
	QPoint m_four;
	QPoint m_five;
	QPoint m_six;
	QPoint m_seven;
	QPoint m_eight;
	QPoint m_nine;
	QPoint m_ten;
	double m_dis;
	double m_disv1;
	double m_disv2;
	double m_lv;
};

#endif // PPCLASS_H
