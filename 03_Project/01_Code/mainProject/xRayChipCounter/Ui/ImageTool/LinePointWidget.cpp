#include "LinePointWidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
LinePointWidget::LinePointWidget(QPoint &pos, int serial, int flags, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	m_position = pos;
	position = pos;
	order = serial;
	flag = flags;
	widthLimit = 0;
	heightLimit = 0;
	m_bll = BllDataFlow::instance();
	this->move(pos.x() - 3, pos.y() - 3);
	this->setFixedSize(15, 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	setCursor(Qt::SizeAllCursor);
	connect(m_bll, SIGNAL(LineMoveChangePointSignal(int, int, QPoint)),
		this, SLOT(LineMoveChangePointSlot(int, int, QPoint)));
	connect(m_bll, SIGNAL(updateLinepointSerialSignal(int)),
		this, SLOT(updateLinepointSerialSlot(int)));
	connect(m_bll, SIGNAL(iniLineLimitSignal(int, int)),
		this, SLOT(iniLineLimitSlot(int, int)));
}

LinePointWidget::~LinePointWidget()
{

}
void LinePointWidget::mousePressEvent(QMouseEvent * event){
	charge = event->pos();
	qDebug() << "this is test press event-----" << mapToParent(event->pos());
}
void LinePointWidget::paintEvent(QPaintEvent* event){
	QPainter painter(this);
	QBrush brush(QColor(255, 0, 0));
	painter.setBrush(brush);
	painter.drawEllipse(0, 0, 6, 6);

}
void LinePointWidget::mouseMoveEvent(QMouseEvent * event){
	m_position = event->pos();
	position = mapToParent(m_position - charge);
	/*if (position.x() < 5){
	position.setX(5);
	}*/
	judgeOver(position);
	this->move(position);
	judgeOver(position);
	QPoint p(position.x() + 5, position.y() + 5);



	position = p;
	//this->move(position);
	m_bll->LinepointMove(order, flag, p);

}
QPoint LinePointWidget::getPos(){
	//qDebug() << "this is PointWidget getPos()" << position;
	return position;

}
void LinePointWidget::pointChangeSlot(int flags){
	if (order == 0){
		order = 1;
	}
	if (order == 1){
		order = 0;
	}

}
void LinePointWidget::LineMoveChangePointSlot(int linenumber, int flagpos, QPoint pos){
	if (linenumber == order){
		qDebug() << "this is linenumber   move---" << order;
		if (flagpos == flag){
			position.setX(pos.x());
			position.setY(pos.y());
			this->move(position.x() - 5, position.y() - 5);

		}


	}

}
void LinePointWidget::judgeOver(QPoint &p){

	if (p.x() <= 10){
		p.setX(10);
	}
	int w = widthLimit - 20;
	if (p.x() >= w){
		p.setX(w);

	}

	if (p.y() <= 10){
		p.setY(10);
	}
	int h = heightLimit - 20;
	if (p.y() >= h){
		p.setY(h);

	}

}
void LinePointWidget::updateLinepointSerialSlot(int lines){
	if (lines == order){
		order = order - 1;
	}
}
void LinePointWidget::iniLineLimitSlot(int w, int h){

	widthLimit = w;
	heightLimit = h;


}