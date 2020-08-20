#include "ChartWidget.h"

ChartWidget::ChartWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_blldata = BllDataFlow::instance();
	m_bll = BllDetectorKZ::instance();
	m_chart = new ChartView();
	connect(m_blldata, SIGNAL(readyGrayCurveSignal()), this, SLOT(readyGrayCurveSlot()));
	connect(m_bll, SIGNAL(returnPaintGraySignal()), this, SLOT(readyGrayCurveSlot()));
	connect(m_blldata, SIGNAL(openAdjustSignal(int)), this, SLOT(openAdjustSlot(int)));
	connect(m_blldata, SIGNAL(closeAdjustSignal()), this, SLOT(closeAdjustSlot()));
	ui.h1->addWidget(m_chart);
	
}

ChartWidget::~ChartWidget()
{

}
void ChartWidget::readyGrayCurveSlot()
{
	m_chart->setCurve();
	
}

void ChartWidget::openAdjustSlot(int c){
	m_adjust = new AdjustWidget();
	m_adjust->show();
	m_bll->readyAdjust(c);
}

void ChartWidget::closeAdjustSlot(){
	//m_adjust->deleteall();
	m_adjust->close();

}