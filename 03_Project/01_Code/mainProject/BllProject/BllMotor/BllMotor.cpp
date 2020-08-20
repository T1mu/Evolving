#include "BllMotor.h"

BllMotor::BllMotor(QObject *parent)
	: QObject(parent)
{
	m_motor = MotorProject::instance();
}

BllMotor::~BllMotor()
{

}

BllMotor* BllMotor::m_instance = 0;

//连接网卡并初始化
bool BllMotor::connectNetCardBll(int index)
{
	if (m_motor->connectNetCardMotor(index))
	{
		if (m_motor->initNetCard())
		{
			m_motor->getAxisNumber();
			m_motor->setAccelMotor(0.5, 0.5);//设置所有轴的加速度减速度
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

//断开连接
bool BllMotor::disconnectNetCardBll(){
	return(m_motor->disconnectNetCardMotor());
}

//返回错误信息
QString BllMotor::getNCErrStr()
{
	return(m_motor->getErrStr());
}

//停止运动
void BllMotor::stopBll()
{
	m_motor->stopMotor();
}

void BllMotor::moveDistBll(int axis, long dist, double speed)
{
	m_motor->moveDistMotor(dist, 0.5, speed, 0, axis);
}