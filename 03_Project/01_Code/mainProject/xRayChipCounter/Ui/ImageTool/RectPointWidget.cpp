#include "RectPointWidget.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
RectPointWidget::RectPointWidget(QPoint &pos, int serial, int lines, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	position = pos;
	Porder = serial;
	lineSerial = lines;
	m_bll = BllDataFlow::instance();
	this->move(pos.x() - 4, pos.y() - 4);
	this->setFixedSize(15, 15);
	this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	connect(m_bll, SIGNAL(RectMovepointsSignal(int, int, int, int, int)),
		this, SLOT(RectMovepointsSlot(int, int, int, int, int)));
	//RectPointMoveLimitSignal(int, int, QPoint, QPoint, QPoint, QPoint)

	//getRectPointMoveLimitSignal(int, int, int, int, int, int, QPoint)
	connect(m_bll, SIGNAL(getRectPointMoveLimitSignal(int, int, int, int, int, int, QPoint)),
		this, SLOT(getRectPointMoveLimitSlot(int, int, int, int, int, int, QPoint)));
	connect(m_bll, SIGNAL(RectMovePointsSignal(int, int, QPoint)),
		this, SLOT(RectMovePointsSlot(int, int, QPoint)));
	connect(m_bll, SIGNAL(updateRectPointsSerialSignal(int)),
		this, SLOT(updateRectPointsSerialSlot(int)));
	setCursor(Qt::SizeAllCursor);
}

RectPointWidget::~RectPointWidget()
{

}
void RectPointWidget::mousePressEvent(QMouseEvent * event){
	charge = event->pos();

}
void RectPointWidget::paintEvent(QPaintEvent* event){
	QPainter painter(this);
	QBrush brush(QColor(255, 0, 0));
	painter.setBrush(brush);
	painter.drawEllipse(0, 0, 8, 8);
}
void RectPointWidget::mouseMoveEvent(QMouseEvent * event){
	//qDebug() << "this is move------------" << mapToParent(event->pos() - charge);;
	position = mapToParent(event->pos() - charge);
	m_bll->setRectPointMoveLimit(lineSerial, Porder, position);
	qDebug() << "this is mouseMoveEvent position--" << position;
	QPoint p(position.x() + 5, position.y() + 5);
	m_bll->RectPointReadytoMove(lineSerial, Porder, p);
	this->move(position.x(), position.y());
	position = p;

}
void RectPointWidget::RectMovepointsSlot(int lines, int flag, int changeflag, int x, int y){
	if (lines == lineSerial){
		if (changeflag == Porder){
			if (flag == 0){
				if (changeflag == 1){
					position.setY(y);

				}
				if (changeflag == 2){
					position.setX(x);

				}
				if (changeflag == 3){
					position.setX(x);
					position.setY(y);

				}
			}
			if (flag == 1){
				if (changeflag == 0){
					position.setY(y);

				}
				if (changeflag == 2){
					position.setX(x);
					position.setY(y);
				}
				if (changeflag == 3){
					position.setX(x);

				}

			}
			if (flag == 2){
				if (changeflag == 0){
					position.setX(x);

				}
				if (changeflag == 1){
					position.setX(x);
					position.setY(y);
				}
				if (changeflag == 3){
					position.setY(y);

				}

			}
			if (flag == 3){
				if (changeflag == 0){
					position.setX(x);
					position.setY(y);

				}
				if (changeflag == 1){
					position.setX(x);
				}
				if (changeflag == 2){
					position.setY(y);

				}

			}

		}
	}
	this->move(position.x() - 5, position.y() - 5);
}

void RectPointWidget::getRectPointMoveLimitSlot(int serial, int p_order, int l, int r, int t, int b, QPoint pos){

	if (serial == lineSerial){
		if (p_order == Porder){
			if (p_order == 0){
				judgeOver(pos, l, r, t, b);
				//qDebug() << "0---l;;r;;t;;b;;" << l << ";;" << ";;" << r << ";;" << t << ";;" << b;
			}
			if (p_order == 1){
				judgeOver(pos, l, r, t, b);
				//qDebug() << "1---l;;r;;t;;b;;" << l << ";;" << ";;" << r << ";;" << t << ";;" << b;
			}
			if (p_order == 2){
				judgeOver(pos, l, r, t, b);
				//qDebug() << "2---l;;r;;t;;b;;" << l << ";;" << ";;" << r << ";;" << t << ";;" << b;
			}
			if (p_order == 3){
				judgeOver(pos, l, r, t, b);
				//qDebug() << "3---l;;r;;t;;b;;" << l << ";;" << ";;" << r << ";;" << t << ";;" << b;
			}
		}


	}


}
void RectPointWidget::judgeOver(QPoint p, int l, int r, int t, int b){
	if (p.x() <= l){
		position.setX(l + 10);
	}
	if (p.x() >= r - 10){
		position.setX(r - 20);
	}
	if (p.y() <= t + 10){
		position.setY(t);
	}
	if (p.y() >= b - 10){
		position.setY(b - 10);
	}

	qDebug() << "this is judgeOver position--" << position;
}
void RectPointWidget::RectMovePointsSlot(int serial, int order, QPoint pos){
	if (serial == lineSerial){
		if (order == Porder){
			if (order == 0){

				position.setX(pos.x());
				position.setY(pos.y());
				this->move(pos.x() - 5, pos.y() - 5);


			}
			if (order == 1){
				position.setX(pos.x());
				position.setY(pos.y());
				this->move(pos.x() - 5, pos.y() - 5);

			}
			if (order == 2){
				position.setX(pos.x());
				position.setY(pos.y());
				this->move(pos.x() - 5, pos.y() - 5);
			}
			if (order == 3){
				position.setX(pos.x());
				position.setY(pos.y());
				this->move(pos.x() - 5, pos.y() - 5);
			}

		}

	}
}
void RectPointWidget::updateRectPointsSerialSlot(int serial){
	if (serial == lineSerial){
		lineSerial = lineSerial - 1;
	}
}