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
	Mat scaleImage_24bit;//缩放后的图片24位
	Mat srcImg_24bit;//原始图片24位
	Mat scaleImage_16bit;//缩放后的图片16位
	Mat srcImg_16bit;//原始图片16位
	Mat srcImg_8bit;//原始图片8位
	Mat scaleImage_8bit;//缩放图片8位
	
	int scaleImageCols_16bit, scaleImageRows_16bit;//16位缩放图片长宽

	int file = 1;
	int	ball_num = 0;
	char image_name[5000];
	int g_Threshold;//ROI的自适应阈值
	int real_row = 0;
	int mouse_ball = 0;//鼠标选中的小球数目
	
// #信号 信号初始化
	void initConnect();
// #界面 界面初始化
	void initUi();
	
	void find_ball_one(Mat &image);
	int adapthreshold16_8(Mat &image);

	void MaxGrayValue16_8(Mat image, int &max, int &min);
	void Threshold_16(Mat &image);
	
	void compare_picture(Mat&image);
	Mat convertTo3Channels(const Mat& binImg);

	double **center_x = (double **)malloc(sizeof(double *)*20);//得到一个 里面有 row 个 double* 类型 的数组
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
