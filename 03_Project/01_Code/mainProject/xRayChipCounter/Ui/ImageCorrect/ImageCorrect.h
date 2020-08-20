#ifndef IMAGECORRECT_H
#define IMAGECORRECT_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include<QTimer>
#include "ui_ImageCorrect.h"
#include "../../BllProject/BllDetectorKZ/DetectorThread.h"
#include "../../BllProject/BllDataFlow.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#include "calibration.h"
#include <queue>

Q_DECLARE_METATYPE(Mat);
class ImageCorrect : public QWidget
{
	Q_OBJECT

	public slots:
	void firstCalibrationPicSlot(Mat);//第一张图处理
	void eachCalibrationPicSlot(Mat);//每来一张图处理一次
	void on_collectBtn_clicked();
	void on_startBtn_clicked();
	void timerSlot();
	void getDetectorParamSlot(int, float, int, int, int, float, float);

public:
	ImageCorrect(QWidget *parent = 0);
	~ImageCorrect();
	Mat convertTo3Channels(const Mat&);
	Mat convertTo8bit(const Mat&);
	int adapthreshold16_8(Mat &);
	void MaxGrayValue16_8(Mat, int &, int &);
	void Threshold_16(Mat &);

	void find_ball_one(Mat &);
	void compare_picture(Mat&);

	void showPara(double *);//参数显示
protected:
	void mousePressEvent(QMouseEvent *e);
	void mouseMoveEvent(QMouseEvent *e);
	void paintEvent(QPaintEvent *);

private:
	Ui::ImageCorrect ui;
	BllDataFlow* m_bllDataFlow;
	BllDetectorKZ* m_bllDetectorKZ;
	DetectorThread *m_detectorThread;
	vector<vector<Point>> g_vContours; //
	vector<Vec4i> g_vHierarchy; //
	vector<Point2f> t_mc; //
	queue<Mat> matBuffer;
	int a, b, c, d; //鼠标点击坐标
	Mat scaleImage_24bit;//缩放后的图片24位
	Mat srcImg_24bit;//原始图片24位
	Mat scaleImage_16bit;//缩放后的图片16位
	Mat srcImg_16bit;//原始图片16位
	Mat srcImg_8bit;//原始图片8位
	Mat scaleImage_8bit;//缩放图片8位

	uchar* m_8bitgrayImg;
	int m_center, m_width;

	int scaleImageCols_16bit, scaleImageRows_16bit;//16位缩放图片长宽

	int g_Threshold;//ROI的自适应阈值
	int	ball_num;//所有球个数

	double **center_x;//中心点坐标
	double **center_y;

	int pic_file_num;
	int selected_balls_num;//框出球的个数

	Calibration cal;

	QTimer *timer;

	//探测器参数
	int size;
	float rate;
	int type;
	int gainlevel;
	float speed;
	float move;

};

#endif // IMAGECORRECT_H
