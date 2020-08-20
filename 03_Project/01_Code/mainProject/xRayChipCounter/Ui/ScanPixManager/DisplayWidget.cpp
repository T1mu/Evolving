#include "DisplayWidget.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>

DisplayWidget::DisplayWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//qDebug() << "test----" << pow(2, 4);
	m_mul = 1;
	m_bllDataFlow = BllDataFlow::instance();
	connect(m_bllDataFlow, SIGNAL(setMulSignal(int)), this, SLOT(setMulSlot(int)));
	connect(m_bllDataFlow, SIGNAL(returnPosSignal(QPoint)), this, SLOT(returnPosSlot(QPoint)));

	connect(m_bllDataFlow, SIGNAL(getPosPixEnableSignal(bool)), this, SLOT(getPosPixEnableSlot(bool)));
	m_top.setX(0);
	m_top.setY(0);
	m_bottom.setX(0);
	m_bottom.setY(0);
}

DisplayWidget::~DisplayWidget()
{

}
void DisplayWidget::paintEvent(QPaintEvent* event){
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	QRect target(0, 0, this->width(), this->height());//最佳宽度：720,高度：720

	int width = m_bottom.x() - m_top.x();
	int height = m_bottom.y() - m_top.y();
	//qDebug() << "m_top------" << m_top;
	if (width != 0){
		Mat roi = m_srcdata(Rect(m_top.x(), m_top.y(), width, height)).clone();
		Mat img;
		cv::resize(roi, img, Size(this->width(), this->height()));
		QImage image((const uchar*)img.data, img.cols, img.rows, QImage::Format_Grayscale8);
		p.drawImage(target, image);
	}
	

}
void DisplayWidget::setMulSlot(int mul){
	m_mul = mul;
	returnPosSlot(m_tempP);
}
void DisplayWidget::returnPosSlot(QPoint pos){

	//qDebug() << "pos------" << pos;
	/*Mat src8;
	normalize(m_srcdata, src8, 0, 255, CV_MINMAX);
	convertScaleAbs(src8, src8);*/
	//qDebug() << src8.at<uchar>(100, 100);
	m_tempP = pos;
	//qDebug() << "size---" << this->width();

	int topx = pos.x() - this->width() / 2 / pow(2,m_mul-1);
	int topy = pos.y() - this->height() / 2 / pow(2, m_mul - 1);
	int bottomx = pos.x() + this->width() / 2 / pow(2, m_mul - 1);
	int bottomy = pos.y() + this->height() / 2 / pow(2, m_mul - 1);
	int rW = this->width() / pow(2, m_mul - 1);
	int rH = this->height() / pow(2, m_mul - 1);
	

	int sizeLimit = BllDetectorKZ::returnSize();

	int minx =  0;
	int maxx = sizeLimit;
	int miny = 0;
	int maxy = sizeLimit;
	if (topx <= minx){
		topx = minx;
		bottomx = minx + rW;
	}
	if (bottomx >= maxx){
		bottomx = maxx;
		topx = bottomx - rW;
	}
	if (topy <= miny){
		topy = miny;
		bottomy = topy + rH;
	}
	if (bottomy >= maxy){
		bottomy = maxy;
		topy = bottomy - rH;
	}
	
	m_top.setX(topx);
	m_top.setY(topy);
	
	m_bottom.setX(bottomx);
	m_bottom.setY(bottomy);
	update();
	//qDebug() << "topx--" << topx << " topy--" << topy ;
	//Mat roi(src8, Rect(topx, topy, width, height));
	
	
	
	

}
void DisplayWidget::iniData(){
	quint16* imgdata = BllDetectorKZ::getSingleImg();
	int size = BllDetectorKZ::returnSize();
	m_srcdata = Mat::zeros(size, size, CV_16U);
	for (int i = 0; i < size * size; i++)
	{
		int row = i / size;
		int col = i % size;
		m_srcdata.at<ushort>(row, col) = imgdata[i];
	}
	normalize(m_srcdata, m_srcdata, 0, 255, CV_MINMAX);
	convertScaleAbs(m_srcdata, m_srcdata);
	//imwrite("test.tiff", m_srcdata);
}
void DisplayWidget::resizeEvent(QResizeEvent * event){
	qDebug() << "size---" << this->width() << "; " << this->height();
}
void DisplayWidget::getPosPixEnableSlot(bool b){
	if (b)
	{
		iniData();
	}
	
}