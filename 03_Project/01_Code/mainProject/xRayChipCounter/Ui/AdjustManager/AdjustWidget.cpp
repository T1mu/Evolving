#include "AdjustWidget.h"
#include <QDebug>
AdjustWidget::AdjustWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_bll = BllDetectorKZ::instance();
	connect(m_bll, SIGNAL(readyAdjustSignal(int)), this, SLOT(readyAdjustSlot(int)));
	connect(m_bll, SIGNAL(returnAdjustSignal(int)), this, SLOT(readyAdjustSlot(int)));//2019/11/28
	m_chart = new AdjustChart();

	m_chart->setEnabled(true);
	//m_test = new testWidget();

	ui.h1->addWidget(m_chart);
	//setAttribute(Qt::WA_DeleteOnClose);
	
}

AdjustWidget::~AdjustWidget()
{

}
void AdjustWidget::readyAdjustSlot(int c)
{
	m_chart->setCurve(c);
}
void AdjustWidget::deleteall()
{
	m_chart->~AdjustChart();
}