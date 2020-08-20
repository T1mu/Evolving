#include "GrayCurveChart.h"

GrayCurveChart::GrayCurveChart(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//m_graycurve = new GrayCurveWidget(ui.widget);
	ui.resetCurveBtn->setEnabled(false);
	m_blldetector = BllDetectorKZ::instance();
	connect(m_blldetector, SIGNAL(resetCurveEnableSignal(QString, QString)), this, SLOT(resetCurveEnableSlot(QString, QString)));
}

GrayCurveChart::~GrayCurveChart()
{

}

void GrayCurveChart::on_resetCurveBtn_clicked(){
	m_blldetector->resetCurve();

}
void GrayCurveChart::resetCurveEnableSlot(QString min, QString max){
	qDebug() << "==============this is resetCurveEnableSlot";
	ui.resetCurveBtn->setEnabled(true);
	ui.label_min->setText(min);
	ui.label_max->setText(max);

}

