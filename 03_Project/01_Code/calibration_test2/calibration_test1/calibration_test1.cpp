#include "calibration_test1.h"
#include<QTimer>
#include<qdebug.h>
#include "QPainter"


char file_name[] = { "..\\..\\src\\%d.tif" };//��ͼƬ��Դ�ļ��е�·�������\\%d.tif
char picture_one_name[] = { "..\\..\\src\\1.tif" }; //��ͼƬ��Դ�ļ��е�·�������\\1.tif



calibration_test1::calibration_test1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initConnect();
	t_mc.resize(20);
	for (int i = 0; i < 20; i++)//����һ����ά��������������С�����ĵ�
	{
		center_x[i] = (double *)malloc(sizeof(double)* 60);// ÿһ�� ���ĵ��xֵ��
		center_y[i] = (double *)malloc(sizeof(double)* 60);// ÿһ�� ���ĵ��yֵ��
	}
	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 60; j++){
			center_x[i][j] = 0;
			center_y[i][j] = 0;
		}
	}

	this->setMouseTracking(0);
	resize(1265, 965);



	srcImg_16bit = imread(picture_one_name, 2);//�����һ��16λ��ԭͼ
	//srcImg_8bit = imread(picture_one_name, 0);//�����һ��8λ��ԭͼ
	//srcImg_24bit = imread(picture_one_name, 1);//�����һ��24λ��ԭͼ

	Mat temp_8bit = Mat::zeros(srcImg_16bit.rows, srcImg_16bit.cols, CV_8UC1);
	for (int i = 0; i<srcImg_16bit.rows; i++){
		for (int j = 0; j<srcImg_16bit.cols; j++){
			int n = srcImg_16bit.at<ushort>(i, j) /255; //tt1
			temp_8bit.at<uchar>(i, j) = n;
		}
	}
	srcImg_8bit = temp_8bit;
	srcImg_24bit = convertTo3Channels(srcImg_8bit);

	cv::resize(srcImg_8bit, scaleImage_8bit, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 8bit
	cv::resize(srcImg_16bit, scaleImage_16bit, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 16bit
	cv::resize(srcImg_24bit, scaleImage_24bit, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 24bit

	scaleImageCols_16bit = scaleImage_16bit.cols;//����ͼƬ�ĳ�
	scaleImageRows_16bit = scaleImage_16bit.rows;//����ͼƬ�Ŀ�
	initUi();

}



Mat calibration_test1::convertTo3Channels(const Mat& binImg)
{
	Mat three_channel = Mat::zeros(binImg.rows, binImg.cols, CV_8UC3);
	vector<Mat> channels;
	for (int i = 0; i<3; i++)
	{
		channels.push_back(binImg);
	}
	merge(channels, three_channel);
	return three_channel;
}

void calibration_test1::mousePressEvent(QMouseEvent *e)
{													//(a)
	if (e->button() == Qt::LeftButton&&e->x()<scaleImageCols_16bit && e->y()<scaleImageRows_16bit)
	{
		a = e->x();
		b = e->y();
	}
	else if (e->button() == Qt::RightButton&&e->x()<scaleImageCols_16bit && e->y()<scaleImageRows_16bit)
	{
		a = e->x();
		b = e->y();
	}
}

void calibration_test1::mouseMoveEvent(QMouseEvent *e)
{
	if (e->x() < scaleImageCols_16bit && e->y() < scaleImageRows_16bit){
		c = e->x();
		d = e->y();
		update();
	}

}

// #�滭 �滭�¼���ʵ��
void calibration_test1::paintEvent(QPaintEvent *event)
{
	
	QPainter  painter(this);
	Mat temp_scaleImage_8bit;//������һ���±���
	equalizeHist(scaleImage_8bit,temp_scaleImage_8bit);//ֱ��ͼ���⻯��ʹԭͼ���Կ����
	QImage Qtemp = QImage((const unsigned char*)(temp_scaleImage_8bit.data), temp_scaleImage_8bit.cols, temp_scaleImage_8bit.rows, temp_scaleImage_8bit.step, QImage::Format_Grayscale8);
	painter.drawPixmap(0, 0, QPixmap::fromImage(Qtemp));
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setRenderHint(QPainter::TextAntialiasing);

	QRect  rect(a, b, c - a, d - b);
	QPen  pen;
	pen.setWidth(3); //�߿�
	pen.setColor(Qt::red); //������ɫ
	pen.setStyle(Qt::SolidLine);//�ߵ����ͣ�ʵ�ߡ����ߵ�
	pen.setCapStyle(Qt::FlatCap);//�߶˵���ʽ
	pen.setJoinStyle(Qt::BevelJoin);//�ߵ����ӵ���ʽ
	painter.setPen(pen);   
	painter.drawRect(rect);

}

// #�� ����silder���ܵ�ʵ��
void calibration_test1::threshSliderChanged(int value)
{
	g_Threshold = value;
	ui.threshValue->setText(QString("%1").arg(g_Threshold));
	cv::Mat dis16 = scaleImage_16bit.clone();
	Threshold_16(dis16);

	scaleImage_8bit = dis16;
// 	cv::imshow("#�� ����silder���ܵ�ʵ��", dis16);
// 	QImage Qtemp = QImage((const uchar *)dis16.data, dis16.cols, dis16.rows, dis16.step, QImage::Format_RGB888);
// 	ui.label->setPixmap(QPixmap::fromImage(Qtemp));
	update();
/*	qDebug() <<"threshSliderChanged"<< value << endl;*/
}

void calibration_test1::ProcessPicture(bool)
{
	ui.btn_threshold->setEnabled(false);//ʹ��ťֻ�ܵ���һ��
	Mat deal_src = scaleImage_16bit;//�����һ��16λ��С��ԭͼ
	//----------ʹ��겻�������Ż����λ��Ƿ��Ż����ζ��ܳɹ�����
	int t_a=a, t_b=b, t_c=c, t_d=d;  
	a = t_a < t_c ? t_a : t_c;
	b = t_b < t_d ? t_b : t_d;
	c = t_a > t_c ? t_a : t_c;
	d = t_b > t_d ? t_b : t_d;
	//-------------

	Mat imageROI = deal_src(Rect(a, b, c - a, d - b));//���������Ȥ����Ϊ����ѡ��Χ�Ĵ�С

/*	g_Threshold = adapthreshold16_8(imageROI);		//��������ѡ����������Ӧһ����ֵ��Ϊ�����������ͼ���ȫ����ֵ*/
	
	Threshold_16(imageROI);							//�������16λͼ�� �̶���ֵ��ֵ���� ���8λ�ڷ���
	find_ball_one(imageROI);						//�õ�����ѡ���������ڵ�С��������Լ����ǵ���������

	ui.label->setGeometry(QRect(0, 0, scaleImageCols_16bit, scaleImageRows_16bit));//���ش�����ͼƬ��label��С��������ͼƬ�����ź�Ĵ�С	
	timer = new QTimer(this);

	//���붨ʱ��

	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(Time_show())); // SLOT����һ���ۺ���
	timer->start(50); // 1000����, ���� 1 ��

}



void calibration_test1::Time_show()
{
	Mat  t_dst;

	if (file <= 60)
	{
		sprintf_s(image_name, file_name, file);
		t_dst = imread(image_name, 2);//˳����ÿһ��ԭʼͼƬ
		compare_picture(t_dst);//�Ƚ�ͼƬ��������������һ��ͼƬ����ʾ��С�������ľ��룬�ó��ĸ�����Ӧ�ñ���ʾ
		
		QImage Qtemp = QImage((const unsigned char*)(t_dst.data), t_dst.cols, t_dst.rows, t_dst.step, QImage::Format_RGB888);
		ui.label->setPixmap(QPixmap::fromImage(Qtemp));
		ui.label->show();
		file = file + 1;//�ļ����+1
	}
	else if (file = 61)//����ļ���ŵ���61
	{
		kongnum = mouse_ball;
		cal.setdata(60, kongnum);//�������ʦ�ֵĺ���,��һ��������ͼƬ������,�ڶ����������������������С�������			
		double *para = cal.get_calibration_para(center_x, center_y);//�����������������С������ĵ�����	
		timer->stop();//ֹͣ��ʱ��
		emit center_signal(para);//�����������ʾ�ڽ�����
	}
}

//#ͼ���� ��ֵ������ͼ��
void calibration_test1::Threshold_16(Mat &image)//�������16λͼ�� �̶���ֵ��ֵ���� ���8λ�ڷ���
{
	Mat result = image.clone();
	for (int i = 0; i < result.rows; i++)
	{
		for (int j = 0; j < result.cols; j++)
		{
			if ((result.at<ushort>(i, j) < g_Threshold))
			{
				result.at<ushort>(i, j) = 65535;
			}
			else
			{
				result.at<ushort>(i, j) = 0;
			}
		}
	}
	cv::convertScaleAbs(result, result);
	image = result;
/*	cv::imshow("Threshold_16 return",result);*/
} 


//#���� ����Ҷ������Сֵ
void calibration_test1::MaxGrayValue16_8(Mat image, int &max, int &min)
{
	min = 65535;
	max = 0;
	Mat *im = reinterpret_cast<Mat*>((void*)&image);//reinterpret_cast<new_type> (expression//ԭʼ�����������һ���µ�ֵ�����ֵ������ԭʼ������expression������ȫ��ͬ�ı���λ)
	int height = image.rows;

	int width = image.cols;
	int N = height * width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if ((static_cast<int>(im->at<ushort>(Point(j, i))))>max)
				max = static_cast<int>(im->at<ushort>(Point(j, i)));
			else if ((static_cast<int>(im->at<ushort>(Point(j, i))))<min)
				min = static_cast<int>(im->at<ushort>(Point(j, i)));
		}
	}
}


//����Ӧ��ֵ ע�������ֻ���ǻҶ�ͼ��
int calibration_test1::adapthreshold16_8(Mat &image)
{
	int max, min;    //����������С�Ҷ�ֵ
	MaxGrayValue16_8(image, max, min);   //����������С�Ҷ�ֵ
	int grayvalue;    //������ʱ��ȡÿ����ĻҶ�ֵ
	int Threshold = (max + min) / 2;  //��ʼ��ֵ
	int Temp_Threshold = Threshold; //���ڴ�ȡÿ�ε��������ֵ
	int big_than_th;       //�����ۼӴ�����ֵ�ĻҶ�ֵ
	int bigcount;           //���ڴ�Ŵ�����ֵ�Ҷ�ֵ�����ص�����
	int sma_than_th;       //�����ۼ�С����ֵ�ĻҶ�ֵ
	int smacount;           //���ڴ��С����ֵ�Ҷ�ֵ�����ص�����
	Mat *im = reinterpret_cast<Mat*>((void*)&image);    //��ȡ���ص���Ϣ
	//Mat *im = &image;
	int height = image.rows;   //��ȡͼ��߶�
	int width = image.cols;    //��ȡͼ����


	for (int k = 0; k < 50; k++)   //������ֵ��������50��
	{
		big_than_th = 0;
		bigcount = 0;
		sma_than_th = 0;
		smacount = 0;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				grayvalue = static_cast<int>(im->at<ushort>(Point(j, i)));  //��ȡָ����Ҷ�ֵ
				if (grayvalue>Threshold)   //����Ҷ�ֵ������ֵ���ӵ��ܻҶ�ֵ������+1
				{
					big_than_th += grayvalue;
					bigcount++;
				}
				else if (grayvalue < Threshold) //����Ҷ�ֵС����ֵ���ӵ��ܻҶ�ֵ������+1
				{
					sma_than_th += grayvalue;
					smacount++;
				}
			}
		}

		Temp_Threshold = ((big_than_th*1.0 / bigcount) + (sma_than_th*1.0 / smacount)) / 2;  //�����µ���ֵ
		if (abs(Temp_Threshold - Threshold) < 2)   //����µ���ֵ�;ɵ���ֵ��ֵ�ľ���ֵС��10�����˳�
			break;
		else
			Threshold = Temp_Threshold;    //�������ֵ��������ֵ
	}

	for (int i = 0; i < height; i++)     //��ͼ����ж�ֵ������
	{
		ushort* data = image.ptr<ushort>(i);
		for (int j = 0; j < width; j++)
		{
			grayvalue = static_cast<int>(im->at<ushort>(Point(j, i)));
			if (grayvalue>Threshold)
				data[j] = 65535;
			else if (grayvalue < Threshold)
				data[j] = 0;
		}
	}
	return Threshold;
}

void calibration_test1::dealcenter_signal(double *para)
{
	ui.ulabel->setText(QString::number(para[0]));
	ui.vlabel->setText(QString::number(para[1]));
	ui.RFIlabel->setText(QString::number(para[2]));
	ui.RFDlabel->setText(QString::number(para[3]));
}

// #�ź� �źų�ʼ����ʵ��
void calibration_test1::initConnect()
{
	connect(ui.threshSlider, SIGNAL(sliderMoved(int)), this, SLOT(threshSliderChanged(int)));
	connect(ui.btn_threshold, SIGNAL(clicked(bool)), this, SLOT(ProcessPicture(bool)));
	connect(this, SIGNAL(center_signal(double *)), this, SLOT(dealcenter_signal(double *)));
}

// #���� ui�ĳ�ʼ������
void calibration_test1::initUi()
{
	int max = 0;
	int min = 0;
	MaxGrayValue16_8(srcImg_16bit, max, min);
	ui.threshSlider->setMaximum(max);
	ui.threshSlider->setMinimum(min);
	ui.label_4->setText(QString("%1").arg(min));
	ui.label_8->setText(QString("%2").arg(max));
}

void calibration_test1::find_ball_one(Mat&image)
{
	vector<vector<Point> > contours_balls;
	vector<Vec4i> hierarchy;
	findContours(image, contours_balls, hierarchy, CV_RETR_LIST, CHAIN_APPROX_NONE, Point(0, 0));
	mouse_ball = contours_balls.size();//������ѡ����С���������Ϊȫ�ֱ���
	//����������
	vector<Moments> mu(contours_balls.size());
	for (int i = 0; i < contours_balls.size(); i++)
	{
		mu[i] = moments(contours_balls[i], false);
	}
	//��������������
	vector<Point2f> mc(contours_balls.size());


	for (int i = 0; i < contours_balls.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);//mc i ��Բ�ĵ�����
		t_mc[i].x = mc[i].x+a;//��Ϊ��껭�˸���Ȥ������ʱ�����������в�������������ѡ�����Ͻ�����Ϊԭ�����ģ�
		t_mc[i].y = mc[i].y +b;//����Ϊ�˽��� ��Ҫx+a��y+b
	}


}
void calibration_test1::compare_picture(Mat &image)
{
	vector<vector<Point> > contours_all;
	vector<Vec4i> hierarchy;
	vector<vector<Point> > contours_balls(200);
	int ballNum_temp = 0;

	cv::resize(image, image, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 8bit
	
	Threshold_16(image);//�������16λͼ�� �̶���ֵ��ֵ���� ���8λ�ڷ���
	
	//��������
	findContours(image, contours_all, hierarchy, 1, CHAIN_APPROX_NONE, Point(0, 0));
	for (int i = 0; i< contours_all.size(); i++)
	{
		if (contourArea(contours_all[i]) > 20 && contourArea(contours_all[i]) < 500)
		{
			contours_balls[ballNum_temp] = contours_all[i];
			ballNum_temp++;

		}
	}
	//����������
	vector<Moments> mu(ballNum_temp);
	for (int i = 0; i < ballNum_temp; i++)
	{
		mu[i] = moments(contours_balls[i], false);
	}
	//��������������
	vector<Point2f> mc(ballNum_temp);

	for (int i = 0; i < ballNum_temp; i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);//mc i ��Բ�ĵ�����
		
	}
	//������
	int m = 0;

	for (int j = 0; j < mouse_ball; j++)//������һ��ͼƬ�е�С��
	{
		double min_temp;
		double *distance = new double[ballNum_temp];
		double max_temp=700000;
		int contour_temp=0;
		for (int i = 0; i < ballNum_temp; i++)//������ͼƬ�е���������
		{
			distance[i] = (mc[i].x - t_mc[j].x)*(mc[i].x - t_mc[j].x) + (mc[i].y - t_mc[j].y)*(mc[i].y - t_mc[j].y);
			//�����Σ�������һ��ÿ��С��ͱ�ͼƬ���������ľ���
			if (distance[i]<max_temp)//�ҵ���ͼƬ������һ��ͼƬ������С������������������������
			{
				
				max_temp = distance[i]; 
				contour_temp = i;	
			}
		}
		t_mc[j].x = mc[contour_temp].x;//�õ���ͼƬ����ʾ��������С������ĵ����꣬��Ϊ��һ��ͼƬ�Ĳο�
		t_mc[j].y = mc[contour_temp].y;
		center_x[j][file - 1] = mc[contour_temp].x/ 0.3;
		center_y[j][file - 1] = mc[contour_temp].y  / 0.3;		
		drawContours(scaleImage_24bit, contours_balls, contour_temp, Scalar(0, 255, 0), 1, LINE_AA, hierarchy, 0, Point());
		image = scaleImage_24bit;
	}
}




