#include "mainXRay.h"

mainXRay::mainXRay(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	initUI();
	initConnect();
}

void mainXRay::initUI()
{
	this->showFullScreen();
	m_canvs = new canvas(this);
	m_dragChart = new dragChartSigleton(this);
	m_motorControl = new motorControl(this);
	m_canvs->show();
	m_dragChart->show();
	m_motorControl->show();
	m_canvs->setGeometry(10, 10, m_canvs->width(), m_canvs->height());
	m_dragChart->setGeometry(m_canvs->pos().x() + m_canvs->width() + 10, m_canvs->pos().y(), m_dragChart->width(), m_dragChart->height());
	m_motorControl->setGeometry(m_canvs->pos().x() + m_canvs->width() + 400, m_canvs->pos().y() + 300, m_motorControl->width(), m_motorControl->height());

}

void mainXRay::initConnect()
{
	connect(m_dragChart->trans, SIGNAL(sendMapRange(const int, const int)), m_canvs, SLOT(getMapRange(const int, const int)));
}
