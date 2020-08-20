#include "LAClass.h"

LAClass::LAClass(int order, QObject *parent)
	: QObject(parent)
{
	m_order = order;

}

LAClass::~LAClass()
{

}
void LAClass::updataPos(QPoint start, QPoint end){
	m_one = start;
	m_two = end;
	calData(m_one, m_two);
}
void LAClass::calData(QPoint s, QPoint e){
	int x1 = s.x();
	int y1 = s.y();
	int x2 = e.x();
	int y2 = e.y();
	int sizeLimit = BllDetectorKZ::returnSize();
	if (x2 - x1 != 0){
		m_k = (double)(y2 - y1) / (x2 - x1);
		m_vk = -1 / m_k;
		m_b = (double)(y1 - m_k*x1);
		double DD = (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1);
		double D = sqrt(DD);
		m_dis = D;
		int diss = m_one.x() + D;
		if (diss >= sizeLimit)
		{
			diss = sizeLimit;
		}
		m_three.setX(diss);
		m_three.setY(m_one.y());
	}
	else{
		double d = y2 - y1;
		m_dis = d;
		int diss = m_one.x() + d;
		if (diss >= sizeLimit)
		{
			diss = sizeLimit;
		}
		m_three.setX(diss);
		m_three.setY(m_one.y());
	}
	

	calAg(m_one, m_two, m_three);
}
QPoint LAClass::getThree(){
	return m_three;
}
QPoint LAClass::getOne(){
	return m_one;
}
QPoint LAClass::getTwo(){
	return m_two;
}
void LAClass::calAg(QPoint f, QPoint s, QPoint t){
	QPoint fs;
	fs.setX(s.x() - f.x());
	fs.setY(s.y() - f.y());
	QPoint ft;
	ft.setX(t.x() - f.x());
	ft.setY(t.y() - f.y());

	double up = fs.x()*ft.x() + fs.y()*ft.y();
	double down = sqrt((fs.x()*fs.x() + fs.y()*fs.y())) * sqrt((ft.x()*ft.x() + ft.y()*ft.y()));
	double cos = up / down;
	double angle = acos(cos) * 180 / 3.1415926;
	m_ag = angle;
}
double LAClass::getAg(){
	return m_ag;
}
double LAClass::getDis(){
	return m_dis;
}
void LAClass::updateOrder(int order){
	if (order == m_order){
		m_order = m_order - 1;
	}
}

