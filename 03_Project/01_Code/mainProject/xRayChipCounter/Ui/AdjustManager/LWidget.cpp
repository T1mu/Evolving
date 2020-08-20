#include "LWidget.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
LWidget::LWidget(QPoint pos, int length, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	m_bll = BllDetectorKZ::instance();
	connect(m_bll, SIGNAL(setLdataSignal(int)), this, SLOT(setLdataSlot(int)));
	height = length;
	start = pos;
	data = pos;
	ui.setupUi(this);
	this->move(start.x()-5, start.y() - 5);//2019/6/21 改动
	this->setFixedSize(12, height + 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setCursor(Qt::SizeHorCursor);
}

LWidget::~LWidget()
{

}
void  LWidget::paintEvent(QPaintEvent* event){
	QPainter p(this);
	QBrush brush(QColor(0, 255, 255));
	p.setBrush(brush);
	QPolygon pts;
	pts.setPoints(3, 0, 0, 12, 0, 6, 6);
	p.drawConvexPolygon(pts);

	QBrush brush1(QColor(0, 255, 255));
	p.setBrush(brush1);
	QPolygon pts1;
	pts1.setPoints(3, 6, height + 4, 0, height + 10, 12, height + 10);
	p.drawConvexPolygon(pts1);

	QPen pen(QColor(0, 255, 255), 2, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
	p.setPen(pen);
	p.drawLine(6, 8, 6, height + 3);



}
void LWidget::mouseMoveEvent(QMouseEvent * event){
	
	QPoint endPoint = mapToParent(event->pos());
	this->move(endPoint.x() - charge
		.x(), start.y() - 5);//2019/6/21 改动
	data = endPoint - charge;
	emit Lmovedata(data.x());
}
void LWidget::mousePressEvent(QMouseEvent * event){

	charge = event->pos();

}
double LWidget::getX(){

	return data.x();
}
void LWidget::setLdataSlot(int l){
	data.setX(l - 5);//2019/11/27 改动将L的可移动范围向左移动5个单位，否则左侧的移动范围会少5个单位
	data.setY(start.y() - 5);//2019/6/21 改动
	this->move(data);

}