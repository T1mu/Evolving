#include "LAPointWidget.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPainter>
LAPointWidget::LAPointWidget(ShapeMode shape,QPoint pos, int flag, int order, QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_shape = shape;
	m_pos = pos;
	m_charge.setX(6);
	m_charge.setY(6);
	m_flag = flag;
	m_order = order;
	m_cancelEnable = false;
	m_bllDataFlow = BllDataFlow::instance();
	this->setFixedSize(14, 14);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setCursor(Qt::SizeAllCursor);
	this->move(pos.x() - 6, pos.y() - 6);
}

LAPointWidget::~LAPointWidget()
{

}
void LAPointWidget::mouseMoveEvent(QMouseEvent * event){
	QPoint p = mapToParent(event->pos() - m_charge);
	QPoint pp = mapToParent(event->pos());
	this->move(p);
	m_pos = pp;
	m_bllDataFlow->setLaMove(m_shape, m_order, m_flag);

}
void LAPointWidget::mousePressEvent(QMouseEvent * event){
	if (m_cancelEnable){
		m_bllDataFlow->setlaCancel(m_order);
	}
	else{
		m_bllDataFlow->setMoveLimit();
		//this->setFixedSize(30, 30);
	}
}
void LAPointWidget::mouseReleaseEvent(QMouseEvent * event){
	m_bllDataFlow->cancelMoveLimitSignal();
	//this->setFixedSize(7, 7);
}
void LAPointWidget::paintEvent(QPaintEvent* event){
	QPainter painter(this);
	QBrush brush(QColor(127, 255, 170));
	painter.setBrush(brush);
	painter.drawEllipse(3, 3, 6, 6);
}
QPoint LAPointWidget::getPos(){
	return m_pos;
}
void LAPointWidget::updateDeleteCursor(){
	m_cancelEnable = !m_cancelEnable;
	if (m_cancelEnable){
		//this->setFixedSize(30, 30);
		setCursor(Qt::PointingHandCursor);
	}
	else{
		//this->setFixedSize(7, 7);
		setCursor(Qt::SizeAllCursor);
	}
}
void LAPointWidget::updateOrder(int order){
	if (order == m_order){
		m_order = m_order - 1;
	}
}