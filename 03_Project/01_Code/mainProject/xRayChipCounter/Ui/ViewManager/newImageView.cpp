#include "newImageView.h"
#include <QPainter>
#include <QDebug>
//using namespace cv;
newImageView::newImageView(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	showImage *myimage = new showImage;
	ui.scrollArea->setBackgroundRole(QPalette::Dark);

	//mywidget->setMinimumSize(5000,1000);

	//mywidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ui.scrollArea->setWidget(myimage);
	ui.scrollArea->show();
	connect(myimage, SIGNAL(paraSignal(Para)), this, SLOT(dealSignal(Para)));
	//maxp = 0;
	//minp = 0;
	//m_bll = BllDetectorKZ::instance();
	//m_bllDataFlow = BllDataFlow::instance();
	//connect(m_bll, SIGNAL(returnImgSignal(int,int)), this, SLOT(returnImgSlot(int,int)));
	//connect(m_bll, SIGNAL(updateSizeSignal(int)), this, SLOT(updateSizeSlot(int)));

	////connect(m_bll, SIGNAL(returnPaintGraySignal()), this, SLOT(paintGraySlot()));
	//
	//connect(m_bllDataFlow, SIGNAL(updateGrayImgSignal()), this, SLOT(updateGrayImageSlot()));

	//connect(m_bllDataFlow, SIGNAL(setLineEnableSignal()), this, SLOT(setLineEnableSlot()));
	//connect(m_bllDataFlow, SIGNAL(LinepointMoveSignal(int, int, QPoint)),
	//	this, SLOT(LinepointMoveSlot(int, int, QPoint)));

	//connect(m_bllDataFlow, SIGNAL(setRectEnableSignal()), this, SLOT(setRectEnableSlot()));
	//connect(m_bllDataFlow, SIGNAL(iniRectPointSignal(QPoint, QPoint, QPoint, QPoint, int)),
	//	this, SLOT(iniRectPointSlot(QPoint, QPoint, QPoint, QPoint, int)));


	//connect(m_bllDataFlow, SIGNAL(setCircleEnableSignal()), this, SLOT(setCircleEnableSlot()));
	//connect(m_bllDataFlow, SIGNAL(setRadiousSignal(int)), this, SLOT(setRadiousSlot(int)));


	//connect(m_bllDataFlow, SIGNAL(setCancelEnableSignal()), this, SLOT(setCancelEnableSlot()));
	//connect(m_bllDataFlow, SIGNAL(cancelCircleSignal(int)),
	//	this, SLOT(cancelCircleSlot(int)));
	//connect(m_bllDataFlow, SIGNAL(cancelRectSignal(int)),
	//	this, SLOT(cancelRectSlot(int)));

	//connect(m_bllDataFlow, SIGNAL(LightContrastChangeSignal(int, int)), this, SLOT(LightContrastChangeSlot(int, int)));
	//connect(m_bllDataFlow, SIGNAL(setBlursizeSignal(int, int)), this, SLOT(setBlursizeSlot(int, int)));
	////connect(m_bllDataFlow, SIGNAL(updateGrayImgSignal()), this, SLOT(updateGrayImageSlot()));
	////connect(m_bllDataFlow, SIGNAL(moveRepaintGrayImgSignal(QVector<QPointF>)), this, SLOT(moveRepaintGrayImgSlot(QVector<QPointF>)));
	//
	//connect(m_bllDataFlow, SIGNAL(getPosSignal()), this, SLOT(getPosSlots()));
	//connect(m_bllDataFlow, SIGNAL(getPosCancelSignal()), this, SLOT(getPosCancelSlots()));

	//connect(m_bll, SIGNAL(lineMoveSignal(QVector<QPointF>)), this, SLOT(lineMoveSlot(QVector<QPointF>)));
	//connect(m_bll, SIGNAL(readyAdjustpaintSignal(int, int)),
	//	this, SLOT(readyAdjustpaintSlot(int, int)));
	//row = 704;
	//m_8bitgrayImg = new uchar[row * row]();
	//memset(m_8bitgrayImg, 0, row * row * sizeof(char));

	//updateEnable = false;
	//moveChange = false;
	//adjustEnable = false;
	//m_width = 0;
	//m_center = 0;
	//adjustWidth = 0;
	//adjustCenter = 0;
	//light = 0;
	//contrast = 0;
	//Sliderchange = false;
	////-------------------------测量工具
	//displayW = 0;
	//displayH = 0;

	////line
	//drawline = false;
	//moveline = false;
	//lineEnable = false;
	//linenumber = 0;
	//pointorder = 1000;
	//clickcount = 0;
	//lineMoveSerial = 1000;
	//lineDeleteSerial = 1000;

	////rect
	//rectEnable = false;
	//pointcount = 0;
	//rectnum = 0;
	////circle
	//circleEnable = false;
	//radious = 0;
	//circleNum = 0;
	////cancel
	//cancelEnable = false;
	//getposE = false;
}

newImageView::~newImageView()
{

}

void newImageView::dealSignal(Para p)
{
	QString str = QString("pixel info:(%1,%2) %3").arg(p.x).arg(p.y).arg(p.pixel);
	ui.label->setText(str);
}

//void newImageView::paintEvent(QPaintEvent * event)
//{	
//	quint16* m_grayImg = BllDetectorKZ::getSingleImg();
//
//	if (m_grayImg == NULL)
//	{
//		return;
//	}
//	if (updateEnable)
//	{
//		//绘制灰度图像
//		if (moveChange)
//		{
//			BllDataFlow::moveTochangeGrayImg(m_grayImg, m_8bitgrayImg, vec);
//			qDebug() << "--------------1-----------------";
//		}
//		if (adjustEnable)
//		{
//			qDebug() << "m_width---" << m_width << "   m_center--" << m_center;
//
//			BllDataFlow::converToGray(m_grayImg, m_8bitgrayImg, adjustWidth, adjustCenter);
//			qDebug() << "--------------2-----------------";
//		}
//		if (!moveChange && !adjustEnable)
//		{
//			BllDataFlow::converToGray(m_grayImg, m_8bitgrayImg, m_width, m_center);
//			qDebug() << "--------------3-----------------";
//			//BllDataFlow::converTo8bitGrayimg(m_grayImg, m_8bitgrayImg);
//		}
//		//moveChange = false;
//		//adjustEnable = false;
//
//		QPainter painter(this);
//		QRect target(0, 0, this->width(), this->height());
//
//		QImage image(m_8bitgrayImg, row, row, QImage::Format_Grayscale8);
//		painter.drawImage(target, image);
//	}
//	
//	/*if (Sliderchange)
//	{
//		srcImg = QImagechange(image);
//		if (!srcImg.data)
//		{
//			qDebug() << "*****************8error,no datachange******************************";
//		}
//		else
//		{
//			qDebug() << "*****************datachange ok******************************";
//			dstImg = Mat::zeros(srcImg.size(), srcImg.type());
//
//		}
//		SliderchangeMethod(contrast, light);
//		QImage changeimage = Matchange(dstImg);
//		painter.drawImage(target, changeimage);
//		Sliderchange = false;
//	}
//	else
//	{
//		painter.drawImage(target, image);
//	}*/
//	
//	updateEnable = false;
//}
//
//void newImageView::mouseMoveEvent(QMouseEvent * event)
//{
//
//	if (moveline)
//	{
//		double dis = vectorLine[lineMoveSerial]->getDistance();
//		moveCalPoint(dis, event->pos());
//
//
//		tmpPoint = event->pos();
//	}
//	if (getposE)
//	{
//		toPos_Value(event->pos());
//
//	}
//}
//
//void newImageView::mousePressEvent(QMouseEvent * event)
//{
//	qDebug() << "---grayImageView::mousePressEvent";
//	clickcount++;
//	if (lineEnable)
//	{
//		pointcount++;
//		if (pointcount % 2 == 1)
//		{
//			int order = pointcount / 2;
//			//linenumber = order + 1;
//			linenumber++;
//			LinePointWidget* startP = new LinePointWidget(event->pos(), linenumber, 0, this);
//			startP->show();
//			vectorPoint.append(startP);
//		}
//		if (pointcount % 2 == 0)
//		{
//			//linenumber = pointcount / 2;
//			//qDebug() << "linecount == 2 this is startp width and height" << startP->getPos().x() << ";;" << startP->getPos().y();
//			LinePointWidget* endP = new LinePointWidget(event->pos(), linenumber, 1, this);
//			endP->show();
//			vectorPoint.append(endP);
//			Line *l = new Line(linenumber);
//			QPoint s = vectorPoint[vectorPoint.size() - 2]->getPos();
//			QPoint e = vectorPoint[vectorPoint.size() - 1]->getPos();
//			if (s.y() > e.y())
//			{
//				l->setPoint(e, s);
//			}
//			else
//			{
//				l->setPoint(s, e);
//			}
//			vectorLine.append(l);
//			qDebug() << "----------------";
//			m_bllDataFlow->iniLineLimit(displayW, displayH);
//			qDebug() << "===================";
//			drawline = true;
//			update();
//			lineEnable = false;
//		}
//	}
//
//	if (pointcount >= 2 && clickcount >= 3)
//	{
//		if (judgeDistanceToMove(event->pos()) && !cancelEnable)
//		{
//			moveline = true;
//			setCursor(Qt::CrossCursor);
//		}
//	}
//	if (rectEnable)
//	{
//		rectnum++;
//		RectWidget* rect = new RectWidget(event->pos(), rectnum, this);
//		rect->show();
//
//		vectorRect.append(rect);
//
//
//		rectEnable = false;
//
//	}
//	if (circleEnable)
//	{
//		circleNum++;
//		qDebug() << "rrrrrrrrrrrrrrrrrrrrrrrrrr" << radious;
//		CircleWidget* circle = new CircleWidget(event->pos(), circleNum, radious, this);
//		circle->show();
//		vectorCircle.append(circle);
//		circleEnable = false;
//	}
//	if (cancelEnable)
//	{
//		if (judgeDeleteLine(event->pos()))
//		{
//			deleteLine(lineDeleteSerial);
//		}
//		cancelEnable = false;
//	}
//}
//
//void newImageView::mouseReleaseEvent(QMouseEvent * event)
//{
//	if (moveline)
//	{
//		moveline = false;
//		setCursor(Qt::ArrowCursor);
//	}
//
//}
//
//void newImageView::resizeEvent(QResizeEvent * event)
//{
//	qDebug() << "this is resize event----------" << this->size();
//	displayW = this->size().width();
//	displayH = this->size().height();
//	updateEnable = true;
//
//}
//
//void newImageView::SliderchangeMethod(int vcontrast, int vlight)
//{
//	for (int y = 0; y < dstImg.rows; y++)
//	{
//		for (int x = 0; x < dstImg.cols; x++)
//		{
//			dstImg.at<uchar>(y, x) = saturate_cast<uchar>((vcontrast*0.01)*(srcImg.at<uchar>(y, x)) + vlight);
//		}
//	}
//}
//
//void newImageView::GaussianBlurMethod(int size)
//{
//	MatchangeQuint(size, 0);
//}
//
//void newImageView::BlurMethod(int size)
//{
//	MatchangeQuint(size, 1);
//}
//
//void newImageView::medianBlurMethod(int size)
//{
//	MatchangeQuint(size, 2);
//
//}
//
//void newImageView::SizeOverLimit(int size)
//{
//	//m_8bitgrayImg
//	Mat Img = Mat::zeros(row, row, CV_8U);
//	for (int i = 0; i < row * row; i++){
//		int rows = i / row;
//		int cols = i % row;
//		int data = m_8bitgrayImg[i];
//		Img.at<uchar>(rows, cols) = data;
//	}
//	Mat result = Mat::zeros(row, row, CV_8U);
//	medianBlur(Img, result, size);
//	for (int i = 0; i < Img.rows; i++){
//		for (int j = 0; j < Img.cols; j++){
//			int data = result.at<uchar>(i, j);
//			m_8bitgrayImg[i * row + j] = data;
//		}
//
//	}
//	update();
//	m_bllDataFlow->readyGrayCurve();
//
//}
//
//void newImageView::MatchangeQuint(int size, int serial)
//{
//	quint16* m_grayImg = BllDetectorKZ::getSingleImg();
//	Mat Img = Mat::zeros(row, row, CV_16U);
//	for (int i = 0; i < row * row; i++){
//		int rows = i / row;
//		int cols = i % row;
//		int data = m_grayImg[i];
//		Img.at<ushort>(rows, cols) = data;
//
//	}
//
//	Mat result = Mat::zeros(row, row, CV_16U);
//	if (serial == 0){
//		GaussianBlur(Img, result, Size(size, size), 0, 0);
//	}
//	if (serial == 1){
//		blur(Img, result, Size(size, size));
//	}
//	if (serial == 2){
//		if (size <= 5){
//			medianBlur(Img, result, size);
//		}
//		else{
//			SizeOverLimit(size);
//		}
//
//	}
//
//	for (int i = 0; i < Img.rows; i++){
//		for (int j = 0; j < Img.cols; j++){
//			int data = result.at<ushort>(i, j);
//			m_grayImg[i * row + j] = data;
//		}
//
//	}
//
//	update();
//	m_bllDataFlow->readyGrayCurve();
//
//}
//
//bool newImageView::judgeDistanceToMove(QPoint p)
//{
//
//	int x = p.x();
//	int y = p.y();
//	bool move = false;
//	if (vectorLine.size() != 0)
//	{
//		//qDebug() << "this is vectorLine.size() vectorLine.size()--" << vectorLine.size();
//		for (int i = 0; i < vectorLine.size(); i++)
//		{
//			double k = vectorLine[i]->getK();
//			double b = vectorLine[i]->getB();
//			double bottom = sqrt(k*k + 1);
//			double top = k*x - y + b;
//			double result = fabs(top / bottom);
//			//qDebug() << "---------------------result" << result;
//			if (result < 6)
//			{
//				move = true;
//				lineMoveSerial = i;
//				QPointF s = vectorLine[i]->getStartP();
//				QPointF e = vectorLine[i]->getEndP();
//				tmpPoint.setX((s.x() + e.x()) / 2);
//				tmpPoint.setY((s.y() + e.y()) / 2);
//				break;
//			}
//
//		}
//	}
//	return move;
//
//}
//
//void newImageView::moveCalPoint(int dis, QPoint pos)
//{
//	int x = pos.x() - tmpPoint.x();
//	int y = pos.y() - tmpPoint.y();
//	QPointF s = vectorLine[lineMoveSerial]->getStartP();
//	QPointF e = vectorLine[lineMoveSerial]->getEndP();
//	s.setX(s.x() + x);
//	s.setY(s.y() + y);
//	e.setX(e.x() + x);
//	e.setY(e.y() + y);
//	vectorLine[lineMoveSerial]->updateDate(s, e);
//	drawline = true;
//	update();
//	QPoint ss((int)(s.x()), (int)(s.y()));
//	QPoint ee((int)(e.x()), (int)(e.y()));
//	m_bllDataFlow->LineMoveChangePoint(lineMoveSerial + 1, 0, ss);
//	m_bllDataFlow->LineMoveChangePoint(lineMoveSerial + 1, 1, ee);
//
//}
//
//bool newImageView::judgeDeleteLine(QPoint pos)
//{
//	int x = pos.x();
//	int y = pos.y();
//	bool deleteline = false;
//	if (vectorLine.size() != 0)
//	{
//		//qDebug() << "this is vectorLine.size() vectorLine.size()--" << vectorLine.size();
//		for (int i = 0; i < vectorLine.size(); i++)
//		{
//			double k = vectorLine[i]->getK();
//			double b = vectorLine[i]->getB();
//			double bottom = sqrt(k*k + 1);
//			double top = k*x - y + b;
//			double result = fabs(top / bottom);
//			//qDebug() << "---------------------result" << result;
//			if (result < 6)
//			{
//				deleteline = true;
//				lineDeleteSerial = i;
//				//qDebug() << "this is test line number---" << lineDeleteSerial;
//				break;
//			}
//		}
//	}
//	return deleteline;
//}
//
//void newImageView::deleteLine(int serial)
//{
//	int point1 = serial * 2;
//	int point2 = serial * 2 + 1;
//	delete vectorPoint[point1];
//	delete vectorPoint[point2];
//	vectorPoint.remove(point1);
//	vectorPoint.remove(point1);
//	delete vectorLine[serial];
//	vectorLine.remove(serial);
//	drawline = true;
//	for (int i = serial; i < vectorLine.size(); i++)
//	{
//		vectorLine[i]->updateSerial();
//		m_bllDataFlow->updateLinepointSerial(i + 2);
//	}
//	update();
//	linenumber--;
//	setCursor(Qt::ArrowCursor);
//}
//
//void newImageView::paintImgTools()
//{
//	QPainter painter(this);
//
//	painter.setRenderHint(QPainter::Antialiasing, true);
//	if (drawline)
//	{
//		qDebug() << "this is ----size--" << vectorLine.size();
//		if (vectorLine.size() != 0)
//		{
//			for (int i = 0; i < vectorLine.size(); i++)
//			{
//				QLineF line(vectorLine[i]->getStartP(), vectorLine[i]->getEndP());
//				painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
//				painter.drawLine(line);
//				qDebug() << "tttttttttttttttttt";
//				double x = (vectorLine[i]->getStartP().x() + vectorLine[i]->getEndP().x()) / 2;
//				double y = (vectorLine[i]->getStartP().y() + vectorLine[i]->getEndP().y()) / 2;
//				QPointF txt(x + 10, y + 10);
//				QString distance = "D: ";
//				double d = vectorLine[i]->getRealD();
//				distance.append(QString::number(d, 10, 2)).append("mm");
//				painter.drawText(txt, distance);
//				if (vectorLine[i]->getLinePoint().size() != 0 && vectorLine[i]->getLinePoint().size() == vectorLine[i]->getVLinePoint().size())
//				{
//					QVector<QPointF> tmpline = vectorLine[i]->getLinePoint();
//					QVector<QPointF> tmpvline = vectorLine[i]->getVLinePoint();
//					for (int j = 0; j < tmpline.size(); j++)
//					{
//						QLineF ll(tmpline[j], tmpvline[j]);
//						painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
//						painter.drawLine(ll);
//					}
//				}
//
//			}
//		}
//		drawline = false;
//	}
//}
//
//void newImageView::toPos_Value(QPoint p)
//{
//	double xalias = (double)row / this->width();
//	double yalias = (double)row / this->height();
//	int x = p.x()*xalias;
//	int y = p.y()*yalias;
//	int pos = y * row + x;;
//	qDebug() << "pos--------------" << pos;
//	quint16* m_grayImg = BllDetectorKZ::getSingleImg();
//	if (m_grayImg == NULL)
//	{
//		return;
//	}
//	int value = m_grayImg[pos];
//	qDebug() << "x: " << x << "  y: " << y << "  value: " << value;
//
//	int row = y + 1;
//	int col = x + 1;
//	m_bllDataFlow->getPos_Value(row, col, value);
//
//}
//
//QImage newImageView::Matchange(const cv::Mat& mat){
//	if (mat.type() == CV_8UC1)
//	{
//		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
//		// Set the color table (used to translate colour indexes to qRgb values)    
//		image.setColorCount(256);
//		for (int i = 0; i < 256; i++)
//		{
//			image.setColor(i, qRgb(i, i, i));
//		}
//		// Copy input Mat    
//		uchar *pSrc = mat.data;
//		for (int row = 0; row < mat.rows; row++)
//		{
//			uchar *pDest = image.scanLine(row);
//			memcpy(pDest, pSrc, mat.cols);
//			pSrc += mat.step;
//		}
//		return image;
//	}
//	// 8-bits unsigned, NO. OF CHANNELS = 3    
//	else if (mat.type() == CV_8UC3)
//	{
//		// Copy input Mat    
//		const uchar *pSrc = (const uchar*)mat.data;
//		// Create QImage with same dimensions as input Mat    
//		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
//		return image.rgbSwapped();
//	}
//	else if (mat.type() == CV_8UC4)
//	{
//		qDebug() << "CV_8UC4";
//		// Copy input Mat    
//		const uchar *pSrc = (const uchar*)mat.data;
//		// Create QImage with same dimensions as input Mat    
//		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
//		return image.copy();
//	}
//	else
//	{
//		qDebug() << "ERROR: Mat could not be converted to QImage.";
//		return QImage();
//	}
//
//}
//
//Mat newImageView::QImagechange(QImage image)
//{
//	cv::Mat mat;
//	switch (image.format())
//	{
//	case QImage::Format_ARGB32:
//	case QImage::Format_RGB32:
//	case QImage::Format_ARGB32_Premultiplied:
//		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
//		break;
//	case QImage::Format_RGB888:
//		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
//		cv::cvtColor(mat, mat, CV_BGR2RGB);
//		break;
//	case QImage::Format_Grayscale8:
//		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
//		break;
//	}
//	return mat;
//}
//
//void newImageView::returnImgSlot(int min,int max)
//{
//	minp = min;
//	maxp = max;
//	m_center = (maxp + minp) / 2;
//	m_width = maxp - minp;
//	updateEnable = true;
//	update();
//}
//
//void newImageView::updateSizeSlot(int width)
//{
//	row = width;
//	if (m_8bitgrayImg != NULL)
//	{
//		delete m_8bitgrayImg;
//		m_8bitgrayImg = NULL;
//	}
//	
//	m_8bitgrayImg = new uchar[row * row]();
//	memset(m_8bitgrayImg, 0, row * row * sizeof(char));
//}
//
//void newImageView::updateGrayImageSlot()//打开文件
//{
//	updateEnable = true;
//	update();
//}
//
////void newImageView::moveRepaintGrayImgSlot(QVector<QPointF> vec)
////{
////	m_vector.clear();
////	updateEnable = true;
////	moveChange = true;
////	adjustEnable = false;
////	m_vector = vec;
////	update();
////}
//
////void newImageView::updateImgSlot()
////{
////	update();
////	m_bllDataFlow->readyGrayCurve();
////
////}
//
//void newImageView::setBlursizeSlot(int size, int serial)
//{
//	if (serial == 0)
//	{
//		GaussianBlurMethod(size);
//	}
//	if (serial == 1)
//	{
//		BlurMethod(size);
//	}
//	if (serial == 2)
//	{
//		medianBlurMethod(size);
//	}
//}
//
//void newImageView::LightContrastChangeSlot(int vlight, int vcontrast)
//{
//	light = vlight;
//	contrast = vcontrast;
//	Sliderchange = true;
//	update();
//}
//
//void newImageView::setLineEnableSlot()
//{
//	lineEnable = true;
//	rectEnable = false;
//	circleEnable = false;
//	cancelEnable = false;
//}
//
//void newImageView::LinepointMoveSlot(int lineOrder, int flag, QPoint pos)
//{
//	int m = lineOrder * 2 - 2;
//	int mm = m + 1;
//	QPoint s = vectorPoint[m]->getPos();
//	QPoint e = vectorPoint[mm]->getPos();
//	if (s.y() > e.y())
//	{
//		vectorLine[lineOrder - 1]->updateDate(e, s);
//	}
//	else
//	{
//		vectorLine[lineOrder - 1]->updateDate(s, e);
//	}
//	drawline = true;
//	update();
//}
//
//void newImageView::setRectEnableSlot()
//{
//	rectEnable = true;
//	lineEnable = false;
//	circleEnable = false;
//	cancelEnable = false;
//}
//
//void newImageView::iniRectPointSlot(QPoint lt, QPoint rt, QPoint lb, QPoint rb, int order)
//{
//	RectPointWidget* leftT = new RectPointWidget(lt, 0, order, this);
//	leftT->show();
//	RectPointWidget* rightT = new RectPointWidget(rt, 1, order, this);
//	rightT->show();
//	RectPointWidget* leftB = new RectPointWidget(lb, 2, order, this);
//	leftB->show();
//	RectPointWidget* rightB = new RectPointWidget(rb, 3, order, this);
//	rightB->show();
//	vectorRectP.append(leftT);
//	vectorRectP.append(rightT);
//	vectorRectP.append(leftB);
//	vectorRectP.append(rightB);
//	m_bllDataFlow->iniDisplayLimittest(displayW, displayH);
//}
//
//void newImageView::setCircleEnableSlot()
//{
//	circleEnable = true;
//	lineEnable = false;
//	rectEnable = false;
//	cancelEnable = false;
//}
//
//void newImageView::setRadiousSlot(int r)
//{
//	radious = r;
//}
//
//void newImageView::setCancelEnableSlot()
//{
//	cancelEnable = true;
//	lineEnable = false;
//	rectEnable = false;
//	circleEnable = false;
//	setCursor(Qt::PointingHandCursor);
//	m_bllDataFlow->cancelShape();
//}
//
//void newImageView::cancelCircleSlot(int circleserial)
//{
//	int serial = circleserial - 1;
//	vectorCircle[serial]->close();
//	vectorCircle.remove(serial);
//
//	for (int i = serial; i < vectorCircle.size(); i++)
//	{
//		m_bllDataFlow->updateCircleSerial(i + 2);
//	}
//
//	circleNum--;
//	setCursor(Qt::ArrowCursor);
//	if (cancelEnable)
//	{
//		cancelEnable = false;
//	}
//	m_bllDataFlow->unableCancelShape();
//}
//
//void newImageView::cancelRectSlot(int rectserial)
//{
//	int serial = rectserial - 1;
//	vectorRect[serial]->close();
//	vectorRect.remove(serial);
//	int point1 = serial * 4;
//	int point2 = serial * 4 + 1;
//	int point3 = serial * 4 + 2;
//	int point4 = serial * 4 + 3;
//	delete vectorRectP[point1];
//	delete vectorRectP[point2];
//	delete vectorRectP[point3];
//	delete vectorRectP[point4];
//	vectorRectP.remove(point1);
//	vectorRectP.remove(point1);
//	vectorRectP.remove(point1);
//	vectorRectP.remove(point1);
//
//	for (int i = serial; i < vectorRect.size(); i++)
//	{
//		m_bllDataFlow->updateRectPointsSerial(i + 2);
//		m_bllDataFlow->updateRectSerial(i + 2);
//	}
//	rectnum--;
//	setCursor(Qt::ArrowCursor);
//
//	if (cancelEnable)
//	{
//		cancelEnable = false;
//	}
//	m_bllDataFlow->unableCancelShape();
//}
//
//void newImageView::getPosSlots()
//{
//	setMouseTracking(true);
//	getposE = true;
//}
//
//void newImageView::getPosCancelSlots()
//{
//	getposE = false;
//	setMouseTracking(false);
//	qDebug() << "this is getPosCancelSlots=========";
//}
//
//void newImageView::lineMoveSlot(QVector<QPointF> v)
//{
//	vec.clear();
//	updateEnable = true;
//	moveChange = true;
//	adjustEnable = false;
//	vec = v;
//	update();
//}
//
//void newImageView::readyAdjustpaintSlot(int w, int c)
//{
//	updateEnable = true;
//	moveChange = false;
//	adjustEnable = true;
//	adjustWidth = w;
//	adjustCenter = c;
//	update();
//}