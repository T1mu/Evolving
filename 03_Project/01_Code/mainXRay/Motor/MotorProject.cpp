#include "MotorProject.h"

MotorProject::MotorProject(QObject *parent)
: QObject(parent)
{
}

MotorProject::~MotorProject()
{
}

MotorProject* MotorProject::m_motor = 0;

int MotorProject::getMotorFlag(){
	//��ȡ���ƿ�����״̬��1��0��
	return motorFlag;
}

bool MotorProject::openMotorCard(){
	//�������ƿ�
	short sRtn;
	sRtn = GT_Open();
	if (sRtn == 0){
		motorFlag = 1;
		return true;
	}
	else{
		return false;
	}
}

bool MotorProject::closeMotorCard(){
	//�رտ��ƿ�
	short sRtn;
	sRtn = GT_Close();
	if (sRtn == 0){
		motorFlag = 0;
		return true;
	}
	else{
		return false;
	}
}

bool MotorProject::resetMotorCard(){
	//��λ���ƿ�
	short sRtn1, sRtn2;
	sRtn1 = GT_ClrSts(1);
	sRtn2 = GT_ClrSts(1);
	if (sRtn1 == 0 && sRtn2 == 0){
		return true;
	}
	else{
		return false;
	}
}

long MotorProject::getStatus(int Axis){
	//����״̬���ݣ�Ϊlong�ͣ����庬������տ����ĵ�
	long sts;
	GT_GetSts(Axis, &sts);
	return sts;
}

double MotorProject::getPos(int Axis){
	//����λ�����ݣ�Ϊdouble�ͣ���λΪ�������������/5000תΪ�Ƕ�����
	double pos;
	GT_GetAxisPrfPos(Axis, &pos);
	return pos;
}

void MotorProject::setServoOn(int Axis){
	//�ŷ�����
	GT_AxisOn(Axis);
}

void MotorProject::setLimitOff(int Axis){
	//�ر�������λ
	GT_LmtsOff(Axis);
}

void MotorProject::setZeroPos(int Axis){
	//�趨�ᵱǰλ��Ϊ��λ
	GT_ZeroPos(Axis);
}

void MotorProject::setAccelMotor(int Axis, double acc, double dec, int smoothTime){
	//������Ӧ��ļ��ٶȡ����ٶ���ƽ��ֹͣʱ��
	GT_PrfTrap(Axis);
	TTrapPrm trap;
	trap.acc = acc;
	trap.dec = dec;
	trap.smoothTime = smoothTime;
	GT_SetTrapPrm(Axis, &trap);
}

void MotorProject::moveDistMotor(int Axis, double vel, long pos){
	//������Ӧ��ת������Ӧλ�ã��Լ�Ŀ���ٶ�
	GT_SetVel(Axis, vel);
	GT_SetPos(Axis, pos);
	GT_Update(1 << (Axis - 1));
}

void MotorProject::emergencyStopMotor(int Axis){
	//��Ӧ�ἱͣ
	GT_Stop(Axis, 1);
}

void MotorProject::smoothStopMotor(int Axis){
	//��Ӧ��ƽ��ֹͣ
	GT_Stop(Axis, 0);
}