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
	**点数算法
	**srcImage为输入图像
	**返回计数个数
	***************************************/
	int chipCounter(Mat srcImage);
	//打开文件
	Mat openImage(string fileName);
	//保存图像
	void saveImage(string fileName,Mat input);
	//结果图像
	Mat m_resultImg;

private:
	//double数组排序 输出原数组序号 和按升序排列的数组
	void BubbledoubleSort(double  *p, int length, int * ind_diff);
	//数组排序 输出原数组序号 和按升序排列的数组
	void BubbleSort(float  *p, int length, int * ind_diff);
	// 寻找下一个点
	int GetNextPoint(vector<Point2f>&  a, int mm, float b, float c, int inipoint);

};

#endif // CHIPCOUNTERALGORITHM_H
