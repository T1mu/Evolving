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
	//开启运动控制卡
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
	//关闭运动控制卡
	//m_thread->exit();
	return (m_motor->closeMotorCard());
}

bool BllMotor::resetCardBll(){
	//复位运动控制卡设置
	bool flag = m_motor->resetMotorCard();
	for (int i = 1; i < 3; i++){
		m_motor->setLimitOff(i);
		m_motor->setZeroPos(i);
	}
	return flag;
}

double BllMotor::getPosBll(int Axis){
	//获取位置
	double pos = m_motor->getPos(Axis);
	while (pos >= 1800000){
		pos -= 1800000;
	}
	return (pos / 50) / 100.00; //转换为角度形式
}

void BllMotor::setZeroPosBll(int Axis){
	//设置当前位置为0位
	m_motor->setZeroPos(Axis);
}

void BllMotor::moveMotorBll(int Axis, double vel, long pos){
	//连续运动电机
	m_motor->moveDistMotor(Axis, vel, pos);
}

void BllMotor::emergencyStopBll(int Axis){
	//急停
	m_motor->emergencyStopMotor(Axis);
}

void BllMotor::smoothStopBll(int Axis){
	//平滑停止
	m_motor->smoothStopMotor(Axis);
}