#include<iostream>

using namespace std;

class Calibration
{
public:
	Calibration();
	~Calibration();
	void setdata(int, int);
	double *Line_Fit(double aa[], double bb[], int b_n);//ֱ����ϣ�����б����ؾ�
	double Sum_Average(double d[], int b_n);//��ƽ����
	double X_Y_By(double m[], double n[], int b_n);//�˻����
	double Squre_sum(double c[], int b_n);//ƽ����
	double **length_cal(double **u_mass_center, double **v_mass_center);//����Լ��㳤��
	int max_colum(double **length, int BB_Index);//����ÿһ�����ֵ���������к�
	int min_colum(double **length, int BB_Index);//����ÿһ����Сֵ���������к�
	double *get_calibration_para(double **u_mass_center, double **v_mass_center);//��ȡ��У׼�������
	
private:
	int count;
	int kongnum;
};