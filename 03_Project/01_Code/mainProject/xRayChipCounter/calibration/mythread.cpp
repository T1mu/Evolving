//#include "mythread.h"
//#include "qdebug.h"
//
//MyThread::MyThread(QObject *parent)
//: QThread(parent)
//{
//}
//
//MyThread::~MyThread()
//{
//}
//
//void MyThread::startThread(int count, unsigned short min, unsigned short max, QStringList strlist, int r, int c)
//{
//	dir_count = count;
//	minnum = min;
//	maxnum = max;
//	list = strlist;
//	row = r;
//	col = c;
//	this->start();
//}
//
//void MyThread::stopThread()
//{
//	if (isStop)
//	{
//		this->quit();
//		if (this->isRunning())
//		{
//			this->wait();
//		}
//	}
//}
//
//void MyThread::run()
//{
//	//
//	double **center_x = (double **)malloc(sizeof(double *)*row);
//	double **center_y = (double **)malloc(sizeof(double *)*row);
//	for (int i = 0; i < row; i++)
//	{
//		center_x[i] = (double *)malloc(sizeof(double)* col);
//		center_y[i] = (double *)malloc(sizeof(double)* col);
//	}
//
//	//����ͼƬ
//	int count = 0;
//	Mat src = Mat::zeros(2000, 2816, CV_8UC1);
//	for (int m = 0; m<dir_count; m++)
//	{
//		qDebug() << list.at(m);
//		string str = list.at(m).toStdString();  // ��filenameת��Ϊstring���ͣ�
//		Mat image = imread(str, CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);
//
//		//16λ�Ҷ�ͼ���ֵ���ָ�
//		Mat result = image.clone();
//		for (int i = 0; i < result.rows; i++)
//		{
//			for (int j = 0; j < result.cols; j++)
//			{
//				if ((result.at<ushort>(i, j) > minnum) && (result.at<ushort>(i, j) < maxnum))
//				{
//					result.at<ushort>(i, j) = 65535;
//				}
//				else
//				{
//					result.at<ushort>(i, j) = 0;
//				}
//			}
//		}
//
//		//16λת����8λ
//		Mat eightresult = Mat::zeros(result.rows, result.cols, CV_8UC1);
//
//		for (int i = 0; i<result.rows; i++)
//		{
//			for (int j = 0; j<result.cols; j++)
//			{
//				if (result.at<ushort>(i, j) == 65535)
//				{
//					eightresult.at<uchar>(i, j) = 255;
//				}
//
//			}
//		}
//
//		eightresult = eightresult(Rect(0, 0, 2816, 2000));
//
//
//		//��˹�˲��ͱ�Ե���
//		cv::GaussianBlur(eightresult, eightresult, Size(3, 3), 0);
//		cv::Canny(eightresult, eightresult, 100, 250);
//
//		//Ѱ������
//		vector<vector<Point>>contours;	//ÿ�������еĵ�
//		vector<Vec4i>hierarchy;			//����������
//		cv::findContours(eightresult, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
//
//		//�����
//		vector<Moments> mu(contours.size());
//		for (int i = 0; i < contours.size(); i++)
//		{
//			mu[i] = moments(contours[i], false);
//		}
//
//		//�����������겢����������
//		vector<Point2d> mc(contours.size());
//
//		//��������
//		for (int i = 0; i < contours.size(); i++)
//		{
//			mc[i] = Point2d(static_cast<double>(mu[i].m10 / mu[i].m00), static_cast<double>(mu[i].m01 / mu[i].m00));
//		}
//
//		//�������������
//		sort(mc.begin(), mc.end(), MyThread::sortFun);
//
//		//��������
//		for (int i = 0; i < row; i++)
//		{
//			center_x[i][count] = mc[i].x;
//			center_y[i][count] = mc[i].y;
//		}
//		count++;
//
//		//��������
//		Mat resultContours = Mat::zeros(eightresult.size(), CV_8UC1);
//		for (int i = 0; i<contours.size(); i++)
//		{
//			drawContours(resultContours, contours, i, Scalar(255), 5, 8, hierarchy);
//		}
//
//		//char *savename = new char;
//		//sprintf(savename, "%d.tif", m+1);
//		//imwrite(savename, resultContours);
//
//		//ͼ�����
//		double alphaValue = 1.0;
//		double betaValue = 1.0;
//		cv::addWeighted(src, alphaValue, resultContours, betaValue, 0.0, src);
//		emit mat_signal(src);
//	}
//	isStop = true;
//
//	//У׼����
//	//cal.setdata(60, 7);
//	//double *para = cal.get_calibration_para(center_x, center_y);
//	//emit center_signal(para);
//
//	//�ͷ��ڴ�
//	for (int i = 0; i < row; i++)
//	{
//		free(center_x[i]); center_x[i] = NULL;
//		free(center_y[i]); center_y[i] = NULL;
//	}
//	free(center_x); center_x = NULL;
//	free(center_y); center_y = NULL;
//
//	//emit free_signal();
//}
