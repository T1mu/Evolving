#include "RightWidget.h"
#include <QDebug>
RightWidget::RightWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//m_graycurve = new GrayCurveWidget(ui.widget);
	//ui.resetCurveBtn->setEnabled(false);
	//m_blldetector = BllDetector::instance();
	//connect(m_blldetector, SIGNAL(resetCurveEnableSignal(QString, QString)), this, SLOT(resetCurveEnableSlot(QString, QString)));
}

RightWidget::~RightWidget()
{

}
void RightWidget::on_resetCurveBtn_clicked(){
	//m_blldetector->resetCrrve();

}
void RightWidget::resetCurveEnableSlot(QString min, QString max){
	qDebug() << "==============this is resetCurveEnableSlot";
}
