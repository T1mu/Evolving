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
	for (int i = 0; i < 20; i++)//开辟一个二维数组来存入所有小球中心点
	{
		center_x[i] = (double *)malloc(sizeof(double)* 60);// 每一行 中心点的x值；
		center_y[i] = (double *)malloc(sizeof(double)* 60);// 每一行 中心点的y值；
	}
	//二维数组初始化
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
	pen.setWidth(3); //线宽
	pen.setColor(Qt::red); //划线颜色
	pen.setStyle(Qt::SolidLine);//线的类型，实线、虚线等
	pen.setCapStyle(Qt::FlatCap);//线端点样式
	pen.setJoinStyle(Qt::BevelJoin);//线的连接点样式
	painter.setPen(pen);

	painter.drawRect(rect);

}

void ImageCorrect::firstCalibrationPicSlot(Mat srcimg)
{

	pic_file_num = 0;
	srcImg_16bit = srcimg;
	srcImg_8bit = convertTo8bit(srcImg_16bit);
	srcImg_24bit = convertTo3Channels(srcImg_8bit);

	cv::resize(srcImg_8bit, scaleImage_8bit, Size(), 0.3, 0.3, 2);//图片大小按照比例缩到0.3倍 8bit
	cv::resize(srcImg_16bit, scaleImage_16bit, Size(), 0.3, 0.3, 2);//图片大小按照比例缩到0.3倍 16bit
	cv::resize(srcImg_24bit, scaleImage_24bit, Size(), 0.3, 0.3, 2);//图片大小按照比例缩到0.3倍 24bit

	scaleImageCols_16bit = scaleImage_16bit.cols;//计算图片的长
	scaleImageRows_16bit = scaleImage_16bit.rows;//计算图片的宽

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

	Mat deal_src = scaleImage_16bit;//读入第一张16位缩小版原图
	//----------使鼠标不管是正着画矩形还是反着画矩形都能成功运行
	int t_a = a, t_b = b, t_c = c, t_d = d;
	a = t_a < t_c ? t_a : t_c;
	b = t_b < t_d ? t_b : t_d;
	c = t_a > t_c ? t_a : t_c;
	d = t_b > t_d ? t_b : t_d;
	//-------------
	Mat imageROI = deal_src(Rect(a, b, c - a, d - b));//设置其感兴趣区域为鼠标框选范围的大小

	g_Threshold = adapthreshold16_8(imageROI);//根据鼠标框选的区域，自适应一个阈值作为处理后续所有图像的全局阈值
	Threshold_16(imageROI);//将传入的16位图像 固定阈值二值化后 变成8位在返回
	find_ball_one(imageROI);//得到鼠标框选出的区域内的小球个数，以及他们的中心坐标

	ui.label->setGeometry(QRect(0, 0, scaleImageCols_16bit, scaleImageRows_16bit));//承载窗口上图片的label大小等于输入图片的缩放后的大小	

	timer = new QTimer(this);
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timerSlot())); // SLOT填入一个槽函数
	timer->start(5000); // 1000毫秒, 等于 1 秒
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
		cal.setdata(60, selected_balls_num);//这是栾浩师兄的函数,第一个参数是图片总数量,第二个参数是用来计算参数的小球的数量			
		double *para = cal.get_calibration_para(center_x, center_y);//传入用来计算参数的小球的中心点坐标
		timer->stop();//停止计时器
		showPara(para);
	}
}


void ImageCorrect::find_ball_one(Mat&image)
{
	vector<vector<Point> > contours_balls;
	vector<Vec4i> hierarchy;
	findContours(image, contours_balls, hierarchy, CV_RETR_LIST, CHAIN_APPROX_NONE, Point(0, 0));
	selected_balls_num = contours_balls.size();//把鼠标框选出的小球个数保存为全局变量


	//计算轮廓矩
	vector<Moments> mu(contours_balls.size());
	for (int i = 0; i < contours_balls.size(); i++)
	{
		mu[i] = moments(contours_balls[i], false);
	}


	//计算轮廓的质心
	vector<Point2f> mc(contours_balls.size());


	for (int i = 0; i < contours_balls.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);//mc i 是圆心的坐标
		t_mc[i].x = mc[i].x + a;//因为鼠标画了感兴趣区域，这时候计算出的所有参数都是以鼠标框选的左上角坐标为原点计算的，
		t_mc[i].y = mc[i].y + b;//所以为了矫正 需要x+a，y+b
	}


}

void ImageCorrect::compare_picture(Mat &image)
{
	vector<vector<Point> > contours_all;
	vector<Vec4i> hierarchy;
	vector<vector<Point> > contours_balls(200);
	int ballNum_temp = 0;

	cv::resize(image, image, Size(), 0.3, 0.3, 2);//图片大小按照比例缩到0.3倍 8bit


	Threshold_16(image);//将传入的16位图像 固定阈值二值化后 变成8位在返回


	//查找轮廓
	findContours(image, contours_all, hierarchy, 1, CHAIN_APPROX_NONE, Point(0, 0));
	for (int i = 0; i< contours_all.size(); i++)
	{
		if (contourArea(contours_all[i]) > 20 && contourArea(contours_all[i]) < 500)
		{
			contours_balls[ballNum_temp] = contours_all[i];
			ballNum_temp++;

		}

	}
	//计算轮廓矩
	vector<Moments> mu(ballNum_temp);
	for (int i = 0; i < ballNum_temp; i++)
	{
		mu[i] = moments(contours_balls[i], false);

	}
	//计算轮廓的质心
	vector<Point2f> mc(ballNum_temp);

	for (int i = 0; i < ballNum_temp; i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);//mc i 是圆心的坐标

	}
	//画轮廓

	int m = 0;

	for (int j = 0; j < selected_balls_num; j++)//遍历上一张图片中的小球
	{
		double min_temp;
		double *distance = new double[ballNum_temp];
		double max_temp = 700000;
		int contour_temp = 0;
		for (int i = 0; i < ballNum_temp; i++)//遍历本图片中的所有轮廓
		{
			distance[i] = (mc[i].x - t_mc[j].x)*(mc[i].x - t_mc[j].x) + (mc[i].y - t_mc[j].y)*(mc[i].y - t_mc[j].y);
			//（依次）计算上一张每个小球和本图片所有轮廓的距离
			if (distance[i]<max_temp)//找到本图片中与上一张图片距离最小的轮廓，输出它的数组内序号
			{

				max_temp = distance[i];
				contour_temp = i;

			}

		}

		t_mc[j].x = mc[contour_temp].x;//得到本图片中显示出的所有小球的中心点坐标，作为下一张图片的参考
		t_mc[j].y = mc[contour_temp].y;
		center_x[j][pic_file_num] = mc[contour_temp].x / 0.3;
		center_y[j][pic_file_num] = mc[contour_temp].y / 0.3;

		drawContours(scaleImage_24bit, contours_balls, contour_temp, Scalar(0, 255, 0), 1, LINE_AA, hierarchy, 0, Point());
		image = scaleImage_24bit;

	}


}



//计算灰度最大最小值
void ImageCorrect::MaxGrayValue16_8(Mat image, int &max, int &min)
{
	min = 65535;
	max = 0;
	Mat *im = reinterpret_cast<Mat*>((void*)&image);//reinterpret_cast<new_type> (expression//原始参数它会产生一个新的值，这个值会有与原始参数（expression）有完全相同的比特位)
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


//自适应阈值 注：传入的只能是灰度图像
int ImageCorrect::adapthreshold16_8(Mat &image)
{

	int max, min;    //保存最大和最小灰度值
	MaxGrayValue16_8(image, max, min);   //计算出最大最小灰度值
	int grayvalue;    //用于暂时存取每个点的灰度值
	int Threshold = (max + min) / 2;  //初始阈值
	int Temp_Threshold = Threshold; //用于存取每次迭代后的阈值
	int big_than_th;       //用于累加大于阈值的灰度值
	int bigcount;           //用于存放大于阈值灰度值的像素点数量
	int sma_than_th;       //用于累加小于阈值的灰度值
	int smacount;           //用于存放小于阈值灰度值的像素点数量
	Mat *im = reinterpret_cast<Mat*>((void*)&image);    //获取像素点信息
	//Mat *im = &image;
	int height = image.rows;   //获取图像高度
	int width = image.cols;       //获取图像宽度


	for (int k = 0; k < 50; k++)   //计算阈值，最大迭代50次
	{
		big_than_th = 0;
		bigcount = 0;
		sma_than_th = 0;
		smacount = 0;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				grayvalue = static_cast<int>(im->at<ushort>(Point(j, i)));  //获取指定点灰度值
				if (grayvalue>Threshold)   //如果灰度值大于阈值，加到总灰度值，数量+1
				{
					big_than_th += grayvalue;
					bigcount++;
				}
				else if (grayvalue < Threshold) //如果灰度值小于阈值，加到总灰度值，数量+1
				{
					sma_than_th += grayvalue;
					smacount++;
				}
			}
		}

		Temp_Threshold = ((big_than_th*1.0 / bigcount) + (sma_than_th*1.0 / smacount)) / 2;  //计算新的阈值
		if (abs(Temp_Threshold - Threshold) < 2)   //如果新的阈值和旧的阈值差值的绝对值小于10，则退出
			break;
		else
			Threshold = Temp_Threshold;    //否则旧阈值等于新阈值
	}

	for (int i = 0; i < height; i++)     //对图像进行二值化处理
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


//将传入的16位图像 固定阈值二值化后 变成8位在返回
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

//显示参数
void ImageCorrect::showPara(double *para)
{
	ui.ulabel_2->setText(QString::number(para[0]));
	ui.vlabel_2->setText(QString::number(para[1]));
	ui.RFIlabel_2->setText(QString::number(para[2]));
	ui.RFDlabel_2->setText(QString::number(para[3]));
}


//8bit灰度图转8bitRGB图
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

//16bit转8bit
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