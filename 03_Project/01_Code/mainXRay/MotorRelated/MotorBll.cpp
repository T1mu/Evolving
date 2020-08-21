#include "MotorBll.h"

MotorBll::MotorBll(QObject *parent)
: QObject(parent)
{
}

MotorBll::~MotorBll()
{
}

MotorBll* MotorBll::m_instance = 0;

bool MotorBll::openCardBll(){
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

bool MotorBll::closeCardBll(){
	//�ر��˶����ƿ�
	//m_thread->exit();
	return (m_motor->closeMotorCard());
}

bool MotorBll::resetCardBll(){
	//��λ�˶����ƿ�����
	bool flag = m_motor->resetMotorCard();
	for (int i = 1; i < 3; i++){
		m_motor->setLimitOff(i);
		m_motor->setZeroPos(i);
	}
	return flag;
}

double MotorBll::getPosBll(int Axis){
	//��ȡλ��
	double pos = m_motor->getPos(Axis);
	while (pos >= 1800000){
		pos -= 1800000;
	}
	return (pos / 50) / 100.00; 
}

void MotorBll::setZeroPosBll(int Axis){
	//���õ�ǰλ��Ϊ0λ
	m_motor->setZeroPos(Axis);
}

void MotorBll::moveMotorBll(int Axis, double vel, long pos){
	//�����˶����
	m_motor->moveDistMotor(Axis, vel, pos);
}

void MotorBll::emergencyStopBll(int Axis){
	//��ͣ
	m_motor->emergencyStopMotor(Axis);
}

void MotorBll::smoothStopBll(int Axis){
	//ƽ��ֹͣ
	m_motor->smoothStopMotor(Axis);
}