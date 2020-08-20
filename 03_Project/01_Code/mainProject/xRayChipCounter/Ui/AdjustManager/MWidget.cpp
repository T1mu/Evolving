#include "MWidget.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
MWidget::MWidget(QPoint pos, int length, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	m_bll = BllDetectorKZ::instance();
	connect(m_bll, SIGNAL(setMdataSignal(int)), this, SLOT(setMdataSlot(int)));
	height = length;
	start = pos;
	data = pos;
	ui.setupUi(this);
	this->move(start.x() - 5, start.y() - 5);//2019/6/21 改动
	this->setFixedSize(12, height + 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setCursor(Qt::SizeHorCursor);
}

MWidget::~MWidget()
{

}
void  MWidget::paintEvent(QPaintEvent* event){
	QPainter p(this);
	QBrush brush(QColor(250, 128, 114));
	p.setBrush(brush);
	QPolygon pts;
	pts.setPoints(3, 0, 0, 12, 0, 6, 6);
	p.drawConvexPolygon(pts);

	QBrush brush1(QColor(250, 128, 114));
	p.setBrush(brush1);
	QPolygon pts1;
	pts1.setPoints(3, 6, height + 4, 0, height + 11, 12, height + 11);
	p.drawConvexPolygon(pts1);
	//250,128,114
	QPen pen(QColor(250, 128, 114), 2, Qt::DashLine, Qt::RoundCap, Qt::RoundJoin);
	p.setPen(pen);
	//------------2019/12/30改动，两条线变成一条
	p.drawLine(6, 8, 6, height + 3);
	//p.drawLine(4, 5, 4, height + 5);
	//p.drawLine(9, 5, 9, height + 5);
	//---------------------------------------------


}
void MWidget::mouseMoveEvent(QMouseEvent * event){
	//qDebug() << "this is move event this is move event this is move event this is move event ";
	QPoint endPoint = mapToParent(event->pos());
	//qDebug() << "move event endpoint:" << endPoint;
	//qDebug() << "pos:" << mapToParent(event->pos());
	this->move(endPoint.x() - charge
		.x(), start.y() - 5);//2019/6/21 改动
	data = endPoint - charge;
	//emit sendLWidthDataSignal(data.x());
	emit Mmovedata(data.x());
}
void MWidget::mousePressEvent(QMouseEvent * event){
	//qDebug() << "this is press event this is press eventthis is press eventthis is press event";
	//qDebug() << event->pos();
	charge = event->pos();
	//qDebug() << "thi sis charge thi sis charge thi sis charge thi sis charge thi sis charge " << charge;
}
double MWidget::getX(){

	return data.x();
}
void MWidget::setMdataSlot(int l){
	data.setX(l);
	data.setY(start.y() - 5);//2019/6/21 改动
	this->move(data);
}