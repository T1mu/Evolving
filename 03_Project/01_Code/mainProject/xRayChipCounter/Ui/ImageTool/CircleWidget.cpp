#include "CircleWidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
CircleWidget::CircleWidget(QPoint &pos, int serial, int r, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	cancelCircleEnable = false;
	position = pos;
	tmpPos = pos;
	circleSerial = serial;
	radious = r;
	int x = pos.x() - radious;
	int y = pos.y() - radious;
	leftTop.setX(x);
	leftTop.setY(y);
	resizeWidget();
	this->move(leftTop.x(), leftTop.y());
	m_bll = BllDataFlow::instance();
	connect(m_bll, SIGNAL(RadiousChangedSignal(int)),
		this, SLOT(RadiousChangedSlot(int)));
	connect(m_bll, SIGNAL(cancelShapeSignal()),
		this, SLOT(cancelShapeSlot()));
	connect(m_bll, SIGNAL(updateCircleSerialSignal(int)),
		this, SLOT(updateCircleSerialSlot(int)));
	connect(m_bll, SIGNAL(unableCancelShapeSignal()),
		this, SLOT(unableCancelShapeSlot()));
	setCursor(Qt::CrossCursor);
	setAttribute(Qt::WA_DeleteOnClose);
}

CircleWidget::~CircleWidget()
{
	//qDebug() << "ddd";
}
void CircleWidget::mousePressEvent(QMouseEvent * event){
	if (cancelCircleEnable){
		m_bll->cancelCircle(circleSerial);
		//setCursor(Qt::CrossCursor);
		cancelCircleEnable = false;

	}
}
void CircleWidget::paintEvent(QPaintEvent* event){
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
	painter.setRenderHint(QPainter::Antialiasing, true);
	//painter.drawRect(0, 0, width, height);
	painter.drawEllipse(1, 1, radious * 2, radious * 2);//»­Ô²

}
void CircleWidget::mouseMoveEvent(QMouseEvent * event){
	QPoint p = mapToParent(event->pos());
	int x = p.x() - tmpPos.x();
	int y = p.y() - tmpPos.y();
	leftTop.setX(leftTop.x() + x);
	leftTop.setY(leftTop.y() + y);
	this->move(leftTop);
	tmpPos = p;

}
void CircleWidget::resizeWidget(){
	width = radious + radious + 5;
	height = radious + radious + 5;
	this->resize(width, height);
	update();
}
void CircleWidget::RadiousChangedSlot(int r){
	radious = r;
	resizeWidget();

}
void CircleWidget::cancelShapeSlot(){
	cancelCircleEnable = true;
	setCursor(Qt::PointingHandCursor);
}
void CircleWidget::updateCircleSerialSlot(int serial){
	if (circleSerial == serial){
		circleSerial = circleSerial - 1;
	}
}
void CircleWidget::unableCancelShapeSlot(){
	cancelCircleEnable = false;
	setCursor(Qt::CrossCursor);
}
