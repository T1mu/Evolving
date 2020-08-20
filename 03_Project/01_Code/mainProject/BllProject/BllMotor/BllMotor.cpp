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

//������������ʼ��
bool BllMotor::connectNetCardBll(int index)
{
	if (m_motor->connectNetCardMotor(index))
	{
		if (m_motor->initNetCard())
		{
			m_motor->getAxisNumber();
			m_motor->setAccelMotor(0.5, 0.5);//����������ļ��ٶȼ��ٶ�
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

//�Ͽ�����
bool BllMotor::disconnectNetCardBll(){
	return(m_motor->disconnectNetCardMotor());
}

//���ش�����Ϣ
QString BllMotor::getNCErrStr()
{
	return(m_motor->getErrStr());
}

//ֹͣ�˶�
void BllMotor::stopBll()
{
	m_motor->stopMotor();
}

void BllMotor::moveDistBll(int axis, long dist, double speed)
{
	m_motor->moveDistMotor(dist, 0.5, speed, 0, axis);
}