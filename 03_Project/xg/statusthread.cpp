#include "statusthread.h"

StatusThread::StatusThread(QObject *parent)
	: QThread(parent)
{

}

StatusThread::~StatusThread()
{

}

void StatusThread::run()
{
	short sRtn;
	long sts;
	double curPos;
	while (1)
	{
// ¶ÁÈ¡AXISÖáµÄ×´Ì¬
		int x;
		sRtn = GT_GetSts(1, &sts);
		if (sts & 0x400)
		{
			x = 0;
		}
		else
		{
			x = 1;
		}
		emit motorStop(x);
	}
	
}
