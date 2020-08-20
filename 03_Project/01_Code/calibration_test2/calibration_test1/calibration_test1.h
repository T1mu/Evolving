#pragma once

#include <QtWidgets/QWidget>
#include "ui_calibration_test1.h"

#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

#include "calibration.h"
#include <windows.h>
#include <iostream>
#include "opencv2\opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;


class calibration_test1 : public QWidget
{
	Q_OBJECT

public:
	calibration_test1(QWidget *parent = Q_NULLPTR);
	Mat scaleImage_24bit;//���ź��ͼƬ24λ
	Mat srcImg_24bit;//ԭʼͼƬ24λ
	Mat scaleImage_16bit;//���ź��ͼƬ16λ
	Mat srcImg_16bit;//ԭʼͼƬ16λ
	Mat srcImg_8bit;//ԭʼͼƬ8λ
	Mat scaleImage_8bit;//����ͼƬ8λ
	
	int scaleImageCols_16bit, scaleImageRows_16bit;//16λ����ͼƬ����

	int file = 1;
	int	ball_num = 0;
	char image_name[5000];
	int g_Threshold;//ROI������Ӧ��ֵ
	int real_row = 0;
	int mouse_ball = 0;//���ѡ�е�С����Ŀ
	
// #�ź� �źų�ʼ��
	void initConnect();
// #���� �����ʼ��
	void initUi();
	
	void find_ball_one(Mat &image);
	int adapthreshold16_8(Mat &image);

	void MaxGrayValue16_8(Mat image, int &max, int &min);
	void Threshold_16(Mat &image);
	
	void compare_picture(Mat&image);
	Mat convertTo3Channels(const Mat& binImg);

	double **center_x = (double **)malloc(sizeof(double *)*20);//�õ�һ�� ������ row �� double* ���� ������
	double **center_y = (double **)malloc(sizeof(double *)*20);
	
	private slots:
	void ProcessPicture(bool);
	void Time_show();
	void dealcenter_signal(double *para);
protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *);
signals:
	void center_signal(double *);

private slots:
	void threshSliderChanged(int value);
private:

	QTimer *timer;
	Calibration cal;
	int kongnum;
	int row = 20;
	vector<vector<Point>> g_vContours; //
	vector<Vec4i> g_vHierarchy; //
	vector<Point2f> t_mc; //
	int a, b, c, d; //

	Ui::calibration_test1Class ui;
};
