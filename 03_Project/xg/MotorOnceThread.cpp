#include "MotorOnceThread.h"

MotorOnceThread::MotorOnceThread(QObject *parent)
	: QThread(parent)
{
	timer = new QTimer(this);
}

MotorOnceThread::~MotorOnceThread()
{

}

//单次1度固定角度旋转
void MotorOnceThread::run()
{
	short sRtn;
	int i = 0;
	TTrapPrm trap;
	trap.acc = 0.25;
	trap.dec = 0.125;
	trap.smoothTime = 25;
	sRtn = GT_SetTrapPrm(1, &trap);
	sRtn = GT_SetVel(1, 50);
	for (i = 0; i < abs(GlobalData::motorOnceMove); i++)
	{
		if (GlobalData::motorOnceMove > 0)
		{
			GT_SetPos(1, 5000*i + GlobalData::Pos_X * 5000);
		}
		else
		{
			GT_SetPos(1, -5000 * i + GlobalData::Pos_X * 5000);
		}
		if (GlobalData::shutDownFlag != 1)
		{
			sRtn = GT_Update(1 << (1- 1));
		}
		else
		{
			break;
		}
		sleep(1);
	}
	exit();
}
