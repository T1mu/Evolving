#include "ScanPixWidget.h"
#include <QDebug>

ScanPixWidget::ScanPixWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	mul = 1;
	m_bllDataFlow = BllDataFlow::instance();
	connect(ui.slider, SIGNAL(valueChanged(int)), this, SLOT(valueChangeSlot(int)));
	connect(ui.checkBox, SIGNAL(stateChanged(int)), this, SLOT(stateChangeSlot(int)));
	
}

ScanPixWidget::~ScanPixWidget()
{

}
void ScanPixWidget::valueChangeSlot(int value){
	//qDebug() << "value------" << value;
	QString str = "X";
	str.append(QString::number(value));
	ui.label->setText(str);
	mul = value;
	m_bllDataFlow->setMul(mul);
}
void ScanPixWidget::stateChangeSlot(int state){
	if (ui.checkBox->isChecked()){
		//qDebug() << "checked=======yes----";
		m_bllDataFlow->getPosPixEnable(true);
		m_bllDataFlow->sendIfMove(true);
	}
	else{
		//qDebug() << "checked=======no----";
		m_bllDataFlow->getPosPixEnable(false);
		m_bllDataFlow->sendIfMove(false);
	}
}
