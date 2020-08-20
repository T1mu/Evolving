#ifndef PERPENWIRECLASS_H
#define PERPENWIRECLASS_H

#include <QObject>
#include <QPoint>
#include "../../Library/Global.h"
class PerpenWireClass : public QObject
{
	Q_OBJECT

public:
	PerpenWireClass(ShapeMode shape,int order, QObject *parent=0);
	~PerpenWireClass();
	void updatePos(QPoint, QPoint, QPoint);
	void calData();
	QPoint getOne();
	QPoint getTwo();
	QPoint getThree();
	QPoint getFour();
	double getDis();
	double getDisV();
	double getLv();
	void updateOrder(int);
private:
	ShapeMode m_shape;
	int m_order;
	QPoint m_one;
	QPoint m_two;
	QPoint m_three;
	QPoint m_four;
	double m_dis;
	double m_disv;
	double m_lv;
};

#endif // PERPENWIRECLASS_H
