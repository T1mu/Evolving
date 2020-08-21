#include "MotorStatusBll.h"

MotorStatusBll::MotorStatusBll(QObject *parent)
: QThread(parent)
{
}

MotorStatusBll::~MotorStatusBll()
{
}

void MotorStatusBll::run(){

	while (1){
		long stsX;
		stsX = m_motor->getStatus(1);
		// �ŷ�ʹ�ܱ�־
		if (stsX & 0x200)
		{
			servoFlagX = 1;
		}
		else
		{
			servoFlagX = 0;
		}
		emit servoFlag_X(servoFlagX);
		// ���˶���־
		if (stsX & 0x400)
		{
			moveFlagX = 1;
		}
		else
		{
			moveFlagX = 0;
		}
		emit moveFlag_X(moveFlagX);

		//Y��״̬ʵʱ��������
		long stsY;
		stsY = m_motor->getStatus(2);
		// �ŷ�ʹ�ܱ�־
		if (stsY & 0x200)
		{
			servoFlagY = 1;
		}
		else
		{
			servoFlagY = 0;
		}
		emit servoFlag_Y(servoFlagY);
		// ���˶���־
		if (stsY & 0x400)
		{
			moveFlagY = 1;
		}
		else
		{
			moveFlagY = 0;
		}
		emit moveFlag_Y(moveFlagY);
	}
}