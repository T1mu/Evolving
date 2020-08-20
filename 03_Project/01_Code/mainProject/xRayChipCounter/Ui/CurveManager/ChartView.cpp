#include "ChartView.h"
#include <QDebug>
#include<omp.h> 
//#include <algorithm>
#include <QMouseEvent>
bool comppp(const QPointF &a, const QPointF &b)
{
	return a.x()<b.x();
}
ChartView::ChartView(QWidget *parent)
	: QChartView(parent)
{
	limit_up = 0;
	limit_down = 0;
	limit_left = 0;
	limit_right = 0;

	minx = 1000;
	maxx = 0;
	linemoveEnable = false;
	hoveredLine = false;
	areaSeries = NULL;
	
	this->chart()->createDefaultAxes();
	seriesx = new QLineSeries();
	seriesx2 = new QLineSeries();
	judge.setX(0);
	judge.setY(0);
	axisx = new QValueAxis();
	axisx->setRange(0, 15000);
	axisx->setTickCount(5);
	axisy = new QValueAxis();
	axisy->setRange(0, 255);
	axisy->setTickCount(5);
	
	this->chart()->setAxisX(axisx);//2019/6/21改动
	this->chart()->setAxisY(axisy);//2019/6/21改动

	m_bll = BllDetectorKZ::instance();
	//下面
	seriesx->setUseOpenGL(true);
	seriesx2->setUseOpenGL(true);
	this->chart()->setTheme(QChart::ChartThemeBlueCerulean);
	this->chart()->legend()->setVisible(false);
	QMargins m(2, 2, 2, 2);
	QBrush brush1(QColor(88, 87, 86));
	this->chart()->setMargins(m);

	connect(m_bll, SIGNAL(resetCurveSignal()), this, SLOT(resetSlot()));
	connect(m_bll, SIGNAL(returnResetSignal()), this, SLOT(resetSlot()));
	connect(m_bll, SIGNAL(pointmoveSignal()), this, SLOT(pointmoveSlot()));

}

ChartView::~ChartView()
{

}

void ChartView::mousePressEvent(QMouseEvent *event){
	if (hoveredLine){
		linemoveEnable = true;
	}

}
void ChartView::mouseMoveEvent(QMouseEvent *event){

	QPointF ff = this->chart()->mapToValue(event->pos());

	/*if (ff.x() < minx){
		ff.setX(minx);
	}if (ff.x()>maxx){
		ff.setX(maxx);
	}
	if (ff.y() < 0){
		ff.setY(0);
	}
	if (ff.y()>255){
		ff.setY(255);
	}*/

	if (judgehoveredLine(ff)){

		this->setCursor(Qt::CrossCursor);
		hoveredLine = true;
	}
	else{
		this->setCursor(Qt::ArrowCursor);
		hoveredLine = false;

	}

	if (linemoveEnable){
		this->setCursor(Qt::CrossCursor);
		if (event->buttons() & Qt::LeftButton){
			updaLinedata(ff);

		}
	}



}

void ChartView::mouseReleaseEvent(QMouseEvent *event){
	QPointF ff = this->chart()->mapToValue(event->pos());
	//qDebug() << "release-----------" << ff;

	//if (ff.x() < minx){
	//	ff.setX(minx);
	//}if (ff.x()>maxx){
	//	ff.setX(maxx);
	//}
	//if (ff.y() < 0){
	//	ff.setY(0);
	//}
	//if (ff.y()>255){
	//	ff.setY(255);
	//}
	if (linemoveEnable){
		//scat->append(ff);

		PointWidget* m_point = new PointWidget(event->pos(), this, 0);
		vectPoint.append(m_point);
		m_point->setEnabled(true);
		m_point->show();

		m_bll->setLimit(limit_up, limit_down, limit_left, limit_right);
		temp.push_back(ff);
		sort(temp.begin(), temp.end(), comppp);
		linemoveEnable = false;
		this->setCursor(Qt::ArrowCursor);
	}
	if (hoveredLine){
		hoveredLine = false;
	}

}

void ChartView::pointsToline(QPointF p1, QPointF p2, double &k, double &b){
	double x1 = p1.x();
	double y1 = p1.y();
	double x2 = p2.x();
	double y2 = p2.y();
	k = (y2 - y1) / (x2 - x1);
	b = y1 - k*x1;
}

void ChartView::updaLinedata(QPointF newp){
	QVector<QPointF> tempvec;
	tempvec = temp;
	tempvec.push_back(newp);
	sort(tempvec.begin(), tempvec.end(), comppp);
	seriesx2->clear();
	//scat->clear();
	for (int i = 0; i < tempvec.size(); i++){
		QPointF p = tempvec[i];
		seriesx2->append(p);
		//scat->append(p);
	}
	m_bll->lineMove(tempvec);

}

bool ChartView::judgehoveredLine(QPointF p){
	//qDebug() << "temp size------" << temp.size();
	bool flag = false;
	double x = p.x();
	double y = p.y();
	if (temp.size() >= 2){
		for (int i = 0; i < temp.size() - 1; i++){
			QPointF p1 = temp[i];
			QPointF p2 = temp[i + 1];
			double k = 0.0;
			double b = 0.0;
			pointsToline(p1, p2, k, b);
			double result = qAbs((k*x - y + b) / (sqrt(k*k + 1)));
			/*qDebug() << "k----" << k << "  b----" << b;
			qDebug() << "result-------------" << result;*/
			if (result<5){
				return true;
			}


		}
	}
	return flag;
}

void ChartView::setCurve(){
	//---11/27改动---start
	if (areaSeries != NULL)
	{
		this->chart()->removeSeries(areaSeries);
	}
	areaSeries = new QAreaSeries(seriesx);	
	areaSeries->setBorderColor(Qt::gray);
	areaSeries->setBrush(Qt::gray);
	//---11/27改动---end

	int countdata[65535];
	memset(countdata, 0, 65535 * sizeof(int));
	quint16* img = BllDetectorKZ::getSingleImg();
	//#pragma omp parallel 
	int row = BllDetectorKZ::returnSize();
	for (int i = 0; i < row * row; i++)
	{
		int data = img[i];
		countdata[data] = countdata[data] + 1;
		if (data < minx){
			minx = data;
		}
		if (data>maxx){
			maxx = data;
		}
	}


	int ymax = 0;
	omp_set_num_threads(8);
#pragma omp parallel for
	for (int i = minx; i < maxx; i++){
		int value = countdata[i];
		if (value>ymax){
			ymax = value;
		}
	}


	if (seriesx->points().size() != 0){
		int index = 0;
	
		seriesx->clear();
		seriesx2->clear();
		//---11/27改动---start
		this->chart()->removeSeries(seriesx);
		this->chart()->removeSeries(seriesx2);
		//---11/27改动---end
		temp.clear();
	
		QVector<QPointF> v;
		for (int k = minx; k < maxx; k++)
		{
			int x = k;
			int data = countdata[k];
			int y = data / ((double)ymax / 255); //2019/6/21改动
			v.push_back(QPointF(x, y));

		}
		seriesx->replace(v);

	}
	else{
		QVector<QPointF> v;
		for (int k = minx; k < maxx; k++)
		{
			int x = k;
			int data = countdata[k];
			int y = data / ((double)ymax / 255);//2019/6/21改动
			v.push_back(QPointF(x, y));
		}
		seriesx->replace(v);
	}

	

	temp.push_back(QPointF(0, 0));
	temp.push_back(QPointF(maxx, 255));

	axisx->setRange(0, (int)maxx);
	axisy->setRange(0, 255);

	QVector<QPointF> v1;
	v1.append(QPointF(0, 0));
	v1.append(QPointF(maxx, 255));



	seriesx2->replace(v1);
	seriesx2->setColor(QColor(0, 255, 255));
	


	this->chart()->addSeries(areaSeries);
	this->chart()->addSeries(seriesx2);


	QString mindata = QString::number(minx);
	QString minstring = "MIN:  ";
	minstring.append(mindata);
	QString maxdata = QString::number(maxx);
	QString maxstring = "MAX:   ";
	maxstring.append(maxdata);
	m_bll->resetCurveEnable(minstring,maxstring);

	setPointMovelimit();

}

void ChartView::resetSlot(){
	if (vectPoint.size() != 0){
		for (int i = 0; i < vectPoint.size(); i++){
			delete vectPoint[i];
		}
	}
	vectPoint.clear();
	seriesx2->clear();
	temp.clear();
	seriesx2->append(QPointF(minx, 0));
	seriesx2->append(QPointF(maxx, 255));
	temp.push_back(QPointF(minx, 0));
	temp.push_back(QPointF(maxx, 255));
}

bool ChartView::judgehoveredPoint(QPointF p){

	for (int i = 0; i < temp.size(); i++){
		double x1 = temp[i].x();
		double y1 = temp[i].y();
		double x = p.x();
		double y = p.y();
		double dis = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
		//qDebug() << "dis=========" << dis;
		if (dis < 50){
			judge.setX(x1);
			judge.setY(y1);

			//scat->remove(judge);

			return true;
		}
		else{
			setCursor(Qt::ArrowCursor);
		}
	}
	return false;

}

void ChartView::pointmoveSlot(){
	seriesx2->clear();
	temp.clear();
	temp.push_back(QPointF(minx, 0));
	temp.push_back(QPointF(maxx, 255));

	if (vectPoint.size() != 0){
		for (int i = 0; i < vectPoint.size(); i++){
			QPoint pos = vectPoint[i]->getpos();

			QPointF ff = this->chart()->mapToValue(pos);
			temp.push_back(ff);
		}
	}
	sort(temp.begin(), temp.end(), comppp);
	for (int i = 0; i < temp.size(); i++){
		seriesx2->append(temp[i]);
	}
	m_bll->lineMove(temp);

}

void ChartView::setPointMovelimit(){
	QPointF f1(0, 0);
	QPointF leftdown = this->chart()->mapToPosition(f1);
	QPointF f4(maxx, 255);
	QPointF rightup = this->chart()->mapToPosition(f4);
	qDebug() << "======leftdown=====" << leftdown;
	limit_up = rightup.y();
	limit_down = leftdown.y();
	limit_left = leftdown.x();
	limit_right = rightup.x();

}

//void ChartView::openAdjustSlot(){
//	m_adjust = new AdjustWidget();
//	m_adjust->show();
//	m_bll->readyAdjust();
//}

//void ChartView::closeAdjustSlot(){
//	m_adjust->close();
//}