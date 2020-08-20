#include "ChipCounterAlgorithm.h"
ChipCounterAlgorithm::ChipCounterAlgorithm(QObject *parent)
	: QObject(parent)
{

}

ChipCounterAlgorithm::~ChipCounterAlgorithm()
{

}
int ChipCounterAlgorithm::chipCounter(Mat srcImage)
{
	int readcols = srcImage.cols;
	int readrows = srcImage.rows;
	int b = 0, gg = 0, mm = 0, kk = 0, ang_length = 50, ang_length1 = 150, num = 0;
	float ang_cos = 0.3, cro = 0;;
	double ab[9000], ab1[3000] = { 0 };
	float vx[9000], vy[9000], jijing[9000], ji_angle[9000], dist[9000], v3000x[3000], v3000y[3000], jijing1[3000], jijing2[3000], dist1[3000];
	float ax[5], ay[5];
	float vmaxx = 0, vmaxy = 0, pi = 3.1415926, vmeanx = 0, vmeany = 0, ameanx = 0, ameany = 0;
	int index[9000] = { 0 }, sortindex[3000] = { 0 }, findex[3000] = { 0 }, vindex[3000] = { 0 };

	//��ֵ����  �趨��ֵΪ85   ��һ��
	uchar thr = 85;
	Mat ReadMat(readrows, readcols, CV_8UC1);
	for (int nrow = 0; nrow < srcImage.rows; nrow++)
	{
		for (int ncol = 0; ncol < srcImage.cols; ncol++)
		{
			if ((srcImage.at<uchar>(nrow, ncol)> thr) || (srcImage.at<uchar>(nrow, ncol) == 0))
			{
				ReadMat.at<uchar>(nrow, ncol) = 0;
			}
			if ((srcImage.at<uchar>(nrow, ncol) >0) && (srcImage.at<uchar>(nrow, ncol) <= thr))
			{
				ReadMat.at<uchar>(nrow, ncol) = 255;
			}
		}
	}

	//  Ѱ����ͨ��   �ڶ���
	Mat ReadMatTemp = ReadMat.clone();
	Mat ReadMatTemp123;
	std::vector<std::vector<cv::Point2i>> contours;
	vector<Vec4i> hierarchy;
	cv::findContours(ReadMatTemp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	for (int i = 0; i < (int)contours.size(); i++)
	{
		double g_dConArea = contourArea(contours[i], true);
	}

	//Ѱ�ҵ�����ͨ������ĵ�   ������
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mu[i] = moments(contours[i], false);
	}
	///  �������ľ�:  
	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	/// �������ĵ�  
	Mat drawing = Mat::zeros(ReadMatTemp.size(), CV_8UC1);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(255);
		circle(drawing, mc[i], 4, color, -1, 6, 0);
	}

	//��̬ѧ���������ʹ���    ��СΪ2��Բ ����7��   ���Ĳ�
	Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));
	dilate(drawing, ReadMatTemp123, element, Point(-1, -1), 7, BORDER_DEFAULT, Scalar(0, 0, 255));

	//�������ĵ����        ÿ��Ԫ�������������� Ӧ���ҵ�9000�����ĵ�
	Mat ReadMatTemp4 = ReadMatTemp123.clone();
	cv::findContours(ReadMatTemp4, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	//��ȡÿ��Ԫ�������������ֵ����ĵ�����  ���岽 ��9000�㣩
	vector<Moments> mt(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		mt[i] = moments(contours[i], false);
	}
�������ľ�:
	vector<Point2f> mk(contours.size());
	vector<Point2f> zxd(contours.size());
	vector<Point2f> zxd2(contours.size());
	vector<Point2f> zxd3(3000);
	for (int i = 0; i < contours.size(); i++)
	{
		mk[i] = Point2f(mt[i].m10 / mt[i].m00, mt[i].m01 / mt[i].m00);
	}
	/// Ѱ��ÿ��Ԫ���������������м䲿�ֵ����ĵ� ������  ��3000�㣩
	Mat drawing123 = Mat::zeros(ReadMatTemp.size(), CV_8UC1);
	Mat drawing3000 = Mat::zeros(drawing123.size(), CV_8UC1);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(255);
		circle(drawing123, mk[i], 4, color, -1, 8, 0);          //����9000����
		vx[i] = mk[i].x;                             //��ȡ���ĵ�X����
		vy[i] = mk[i].y;                            //��ȡ���ĵ�X����
		vmaxx = vx[i] + vmaxx;                      //��ȡ���ĵ�X����
		vmaxy = vy[i] + vmaxy;
	}
	vmaxx = vmaxx / 9000;							//ԭ������
	vmaxy = vmaxy / 9000;
	for (int i = 0; i < contours.size(); i++)
	{
		zxd[i].x = mk[i].x - vmaxx;                 //��ʼ����
		zxd[i].y = mk[i].y - vmaxy;
		jijing[i] = sqrt(zxd[i].x*zxd[i].x + zxd[i].y*zxd[i].y);

	}

	for (int i = 0; i < contours.size(); i++)
	{
		for (int j = 0; j< contours.size(); j++)
		{
			dist[j] = sqrt((vx[i] - vx[j])*(vx[i] - vx[j]) + (vy[i] - vy[j])*(vy[i] - vy[j]));
			zxd2[j].x = vx[j] - vx[i];
			zxd2[j].y = vy[j] - vy[i];
			ab[j] = zxd2[j].dot(zxd[j]);
			if ((dist[j]<ang_length) && (i != j))
			{

				ji_angle[j] = ab[j] / jijing[i] / dist[j];
				if (abs(ji_angle[j])< ang_cos)
				{
					index[i]++;
				}
			}
		}
		if (index[i] == 2)
		{

			zxd3[b].x = vx[i];
			zxd3[b].y = vy[i];

			b = b + 1;

		}
	}

	// ��ͼ����3000��
	for (int i = 0; i < zxd3.size(); i++)
	{


		Scalar color = Scalar(255);
		circle(drawing3000, zxd3[i], 4, color, -1, 8, 0);
		v3000x[i] = zxd3[i].x;                             //��ȡ���ĵ�X����
		v3000y[i] = zxd3[i].y;                            //��ȡ���ĵ�X����
		vmeanx = v3000x[i] + vmeanx;                      //��ȡ���ĵ�X����
		vmeany = v3000y[i] + vmeanx;

	}
	vmeanx = vmeanx / 3000;
	vmeany = vmeany / 3000;

	//����������������    ���߲�
	//Ѱ��Ԫ�������ĵ�
	Mat ReadMatTempPX = drawing3000.clone();
	cv::findContours(ReadMatTempPX, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	vector<Point2f> zxd4(zxd3.size());
	vector<Point2f> zxd5(5);
	vector<Point2f> zxd6(zxd3.size());
	for (int i = 0; i <zxd3.size(); i++)
	{
		zxd4[i].x = zxd3[i].x - vmeanx;                 //��ʼ����
		zxd4[i].y = vmeany - zxd3[i].y;
		jijing1[i] = sqrt(zxd4[i].x*zxd4[i].x + zxd4[i].y*zxd4[i].y);
		jijing2[i] = jijing1[i];
	}
	BubbleSort(jijing2, 3000, sortindex);
	findex[0] = 1213;
	for (int i = 1; i < zxd3.size(); i++)
	{


		findex[i] = GetNextPoint(zxd3, mm, vmeanx, vmeany, findex[i - 1]);
	}

	//  ��������ע��
	for (int i = 0; i < zxd3.size(); i++)
	{
		num = i + 1;
		string Numbers = to_string(num);
		Scalar color = Scalar(255);
		circle(drawing3000, zxd3[findex[i]], 4, color, -1, 8, 0);
		putText(ReadMatTempPX, Numbers, zxd3[findex[i]], CV_FONT_HERSHEY_COMPLEX, 1, color);
	}
	imwrite("result.jpg", ReadMatTempPX);   //��imageͼ�񱣴�Ϊmy.jpg
	m_resultImg = ReadMatTempPX;
	return contours.size();
}

//double�������� ���ԭ������� �Ͱ��������е�����
void ChipCounterAlgorithm::BubbledoubleSort(double  *p, int length, int * ind_diff)
{
	for (int m = 0; m < length; m++)
	{
		ind_diff[m] = m;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				double temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

				int ind_temp = ind_diff[j];
				ind_diff[j] = ind_diff[j + 1];
				ind_diff[j + 1] = ind_temp;
			}
		}
	}
}

//�������� ���ԭ������� �Ͱ��������е�����
void ChipCounterAlgorithm::BubbleSort(float  *p, int length, int * ind_diff)
{
	for (int m = 0; m < length; m++)
	{
		ind_diff[m] = m;
	}

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				float temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

				int ind_temp = ind_diff[j];
				ind_diff[j] = ind_diff[j + 1];
				ind_diff[j + 1] = ind_temp;
			}
		}
	}
}

//// Ѱ����һ����
int ChipCounterAlgorithm::GetNextPoint(vector<Point2f>&  a, int mm, float b, float c, int inipoint)
{

	vector<Point2f> zxd6(3000);
	float dist1[3000];
	float cro = 0;
	int ang_length1 = 150, bb = 0;
	double ab1[3000] = { 0 };
	int index[3000] = { 0 };
	//Ѱ�Һ͵�һ�㻡������ֵ��150���ڵĵ� 
	for (int i = 0; i < a.size(); i++)
	{


		dist1[i] = sqrt((a[i].x - a[inipoint].x)*(a[i].x - a[inipoint].x) + (a[i].y - a[inipoint].y)*(a[i].y - a[inipoint].y));

		if ((dist1[i]<(1.5*ang_length1)) && (i != inipoint))
		{
			zxd6[i].x = a[i].x - a[inipoint].x;
			zxd6[i].y = a[inipoint].y - a[i].y;
			cro = (a[inipoint].x - b)*(zxd6[i].y) - (c - a[inipoint].y)*(zxd6[i].x);
			if (cro>0)
			{
				/*ab1[i] = abs(zxd6[i].dot(zxd3[990]));*/
				ab1[i] = abs((a[inipoint].x - b)*(a[i].x - a[inipoint].x) + (c - a[inipoint].y)*(a[inipoint].y - a[i].y));
				bb++;

			}
		}
	}
	BubbledoubleSort(ab1, 3000, index);
	return index[3000 - bb];
}

//���ļ�
Mat ChipCounterAlgorithm::openImage(string fileName)
{
	return imread(fileName, CV_LOAD_IMAGE_ANYDEPTH);
}

//����ͼ��
void ChipCounterAlgorithm::saveImage(string fileName, Mat input)
{
	imwrite(fileName, input);
}

