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

bool BllMotor::openCardBll(){
	//�����˶����ƿ�
	if (m_motor->openMotorCard()){
		for (int i = 1; i < 3; i++){
			m_motor->setServoOn(i);
			m_motor->setLimitOff(i);
			m_motor->setZeroPos(i);
			m_motor->setAccelMotor(i, 0.25, 0.125, 25);
		}
		//m_thread->start();
		return true;
	}
	else{
		return false;
	}
}

bool BllMotor::closeCardBll(){
	//�ر��˶����ƿ�
	//m_thread->exit();
	return (m_motor->closeMotorCard());
}

bool BllMotor::resetCardBll(){
	//��λ�˶����ƿ�����
	bool flag = m_motor->resetMotorCard();
	for (int i = 1; i < 3; i++){
		m_motor->setLimitOff(i);
		m_motor->setZeroPos(i);
	}
	return flag;
}

double BllMotor::getPosBll(int Axis){
	//��ȡλ��
	double pos = m_motor->getPos(Axis);
	while (pos >= 1800000){
		pos -= 1800000;
	}
	return (pos / 50) / 100.00; //ת��Ϊ�Ƕ���ʽ
}

void BllMotor::setZeroPosBll(int Axis){
	//���õ�ǰλ��Ϊ0λ
	m_motor->setZeroPos(Axis);
}

void BllMotor::moveMotorBll(int Axis, double vel, long pos){
	//�����˶����
	m_motor->moveDistMotor(Axis, vel, pos);
}

void BllMotor::emergencyStopBll(int Axis){
	//��ͣ
	m_motor->emergencyStopMotor(Axis);
}

void BllMotor::smoothStopBll(int Axis){
	//ƽ��ֹͣ
	m_motor->smoothStopMotor(Axis);
}