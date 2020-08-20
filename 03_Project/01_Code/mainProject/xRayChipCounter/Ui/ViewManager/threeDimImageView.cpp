#include "threeDimImageView.h"
#include "qpainter.h"
#include "qdebug.h"
threeDimImageView::threeDimImageView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	sliderNum = 0;
	m_blldataflow = BllDataFlow::instance();
	imgNum = BllDataFlow::multiImg_Num;
	imgRow = BllDataFlow::multiImg_SizeRow;
	imgCol = BllDataFlow::multiImg_SizeCol;
	m_8bitgrayImg = new uchar[imgRow * imgCol]();
	memset(m_8bitgrayImg, 0, imgRow * imgCol * sizeof(char));
	arrThreeDim = new int **[imgNum];
	for (int i = 0; i < imgNum; i++)
	{
		arrThreeDim[i] = new int *[imgRow];
		for (int j = 0; j < imgRow; j++)
		{
			arrThreeDim[i][j] = new int[imgCol];
		}
	}
	pixelsCenter = new int[imgNum];
	pixelsWidth = new int[imgNum];
	m_scale = 1;
	connect(ui.frameSlider, SIGNAL(valueChanged(int)), this, SLOT(setSliderNum(int)));
	connect(m_blldataflow, SIGNAL(threeDimPicSignal()), this, SLOT(receivePicSlot()));
	receivePicSlot();
	setSliderNum(0);

}

threeDimImageView::~threeDimImageView()
{

}

void threeDimImageView::paintEvent(QPaintEvent * event)
{
	BllDataFlow::converToGrayTest(viewData, m_8bitgrayImg, 11000, 5500);
	//BllDataFlow::converTo8bitGrayimgTest(viewData, m_8bitgrayImg);
	QPainter painter(this);
	this->setMinimumSize(450 * m_scale, 400 * m_scale);//控制显示区域的大小
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	QRect target(0, 0, this->width(), this->height());
	qDebug() << "threeDim---------" << this->width() << this->height();
	QImage image(m_8bitgrayImg, imgRow, imgCol, QImage::Format_Grayscale8);
	painter.drawImage(target, image);
}

void threeDimImageView::setSliderNum(int num)
{
	sliderNum = num;
	viewData = new qint16[imgRow*imgCol];
	//viewData[0] = 0;
	for (int i = 0; i < imgRow;i++)
	{
		for (int j = 0; j < imgCol;j++)
		{
			viewData[i*imgRow + j] = 0;
		}
	}
	for (int i = 0; i < imgRow; i++)
	{
		for (int j = 0; j < imgCol; j++)
		{			
			viewData[i*imgRow + j] = arrThreeDim[sliderNum][i][j];
		}
	}
	//qDebug() << "center and width" << pixelsCenter[sliderNum] << pixelsWidth[sliderNum];
	update();
	
}

void threeDimImageView::receivePicSlot()
{
	if (m_8bitgrayImg != NULL)
	{
		delete m_8bitgrayImg;
		m_8bitgrayImg = NULL;
	}
	m_8bitgrayImg = new uchar[imgRow * imgCol]();
	memset(m_8bitgrayImg, 0, imgRow * imgCol * sizeof(char));

	if (pixelsCenter != NULL)
	{
		delete pixelsCenter;
		pixelsCenter = NULL;
	}
	pixelsCenter = new int[imgNum];
	pixelsWidth = new int[imgNum];

	if (arrThreeDim != NULL)
	{
		delete arrThreeDim;
		arrThreeDim = NULL;
	}

	//动态创建三维数组
	arrThreeDim = new int **[imgNum];
	for (int i = 0; i < imgNum;i++)
	{
		arrThreeDim[i] = new int *[imgRow];
		for (int j = 0; j < imgRow; j++)
		{
			arrThreeDim[i][j] = new int[imgCol];
		}
	}

	
	int *maxPixels = new int[imgNum];//每张图的最大像素值
	for (int i = 0; i < imgNum;i++)
	{
		maxPixels[i] = 0;
	}

	int *minPixels = new int[imgNum];//每张图的最小像素值
	for (int i = 0; i < imgNum; i++)
	{
		minPixels[i] = 20000;
	}

	//为三维数组赋值
	qint16 *imgData = BllDataFlow::getMultiImg();//获取三维图像数据
	for (int k = 0; k < imgNum; k++)
	{
		for (int i = 0; i < imgRow; i++)
		{
			for (int j = 0; j < imgCol; j++)
			{
				arrThreeDim[k][i][j] = imgData[k*imgRow*imgCol + i*imgRow + j];
				if (maxPixels[k]<arrThreeDim[k][i][j])
				{
					maxPixels[k] = arrThreeDim[k][i][j];
				}
				if (minPixels[k]>arrThreeDim[k][i][j])
				{
					minPixels[k] = arrThreeDim[k][i][j];				
				}
			//	qDebug() << arrThreeDim[k][i][j];
				pixelsCenter[k] = (maxPixels[k] + minPixels[k]) / 2;
				pixelsWidth[k] = maxPixels[k] - minPixels[k];
				
			}
		}
	}
}