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
	//获取控制卡开关状态。1开0关
	return motorFlag;
}

bool MotorProject::openMotorCard(){
	//开启控制卡
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
	//关闭控制卡
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
	//复位控制卡
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
	//返回状态数据，为long型，具体含义需参照开发文档
	long sts;
	GT_GetSts(Axis, &sts);
	return sts;
}

double MotorProject::getPos(int Axis){
	//返回位置数据，为double型，单位为脉冲数，需计算/5000转为角度数据
	double pos;
	GT_GetAxisPrfPos(Axis, &pos);
	return pos;
}

void MotorProject::setServoOn(int Axis){
	//伺服开启
	GT_AxisOn(Axis);
}

void MotorProject::setLimitOff(int Axis){
	//关闭正负限位
	GT_LmtsOff(Axis);
}

void MotorProject::setZeroPos(int Axis){
	//设定轴当前位置为零位
	GT_ZeroPos(Axis);
}

void MotorProject::setAccelMotor(int Axis, double acc, double dec, int smoothTime){
	//设置相应轴的加速度、减速度与平滑停止时间
	GT_PrfTrap(Axis);
	TTrapPrm trap;
	trap.acc = acc;
	trap.dec = dec;
	trap.smoothTime = smoothTime;
	GT_SetTrapPrm(Axis, &trap);
}

void MotorProject::moveDistMotor(int Axis, double vel, long pos){
	//设置相应轴转动至相应位置，以及目标速度
	GT_SetVel(Axis, vel);
	GT_SetPos(Axis, pos);
	GT_Update(1 << (Axis - 1));
}

void MotorProject::emergencyStopMotor(int Axis){
	//相应轴急停
	GT_Stop(Axis, 1);
}

void MotorProject::smoothStopMotor(int Axis){
	//相应轴平滑停止
	GT_Stop(Axis, 0);
}