#include "RWidget.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
RWidget::RWidget(QPoint pos, int length, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	m_bll = BllDetectorKZ::instance();
	connect(m_bll, SIGNAL(setRdataSignal(int)), this, SLOT(setRdataSlot(int)));
	height = length;
	start = pos;
	data = pos;
	ui.setupUi(this);
	this->move(start.x() - 5, start.y() - 5);//2019/6/21 改动
	this->setFixedSize(12, height + 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setCursor(Qt::SizeHorCursor);
}

RWidget::~RWidget()
{

}
void  RWidget::paintEvent(QPaintEvent* event){
	QPainter p(this);
	QBrush brush(QColor(0, 255, 255));
	p.setBrush(brush);
	QPolygon pts;
	pts.setPoints(3, 0, 0, 12, 0, 6, 6);
	p.drawConvexPolygon(pts);

	QBrush brush1(QColor(0, 255, 255));
	p.setBrush(brush1);
	QPolygon pts1;
	pts1.setPoints(3, 6, height + 5, 0, height + 11, 12, height + 11);
	p.drawConvexPolygon(pts1);

	QPen pen(QColor(0, 255, 255), 2, Qt::DashDotLine, Qt::RoundCap, Qt::RoundJoin);
	p.setPen(pen);
	p.drawLine(6, 8, 6, height + 4);



}
void RWidget::mouseMoveEvent(QMouseEvent * event){
	//qDebug() << "this is move event this is move event this is move event this is move event ";
	QPoint endPoint = mapToParent(event->pos());
	//qDebug() << "move event endpoint:" << endPoint;
	//qDebug() << "pos:" << mapToParent(event->pos());
	this->move(endPoint.x() - charge
		.x(), start.y() - 5);//2019/6/21 改动
	data = endPoint - charge;
	//emit sendLWidthDataSignal(data.x());
	emit Rmovedata(data.x());
}
void RWidget::mousePressEvent(QMouseEvent * event){
	//qDebug() << "this is press event this is press eventthis is press eventthis is press event";
	//qDebug() << event->pos();
	charge = event->pos();
	//qDebug() << "thi sis charge thi sis charge thi sis charge thi sis charge thi sis charge " << charge;
}
double RWidget::getX(){

	return data.x();
}
void RWidget::setRdataSlot(int l){
	data.setX(l);
	data.setY(start.y() - 5);//2019/6/21 改动
	this->move(data);
}