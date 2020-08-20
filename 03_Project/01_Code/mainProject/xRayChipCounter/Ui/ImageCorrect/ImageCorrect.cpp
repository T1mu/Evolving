#include "ImageCorrect.h"

ImageCorrect::ImageCorrect(QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	//setAttribute(Qt::WA_DeleteOnClose);
	qRegisterMetaType<Mat>("Mat");
	t_mc.resize(20);
	//matBuffer.resize(70);

	center_x = (double **)malloc(sizeof(double *)* 20);
	center_y = (double **)malloc(sizeof(double *)* 20);
	for (int i = 0; i < 20; i++)//����һ����ά��������������С�����ĵ�
	{
		center_x[i] = (double *)malloc(sizeof(double)* 60);// ÿһ�� ���ĵ��xֵ��
		center_y[i] = (double *)malloc(sizeof(double)* 60);// ÿһ�� ���ĵ��yֵ��
	}
	//��ά�����ʼ��
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			center_x[i][j] = 0;
			center_y[i][j] = 0;
		}
	}

	this->setMouseTracking(0);
	resize(1265, 965);
	ball_num = 0;
	m_detectorThread = DetectorThread::instance();
	m_bllDetectorKZ = BllDetectorKZ::instance();
	m_bllDataFlow = BllDataFlow::instance();
	connect(m_detectorThread, SIGNAL(sendFirstCalibrationPicSignal(Mat)), this, SLOT(firstCalibrationPicSlot(Mat)));
	connect(m_detectorThread, SIGNAL(sendEachCalibrationPicSignal(Mat)), this, SLOT(eachCalibrationPicSlot(Mat)));

	connect(m_bllDataFlow, SIGNAL(detectorParamSignal(int, float, int, int, int, float, float)), this, SLOT(getDetectorParamSlot(int, float, int, int, int, float, float)));

}

ImageCorrect::~ImageCorrect()
{
	
}

void ImageCorrect::mousePressEvent(QMouseEvent *e)
{
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

void ImageCorrect::mouseMoveEvent(QMouseEvent *e)
{
	if (e->x() < scaleImageCols_16bit && e->y() < scaleImageRows_16bit)
	{
		c = e->x();
		d = e->y();
		update();
	}
}

void ImageCorrect::paintEvent(QPaintEvent *event)
{
	QPainter  painter(this);
	QImage Qtemp = QImage(m_8bitgrayImg, srcImg_16bit.rows, srcImg_16bit.cols, QImage::Format_Grayscale8);
	QRect target(0, 0, scaleImageCols_16bit, scaleImageRows_16bit);
	painter.drawImage(target, Qtemp);

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

void ImageCorrect::firstCalibrationPicSlot(Mat srcimg)
{

	pic_file_num = 0;
	srcImg_16bit = srcimg;
	srcImg_8bit = convertTo8bit(srcImg_16bit);
	srcImg_24bit = convertTo3Channels(srcImg_8bit);

	cv::resize(srcImg_8bit, scaleImage_8bit, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 8bit
	cv::resize(srcImg_16bit, scaleImage_16bit, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 16bit
	cv::resize(srcImg_24bit, scaleImage_24bit, Size(), 0.3, 0.3, 2);//ͼƬ��С���ձ�������0.3�� 24bit

	scaleImageCols_16bit = scaleImage_16bit.cols;//����ͼƬ�ĳ�
	scaleImageRows_16bit = scaleImage_16bit.rows;//����ͼƬ�Ŀ�

	int maxp = 0;
	int minp = 20000;

	quint16* img = new quint16[srcimg.rows *srcimg.cols]();
	m_8bitgrayImg = new uchar[srcimg.rows *srcimg.cols]();
	for (int i = 0; i<srcimg.rows; i++)
	{
		for (int j = 0; j<srcimg.cols; j++)
		{
			int data = srcimg.at<ushort>(i, j);
			img[i * srcimg.rows + j] = data;
			if (data>maxp)
			{
				maxp = data;
			}
			if (data < minp)
			{
				minp = data;
			}
		}
	}

	m_center = (maxp + minp) / 2;
	m_width = maxp - minp;
	BllDataFlow::converToGray(img, m_8bitgrayImg, m_width, m_center);

	update();

}

void ImageCorrect::eachCalibrationPicSlot(Mat eachImg)
{
	matBuffer.push(eachImg);

}


void ImageCorrect::getDetectorParamSlot(int psize, float pFrameRate, int pExposureTime, int nTrigType, int nGainLevel, float rSpeed, float rMove)
{
	size = psize;
	rate = pFrameRate;
	type = nTrigType;
	gainlevel = nGainLevel;
	speed = rSpeed;
	move = rMove;
}

void ImageCorrect::on_collectBtn_clicked()
{

}
void ImageCorrect::on_startBtn_clicked()
{

	Mat deal_src = scaleImage_16bit;//�����һ��16λ��С��ԭͼ
	//----------ʹ��겻�������Ż����λ��Ƿ��Ż����ζ��ܳɹ�����
	int t_a = a, t_b = b, t_c = c, t_d = d;
	a = t_a < t_c ? t_a : t_c;
	b = t_b < t_d ? t_b : t_d;
	c = t_a > t_c ? t_a : t_c;
	d = t_b > t_d ? t_b : t_d;
	//-------------
	Mat imageROI = deal_src(Rect(a, b, c - a, d - b));//���������Ȥ����Ϊ����ѡ��Χ�Ĵ�С

	g_Threshold = adapthreshold16_8(imageROI);//��������ѡ����������Ӧһ����ֵ��Ϊ�����������ͼ���ȫ����ֵ
	Threshold_16(imageROI);//�������16λͼ�� �̶���ֵ��ֵ���� ���8λ�ڷ���
	find_ball_one(imageROI);//�õ�����ѡ���������ڵ�С��������Լ����ǵ���������

	ui.label->setGeometry(QRect(0, 0, scaleImageCols_16bit, scaleImageRows_16bit));//���ش�����ͼƬ��label��С��������ͼƬ�����ź�Ĵ�С	

	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot())); // SLOT����һ���ۺ���
	timer->start(5000); // 1000����, ���� 1 ��
}

void ImageCorrect::timerSlot()
{
	if (pic_file_num<60)
	{
		Mat  tempMat = matBuffer.front();
		compare_picture(tempMat);
		matBuffer.pop();

		QImage Qtemp = QImage((const unsigned char*)(tempMat.data), tempMat.cols, tempMat.rows, tempMat.step, QImage::Format_RGB888);
		ui.label->setPixmap(QPixmap::fromImage(Qtemp));
		ui.label->show();
		pic_file_num++;
	}
	else
	{
		cal.setdata(60, selected_balls_num);//�������ʦ�ֵĺ���,��һ��������ͼƬ������,�ڶ����������������������С�������			
		double *para = cal.get_calibration_para(center_x, center_y);//�����������������С������ĵ�����
		timer->stop();//ֹͣ��ʱ��
		showPara(para);
	}
}


void ImageCorrect::find_ball_one(Mat&image)
{
	vector<vector<Point> > contours_balls;
	vector<Vec4i> hierarchy;
	findContours(image, contours_balls, hierarchy, CV_RETR_LIST, CHAIN_APPROX_NONE, Point(0, 0));
	selected_balls_num = contours_balls.size();//������ѡ����С���������Ϊȫ�ֱ���


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
		t_mc[i].x = mc[i].x + a;//��Ϊ��껭�˸���Ȥ������ʱ�����������в�������������ѡ�����Ͻ�����Ϊԭ�����ģ�
		t_mc[i].y = mc[i].y + b;//����Ϊ�˽��� ��Ҫx+a��y+b
	}


}

void ImageCorrect::compare_picture(Mat &image)
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

	for (int j = 0; j < selected_balls_num; j++)//������һ��ͼƬ�е�С��
	{
		double min_temp;
		double *distance = new double[ballNum_temp];
		double max_temp = 700000;
		int contour_temp = 0;
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
		center_x[j][pic_file_num] = mc[contour_temp].x / 0.3;
		center_y[j][pic_file_num] = mc[contour_temp].y / 0.3;

		drawContours(scaleImage_24bit, contours_balls, contour_temp, Scalar(0, 255, 0), 1, LINE_AA, hierarchy, 0, Point());
		image = scaleImage_24bit;

	}


}



//����Ҷ������Сֵ
void ImageCorrect::MaxGrayValue16_8(Mat image, int &max, int &min)
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
int ImageCorrect::adapthreshold16_8(Mat &image)
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
	int width = image.cols;       //��ȡͼ����


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


//�������16λͼ�� �̶���ֵ��ֵ���� ���8λ�ڷ���
void ImageCorrect::Threshold_16(Mat &image)
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
}

//��ʾ����
void ImageCorrect::showPara(double *para)
{
	ui.ulabel_2->setText(QString::number(para[0]));
	ui.vlabel_2->setText(QString::number(para[1]));
	ui.RFIlabel_2->setText(QString::number(para[2]));
	ui.RFDlabel_2->setText(QString::number(para[3]));
}


//8bit�Ҷ�ͼת8bitRGBͼ
Mat ImageCorrect::convertTo3Channels(const Mat& binImg)
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

//16bitת8bit
Mat ImageCorrect::convertTo8bit(const Mat& sixteenbitImg)
{
	Mat temp_8bit = Mat::zeros(sixteenbitImg.rows, sixteenbitImg.cols, CV_8UC1);
	for (int i = 0; i<sixteenbitImg.rows; i++)
	{
		for (int j = 0; j<sixteenbitImg.cols; j++)
		{
			int n = sixteenbitImg.at<ushort>(i, j) / 255; //tt1
			temp_8bit.at<uchar>(i, j) = n;
		}
	}
	return temp_8bit;
}