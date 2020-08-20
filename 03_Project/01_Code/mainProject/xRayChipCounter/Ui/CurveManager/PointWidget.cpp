#include "PointWidget.h"
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
PointWidget::PointWidget(QPoint &pos, QWidget *parent, int flag)
: QWidget(parent)
{
	ui.setupUi(this);
	m_bll = BllDetectorKZ::instance();
	connect(m_bll, SIGNAL(setLimitSignal(int, int, int, int)), this, SLOT(setLimitSlot(int, int, int, int)));
	m_position = pos;
	position = pos;
	this->move(m_position.x() - 4, m_position.y() - 7);
	this->setFixedSize(15, 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setCursor(Qt::SizeAllCursor);
	order = flag;
	limit_up = 0;
	limit_down = 0;
	limit_left = 0;
	limit_right = 0;
}

PointWidget::~PointWidget()
{

}
void PointWidget::mousePressEvent(QMouseEvent * event){

	charge = event->pos();

}
void  PointWidget::paintEvent(QPaintEvent* event){
	QPainter painter(this);
	QBrush brush(QColor(127, 255, 170));
	painter.setBrush(brush);
	painter.drawEllipse(0, 0, 8, 8);

}
void PointWidget::mouseMoveEvent(QMouseEvent * event){
	m_position = event->pos();
	QPoint p(4, 4);
	position = mapToParent(m_position - p);
	judgemove(position);
	//qDebug() << "move pos==========" << position;
	this->move(position);
	int x = position.x() + 4;
	int y = position.y() + 7;
	position.setX(x);
	position.setY(y);
	m_bll->pointmove();
}
QPoint PointWidget::getpos(){

	return position;
}
void PointWidget::setLimitSlot(int u, int d, int l, int r){
	limit_up = u;
	limit_down = d;
	limit_left = l;
	limit_right = r;
}
void PointWidget::judgemove(QPoint& pos){
	qDebug() << "pos=======" << pos.x() << ";;" << pos.y();
	qDebug() << "limit-----";
	qDebug() << "left---" << limit_left;
	qDebug() << "right---" << limit_right;
	qDebug() << "up---" << limit_up;
	qDebug() << "down---" << limit_down;

	//left over
	if (pos.x() < limit_left){
		pos.setX(limit_left - 2);
	}
	//right over
	if (pos.x()>limit_right - 4){
		pos.setX(limit_right - 4);
	}
	//up over
	if (pos.y()<limit_up){
		pos.setY(limit_up - 7);
	}
	//down over
	if (pos.y()>limit_down - 4){
		pos.setY(limit_down - 4);
	}
}