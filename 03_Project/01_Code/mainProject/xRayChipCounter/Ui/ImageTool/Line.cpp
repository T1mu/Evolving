#include "Line.h"
#include <QDebug>
Line::Line(int order, QObject *parent)
: QObject(parent)
{
	k = 0;
	b = 0;
	vk = 0;
	distance = 0;
	serial = order;
	xvalue = 0;
	yvalue = 0;
}

Line::~Line()
{

}
QVector<QPointF> Line::getLinePoint(){
	if (vec_line.size() != 0){
		return vec_line;
	}
	QVector<QPointF> tmp;
	return tmp;

}
QVector<QPointF> Line::getVLinePoint(){
	if (vec_Vline.size() != 0){
		return vec_Vline;
	}
	QVector<QPointF> tmp;
	return tmp;

}
void Line::setPoint(QPointF s, QPointF e){

	startp = s;
	endp = e;




	calK_B_VK(startp, endp);

}
QPointF Line::getStartP(){
	return startp;
}
QPointF Line::getEndP(){
	return endp;
}
void Line::calK_B_VK(QPointF s, QPointF e){
	int x1 = s.x();
	int y1 = s.y();
	int x2 = e.x();
	int y2 = e.y();

	if (x1 != x2){
		k = (double)(y1 - y2) / (x1 - x2);
		b = (double)(y1 - k*x1);

	}
	//qDebug() << "this is line k and b------" << k << ";;" << b;
	vk = -1 / k;
	//qDebug() << "this is vk---------------" << vk;
	calD();

}
void Line::calD(){
	int x1 = startp.x();
	int y1 = startp.y();
	int x2 = endp.x();
	int y2 = endp.y();
	double DD = (y2 - y1)*(y2 - y1) + (x2 - x1)*(x2 - x1);
	double D = sqrt(DD);

	distance = D;


	int pointnum = D / 30;
	double lastvalue = (D - pointnum * 30) / 30 * 10;

	realD = 10 * pointnum + lastvalue;



	for (int i = 1; i <= pointnum; i++){
		calPoint(i);
	}

}
void Line::calPoint(int multiple){
	int x1 = startp.x();
	int y1 = startp.y();
	double aa = k*k + 1;
	double bb = 2 * (k*b - k*y1 - x1);
	double cc = (b - y1)*(b - y1) + x1*x1 - 900 * multiple*multiple;

	//qDebug() << "this is a b and c==============" << aa << ";;" << bb << ";;" << cc;
	double delta = bb*bb - 4 * aa*cc;
	if (delta >= 0)
	{
		if (delta >0)
		{
			double xvalue1 = (-bb + sqrt(delta)) / (2 * aa);
			double xvalue2 = (-bb - sqrt(delta)) / (2 * aa);
			//qDebug() << "two result not equal---------" << xvalue1 << ";;" << xvalue2;
			if (k > 0){
				if (xvalue1 > xvalue2){
					xvalue = xvalue1;
				}
				else{

					xvalue = xvalue2;
				}
				yvalue = xvalue*k + b;
			}
			else{
				if (xvalue1 < xvalue2){
					xvalue = xvalue1;
				}
				else{

					xvalue = xvalue2;
				}
				yvalue = xvalue*k + b;

			}



		}
		else
		{
			double xvalue1 = -bb / (2 * aa);
			xvalue = xvalue1;
			yvalue = xvalue*k + b;

			qDebug() << "two result equal---------" << xvalue1;
		}
		QPointF p(xvalue, yvalue);
		vec_line.append(p);
		calVPoint(xvalue, yvalue);
	}
	else
		qDebug() << "no result";



}
void Line::calVPoint(double x, double y){
	if (k != 0){

		/*double vb = y - vk*x;
		double xx = x + 7;
		double yy = vk*xx + vb;

		QPointF p(xx, yy);
		vec_Vline.append(p);*/
		appenVlinePoint(x, y);
	}
}
void Line::updateDate(QPointF s, QPointF e){


	startp = s;
	endp = e;

	vec_line.clear();
	vec_Vline.clear();
	calK_B_VK(startp, endp);
}
void Line::appenVlinePoint(double x, double y){
	int x1 = x;
	int y1 = y;
	double vb = y - vk*x;
	double aa = vk*vk + 1;
	double bb = 2 * (vk*vb - vk*y1 - x1);
	double cc = (vb - y1)*(vb - y1) + x1*x1 - 49;
	double delta = bb*bb - 4 * aa*cc;
	double xvalues = 0;
	double yvalues = 0;
	if (delta >= 0)
	{
		if (delta >0)
		{
			double xvalue1 = (-bb + sqrt(delta)) / (2 * aa);
			double xvalue2 = (-bb - sqrt(delta)) / (2 * aa);

			//qDebug() << "two result not equal---------" << xvalue1 << ";;" << xvalue2;
			if (k > 0){
				if (xvalue1 > xvalue2){
					xvalues = xvalue1;
				}
				else{

					xvalues = xvalue2;
				}
				yvalues = xvalues*vk + vb;
			}
			else{
				if (xvalue1 < xvalue2){
					xvalues = xvalue1;
				}
				else{

					xvalues = xvalue2;
				}
				yvalues = xvalues*vk + vb;

			}

		}
		else
		{
			double xvalue1 = -bb / (2 * aa);
			xvalues = xvalue1;
			yvalues = xvalues*vk + vb;


		}
		QPointF p(xvalues, yvalues);
		vec_Vline.append(p);

	}
	else
		qDebug() << "no result";


}
double Line::getK(){
	return k;
}
double Line::getB(){
	return b;
}
double Line::getDistance(){
	return distance;
}
double Line::getRealD(){
	return realD;
}
void Line::updateSerial(){

	serial = serial - 1;
}