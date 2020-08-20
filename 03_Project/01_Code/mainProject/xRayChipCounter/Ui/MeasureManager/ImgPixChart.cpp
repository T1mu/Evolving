#include "ImgPixChart.h"
#include <QDebug>
ImgPixChart::ImgPixChart(QWidget *parent)
	: QChartView(parent)
{
	seriesx = new QLineSeries();
	axisx = new QValueAxis;
	axisy = new QValueAxis;
	axisx->setRange(0, 1000);
	axisx->setTickCount(5);
	axisy->setRange(0, 65535);
	axisy->setTickCount(5);
	this->chart()->addAxis(axisx, Qt::AlignBottom);
	this->chart()->addAxis(axisy, Qt::AlignLeft);
	this->chart()->addSeries(seriesx);
	seriesx->attachAxis(axisx);
	seriesx->attachAxis(axisy);
	seriesx->setColor(Qt::blue);
	seriesx->setUseOpenGL(true);
	this->chart()->legend()->hide();
	this->chart()->setTheme(QChart::ChartThemeDark);
	QMargins m(2, 2, 2, 2);
	this->chart()->setMargins(m);
}

ImgPixChart::~ImgPixChart()
{
	
}
void ImgPixChart::updateCurve(QVector<QPoint> vec){
	
	seriesx->clear();

	quint16* img = BllDetectorKZ::getSingleImg();
	int sizeLimit = BllDetectorKZ::returnSize();
	std::vector<int> imgdata;
	
	for (int i = 0; i < vec.size(); i++){
		int row = vec[i].y();
		int col = vec[i].x();
		int data = img[row * sizeLimit + col];
	
		imgdata.push_back(data);
	}
	//qDebug() << "dsata----" << imgdata[imgdata.size() - 1] << ";;" << imgdata[imgdata.size() - 2];

	std::vector<int> temp;
	
	temp = imgdata;
	sort(temp.begin(), temp.end());
	int ymax = temp[temp.size() - 1];
	int xmax = vec.size();

	QVector<QPointF> v;
	
	/*omp_set_num_threads(8);
	#pragma omp parallel for*/
	for (int k = 0; k < imgdata.size(); k++)
	{
		int x = k;
		int y = imgdata[k];
		v.push_back(QPointF(x, y));
		
	}

	//qDebug() << "dsata----" << v[imgdata.size() - 1] << ";;" << v[imgdata.size() - 2];
	axisx->setRange(0, xmax);
	axisy->setRange(0, ymax*2);
	seriesx->replace(v);
	

}