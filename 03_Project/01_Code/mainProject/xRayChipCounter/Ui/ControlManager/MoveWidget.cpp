#include "MoveWidget.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
MoveWidget::MoveWidget(QPoint &pos, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_position = pos;
	m_blldataflow = BllDataFlow::instance();
	//this->move(m_position.x()-5,m_position.y()-5);
	//qDebug() << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << m_position.x()-5 << "pppppp" << m_position.y()-5;
	this->move(m_position.x() - 5, m_position.y() - 5);
	this->setFixedSize(15, 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	connect(m_blldataflow, SIGNAL(MovePointSignal(QPoint)), this, SLOT(MoveToPosSlot(QPoint)));
	connect(m_blldataflow, SIGNAL(MoveResetSignal(QPoint)), this, SLOT(MoveResetSlot(QPoint)));
}

MoveWidget::~MoveWidget()
{

}
//void MoveWidget::mousePressEvent(QMouseEvent * event){
//	qDebug() << "this is point press event";
//	charge = event->pos();
//	qDebug() << "this is charge point" << charge;
//
//
//}
void MoveWidget::paintEvent(QPaintEvent* event){
	/*this->setSizePolicy(QSizePolicy::Fixed);*/

	qDebug() << "this is point paint event";
	QPainter painter(this);
	QBrush brush(QColor(255, 0, 0));
	painter.setBrush(brush);
	painter.drawEllipse(0, 0, 10, 10);
}
//void MoveWidget::mouseMoveEvent(QMouseEvent * event){
//	qDebug() << "this is point move event" << "888888888888888888888888888888888888";
//	m_position = event->pos();
//	endPoint = mapToParent(m_position - charge);
//	this->move(endPoint);
//}
//void MoveWidget::mouseReleaseEvent(QMouseEvent * event){
//	//emit sendreleasePos(mapToParent(event->pos()));
//
//}
void MoveWidget::MoveToPosSlot(QPoint p){
	qDebug() << "this is movewidget MoveToPosSlot MoveToPosSlot";
	QPoint pp(p.x() - 5, p.y() - 5);
	this->move(pp);
}
void MoveWidget::MoveResetSlot(QPoint p){
	QPoint pp(p.x() - 5, p.y() - 5);
	this->move(pp);
}
