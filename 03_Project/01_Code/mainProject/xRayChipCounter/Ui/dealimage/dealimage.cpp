#include "dealimage.h"
#include <qdebug.h>
#include <qimage.h>
#include <QMetaType>
#include <qstring.h>


dealimage::dealimage(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);

	qRegisterMetaType<Mat>("Mat");

	m_detectorThread = DetectorThread::instance();

	connect(m_detectorThread, SIGNAL(sendMatSignal(Mat)), this, SLOT(dealmat(Mat)));
	connect(m_detectorThread, SIGNAL(sendCenterSignal(double *)), this, SLOT(dealcenter_signal(double *)));
	//connect(this, SIGNAL(destroyed(QObject * = Q_NULLPTR)), this, SLOT(dealclose()));

	//string title = "几何校正";
	//this->setWindowTitle(QString::fromLocal8Bit(title.data()));

}

dealimage::~dealimage()
{

}



void dealimage::dealcenter_signal(double *para)
{
	ui.ulabel->setText(QString::number(para[0]));
	ui.vlabel->setText(QString::number(para[1]));
	ui.RFIlabel->setText(QString::number(para[2]));
	ui.RFDlabel->setText(QString::number(para[3]));
}


void dealimage::dealmat(Mat disimg)
{
	QImage image = QImage((const unsigned char*)(disimg.data), disimg.cols, disimg.rows, QImage::Format_Grayscale8);
	ui.label->setScaledContents(true);
	ui.label->setPixmap(QPixmap::fromImage(image));
}