#include "PPClass.h"

PPClass::PPClass(int order, QObject *parent)
	: QObject(parent)
{
	m_order = order;
}

PPClass::~PPClass()
{

}
void PPClass::updatePos(QPoint one, QPoint two, QPoint three, QPoint four){
	m_one = one;
	m_two = two;
	m_three = three;
	m_four = four;
	calData();
}
void PPClass::calData(){
	int x1 = m_one.x();
	int y1 = m_one.y();
	int x2 = m_two.x();
	int y2 = m_two.y();
	int x3 = m_three.x();
	int y3 = m_three.y();
	int x4 = m_four.x();
	int y4 = m_four.y();
	double x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10=0;
	if (x2 != x1){
		//p1 p2;
		double k = (double)(y2 - y1) / (x2 - x1);
		double b = y1 - k*x1;
		//p3 k=k 平行线
		double bb = y3 - k*x3;
		//p4 k=k 平行线
		double bbb = y4 - k*x4;

		// p3 垂线
		double vk = -1 / k;
		double vbb = y3 - vk*x3;

		//p4 垂线
		double vbbb = y4 - vk*x4;

		//---point 5
		double vb1 = y1 - vk*x1;
		x5 = (vb1 - bb) / (k - vk);
		y5 = vk*x5 + vb1;
		/*m_five.setX(x5);
		m_five.setY(y5);*/
		//--point 6
		double vb2 = y2 - vk*x2;
		x6 = (vb2 - bb) / (k - vk);
		y6 = vk*x6 + vb2;
		/*m_six.setX(x6);
		m_six.setY(y6);*/
		//--point 7
		x7 = (vbb - b) / (k - vk);
		y7 = x7*k + b;
		/*m_seven.setX(x7);
		m_seven.setY(y7);*/
		//--point 8
		x8 = (vb1 - bbb) / (k - vk);
		y8 = vk*x8 + vb1;
		/*m_eight.setX(x8);
		m_eight.setY(y8);*/
		//--point 9
		x9 = (vb2 - bbb) / (k - vk);
		y9 = vk*x9 + vb2;
		/*m_nine.setX(x9);
		m_nine.setY(y9);*/
		//--point 10
		x10 = (vbbb - b) / (k - vk);
		y10 = k*x10 + b;
		/*m_ten.setX(x10); 
		m_ten.setY(y10);*/
	
	}
	else{
		x5 = x3;
		y5 = y1;
		x6 = x3;
		y6 = y2;
		x7 = x1;
		y7 = y3;
		x8 = x4;
		y8 = y1;
		x9 = x4;
		y9 = y2;
		x10 = x1;
		y10 = y4;
	
	}

	m_five.setX(x5);
	m_five.setY(y5);

	m_six.setX(x6);
	m_six.setY(y6);

	m_seven.setX(x7);
	m_seven.setY(y7);

	m_eight.setX(x8);
	m_eight.setY(y8);

	m_nine.setX(x9);
	m_nine.setY(y9);

	m_ten.setX(x10);
	m_ten.setY(y10);



	double d = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	m_dis = d;
	double dd = sqrt((x3 - x7)*(x3 - x7) + (y3 - y7)*(y3 - y7));
	m_disv1 = dd;
	double ddd = sqrt((x4 - x10)*(x4 - x10) + (y4 - y10)*(y4 - y10));
	m_disv2 = ddd;

	if (m_disv1 < m_disv2){
		m_lv = m_disv1 / m_disv2;
	}
	else{
		m_lv = m_disv2 / m_disv1;
	}
}
QPoint PPClass::getOne(){
	return m_one;
}
QPoint PPClass::getTwo(){
	return m_two;
}
QPoint PPClass::getThree(){
	return m_three;
}
QPoint PPClass::getFour(){
	return m_four;
}
QPoint PPClass::getFive(){
	return m_five;
}
QPoint PPClass::getSix(){
	return m_six;
}
QPoint PPClass::getSeven(){
	return m_seven;
}
QPoint PPClass::getEight(){
	return m_eight;
}
QPoint PPClass::getNine(){
	return m_nine;
}
QPoint PPClass::getTen(){
	return m_ten;
}

double PPClass::getDis(){
	return m_dis;
}
double PPClass::getDisV1(){
	return m_disv1;
}
double PPClass::getDisV2(){
	return m_disv2;
}
double PPClass::getLv(){
	return m_lv;
}
void PPClass::updateOrder(int order){
	if (order == m_order){
		m_order = m_order - 1;
	}
}