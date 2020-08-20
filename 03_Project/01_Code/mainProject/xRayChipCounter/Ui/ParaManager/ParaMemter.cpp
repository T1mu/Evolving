#include "ParaMemter.h"

ParaMemter::ParaMemter(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_detectorThread = DetectorThread::instance();
	connect(m_detectorThread, SIGNAL(sendCenterSignal(double *)), this, SLOT(dealcentersignal(double *)));
}

ParaMemter::~ParaMemter()
{

}

void ParaMemter::dealcentersignal(double *para)
{
	ui.ulabel->setText(QString::number(para[0]));
	ui.vlabel->setText(QString::number(para[1]));
	ui.RFIlabel->setText(QString::number(para[2]));
	ui.RFDlabel->setText(QString::number(para[3]));
}