#include<iostream>

using namespace std;

class Calibration
{
public:
	Calibration();
	~Calibration();
	void setdata(int, int);
	double *Line_Fit(double aa[], double bb[], int b_n);//直线拟合，返回斜率与截距
	double Sum_Average(double d[], int b_n);//求平均数
	double X_Y_By(double m[], double n[], int b_n);//乘积求和
	double Squre_sum(double c[], int b_n);//平方和
	double **length_cal(double **u_mass_center, double **v_mass_center);//计算对极点长度
	int max_colum(double **length, int BB_Index);//计算每一行最大值，并返回列号
	int min_colum(double **length, int BB_Index);//计算每一行最小值，并返回列号
	double *get_calibration_para(double **u_mass_center, double **v_mass_center);//获取待校准参数结果
	
private:
	int count;
	int kongnum;
};