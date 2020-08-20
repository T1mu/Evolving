#include "ControlWidget.h"
#include <QDebug>
#include <QPixmap>
#include <QMouseEvent>
ControlWidget::ControlWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.directionlabel
	QPixmap myPix(":/image/directionC.ico");
	ui.directionlabel->setPixmap(myPix);;
	ui.directionlabel->setScaledContents(true);
	m_bllDataFlow = BllDataFlow::instance();
	/*ui->label_8->setPixmap(myPix);
	ui->label_8->setScaledContents(true);*/
}

ControlWidget::~ControlWidget()
{

}
void ControlWidget::mousePressEvent(QMouseEvent * event){
	qDebug() << "this is ControlWidget mousePressEvent mousePressEvent";
	QPoint p = event->pos();
	m_bllDataFlow->setMovePoint(p);
}