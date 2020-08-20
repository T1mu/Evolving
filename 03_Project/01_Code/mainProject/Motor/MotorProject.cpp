#include "MotorProject.h"

MotorProject::MotorProject(QObject *parent)
	: QObject(parent)
{

}

MotorProject::~MotorProject()
{

}

MotorProject* MotorProject::m_motor = 0;

int MotorProject::getMotorFlag()
{
	return motorflag;
}

//连接网卡
bool MotorProject::connectNetCardMotor(int index){
	g_handle = PKG_IMC_Open(index, 0);
	if (g_handle != NULL)
	{
		motorflag = 1;
		return true;
	}
	else
	{
		return false;
	}
}


//断开连接
bool MotorProject::disconnectNetCardMotor()
{
	if (PKG_IMC_Close(g_handle) != 0)
	{
		motorflag = 0;
		return true;

	}
	else
	{
		return false;
	}
}

//配置网卡
bool MotorProject::initNetCard()
{
	if (PKG_IMC_InitCfg(g_handle) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//获取错误信息
QString MotorProject::getErrStr()
{
	QString err;
	err = PKG_IMC_GetFunErrStr();
	return err;
}

//获得控制卡轴数
int MotorProject::getAxisNumber()
{
	g_naxis = PKG_IMC_GetNaxis(g_handle);
	return g_naxis;
}

//停止运动
void MotorProject::stopMotor(){
	for (int i = 0; i < 5; i++){
		PKG_IMC_P2Pstop(g_handle, i);
	}
}

//设置加速度减速度
void MotorProject::setAccelMotor(double accel, double decel){
	for (int i = 0; i < 5; i++){
		PKG_IMC_SetAccel(g_handle, accel, decel, i);
	}
	
}

//移动指定距离
void MotorProject::moveDistMotor(long dist, double startvel, double tgvel, int wait, int axis){
	PKG_IMC_MoveDist(g_handle, dist, startvel, tgvel, wait, axis);
}
//连续运动
void MotorProject::moveVelMotor(double startvel, double tgvel, int axis)
{
	PKG_IMC_MoveVel(g_handle, startvel, tgvel, axis);
}








