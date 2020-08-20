#include "AdjustChart.h"
#include <QMouseEvent>
#include <QDebug>
//#include <omp.h>
AdjustChart::AdjustChart(QWidget *parent)
: QChartView(parent)
{
	up = 0;
	down = 0;
	left = 0;
	right = 0;
	minx = 1000;
	maxx = 0;
	lineHight = 0;
	seriesx = new QLineSeries();
	areaSeries = NULL;
	axisx = new QValueAxis;
	axisx->setRange(0, 15000);
	axisx->setTickCount(5);
	axisy = new QValueAxis;
	axisy->setRange(0, 255);
	axisy->setTickCount(5);

	this->chart()->setAxisX(axisx, seriesx);
	this->chart()->setAxisY(axisy, seriesx);

	seriesx->setUseOpenGL(true);
	m_bll = BllDetectorKZ::instance();
	this->chart()->setTheme(QChart::ChartThemeBlueCerulean);
	this->chart()->legend()->setVisible(false);
	QMargins m(2, 2, 2, 2);
	QBrush brush1(QColor(88, 87, 86));

	this->chart()->setMargins(m);
}

AdjustChart::~AdjustChart()
{
	
}

//设置灰度曲线
void AdjustChart::setCurve(int c){
	//---11/27改动---start
	if (areaSeries != NULL)	
	{
		this->chart()->removeSeries(areaSeries);
	}
	areaSeries = new QAreaSeries(seriesx);
	areaSeries->setBorderColor(Qt::gray);
	areaSeries->setBrush(Qt::gray);
	//---11/27改动---end

	int countdata[65535];								//存放 图像中各像素值出现次数 的数组 
	memset(countdata, 0, 65535 * sizeof(int));		
	//memset是计算机中C/C++语言初始化函数。作用是将某一块内存中的内容全部设置为指定的值， 这个函数通常为新申请的内存做初始化工作。
	
	quint16* img = BllDetectorKZ::getSingleImg();
	int row = BllDetectorKZ::returnSize();
	//#pragma omp parallel for
	for (int i = 0; i < row * row; i++){
		int data = img[i];
		countdata[data] = countdata[data] + 1;		
		if (data < minx){		//像素值最低的像素的像素值
			minx = data;
		}
		if (data>maxx){			//像素值最高的像素的像素值
			maxx = data;
		}
	}
	int ymax = 0;
	for (int i = minx; i < maxx; i++){
		int value = countdata[i];
		if (value>ymax){		
			ymax = value;							//像素值个数最多数量
		}
	}
	if (seriesx->points().size() != 0){
		int index = 0;
		seriesx->clear();
		QVector<QPointF> v;
		for (int k = minx; k < maxx; k++)
		{
			int x = k;
			int data = countdata[k];
			int y = data / ((double)ymax / 255);	//2019/6/21 改动
			v.push_back(QPointF(x, y));				//横坐标为像素值 纵坐标为 出现次数/最大出现次数*255
		}
		seriesx->replace(v);
	}
	else{
		QVector<QPointF> v;
		for (int k = minx; k < maxx; k++)
		{
			int x = k;
			int data = countdata[k];
			
			int y = data *255.0 / ymax;	//2019/6/21 改动

			qDebug() <<"Xpos:"<< k << " count:" << data << " y:" << y <<" yMax:" << ymax;
			v.push_back(QPointF(x, y));
		}
		seriesx->replace(v);
	}
	

	axisx->setRange(0, (int)maxx);			//设置x坐标轴范围为[0,最大像素值]
	axisy->setRange(0, (int)255);			//设置y坐标轴范围为[0,255]

	this->chart()->addSeries(areaSeries);

	setLineHeight();
	if (maxx != 0 && minx != 1000){

		if (vecl.size() == 1)
		{
			delete vecl[0];
			vecl[0] = NULL;
			vecl.clear();
		}
		if (vecm.size() == 1)
		{
			delete vecm[0];
			vecm[0] = NULL;
			vecm.clear();
		}
		if (vecr.size() == 1)
		{
			delete vecr[0];
			vecr[0] = NULL;
			vecr.clear();
		}

		QPoint l(left, up);
		LWidget *ll = new LWidget(l, lineHight, this);

		QPoint r(right, up);
		RWidget *rr = new RWidget(r, lineHight, this);

		QPoint m((left + right) / 2, up);
		MWidget *mm = new MWidget(m, lineHight, this);

		connect(ll, SIGNAL(Lmovedata(int)), this, SLOT(LmoveSlot(int)));
		connect(rr, SIGNAL(Rmovedata(int)), this, SLOT(RmoveSlot(int)));
		connect(mm, SIGNAL(Mmovedata(int)), this, SLOT(MmoveSlot(int)));

		vecl.append(ll);
		vecm.append(mm);
		vecr.append(rr);

		ll->show();
		rr->show();
		mm->show();
			
	}
	//delete areaSeries;
	//areaSeries = NULL;
}
void AdjustChart::setLineHeight(){
	QPointF f1(0, 0);
	QPointF leftdown = this->chart()->mapToPosition(f1);
	QPointF f4(maxx, 255);
	QPointF rightup = this->chart()->mapToPosition(f4);

	qDebug() << "leftdown===================" << leftdown;

	up = rightup.y();
	down = leftdown.y();
	left = leftdown.x();
	right = rightup.x();
	lineHight = down - up;
}

//void  AdjustChart::paintEvent(QPaintEvent *event){
//	QPointF f1(0, 0);
//	QPointF leftdown = this->chart()->mapToPosition(f1);
//	qDebug() << "paintevent pos============" << leftdown;
//}
void AdjustChart::LmoveSlot(int value){
	int middle = 0;
	double rl = vecr[0]->getX();
	if (value < rl){
		middle = (int)(value + rl) / 2;
	}
	if (value >= rl - 20){
		value = rl - 20;
		middle = (int)(value + rl) / 2;
		m_bll->setLdata(value);
	}
	if (value <= left + 3){
		value = left;
		middle = (int)(value + rl) / 2;
		m_bll->setLdata(value);
	}
	m_bll->setMdata(middle);
	double width = rl - value;

	transPos(value, rl);

}
void AdjustChart::RmoveSlot(int value){
	int middle = 0;
	double l = vecl[0]->getX();
	if (value > l + 30){
		middle = (int)(value + l) / 2;
	}
	if (value < l + 20){
		value = l + 20;
		middle = (int)(value + l) / 2;
		m_bll->setRdata(value);
	}if (value >= right - 5){
		value = right - 5;
		middle = (int)(value + l) / 2;
		m_bll->setRdata(value);
	}
	//qDebug() << "this is r move r move r move r move r move r move r move r move r move r move " << this->invTransform(QwtPlot::xBottom, (int)value);
	m_bll->setMdata(middle);
	double width = value - l;

	transPos(l, value);
}
void AdjustChart::MmoveSlot(int value){
	double lll = vecl[0]->getX();
	double rl = vecr[0]->getX();
	double mmm = vecm[0]->getX();
	double oldcenter = (lll + rl) / 2;
	double middle = 0;
	if (oldcenter > value){
		if (lll <= left + 3){
			double llj = left;
			middle = (llj + rl) / 2;
			m_bll->setLdata(left);
			m_bll->setMdata(middle);
			m_bll->setRdata(rl);
			double w1 = rl - llj;

			transPos(llj, rl);
		}
		else
		{
			double width = oldcenter - value;
			int lmove = (int)(lll - width);
			int rmove = (int)(rl - width);
			m_bll->setLdata(lmove);
			m_bll->setRdata(rmove);
			double w2 = rmove - lmove;

			transPos(lmove, rmove);
		}

	}
	else{
		if (rl <right - 5){
			double width = value - oldcenter;
			int lmove = (int)(lll + width);
			int rmove = (int)(rl + width);
			m_bll->setLdata(lmove);
			m_bll->setRdata(rmove);
			double w3 = rmove - lmove;

			transPos(lmove, rmove);
		}
		else{
			double rlj = right - 5;
			middle = (int)(rlj + lll) / 2;
			m_bll->setLdata(lll);
			m_bll->setMdata(middle);
			m_bll->setRdata(rlj);
			double w4 = rlj - lll;

			transPos(lll, rlj);

		}
	}
}
void AdjustChart::transPos(int l, int r){


	QPointF test1 = this->chart()->mapToValue(QPointF(50, 0));
	QPointF test2 = this->chart()->mapToValue(QPointF(55, 0));
	qDebug() << "this is test=========" << test2.x() - test1.x();

	QPointF llll(l, 0);
	QPointF leftdata = this->chart()->mapToValue(llll);
	//qDebug() << "leftdata============" << leftdata;
	QPointF rrrr(r, 0);
	QPointF rightdata = this->chart()->mapToValue(rrrr);
	//qDebug() << "rightdata============" << rightdata;

	double width = rightdata.x() - leftdata.x();
	double center = (rightdata.x() + leftdata.x()) / 2;

	//qDebug() << "width and center==========" << width << "...." << center;
	m_bll->readyAdjustpaint(width, center);
}