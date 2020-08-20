#include "PerpenWireClass.h"

PerpenWireClass::PerpenWireClass(ShapeMode shape, int order, QObject *parent)
	: QObject(parent)
{
	m_shape = shape;
	m_order = order;
	m_dis = 0;
	m_disv = 0;
}

PerpenWireClass::~PerpenWireClass()
{

}
void PerpenWireClass::updatePos(QPoint one, QPoint two, QPoint three){
	m_one = one;
	m_two = two;
	m_three = three;
	calData();
}
void PerpenWireClass::calData(){
	int x1 = m_one.x();
	int y1 = m_one.y();
	int x2 = m_two.x();
	int y2 = m_two.y();
	int x3 = m_three.x();
	int y3 = m_three.y();
	if (x2 - x1 != 0){
		double k = (double)(y2 - y1) / (x2 - x1);
		double b = (double)(y1 - k*x1);
		double vk = -1 / k;
		/**/
		double vb = (double)(y3 - vk*x3);
		double x = (vb - b) / (k - vk);
		double y = k*x + b;
		m_four.setX(x);
		m_four.setY(y);
	}
	else{
		m_four.setX(m_one.x());
		m_four.setY(m_three.y());
	}
	double DD = (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1);
	double D = sqrt(DD);
	m_dis = D;
	int x4 = m_four.x();
	int y4 = m_four.y();
	double ff = (y4 - y3)*(y4 - y3) + (x4 - x3)*(x4 - x3);
	double f = sqrt(ff);
	m_disv = f;
	m_lv = m_disv / m_dis;
}
QPoint PerpenWireClass::getOne(){
	return m_one;
}
QPoint PerpenWireClass::getTwo(){
	return m_two;
}
QPoint PerpenWireClass::getThree(){
	return m_three;
}
QPoint PerpenWireClass::getFour(){
	return m_four;
}
double PerpenWireClass::getDis(){
	return m_dis;
}
double PerpenWireClass::getDisV(){
	return m_disv;
}
double PerpenWireClass::getLv(){
	return m_lv;
}
void PerpenWireClass::updateOrder(int order){
	if (m_order == order){
		m_order = m_order - 1;
	}
}