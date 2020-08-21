#ifndef BLLMOTOR_H
#define BLLMOTOR_H

#include <QObject>
#include "../Motor/MotorProject.h"
//#include "BllMotorThread.h"
#include "bllproject_global.h"

class BLLPROJECT_EXPORT BllMotor : public QObject
{
	Q_OBJECT

public:

	static BllMotor* instance()
	{
		static QMutex mutex;//只初始化一次，下次调用是上次的值
		if (!m_instance) {
			QMutexLocker locker(&mutex);
			if (!m_instance) {
				m_instance = new BllMotor();
			}
		}
		return m_instance;
	}

	bool openCardBll();
	bool closeCardBll();
	bool resetCardBll();

	void setZeroPosBll(int);
	void moveMotorBll(int, double, long);

	void emergencyStopBll(int);
	void smoothStopBll(int);

	double getPosBll(int);

private:
	explicit BllMotor(QObject *parent = 0);
	~BllMotor();

	static BllMotor* m_instance;
	MotorProject* m_motor;
	//BllMotorThread* m_thread;
};
#endif
