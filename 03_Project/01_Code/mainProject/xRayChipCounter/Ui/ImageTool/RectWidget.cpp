#include "RectWidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
RectWidget::RectWidget(QPoint &pos, int serial, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	position = pos;
	cancelRectEnable = false;
	qDebug() << "this ini widget=========" << pos;
	order = serial;
	leftTop.setX(position.x() - 50);
	leftTop.setY(position.y() - 40);
	rightBottom.setX(position.x() + 50);
	rightBottom.setY(position.y() + 40);
	rightTop.setX(rightBottom.x());
	rightTop.setY(leftTop.y());

	leftBottom.setX(leftTop.x());
	leftBottom.setY(rightBottom.y());



	width = 100;
	height = 80;
	widthLimit = 0;
	heightLimit = 0;
	this->move(leftTop);
	this->setCursor(Qt::CrossCursor);

	resizeWidget(width, height);

	//setCursor(Qt::SizeAllCursor);
	m_bll = BllDataFlow::instance();
	connect(m_bll, SIGNAL(RectPointReadytoMoveSignal(int, int, QPoint)),
		this, SLOT(RectPointReadytoMoveSlot(int, int, QPoint)));

	//setRectPointMoveLimitSignal(int, int, QPoint);
	connect(m_bll, SIGNAL(setRectPointMoveLimitSignal(int, int, QPoint)),
		this, SLOT(setRectPointMoveLimitSlot(int, int, QPoint)));
	connect(m_bll, SIGNAL(iniDisplayLimitSignaltest(int, int)),
		this, SLOT(iniDisplayLimitSlot(int, int)));

	connect(m_bll, SIGNAL(cancelShapeSignal()),
		this, SLOT(cancelShapeSlot()));
	connect(m_bll, SIGNAL(updateRectSerialSignal(int)),
		this, SLOT(updateRectSerialSlot(int)));
	connect(m_bll, SIGNAL(unableCancelShapeSignal()),
		this, SLOT(unableCancelShapeSlot()));

	m_bll->iniRectPoint(leftTop, rightTop, leftBottom, rightBottom, order);
	//RectPointMoveSignal(int, QPoint)
	int x = (leftTop.x() + rightTop.x()) / 2;
	int y = (leftTop.y() + leftBottom.y()) / 2;
	tmp.setX(x);
	tmp.setY(y);
	setAttribute(Qt::WA_DeleteOnClose);
}

RectWidget::~RectWidget()
{
	//qDebug() << "this is RectWidget delete";
}
void RectWidget::mousePressEvent(QMouseEvent * event){
	//charge = event->pos();
	if (cancelRectEnable){
		m_bll->cancelRect(order);

		setCursor(Qt::CrossCursor);
		cancelRectEnable = false;
	}
}
void RectWidget::paintEvent(QPaintEvent* event){
	QPainter painter(this);
	painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
	painter.drawRect(0, 0, width, height);

}
void RectWidget::mouseMoveEvent(QMouseEvent * event){
	QPoint p = mapToParent(event->pos());
	/*qDebug() << "this is pos---------" << p;
	qDebug() << "this is tmp pos------" << tmp;*/
	int x = p.x() - tmp.x();
	int y = p.y() - tmp.y();
	//qDebug() << "xxxxxxxxxxx yyyyy----" << x << ";;" << y;
	leftTop.setX(leftTop.x() + x);
	leftTop.setY(leftTop.y() + y);
	rightTop.setX(rightTop.x() + x);
	rightTop.setY(rightTop.y() + y);
	leftBottom.setX(leftBottom.x() + x);
	leftBottom.setY(leftBottom.y() + y);
	rightBottom.setX(rightBottom.x() + x);
	rightBottom.setY(rightBottom.y() + y);
	//qDebug() << "000000000000000000mouseMoveEvent lefttop" << leftTop;
	tmp = p;
	this->move(leftTop);
	m_bll->RectMovePoints(order, 0, leftTop);
	m_bll->RectMovePoints(order, 1, rightTop);
	m_bll->RectMovePoints(order, 2, leftBottom);
	m_bll->RectMovePoints(order, 3, rightBottom);

	//update();
}
void RectWidget::resizeWidget(int w, int h){
	this->resize(w, h);
	update();
	int x = (leftTop.x() + rightTop.x()) / 2;
	int y = (leftTop.y() + leftBottom.y()) / 2;
	tmp.setX(x);
	tmp.setY(y);
}

void RectWidget::setRectPointMoveLimitSlot(int rect_serial, int rect_Porder, QPoint pos){
	if (rect_serial == order){
		if (rect_Porder == 0){
			int rightLimit = rightTop.x();
			int bottomLimit = leftBottom.y();
			m_bll->getRectPointMoveLimit(order, 0, 10, rightLimit, 10, bottomLimit, pos);
			//qDebug() << "this is 0 judge---rightLimit-" << rightLimit << ";bottomLimit--" << bottomLimit;

		}
		if (rect_Porder == 1){
			int leftLimit = leftTop.x();
			int bottomLimit = rightBottom.y();
			m_bll->getRectPointMoveLimit(order, 1, leftLimit, widthLimit - 10, 10, bottomLimit - 10, pos);

		}
		if (rect_Porder == 2){
			int rightLimit = rightBottom.x();
			int topLimit = leftTop.y();
			m_bll->getRectPointMoveLimit(order, 2, 10, rightLimit - 10, topLimit + 10, heightLimit - 10, pos);

		}
		if (rect_Porder == 3){
			int leftLimit = leftBottom.x();
			int topLimit = rightTop.y();
			m_bll->getRectPointMoveLimit(order, 3, leftLimit, widthLimit - 10, topLimit + 10, heightLimit - 10, pos);

		}


	}

}

void RectWidget::RectPointReadytoMoveSlot(int lines, int flag, QPoint pos){
	/*m_bll->RectMovepoints(lines, flag, 1, pos.x(), pos.y());
	m_bll->RectMovepoints(lines, flag, 2, pos.x(), pos.y());*/
	if (lines == order){
		if (flag == 0){
			leftTop = pos;
			rightTop.setY(pos.y());
			leftBottom.setX(pos.x());
			m_bll->RectMovepoints(lines, flag, 1, rightTop.x(), rightTop.y());
			m_bll->RectMovepoints(lines, flag, 2, leftBottom.x(), leftBottom.y());
			m_bll->RectMovepoints(lines, flag, 3, rightTop.x(), leftBottom.y());

		}
		if (flag == 1){
			rightTop = pos;
			leftTop.setY(pos.y());
			rightBottom.setX(pos.x());
			m_bll->RectMovepoints(lines, flag, 0, leftTop.x(), leftTop.y());
			m_bll->RectMovepoints(lines, flag, 2, leftTop.x(), rightBottom.y());
			m_bll->RectMovepoints(lines, flag, 3, rightBottom.x(), rightBottom.y());

		}
		if (flag == 2){
			leftBottom = pos;
			leftTop.setX(pos.x());
			rightBottom.setY(pos.y());
			m_bll->RectMovepoints(lines, flag, 0, leftTop.x(), leftTop.y());
			m_bll->RectMovepoints(lines, flag, 1, rightBottom.x(), leftTop.y());
			m_bll->RectMovepoints(lines, flag, 3, rightBottom.x(), rightBottom.y());
		}
		if (flag == 3){
			rightBottom = pos;
			rightTop.setX(pos.x());
			leftBottom.setY(pos.y());
			m_bll->RectMovepoints(lines, flag, 0, leftBottom.x(), rightTop.y());
			m_bll->RectMovepoints(lines, flag, 1, rightTop.x(), rightTop.y());
			m_bll->RectMovepoints(lines, flag, 2, leftBottom.x(), leftBottom.y());

		}


	}
	this->move(leftTop);
	width = rightTop.x() - leftTop.x();
	height = leftBottom.y() - leftTop.y();
	resizeWidget(width, height);
}
void RectWidget::iniDisplayLimitSlot(int w, int h){
	widthLimit = w;
	heightLimit = h;
	qDebug() << "this is widthlimit and heightlimit----" << widthLimit << ";;" << heightLimit;
}
void RectWidget::cancelShapeSlot(){
	cancelRectEnable = true;
	setCursor(Qt::PointingHandCursor);
}
void RectWidget::updateRectSerialSlot(int serial){
	if (serial == order){
		order = order - 1;
	}
}
void RectWidget::unableCancelShapeSlot(){
	cancelRectEnable = false;
	setCursor(Qt::CrossCursor);
}