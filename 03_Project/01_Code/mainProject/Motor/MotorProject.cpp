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

//��������
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


//�Ͽ�����
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

//��������
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

//��ȡ������Ϣ
QString MotorProject::getErrStr()
{
	QString err;
	err = PKG_IMC_GetFunErrStr();
	return err;
}

//��ÿ��ƿ�����
int MotorProject::getAxisNumber()
{
	g_naxis = PKG_IMC_GetNaxis(g_handle);
	return g_naxis;
}

//ֹͣ�˶�
void MotorProject::stopMotor(){
	for (int i = 0; i < 5; i++){
		PKG_IMC_P2Pstop(g_handle, i);
	}
}

//���ü��ٶȼ��ٶ�
void MotorProject::setAccelMotor(double accel, double decel){
	for (int i = 0; i < 5; i++){
		PKG_IMC_SetAccel(g_handle, accel, decel, i);
	}
	
}

//�ƶ�ָ������
void MotorProject::moveDistMotor(long dist, double startvel, double tgvel, int wait, int axis){
	PKG_IMC_MoveDist(g_handle, dist, startvel, tgvel, wait, axis);
}
//�����˶�
void MotorProject::moveVelMotor(double startvel, double tgvel, int axis)
{
	PKG_IMC_MoveVel(g_handle, startvel, tgvel, axis);
}








