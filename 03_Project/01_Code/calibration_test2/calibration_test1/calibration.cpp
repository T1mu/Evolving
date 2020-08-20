#include "calibration.h"
#include<stdlib.h>
#include<math.h>


const double  Pi = 3.1415926;
const double L = 30 * 1000 / 154;
Calibration::Calibration()
{
}


Calibration::~Calibration()
{
}

void Calibration::setdata(int a, int b)
{
	count = a;
	kongnum = b;
}

//直线拟合，返回斜率与截距
double *Calibration::Line_Fit(double aa[], double bb[], int b_n)
{
	double K = 0;               //拟合直线的斜率
	double R = 0;               //拟合直线的截距
	double x_sum_average = 0;   //数组 X[N] 个元素求和 并求平均值
	double y_sum_average = 0;   //数组 Y[N] 个元素求和 并求平均值
	double x_square_sum = 0;    //数组 X[N] 个个元素的平均值
	double x_multiply_y = 0;    //数组 X[N]和Y[N]对应元素的乘机
	x_sum_average = Sum_Average(aa, b_n);
	y_sum_average = Sum_Average(bb, b_n);
	x_square_sum = Squre_sum(aa, b_n);
	x_multiply_y = X_Y_By(aa, bb, b_n);
	K = (x_multiply_y - kongnum * x_sum_average * y_sum_average) / (x_square_sum - kongnum * x_sum_average*x_sum_average);
	R = y_sum_average - K * x_sum_average;
	double *P = new double[2];
	P[0] = K;
	P[1] = R;
	return P;
}

//求平均数
double Calibration::Sum_Average(double d[], int b_n)
{
	unsigned int i = 0;
	double z = 0;
	for (i = 0; i<b_n; i++)
	{
		z = z + d[i];
	}
	z = z / b_n;
	return z;
}

//乘积求和
double Calibration::X_Y_By(double m[], double n[], int b_n)
{
	unsigned int i = 0;
	double z = 0;
	for (i = 0; i<b_n; i++)
	{
		z = z + m[i] * n[i];
	}
	return z;
}

//平方和
double Calibration::Squre_sum(double c[], int b_n)
{
	unsigned int i = 0;
	double z = 0;
	for (i = 0; i<b_n; i++)
	{
		z = z + c[i] * c[i];
	}
	return z;
}

//计算对极点长度
double **Calibration::length_cal(double **u_mass_center, double **v_mass_center)
{
	double **length;
	length = (double**)malloc(kongnum * sizeof(double*));
	for (int i = 0; i < kongnum; i++)
	{
		length[i] = (double *)malloc(count / 2 * sizeof(double));
	}
	for (int BB_Index = 0; BB_Index < kongnum; BB_Index++)
	{
		for (int view = 0; view < count / 2; view++)
		{
			length[BB_Index][view] = sqrt((u_mass_center[BB_Index][view] - u_mass_center[BB_Index][view + count / 2])
				*(u_mass_center[BB_Index][view] - u_mass_center[BB_Index][view + count / 2])
				+ (v_mass_center[BB_Index][view] - v_mass_center[BB_Index][view + count / 2])
				*(v_mass_center[BB_Index][view] - v_mass_center[BB_Index][view + count / 2]));
		}
	}
	return length;
}
//计算每一行最大值，并返回列号
int Calibration::max_colum(double **length, int BB_Index)
{
	double max_length = length[BB_Index][0];
	int max_length_Index = 0;
	for (int view = 0; view < count / 2; view++)
	{
		if (length[BB_Index][view]>max_length)
		{
			max_length = length[BB_Index][view];
			max_length_Index = view;
		}

	}
	return max_length_Index;
}
//计算每一行最小值，并返回列号
int Calibration::min_colum(double **length, int BB_Index)
{
	double min_length = length[BB_Index][0];
	int min_length_Index = 0;
	for (int view = 0; view < count / 2; view++)
	{
		if (length[BB_Index][view]<min_length)
		{
			min_length = length[BB_Index][view];
			min_length_Index = view;
		}

	}
	return min_length_Index;
}  
//获取待校准参数结果
double *Calibration::get_calibration_para(double **u_mass_center, double **v_mass_center)
{
	
	//
	double **length = length_cal(u_mass_center, v_mass_center);

	//
	double *u1 = (double *)malloc(sizeof(double)*kongnum);
	double *u2 = (double *)malloc(sizeof(double)*kongnum);
	double *u3 = (double *)malloc(sizeof(double)*kongnum);
	double *u4 = (double *)malloc(sizeof(double)*kongnum);
	double *v1 = (double *)malloc(sizeof(double)*kongnum);
	double *v2 = (double *)malloc(sizeof(double)*kongnum);
	double *v3 = (double *)malloc(sizeof(double)*kongnum);
	double *v4 = (double *)malloc(sizeof(double)*kongnum);
	double *orig_theta = (double *)malloc(sizeof(double)*kongnum);
	double *A3_A4 = (double *)malloc(sizeof(double)*kongnum);
	double *X = (double *)malloc(sizeof(double)*kongnum);
	double *Y = (double *)malloc(sizeof(double)*kongnum);
	double *u0 = (double *)malloc(sizeof(double)*kongnum);
	double *v0 = (double *)malloc(sizeof(double)*kongnum);

	for (int ii = 0; ii < kongnum; ii++)
	{
		int q = max_colum(length, ii);
		u3[ii] = u_mass_center[ii][q];
		v3[ii] = v_mass_center[ii][q];
		u4[ii] = u_mass_center[ii][q + count / 2];
		v4[ii] = v_mass_center[ii][q + count / 2];

		orig_theta[ii] = 2 * Pi*q / count;

		q = min_colum(length, ii);
		u1[ii] = u_mass_center[ii][q];
		v1[ii] = v_mass_center[ii][q];
		u2[ii] = u_mass_center[ii][q + count / 2];
		v2[ii] = v_mass_center[ii][q + count / 2];

		A3_A4[ii] = sqrt(((v3[ii] - v4[ii]))*((v3[ii] - v4[ii])) + (u3[ii] - u4[ii])*(u3[ii] - u4[ii]));
		Y[ii] = (v1[ii] - v2[ii]) / A3_A4[ii];
		X[ii] = (v1[ii] + v2[ii]) / 2;
		u0[ii] = ((u1[ii] * v2[ii] - u2[ii] * v1[ii])*(u3[ii] - u4[ii]) - (u3[ii] * v4[ii] - u4[ii] * v3[ii])*(u1[ii] - u2[ii]))
			/ ((u1[ii] - u2[ii])*(v3[ii] - v4[ii]) - (u3[ii] - u4[ii])*(v1[ii] - v2[ii]));
		v0[ii] = ((u1[ii] * v2[ii] - u2[ii] * v1[ii])*(v3[ii] - v4[ii]) - (u3[ii] * v4[ii] - u4[ii] * v3[ii])*(v1[ii] - v2[ii]))
			/ ((u1[ii] - u2[ii])*(v3[ii] - v4[ii]) - (u3[ii] - u4[ii])*(v1[ii] - v2[ii]));
	}


	//求v,Rfd
	double *P = Line_Fit(Y, X, kongnum);
	P = Line_Fit(Y, X, kongnum);
	double v = P[1];
	double Rfd = P[0];
	if (Rfd <= 0)
	{
		Rfd = -Rfd;
	}

	P = Line_Fit(v0, u0, kongnum);
	double u = P[1] + P[0] * v;
	double yita = atan(P[0]);

	//
	double theta10 = orig_theta[0];
	double theta20 = orig_theta[6];
	double A10_A20 = sqrt((u0[0] - u0[6])*(u0[0] - u0[6]) + (v0[0] - v0[6])*(v0[0] - v0[6]));
	double A13_A14 = sqrt((u3[0] - u4[0])*(u3[0] - u4[0]) + (v3[0] - v4[0])*(v3[0] - v4[0]));
	double A23_A24 = sqrt((u3[6] - u4[6])*(u3[6] - u4[6]) + (v3[6] - v4[6])*(v3[6] - v4[6]));
	double Rfi = L*Rfd / sqrt(A10_A20*A10_A20 + (A13_A14*A13_A14) / 4 + A23_A24*A23_A24 / 4 - A13_A14*A23_A24*cos(theta10 - theta20) / 2);
	double RFD = Rfd*0.154;
	double RFI = Rfi*0.154;
	
	double *parameter = (double *)malloc(sizeof(double)* 4);
	parameter[0] = u;
	parameter[1] = v;
	parameter[2] = RFI;
	parameter[3] = RFD;
	
	return parameter;
	
	//
	free(u1); u1 = NULL;
	free(u2); u2 = NULL;
	free(u3); u3 = NULL;
	free(u4); u4 = NULL;
	free(v1); v1 = NULL;
	free(v2); v2 = NULL;
	free(v3); v3 = NULL;
	free(v4); v4 = NULL;
	free(orig_theta); orig_theta = NULL;
	free(X); X = NULL;
	free(Y); Y = NULL;
	free(u0); u0 = NULL;
	free(v0); v0 = NULL;
	free(A3_A4); A3_A4 = NULL;
	
}