#include "MotorThread.h"

MotorThread::MotorThread(QObject *parent)
	: QThread(parent)
{
}

MotorThread::~MotorThread()
{
}

void MotorThread::stop()
{
	stopped = true;
}

void MotorThread::run()
{
	while (1)
	{
		short sRtn;
		long sts;
		double curPos;
		int x;
		sRtn = GT_GetSts(1, &sts);
		
		emit motorStatus_X(sts);
	    // ��ȡAXIS��Ĺ滮λ��
		sRtn = GT_GetPrfPos(1, &curPos);
		//printf("prfPos=%-10.1lf\n", curPos);
		if (curPos > 1800000)
		{
			curPos = curPos - 1800000;
		}
		else if (curPos < 1800000)
		{
			curPos = curPos + 1800000;
		}
		emit readOne_X(QString::number(curPos*0.0002, 'f', 2));
		msleep(1);//�������CPUռ���ʸߴ�50%
	}
	stopped = false;
}