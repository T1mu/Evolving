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
	void firstCalibrationPicSlot(Mat);//��һ��ͼ����
	void eachCalibrationPicSlot(Mat);//ÿ��һ��ͼ����һ��
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

	void showPara(double *);//������ʾ
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
	int a, b, c, d; //���������
	Mat scaleImage_24bit;//���ź��ͼƬ24λ
	Mat srcImg_24bit;//ԭʼͼƬ24λ
	Mat scaleImage_16bit;//���ź��ͼƬ16λ
	Mat srcImg_16bit;//ԭʼͼƬ16λ
	Mat srcImg_8bit;//ԭʼͼƬ8λ
	Mat scaleImage_8bit;//����ͼƬ8λ

	uchar* m_8bitgrayImg;
	int m_center, m_width;

	int scaleImageCols_16bit, scaleImageRows_16bit;//16λ����ͼƬ����

	int g_Threshold;//ROI������Ӧ��ֵ
	int	ball_num;//���������

	double **center_x;//���ĵ�����
	double **center_y;

	int pic_file_num;
	int selected_balls_num;//�����ĸ���

	Calibration cal;

	QTimer *timer;

	//̽��������
	int size;
	float rate;
	int type;
	int gainlevel;
	float speed;
	float move;

};

#endif // IMAGECORRECT_H
