#include "showimage.h"
#include <QPainter>
#include <QDebug>

showImage::showImage(QWidget *parent)
: QWidget(parent)
{
	maxp = 0;
	minp = 0;
	m_bll = BllDetectorKZ::instance();
	m_bllDataFlow = BllDataFlow::instance();
	connect(m_bll, SIGNAL(returnImgSignal(int, int)), this, SLOT(returnImgSlot(int, int)));
	connect(m_bll, SIGNAL(updateSizeSignal(int)), this, SLOT(updateSizeSlot(int)));

	//connect(m_bll, SIGNAL(returnPaintGraySignal()), this, SLOT(paintGraySlot()));

	connect(m_bllDataFlow, SIGNAL(updateGrayImgSignal()), this, SLOT(updateGrayImageSlot()));

	connect(m_bllDataFlow, SIGNAL(setLineEnableSignal()), this, SLOT(setLineEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(LinepointMoveSignal(int, int, QPoint)),
		this, SLOT(LinepointMoveSlot(int, int, QPoint)));

	connect(m_bllDataFlow, SIGNAL(setRectEnableSignal()), this, SLOT(setRectEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(iniRectPointSignal(QPoint, QPoint, QPoint, QPoint, int)),
		this, SLOT(iniRectPointSlot(QPoint, QPoint, QPoint, QPoint, int)));


	connect(m_bllDataFlow, SIGNAL(setCircleEnableSignal()), this, SLOT(setCircleEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(setRadiousSignal(int)), this, SLOT(setRadiousSlot(int)));


	connect(m_bllDataFlow, SIGNAL(setCancelEnableSignal()), this, SLOT(setCancelEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(cancelCircleSignal(int)),
		this, SLOT(cancelCircleSlot(int)));
	connect(m_bllDataFlow, SIGNAL(cancelRectSignal(int)),
		this, SLOT(cancelRectSlot(int)));

	connect(m_bllDataFlow, SIGNAL(LightContrastChangeSignal(int, int)), this, SLOT(LightContrastChangeSlot(int, int)));
	connect(m_bllDataFlow, SIGNAL(setBlursizeSignal(int, int)), this, SLOT(setBlursizeSlot(int, int)));

	connect(m_bllDataFlow, SIGNAL(getPosSignal()), this, SLOT(getPosSlots()));
	connect(m_bllDataFlow, SIGNAL(getPosCancelSignal()), this, SLOT(getPosCancelSlots()));

	connect(m_bll, SIGNAL(lineMoveSignal(QVector<QPointF>)), this, SLOT(lineMoveSlot(QVector<QPointF>)));
	connect(m_bll, SIGNAL(readyAdjustpaintSignal(int, int)),
		this, SLOT(readyAdjustpaintSlot(int, int)));


	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
	connect(m_bllDataFlow, SIGNAL(setLineAngleEnableSignal()), this, SLOT(setLineAngleEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(setperpenEnableSignal()), this, SLOT(setperpenEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(setperdenEnableSignal()), this, SLOT(setperdenEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(setpixEnableSignal()), this, SLOT(setpixEnableSlot()));
	connect(m_bllDataFlow, SIGNAL(setDisenableSignal()), this, SLOT(setDisenableSlot()));
	connect(m_bllDataFlow, SIGNAL(setMoveLimitSignal()), this, SLOT(setMoveLimitSlot()));
	connect(m_bllDataFlow, SIGNAL(setLaMoveSignal(ShapeMode, int, int)), this, SLOT(setLaMoveSlot(ShapeMode, int, int)));
	connect(m_bllDataFlow, SIGNAL(cancelMoveLimitSignal()), this, SLOT(cancelMoveLimitSlot()));
	connect(m_bllDataFlow, SIGNAL(cancelShapeSignal()), this, SLOT(cancelShapeSlot()));
	connect(m_bllDataFlow, SIGNAL(setlaCancelSignal(int)), this, SLOT(setlaCancelSlot(int)));
	connect(m_bllDataFlow, SIGNAL(setPmoveSignal(ShapeMode, int, int)), this, SLOT(setPmoveSlot(ShapeMode, int, int)));
	connect(m_bllDataFlow, SIGNAL(setPcancelSignal(ShapeMode, int)), this, SLOT(setPcancelSlot(ShapeMode, int)));
	connect(m_bllDataFlow, SIGNAL(clearShapeSignal()), this, SLOT(clearShapeSlot()));
	connect(m_bllDataFlow, SIGNAL(setPixReleaseSignal()), this, SLOT(setPixReleaseSlot()));
	//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++



	row = 704;
	m_8bitgrayImg = new uchar[row * row]();
	memset(m_8bitgrayImg, 0, row * row * sizeof(char));

	updateEnable = false;
	moveChange = false;
	adjustEnable = false;
	m_width = 0;
	m_center = 0;
	adjustWidth = 0;
	adjustCenter = 0;
	light = 0;
	contrast = 0;
	Sliderchange = false;
	//-------------------------测量工具
	displayW = 0;
	displayH = 0;

	//line
	drawline = false;
	moveline = false;
	lineEnable = false;
	linenumber = 0;
	pointorder = 1000;
	clickcount = 0;
	lineMoveSerial = 1000;
	lineDeleteSerial = 1000;

	//rect
	rectEnable = false;
	pointcount = 0;
	rectnum = 0;
	//circle
	circleEnable = false;
	radious = 0;
	circleNum = 0;
	//cancel
	cancelEnable = false;
	getposE = false;

	//--------------------------------
	m_scale = 1;


	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
	m_Count = 0;
	m_la = 0;
	m_ppCount = 0;
	m_perdenCount = 0;
	m_pix = new PixClass();
	m_laEnable = false;
	m_perpenEnable = false;
	m_perdenwireEnable = false;
	m_pixEnable = false;
	m_chartWidget = new PixChartWidget();
	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++



	//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
	connect(m_bllDataFlow, SIGNAL(ifMouseMoveSignal(bool)), this, SLOT(ifMouseMoveSlot(bool)));
	//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++
}

showImage::~showImage()
{

}

void showImage::wheelEvent(QWheelEvent *event)
{
	int data = event->delta();
	if (data > 0)
	{
		m_scale *= 2;
		//zoomin_count += 1;
		//qDebug() << "zoomin_count:" << zoomin_count;
	}
	if (data < 0)
	{
		if (m_scale >= 2)
		{
			m_scale *= 0.5;
			//zoomout_count += 1;
			//qDebug() << "zoomout_count:" << zoomout_count;
		}
	}
	//updateEnable = true;
	//moveChange = true;
	//adjustEnable = true;
	update();
}

void showImage::paintEvent(QPaintEvent * event)
{

	quint16* m_grayImg = BllDetectorKZ::getSingleImg();

	if (m_grayImg == NULL)
	{
		return;
	}
	if (updateEnable || mainImageFlag )
	{
		//绘制灰度图像
		if (moveChange)
		{
			BllDataFlow::moveTochangeGrayImg(m_grayImg, m_8bitgrayImg, vec);
			qDebug() << "--------------1-----------------";
		}
		if (adjustEnable)
		{
			qDebug() << "m_width---" << m_width << "   m_center--" << m_center;

			BllDataFlow::converToGray(m_grayImg, m_8bitgrayImg, adjustWidth, adjustCenter);
			qDebug() << "--------------2-----------------";
		}
		if (!moveChange && !adjustEnable)
		{
			BllDataFlow::converToGray(m_grayImg, m_8bitgrayImg, m_width, m_center);
			qDebug() << "--------------3-----------------";
			//BllDataFlow::converTo8bitGrayimg(m_grayImg, m_8bitgrayImg);
		}
		//moveChange = false;
		//adjustEnable = false;

		//QStyleOption opt;
		//opt.init(this);
		QPainter p(this);
		//style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);

		this->setMinimumSize(930 * m_scale, 800 * m_scale);//控制显示区域的大小
		this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		QRect target(0, 0, this->width(), this->height());
		//qDebug() <<"main---------"<< this->width() << this->height();
		QImage image(m_8bitgrayImg, row, row, QImage::Format_Grayscale8);
		//qDebug() << "main---------" << row << row;
		//亮度调节----start
		if (Sliderchange)
		{
			srcImg = QImagechange(image);
			if (!srcImg.data)
			{
				//qDebug() << "*****************8error,no datachange******************************";
			}
			else
			{
				//qDebug() << "*****************datachange ok******************************";
				dstImg = Mat::zeros(srcImg.size(), srcImg.type());

			}
			SliderchangeMethod(contrast, light);
			QImage changeimage = Matchange(dstImg);
			p.drawImage(target, changeimage);
			Sliderchange = false;

		}
		else
		{
			p.drawImage(target, image);
		}
		//亮度调节----end
		//p.drawImage(target, image);
		p.setRenderHint(QPainter::Antialiasing, true);
		QFont font("Microsoft YaHei", 10, 50);
		p.setFont(font);

		//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
		if (m_vecLa.size() > 0)
		{
			for (int i = 0; i < m_vecLa.size(); i++)
			{
				QLineF line1(m_vecLa[i]->getOne(), m_vecLa[i]->getTwo());
				QLineF line2(m_vecLa[i]->getOne(), m_vecLa[i]->getThree());
				p.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
				p.drawLine(line1);
				p.drawLine(line2);

				//QPoint start(m_vecLa[i]->getOne().x() - 4, m_vecLa[i]->getOne().y()-4);
				double ag = m_vecLa[i]->getAg();
				QRectF rect(m_vecLa[i]->getOne().x() - 8, m_vecLa[i]->getOne().y() - 8, 16, 16);
				//paint->drawArc(20, 20, 210, 160, 500, 1000);
				p.setPen(QPen(Qt::red, 2, Qt::SolidLine));
				p.drawArc(rect, 0, -ag * 16);


				QString strag = "Ag: ";
				strag.append(QString::number(ag)).append("°");
				p.drawText(m_vecLa[i]->getOne().x() + 15, m_vecLa[i]->getOne().y() + 15, strag);
				QString strdis = "Dis: ";
				double dis = m_vecLa[i]->getDis();
				strdis.append(QString::number(dis)).append(" pix").append(" /n ").append("122343");
				/*int x = (m_vecLa[i]->getOne().x() + m_vecLa[i]->getTwo().x())/2;
				int y = (m_vecLa[i]->getOne().y() + m_vecLa[i]->getTwo().y()) / 2;
				int mar = strdis.length();*/

				p.drawText(m_vecLa[i]->getOne().x() + 15, m_vecLa[i]->getOne().y() + 30, strdis);
			}
		}

		if (m_vecpw.size() > 0)
		{
			for (int i = 0; i < m_vecpw.size(); i++)
			{
				QLineF line1(m_vecpw[i]->getOne(), m_vecpw[i]->getTwo());
				QLineF line2(m_vecpw[i]->getThree(), m_vecpw[i]->getFour());
				p.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
				p.drawLine(line1);
				p.setPen(QPen(Qt::green, 2, Qt::DashLine));
				p.drawLine(line2);

				p.setPen(QPen(Qt::red, 2, Qt::SolidLine));
				double ldis = m_vecpw[i]->getDis();
				QString strldis = "LDis: ";
				strldis.append(QString::number(ldis)).append(" pix");

				int x = m_vecpw[i]->getOne().x();
				int y = m_vecpw[i]->getOne().y();
				p.drawText(x + 15, y + 15, strldis);

				double lvdis = m_vecpw[i]->getDisV();
				QString strlvdis = "LVDis: ";
				strlvdis.append(QString::number(lvdis)).append(" pix");
				p.drawText(x + 15, y + 30, strlvdis);

				double ratio = lvdis / ldis * 100;
				QString strra = "Ra: ";
				strra.append(QString::number(ratio)).append("%");
				p.drawText(x + 15, y + 45, strra);

				int x1 = m_vecpw[i]->getOne().x();
				int y1 = m_vecpw[i]->getOne().y();
				int x2 = m_vecpw[i]->getTwo().x();
				int y2 = m_vecpw[i]->getTwo().y();
				int x4 = m_vecpw[i]->getFour().x();
				int y4 = m_vecpw[i]->getFour().y();
				QPoint minP;
				QPoint maxP;
				double d14 = (x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4);
				double d24 = (x2 - x4)*(x2 - x4) + (y2 - y4)*(y2 - y4);
				if (d14 > d24)
				{
					maxP = m_vecpw[i]->getOne();
					minP = m_vecpw[i]->getTwo();
				}
				else
				{
					maxP = m_vecpw[i]->getTwo();
					minP = m_vecpw[i]->getOne();
				}
				double d12 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
				double dd = (maxP.x() - x4)*(maxP.x() - x4) + (maxP.y() - y4)*(maxP.y() - y4);
				if (dd > d12)
				{
					p.setPen(QPen(Qt::red, 2, Qt::DashLine));
					QLineF line3(minP, m_vecpw[i]->getFour());
					p.drawLine(line3);
				}
			}
		}


		if (m_vecpp.size() > 0)
		{
			for (int i = 0; i < m_vecpp.size(); i++)
			{
				QLineF line1(m_vecpp[i]->getOne(), m_vecpp[i]->getTwo());
				QLineF line2(m_vecpp[i]->getFive(), m_vecpp[i]->getSix());
				QLineF line3(m_vecpp[i]->getEight(), m_vecpp[i]->getNine());
				p.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
				p.drawLine(line1);
				p.drawLine(line2);
				p.drawLine(line3);
				p.setPen(QPen(Qt::green, 2, Qt::DashLine));
				QLineF line4(m_vecpp[i]->getThree(), m_vecpp[i]->getSeven());
				QLineF line5(m_vecpp[i]->getFour(), m_vecpp[i]->getTen());
				p.drawLine(line4);
				p.drawLine(line5);

				p.setPen(QPen(Qt::red, 2, Qt::SolidLine));

				double dis = m_vecpp[i]->getDis();
				QString strdis = "Dis: ";
				strdis.append(QString::number(dis)).append(" pix");

				double disv1 = m_vecpp[i]->getDisV1();
				QString strdisv1 = "LV1Dis: ";
				strdisv1.append(QString::number(disv1)).append(" pix");

				double disv2 = m_vecpp[i]->getDisV2();
				QString strdisv2 = "LV2Dis: ";
				strdisv2.append(QString::number(disv2)).append(" pix");

				double ra = m_vecpp[i]->getLv() * 100;
				QString strra = "Ra: ";
				strra.append(QString::number(ra)).append("%");

				int x = m_vecpp[i]->getOne().x();
				int y = m_vecpp[i]->getOne().y();

				p.drawText(x + 15, y + 15, strdis);
				p.drawText(x + 15, y + 30, strdisv1);
				p.drawText(x + 15, y + 45, strdisv2);
				p.drawText(x + 15, y + 60, strra);

				int x1 = m_vecpp[i]->getOne().x();
				int y1 = m_vecpp[i]->getOne().y();
				int x2 = m_vecpp[i]->getTwo().x();
				int y2 = m_vecpp[i]->getTwo().y();
				int x7 = m_vecpp[i]->getSeven().x();
				int y7 = m_vecpp[i]->getSeven().y();
				int x10 = m_vecpp[i]->getTen().x();;
				int y10 = m_vecpp[i]->getTen().y();


				QPoint minP1;
				QPoint maxP1;
				QPoint minP2;
				QPoint maxP2;
				double d17 = (x1 - x7)*(x1 - x7) + (y1 - y7)*(y1 - y7);
				double d27 = (x2 - x7)*(x2 - x7) + (y2 - y7)*(y2 - y7);
				double d110 = (x1 - x10)*(x1 - x10) + (y1 - y10)*(y1 - y10);
				double d210 = (x2 - x10)*(x2 - x10) + (y2 - y10)*(y2 - y10);

				if (d17 > d27)
				{
					maxP1 = m_vecpp[i]->getOne();
					minP1 = m_vecpp[i]->getTwo();
				}
				else
				{
					maxP1 = m_vecpp[i]->getTwo();
					minP1 = m_vecpp[i]->getOne();
				}

				if (d110 > d210)
				{
					maxP2 = m_vecpp[i]->getOne();
					minP2 = m_vecpp[i]->getTwo();
				}
				else
				{
					maxP2 = m_vecpp[i]->getTwo();
					minP2 = m_vecpp[i]->getOne();
				}
				p.setPen(QPen(Qt::red, 2, Qt::DashLine));
				double d12 = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
				double dd = (maxP1.x() - x7)*(maxP1.x() - x7) + (maxP1.y() - y7)*(maxP1.y() - y7);
				double ddd = (maxP2.x() - x10)*(maxP2.x() - x10) + (maxP2.y() - y10)*(maxP2.y() - y10);
				if (dd > d12)
				{

					QLineF line6(minP1, m_vecpp[i]->getSeven());
					p.drawLine(line6);
					int x11 = m_vecpp[i]->getThree().x();
					int y11 = m_vecpp[i]->getThree().y();
					int x55 = m_vecpp[i]->getFive().x();
					int y55 = m_vecpp[i]->getFive().y();
					int x66 = m_vecpp[i]->getSix().x();
					int y66 = m_vecpp[i]->getSix().y();
					double d = (x11 - x55)*(x11 - x55) + (y11 - y55)*(y11 - y55);
					double dd = (x11 - x66)*(x11 - x66) + (y11 - y66)*(y11 - y66);
					if (d < dd)
					{
						QLineF line7(QPoint(x55, y55), m_vecpp[i]->getThree());
						p.drawLine(line7);
					}
					else
					{
						QLineF line7(QPoint(x66, y66), m_vecpp[i]->getThree());
						p.drawLine(line7);
					}


				}
				if (ddd > d12)
				{
					QLineF line7(minP2, m_vecpp[i]->getTen());
					p.drawLine(line7);
					int x11 = m_vecpp[i]->getFour().x();
					int y11 = m_vecpp[i]->getFour().y();
					int x55 = m_vecpp[i]->getEight().x();
					int y55 = m_vecpp[i]->getEight().y();
					int x66 = m_vecpp[i]->getNine().x();
					int y66 = m_vecpp[i]->getNine().y();
					double d = (x11 - x55)*(x11 - x55) + (y11 - y55)*(y11 - y55);
					double dd = (x11 - x66)*(x11 - x66) + (y11 - y66)*(y11 - y66);
					if (d < dd)
					{
						QLineF line8(QPoint(x55, y55), m_vecpp[i]->getFour());
						p.drawLine(line8);
					}
					else
					{
						QLineF line8(QPoint(x66, y66), m_vecpp[i]->getFour());
						p.drawLine(line8);
					}
				}

				//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
			}

		}

		if (m_vecPixP.size() == 2)
		{
			QLineF line(m_vecPixP[0]->getPos(), m_vecPixP[1]->getPos());
			p.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
			p.drawLine(line);


		}
	}


	updateEnable = false;
	paintImgTools();

}

void showImage::mouseMoveEvent(QMouseEvent * event)
{

	if (moveline)
	{
		double dis = vectorLine[lineMoveSerial]->getDistance();
		moveCalPoint(dis, event->pos());


		tmpPoint = event->pos();
	}
	if (getposE)
	{
		toPos_Value(event->pos());

	}
	//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
	m_bllDataFlow->sendPosSignal(event->pos());
	//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++
}

void showImage::mousePressEvent(QMouseEvent * event)
{
	qDebug() << "---grayImageView::mousePressEvent";
	clickcount++;
	if (lineEnable)
	{
		pointcount++;
		if (pointcount % 2 == 1)
		{
			int order = pointcount / 2;
			//linenumber = order + 1;
			linenumber++;
			LinePointWidget* startP = new LinePointWidget(event->pos(), linenumber, 0, this);
			startP->show();
			vectorPoint.append(startP);
		}
		if (pointcount % 2 == 0)
		{
			//linenumber = pointcount / 2;
			//qDebug() << "linecount == 2 this is startp width and height" << startP->getPos().x() << ";;" << startP->getPos().y();
			LinePointWidget* endP = new LinePointWidget(event->pos(), linenumber, 1, this);
			endP->show();
			vectorPoint.append(endP);
			Line *l = new Line(linenumber);
			QPoint s = vectorPoint[vectorPoint.size() - 2]->getPos();
			QPoint e = vectorPoint[vectorPoint.size() - 1]->getPos();
			if (s.y() > e.y())
			{
				l->setPoint(e, s);
			}
			else
			{
				l->setPoint(s, e);
			}
			vectorLine.append(l);
			qDebug() << "----------------";
			m_bllDataFlow->iniLineLimit(displayW, displayH);
			qDebug() << "===================";
			drawline = true;
			update();
			lineEnable = false;
		}
	}

	if (pointcount >= 2 && clickcount >= 3)
	{
		if (judgeDistanceToMove(event->pos()) && !cancelEnable)
		{
			moveline = true;
			setCursor(Qt::CrossCursor);
		}
	}
	if (rectEnable)
	{
		rectnum++;
		RectWidget* rect = new RectWidget(event->pos(), rectnum, this);
		rect->show();

		vectorRect.append(rect);


		rectEnable = false;

	}
	if (circleEnable)
	{
		circleNum++;
		qDebug() << "rrrrrrrrrrrrrrrrrrrrrrrrrr" << radious;
		CircleWidget* circle = new CircleWidget(event->pos(), circleNum, radious, this);
		circle->show();
		vectorCircle.append(circle);
		circleEnable = false;
	}
	if (cancelEnable)
	{
		if (judgeDeleteLine(event->pos()))
		{
			deleteLine(lineDeleteSerial);
		}
		cancelEnable = false;
	}

	//----------------------------------------------
	quint16* m_grayImg = BllDetectorKZ::getSingleImg();
	Mat src = Mat::zeros(row, row, CV_16U);
	for (int i = 0; i < row*row; i++)
	{
		int rows = i / row;
		int cols = i % row;
		src.at<ushort>(rows, cols) = m_grayImg[i];
	}
	QPoint point = event->pos();
	int x = point.x()*row / this->width();
	int y = point.y()*row / this->height();
	ushort value = src.at<ushort>(y, x);
	Para p;
	p.x = x;
	p.y = y;
	p.pixel = value;
	emit paraSignal(p);


	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++

	if (m_laEnable)
	{
		m_Count++;
		if (m_Count % 2 != 0)
		{
			m_la++;
			LAPointWidget* la1 = new LAPointWidget(ShapeMode::Line_angle, event->pos(), 0, m_la, this);
			la1->show();
			m_vecLaP.append(la1);
		}
		else
		{
			LAPointWidget* la2 = new LAPointWidget(ShapeMode::Line_angle, event->pos(), 1, m_la, this);
			la2->show();
			m_vecLaP.append(la2);
			QPoint s = m_vecLaP[m_la * 2 - 2]->getPos();
			QPoint e = m_vecLaP[m_la * 2 - 1]->getPos();
			LAClass* lac = new LAClass(m_la);
			if (s.y() < e.y())
			{
				lac->updataPos(s, e);
			}
			else
			{
				lac->updataPos(e, s);
			}

			//QPoint t = lac->getThree();
			m_vecLa.append(lac);
			update();
			m_Count = 0;
		}
	}
	if (m_perdenwireEnable)
	{
		m_Count++;
		if (m_Count % 3 == 1)
		{
			m_perdenCount++;
			MeasurePointWidget* p1 = new MeasurePointWidget(PerdenWire, event->pos(), 0, m_perdenCount, this);
			p1->show();
			m_vecpwP.append(p1);
		}
		else if (m_Count % 3 == 2)
		{
			MeasurePointWidget* p2 = new MeasurePointWidget(PerdenWire, event->pos(), 1, m_perdenCount, this);
			p2->show();
			m_vecpwP.append(p2);
		}
		else
		{
			MeasurePointWidget* p3 = new MeasurePointWidget(PerdenWire, event->pos(), 2, m_perdenCount, this);
			p3->show();
			m_vecpwP.append(p3);

			QPoint pp1 = m_vecpwP[m_perdenCount * 3 - 3]->getPos();
			QPoint pp2 = m_vecpwP[m_perdenCount * 3 - 2]->getPos();
			QPoint pp3 = m_vecpwP[m_perdenCount * 3 - 1]->getPos();
			PerpenWireClass* pw = new PerpenWireClass(PerdenWire, m_perdenCount);
			if (pp1.y() < pp2.y())
			{
				pw->updatePos(pp1, pp2, pp3);
			}
			else
			{
				pw->updatePos(pp2, pp1, pp3);
			}
			m_vecpw.append(pw);
			update();
			m_Count = 0;

		}
	}
	if (m_perpenEnable)
	{
		m_Count++;
		if (m_Count % 4 == 1)
		{
			m_ppCount++;
			MeasurePointWidget* p1 = new MeasurePointWidget(ShapeMode::Perpen, event->pos(), 0, m_ppCount, this);
			p1->show();
			m_vecppP.append(p1);
		}
		else if (m_Count % 4 == 2)
		{
			MeasurePointWidget* p2 = new MeasurePointWidget(ShapeMode::Perpen, event->pos(), 1, m_ppCount, this);
			p2->show();
			m_vecppP.append(p2);
		}
		else if (m_Count % 4 == 3)
		{
			MeasurePointWidget* p3 = new MeasurePointWidget(ShapeMode::Perpen, event->pos(), 2, m_ppCount, this);
			p3->show();
			m_vecppP.append(p3);
		}
		else
		{
			MeasurePointWidget* p4 = new MeasurePointWidget(ShapeMode::Perpen, event->pos(), 3, m_ppCount, this);
			p4->show();
			m_vecppP.append(p4);

			QPoint pp1 = m_vecppP[4 * m_ppCount - 4]->getPos();
			QPoint pp2 = m_vecppP[4 * m_ppCount - 3]->getPos();
			QPoint pp3 = m_vecppP[4 * m_ppCount - 2]->getPos();
			QPoint pp4 = m_vecppP[4 * m_ppCount - 1]->getPos();

			PPClass* pp = new PPClass(m_ppCount);
			if (pp1.y() < pp2.y())
			{
				pp->updatePos(pp1, pp2, pp3, pp4);
			}
			else
			{
				pp->updatePos(pp2, pp1, pp3, pp4);
			}

			m_vecpp.append(pp);
			update();
			m_Count = 0;

		}
	}
	if (m_pixEnable)
	{
		if (m_vecPixP.size() < 2)
		{
			m_Count++;
			if (m_Count % 2 != 0)
			{
				MeasurePointWidget* m_pixStart = new MeasurePointWidget(ShapeMode::Pix, event->pos(), 0, 0, this);
				m_pixStart->show();
				m_vecPixP.append(m_pixStart);
			}
			else
			{
				MeasurePointWidget* m_pixEnd = new MeasurePointWidget(ShapeMode::Pix, event->pos(), 1, 0, this);
				m_pixEnd->show();
				m_vecPixP.append(m_pixEnd);
				QPoint s = m_vecPixP[0]->getPos();
				QPoint e = m_vecPixP[1]->getPos();
				if (s.y() < e.y())
				{
					m_pix->updateData(s, e);
				}
				else
				{
					m_pix->updateData(e, s);
				}

				update();
				QVector<QPoint> imgdata = m_pix->getData();
				m_chartWidget->show();
				m_chartWidget->updateChart(imgdata);
				m_Count = 0;
			}
		}
	}


	//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++

	

}

void showImage::mouseReleaseEvent(QMouseEvent * event)
{
	if (moveline)
	{
		moveline = false;
		setCursor(Qt::ArrowCursor);
	}

}

void showImage::resizeEvent(QResizeEvent * event)
{
	qDebug() << "this is resize event----------" << this->size();
	displayW = this->size().width();
	displayH = this->size().height();
	updateEnable = true;

}

void showImage::SliderchangeMethod(int vcontrast, int vlight)
{
	for (int y = 0; y < dstImg.rows; y++)
	{
		for (int x = 0; x < dstImg.cols; x++)
		{
			dstImg.at<uchar>(y, x) = saturate_cast<uchar>((vcontrast*0.01)*(srcImg.at<uchar>(y, x)) + vlight);
		}
	}
}

void showImage::GaussianBlurMethod(int size)
{
	MatchangeQuint(size, 0);
}

void showImage::BlurMethod(int size)
{
	MatchangeQuint(size, 1);
}

void showImage::medianBlurMethod(int size)
{
	MatchangeQuint(size, 2);

}

void showImage::SizeOverLimit(int size)
{
	//m_8bitgrayImg
	Mat Img = Mat::zeros(row, row, CV_8U);
	for (int i = 0; i < row * row; i++)
	{
		int rows = i / row;
		int cols = i % row;
		int data = m_8bitgrayImg[i];
		Img.at<uchar>(rows, cols) = data;
	}
	Mat result = Mat::zeros(row, row, CV_8U);
	medianBlur(Img, result, size);
	for (int i = 0; i < Img.rows; i++)
	{
		for (int j = 0; j < Img.cols; j++)
		{
			int data = result.at<uchar>(i, j);
			m_8bitgrayImg[i * row + j] = data;
		}

	}
	update();
	m_bllDataFlow->readyGrayCurve();
	m_bll->readyAdjust(1);//显示直方图调整的曲线

}

void showImage::MatchangeQuint(int size, int serial)
{
	quint16* m_grayImg = BllDetectorKZ::getSingleImg();
	Mat Img = Mat::zeros(row, row, CV_16U);
	for (int i = 0; i < row * row; i++)
	{
		int rows = i / row;
		int cols = i % row;
		int data = m_grayImg[i];
		Img.at<ushort>(rows, cols) = data;

	}

	Mat result = Mat::zeros(row, row, CV_16U);
	if (serial == 0)
	{
		GaussianBlur(Img, result, Size(size, size), 0, 0);
	}
	if (serial == 1)
	{
		blur(Img, result, Size(size, size));
	}
	if (serial == 2)
	{
		if (size <= 5)
		{
			medianBlur(Img, result, size);
		}
		else
		{
			SizeOverLimit(size);
		}

	}

	for (int i = 0; i < Img.rows; i++)
	{
		for (int j = 0; j < Img.cols; j++)
		{
			int data = result.at<ushort>(i, j);
			m_grayImg[i * row + j] = data;
		}

	}

	update();
	m_bllDataFlow->readyGrayCurve();
	m_bll->readyAdjust(1);//显示直方图调整的曲线

}

bool showImage::judgeDistanceToMove(QPoint p)
{

	int x = p.x();
	int y = p.y();
	bool move = false;
	if (vectorLine.size() != 0)
	{
		//qDebug() << "this is vectorLine.size() vectorLine.size()--" << vectorLine.size();
		for (int i = 0; i < vectorLine.size(); i++)
		{
			double k = vectorLine[i]->getK();
			double b = vectorLine[i]->getB();
			double bottom = sqrt(k*k + 1);
			double top = k*x - y + b;
			double result = fabs(top / bottom);
			//qDebug() << "---------------------result" << result;
			if (result < 6)
			{
				move = true;
				lineMoveSerial = i;
				QPointF s = vectorLine[i]->getStartP();
				QPointF e = vectorLine[i]->getEndP();
				tmpPoint.setX((s.x() + e.x()) / 2);
				tmpPoint.setY((s.y() + e.y()) / 2);
				break;
			}

		}
	}
	return move;

}

void showImage::moveCalPoint(int dis, QPoint pos)
{
	int x = pos.x() - tmpPoint.x();
	int y = pos.y() - tmpPoint.y();
	QPointF s = vectorLine[lineMoveSerial]->getStartP();
	QPointF e = vectorLine[lineMoveSerial]->getEndP();
	s.setX(s.x() + x);
	s.setY(s.y() + y);
	e.setX(e.x() + x);
	e.setY(e.y() + y);
	vectorLine[lineMoveSerial]->updateDate(s, e);
	drawline = true;
	update();
	QPoint ss((int)(s.x()), (int)(s.y()));
	QPoint ee((int)(e.x()), (int)(e.y()));
	m_bllDataFlow->LineMoveChangePoint(lineMoveSerial + 1, 0, ss);
	m_bllDataFlow->LineMoveChangePoint(lineMoveSerial + 1, 1, ee);

}

bool showImage::judgeDeleteLine(QPoint pos)
{
	int x = pos.x();
	int y = pos.y();
	bool deleteline = false;
	if (vectorLine.size() != 0)
	{
		//qDebug() << "this is vectorLine.size() vectorLine.size()--" << vectorLine.size();
		for (int i = 0; i < vectorLine.size(); i++)
		{
			double k = vectorLine[i]->getK();
			double b = vectorLine[i]->getB();
			double bottom = sqrt(k*k + 1);
			double top = k*x - y + b;
			double result = fabs(top / bottom);
			//qDebug() << "---------------------result" << result;
			if (result < 6)
			{
				deleteline = true;
				lineDeleteSerial = i;
				//qDebug() << "this is test line number---" << lineDeleteSerial;
				break;
			}
		}
	}
	return deleteline;
}

void showImage::deleteLine(int serial)
{
	int point1 = serial * 2;
	int point2 = serial * 2 + 1;
	delete vectorPoint[point1];
	delete vectorPoint[point2];
	vectorPoint.remove(point1);
	vectorPoint.remove(point1);
	delete vectorLine[serial];
	vectorLine.remove(serial);
	drawline = true;
	for (int i = serial; i < vectorLine.size(); i++)
	{
		vectorLine[i]->updateSerial();
		m_bllDataFlow->updateLinepointSerial(i + 2);
	}
	update();
	linenumber--;
	setCursor(Qt::ArrowCursor);
}

void showImage::paintImgTools()
{
	QPainter painter(this);

	painter.setRenderHint(QPainter::Antialiasing, true);
	if (drawline)
	{
		qDebug() << "this is ----size--" << vectorLine.size();
		if (vectorLine.size() != 0)
		{
			for (int i = 0; i < vectorLine.size(); i++)
			{
				QLineF line(vectorLine[i]->getStartP(), vectorLine[i]->getEndP());
				painter.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
				painter.drawLine(line);
				qDebug() << "tttttttttttttttttt";
				double x = (vectorLine[i]->getStartP().x() + vectorLine[i]->getEndP().x()) / 2;
				double y = (vectorLine[i]->getStartP().y() + vectorLine[i]->getEndP().y()) / 2;
				QPointF txt(x + 10, y + 10);
				QString distance = "D: ";
				double d = vectorLine[i]->getRealD();
				distance.append(QString::number(d, 10, 2)).append("mm");
				painter.drawText(txt, distance);
				if (vectorLine[i]->getLinePoint().size() != 0 && vectorLine[i]->getLinePoint().size() == vectorLine[i]->getVLinePoint().size())
				{
					QVector<QPointF> tmpline = vectorLine[i]->getLinePoint();
					QVector<QPointF> tmpvline = vectorLine[i]->getVLinePoint();
					for (int j = 0; j < tmpline.size(); j++)
					{
						QLineF ll(tmpline[j], tmpvline[j]);
						painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
						painter.drawLine(ll);
					}
				}

			}
		}
		drawline = false;
	}
}

void showImage::toPos_Value(QPoint p)
{
	double xalias = (double)row / this->width();
	double yalias = (double)row / this->height();
	int x = p.x()*xalias;
	int y = p.y()*yalias;
	int pos = y * row + x;;
	qDebug() << "pos--------------" << pos;
	quint16* m_grayImg = BllDetectorKZ::getSingleImg();
	if (m_grayImg == NULL)
	{
		return;
	}
	int value = m_grayImg[pos];
	qDebug() << "x: " << x << "  y: " << y << "  value: " << value;

	int row = y + 1;
	int col = x + 1;
	m_bllDataFlow->getPos_Value(row, col, value);

}

QImage showImage::Matchange(const cv::Mat& mat)
{
	if (mat.type() == CV_8UC1)
	{
		QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)    
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat    
		uchar *pSrc = mat.data;
		for (int row = 0; row < mat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mat.cols);
			pSrc += mat.step;
		}
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3    
	else if (mat.type() == CV_8UC3)
	{
		// Copy input Mat    
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat    
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
		return image.rgbSwapped();
	}
	else if (mat.type() == CV_8UC4)
	{
		qDebug() << "CV_8UC4";
		// Copy input Mat    
		const uchar *pSrc = (const uchar*)mat.data;
		// Create QImage with same dimensions as input Mat    
		QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
		return image.copy();
	}
	else
	{
		qDebug() << "ERROR: Mat could not be converted to QImage.";
		return QImage();
	}

}

Mat showImage::QImagechange(QImage image)
{
	cv::Mat mat;
	switch (image.format())
	{
	case QImage::Format_ARGB32:
	case QImage::Format_RGB32:
	case QImage::Format_ARGB32_Premultiplied:
		mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
		break;
	case QImage::Format_RGB888:
		mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
		cv::cvtColor(mat, mat, CV_BGR2RGB);
		break;
	case QImage::Format_Grayscale8:
		mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
		break;
	}
	return mat;
}

void showImage::returnImgSlot(int min, int max)
{
	minp = min;
	maxp = max;
	m_center = (maxp + minp) / 2;
	m_width = maxp - minp;
	updateEnable = true;
	mainImageFlag = 1;
	update();
}

void showImage::updateSizeSlot(int width)
{
	row = width;
	if (m_8bitgrayImg != NULL)
	{
		delete m_8bitgrayImg;
		m_8bitgrayImg = NULL;
	}

	m_8bitgrayImg = new uchar[row * row]();
	memset(m_8bitgrayImg, 0, row * row * sizeof(char));
}

void showImage::updateGrayImageSlot()//打开文件
{
	updateEnable = true;
	update();
}

//void newImageView::moveRepaintGrayImgSlot(QVector<QPointF> vec)
//{
//	m_vector.clear();
//	updateEnable = true;
//	moveChange = true;
//	adjustEnable = false;
//	m_vector = vec;
//	update();
//}

//void newImageView::updateImgSlot()
//{
//	update();
//	m_bllDataFlow->readyGrayCurve();
//
//}

void showImage::setBlursizeSlot(int size, int serial)
{
	if (serial == 0)
	{
		GaussianBlurMethod(size);
	}
	if (serial == 1)
	{
		BlurMethod(size);
	}
	if (serial == 2)
	{
		medianBlurMethod(size);
	}
}

void showImage::LightContrastChangeSlot(int vlight, int vcontrast)
{
	light = vlight;
	contrast = vcontrast;
	Sliderchange = true;
	update();
}

void showImage::setLineEnableSlot()
{
	lineEnable = true;
	rectEnable = false;
	circleEnable = false;
	cancelEnable = false;
}

void showImage::LinepointMoveSlot(int lineOrder, int flag, QPoint pos)
{
	int m = lineOrder * 2 - 2;
	int mm = m + 1;
	QPoint s = vectorPoint[m]->getPos();
	QPoint e = vectorPoint[mm]->getPos();
	if (s.y() > e.y())
	{
		vectorLine[lineOrder - 1]->updateDate(e, s);
	}
	else
	{
		vectorLine[lineOrder - 1]->updateDate(s, e);
	}
	drawline = true;
	update();
}

void showImage::setRectEnableSlot()
{
	rectEnable = true;
	lineEnable = false;
	circleEnable = false;
	cancelEnable = false;
}

void showImage::iniRectPointSlot(QPoint lt, QPoint rt, QPoint lb, QPoint rb, int order)
{
	RectPointWidget* leftT = new RectPointWidget(lt, 0, order, this);
	leftT->show();
	RectPointWidget* rightT = new RectPointWidget(rt, 1, order, this);
	rightT->show();
	RectPointWidget* leftB = new RectPointWidget(lb, 2, order, this);
	leftB->show();
	RectPointWidget* rightB = new RectPointWidget(rb, 3, order, this);
	rightB->show();
	vectorRectP.append(leftT);
	vectorRectP.append(rightT);
	vectorRectP.append(leftB);
	vectorRectP.append(rightB);
	m_bllDataFlow->iniDisplayLimittest(displayW, displayH);
}

void showImage::setCircleEnableSlot()
{
	circleEnable = true;
	lineEnable = false;
	rectEnable = false;
	cancelEnable = false;
}

void showImage::setRadiousSlot(int r)
{
	radious = r;
}

void showImage::setCancelEnableSlot()
{
	cancelEnable = true;
	lineEnable = false;
	rectEnable = false;
	circleEnable = false;
	setCursor(Qt::PointingHandCursor);
	m_bllDataFlow->cancelShape();
}

void showImage::cancelCircleSlot(int circleserial)
{
	int serial = circleserial - 1;
	vectorCircle[serial]->close();
	vectorCircle.remove(serial);

	for (int i = serial; i < vectorCircle.size(); i++)
	{
		m_bllDataFlow->updateCircleSerial(i + 2);
	}

	circleNum--;
	setCursor(Qt::ArrowCursor);
	if (cancelEnable)
	{
		cancelEnable = false;
	}
	m_bllDataFlow->unableCancelShape();
}

void showImage::cancelRectSlot(int rectserial)
{
	int serial = rectserial - 1;
	vectorRect[serial]->close();
	vectorRect.remove(serial);
	int point1 = serial * 4;
	int point2 = serial * 4 + 1;
	int point3 = serial * 4 + 2;
	int point4 = serial * 4 + 3;
	delete vectorRectP[point1];
	delete vectorRectP[point2];
	delete vectorRectP[point3];
	delete vectorRectP[point4];
	vectorRectP.remove(point1);
	vectorRectP.remove(point1);
	vectorRectP.remove(point1);
	vectorRectP.remove(point1);

	for (int i = serial; i < vectorRect.size(); i++)
	{
		m_bllDataFlow->updateRectPointsSerial(i + 2);
		m_bllDataFlow->updateRectSerial(i + 2);
	}
	rectnum--;
	setCursor(Qt::ArrowCursor);

	if (cancelEnable)
	{
		cancelEnable = false;
	}
	m_bllDataFlow->unableCancelShape();
}

void showImage::getPosSlots()
{
	setMouseTracking(true);
	getposE = true;
}

void showImage::getPosCancelSlots()
{
	getposE = false;
	setMouseTracking(false);
	qDebug() << "this is getPosCancelSlots=========";
}

void showImage::lineMoveSlot(QVector<QPointF> v)
{
	vec.clear();
	updateEnable = true;
	moveChange = true;
	adjustEnable = false;
	vec = v;
	update();
}

void showImage::readyAdjustpaintSlot(int w, int c)
{
	updateEnable = true;
	moveChange = false;
	adjustEnable = true;
	adjustWidth = w;
	adjustCenter = c;
	update();
}


//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++

void showImage::setLineAngleEnableSlot()
{
	m_Count = 0;
	m_laEnable = true;
	m_perpenEnable = false;
	m_perdenwireEnable = false;
	m_pixEnable = false;
}
void showImage::setperpenEnableSlot()
{
	m_Count = 0;
	m_laEnable = false;
	m_perpenEnable = true;
	m_perdenwireEnable = false;
	m_pixEnable = false;
}
void showImage::setperdenEnableSlot()
{
	m_Count = 0;
	m_laEnable = false;
	m_perpenEnable = false;
	m_perdenwireEnable = true;
	m_pixEnable = false;
}

void showImage::setpixEnableSlot()
{
	m_Count = 0;
	m_laEnable = false;
	m_perpenEnable = false;
	m_perdenwireEnable = false;
	m_pixEnable = true;
}
void showImage::setMoveLimitSlot()
{

	int sizeLimit = BllDetectorKZ::returnSize();

	RECT mainWinRect; //RECT在windef.h中被定义
	mainWinRect.left = mapToGlobal(QPoint(3, 3)).x();
	mainWinRect.right = mapToGlobal(QPoint(sizeLimit - 4, 3)).x();
	mainWinRect.top = mapToGlobal(QPoint(3, 3)).y();
	mainWinRect.bottom = mapToGlobal(QPoint(3, sizeLimit - 4)).y();
	ClipCursor(&mainWinRect); //这是Windows API
}
void showImage::setLaMoveSlot(ShapeMode shape, int order, int flag)
{
	if (shape == ShapeMode::Line_angle)
	{
		if (m_vecLaP.size() % 2 == 0)
		{
			QPoint s = m_vecLaP[2 * order - 2]->getPos();
			QPoint e = m_vecLaP[2 * order - 1]->getPos();
			if (s.y() < e.y())
			{
				m_vecLa[order - 1]->updataPos(s, e);
			}
			else
			{
				m_vecLa[order - 1]->updataPos(e, s);
			}
			update();
		}

	}


}
void showImage::cancelMoveLimitSlot()
{
	ClipCursor(NULL);//释放
}
void showImage::setDisenableSlot()
{
	m_laEnable = false;
	m_perpenEnable = false;
	m_perdenwireEnable = false;
	m_pixEnable = false;
}
void showImage::cancelShapeSlot()
{
	if (m_vecLaP.size() % 2 != 0 && m_vecLaP.size()>0)
	{
		int index = m_vecLaP.size() - 1;
		delete m_vecLaP[index];
		m_vecLaP.remove(index);
		m_Count = 0;
		m_la--;
	}
	if (m_vecpwP.size() % 3 != 0 && m_vecpwP.size()>0)
	{

		int size = m_perdenCount * 3 - m_vecpwP.size();
		int ssize = 3 - size;
		if (ssize == 1)
		{
			int index = m_vecpwP.size() - 1;
			delete m_vecpwP[index];
			m_vecpwP.remove(index);
		}
		if (ssize == 2)
		{
			delete m_vecpwP[m_vecpwP.size() - 1];
			delete m_vecpwP[m_vecpwP.size() - 2];
			for (int i = 0; i < 2; i++)
			{
				m_vecpwP.remove(m_vecpwP.size() - 1);
			}
		}
		m_Count = 0;
		m_perdenCount--;
	}
	if (m_vecppP.size() % 4 != 0 && m_vecppP.size()>0)
	{
		int size = m_ppCount * 4 - m_vecppP.size();
		int ssize = 4 - size;
		if (ssize == 1)
		{
			int index = m_vecppP.size() - 1;
			delete m_vecppP[index];
			m_vecppP.remove(index);
		}
		if (ssize == 2)
		{
			delete m_vecppP[m_vecppP.size() - 1];
			delete m_vecppP[m_vecppP.size() - 2];
			for (int i = 0; i < 2; i++)
			{
				m_vecppP.remove(m_vecppP.size() - 1);
			}
		}
		if (ssize == 3)
		{
			delete m_vecppP[m_vecppP.size() - 1];
			delete m_vecppP[m_vecppP.size() - 2];
			delete m_vecppP[m_vecppP.size() - 3];
			for (int i = 0; i < 3; i++)
			{
				m_vecppP.remove(m_vecppP.size() - 1);
			}
		}
		m_Count = 0;
		m_ppCount--;

	}

	if (m_vecPixP.size() % 2 != 0 && m_vecPixP.size()>0)
	{
		delete m_vecPixP[m_vecPixP.size() - 1];
		m_vecPixP.remove(m_vecPixP.size() - 1);
		m_Count = 0;
	}

	if (m_vecLaP.size() % 2 == 0 && m_vecLaP.size()>0)
	{
		for (int i = 0; i < m_vecLaP.size(); i++)
		{
			m_vecLaP[i]->updateDeleteCursor();
		}
	}

	if (m_vecpwP.size() % 3 == 0 && m_vecpwP.size()>0)
	{
		for (int i = 0; i < m_vecpwP.size(); i++)
		{
			m_vecpwP[i]->updateDeleteCursor();
		}
	}

	if (m_vecppP.size() % 4 == 0 && m_vecppP.size()>0)
	{
		for (int i = 0; i < m_vecppP.size(); i++)
		{
			m_vecppP[i]->updateDeleteCursor();
		}
	}

	if (m_vecPixP.size() % 2 == 0 && m_vecPixP.size() > 0)
	{
		for (int i = 0; i < m_vecPixP.size(); i++)
		{
			m_vecPixP[i]->updateDeleteCursor();
		}
	}

}
void showImage::setlaCancelSlot(int order)
{
	int index = order - 1;
	delete m_vecLa[index];
	m_vecLa.remove(index);
	delete m_vecLaP[2 * index];
	delete m_vecLaP[2 * index + 1];
	m_vecLaP.remove(2 * index);
	m_vecLaP.remove(2 * index);
	for (int i = index; i < m_vecLa.size(); i++)
	{
		m_vecLa[i]->updateOrder(i + 2);
		m_vecLaP[2 * i]->updateOrder(i + 2);
		m_vecLaP[2 * i + 1]->updateOrder(i + 2);
	}
	m_la--;
	for (int i = 0; i < m_vecLaP.size(); i++)
	{
		m_vecLaP[i]->updateDeleteCursor();
	}
	update();
}
void showImage::setPmoveSlot(ShapeMode shape, int order, int flag)
{
	if (shape == ShapeMode::PerdenWire)
	{
		if (m_vecpwP.size() % 3 == 0)
		{
			QPoint p1 = m_vecpwP[3 * order - 3]->getPos();
			QPoint p2 = m_vecpwP[3 * order - 2]->getPos();
			QPoint p3 = m_vecpwP[3 * order - 1]->getPos();
			if (p1.y() < p2.y())
			{
				m_vecpw[order - 1]->updatePos(p1, p2, p3);
			}
			else
			{
				m_vecpw[order - 1]->updatePos(p2, p1, p3);
			}

		}
		update();

	}
	if (shape == ShapeMode::Perpen)
	{
		if (m_vecppP.size() % 4 == 0)
		{
			QPoint p1 = m_vecppP[4 * order - 4]->getPos();
			QPoint p2 = m_vecppP[4 * order - 3]->getPos();
			QPoint p3 = m_vecppP[4 * order - 2]->getPos();
			QPoint p4 = m_vecppP[4 * order - 1]->getPos();
			if (p1.y() < p2.y())
			{
				m_vecpp[order - 1]->updatePos(p1, p2, p3, p4);
			}
			else
			{
				m_vecpp[order - 1]->updatePos(p2, p1, p3, p4);
			}
		}
		update();
	}
	if (shape == ShapeMode::Pix)
	{
		update();
		//qDebug() << "this is move event===========";
	}
}
void showImage::setPcancelSlot(ShapeMode shape, int order)
{
	if (shape == ShapeMode::PerdenWire)
	{
		int index = order - 1;
		delete m_vecpw[index];
		m_vecpw.remove(index);
		delete m_vecpwP[3 * index];
		delete m_vecpwP[3 * index + 1];
		delete m_vecpwP[3 * index + 2];
		m_vecpwP.remove(3 * index);
		m_vecpwP.remove(3 * index);
		m_vecpwP.remove(3 * index);

		for (int i = index; i < m_vecpw.size(); i++)
		{
			m_vecpw[i]->updateOrder(i + 2);
			m_vecpwP[3 * i]->updateOrder(PerdenWire, i + 2);
			m_vecpwP[3 * i + 1]->updateOrder(PerdenWire, i + 2);
			m_vecpwP[3 * i + 2]->updateOrder(PerdenWire, i + 2);
		}
		m_perdenCount--;
		for (int i = 0; i < m_vecpwP.size(); i++)
		{
			m_vecpwP[i]->updateDeleteCursor();
		}
		update();

	}
	if (shape == ShapeMode::Perpen)
	{
		int index = order - 1;
		delete m_vecpp[index];
		m_vecpp.remove(index);
		delete m_vecppP[4 * index];
		delete m_vecppP[4 * index + 1];
		delete m_vecppP[4 * index + 2];
		delete m_vecppP[4 * index + 3];
		m_vecppP.remove(4 * index);
		m_vecppP.remove(4 * index);
		m_vecppP.remove(4 * index);
		m_vecppP.remove(4 * index);

		for (int i = index; i < m_vecpp.size(); i++)
		{
			m_vecpp[i]->updateOrder(i + 2);
			m_vecppP[4 * i]->updateOrder(Perpen, i + 2);
			m_vecppP[4 * i + 1]->updateOrder(Perpen, i + 2);
			m_vecppP[4 * i + 2]->updateOrder(Perpen, i + 2);
			m_vecppP[4 * i + 3]->updateOrder(Perpen, i + 2);
		}
		m_ppCount--;
		for (int i = 0; i < m_vecppP.size(); i++)
		{
			m_vecppP[i]->updateDeleteCursor();
		}
		update();

	}

	if (shape == ShapeMode::Pix)
	{
		if (m_vecPixP.size() == 2)
		{
			for (int i = 0; i < m_vecPixP.size(); i++)
			{
				delete m_vecPixP[i];

			}
			m_vecPixP.clear();

			m_chartWidget->close();
			update();
		}

	}
	m_Count = 0;
}
void showImage::clearShapeSlot()
{
	if (m_vecLa.size() != 0)
	{
		for (int i = 0; i < m_vecLa.size(); i++)
		{
			delete m_vecLa[i];
		}
		m_vecLa.clear();

		for (int i = 0; i < m_vecLaP.size(); i++)
		{
			delete m_vecLaP[i];
		}
		m_vecLaP.clear();
		m_la = 0;
	}
	if (m_vecpw.size() != 0)
	{
		for (int i = 0; i < m_vecpw.size(); i++)
		{
			delete m_vecpw[i];
		}
		m_vecpw.clear();
		for (int i = 0; i < m_vecpwP.size(); i++)
		{
			delete m_vecpwP[i];
		}
		m_vecpwP.clear();
		m_perdenCount = 0;
	}
	if (m_vecpp.size() != 0)
	{
		for (int i = 0; i < m_vecpp.size(); i++)
		{
			delete m_vecpp[i];
		}
		m_vecpp.clear();
		for (int i = 0; i < m_vecppP.size(); i++)
		{
			delete m_vecppP[i];
		}
		m_vecppP.clear();
		m_ppCount = 0;
	}
	if (m_vecPixP.size() != 0)
	{
		for (int i = 0; i < m_vecPixP.size(); i++)
		{
			delete m_vecPixP[i];

		}
		m_vecPixP.clear();
		//delete m_pix;
		m_chartWidget->close();
	}
	m_Count = 0;
	update();
}
void showImage::setPixReleaseSlot()
{

	update();

	m_chartWidget->hide();

	QPoint s = m_vecPixP[0]->getPos();
	QPoint e = m_vecPixP[1]->getPos();
	if (s.y() < e.y())
	{
		m_pix->updateData(s, e);
	}
	else
	{
		m_pix->updateData(e, s);
	}
	QVector<QPoint> imgdata = m_pix->getData();
	m_chartWidget->show();
	m_chartWidget->updateChart(imgdata);
}

//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
void showImage::ifMouseMoveSlot(bool flag)
{
	setMouseTracking(flag);
}
//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++