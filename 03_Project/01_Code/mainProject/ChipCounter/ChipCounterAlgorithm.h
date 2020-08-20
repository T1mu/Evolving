#ifndef CHIPCOUNTERALGORITHM_H
#define CHIPCOUNTERALGORITHM_H

#include <QObject>
#include "chipcounter_global.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <string>
#include <math.h>
#include <opencv2/core/core.hpp>  

using namespace cv;
using namespace std;

class CHIPCOUNTER_EXPORT ChipCounterAlgorithm : public QObject
{
	Q_OBJECT

public:
	ChipCounterAlgorithm(QObject *parent=0);
	~ChipCounterAlgorithm();
	/**************************************
	**�����㷨
	**srcImageΪ����ͼ��
	**���ؼ�������
	***************************************/
	int chipCounter(Mat srcImage);
	//���ļ�
	Mat openImage(string fileName);
	//����ͼ��
	void saveImage(string fileName,Mat input);
	//���ͼ��
	Mat m_resultImg;

private:
	//double�������� ���ԭ������� �Ͱ��������е�����
	void BubbledoubleSort(double  *p, int length, int * ind_diff);
	//�������� ���ԭ������� �Ͱ��������е�����
	void BubbleSort(float  *p, int length, int * ind_diff);
	// Ѱ����һ����
	int GetNextPoint(vector<Point2f>&  a, int mm, float b, float c, int inipoint);

};

#endif // CHIPCOUNTERALGORITHM_H
