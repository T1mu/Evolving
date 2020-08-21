#pragma once

#include <QObject>
#include "MotorProject.h"
class MotorBll : public QObject
{
	Q_OBJECT

public:

	static MotorBll* instance()
	{
		static QMutex mutex;
		if (!m_instance) {
			QMutexLocker locker(&mutex);
			if (!m_instance) {
				m_instance = new MotorBll();
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
	explicit MotorBll(QObject *parent = 0);
	~MotorBll();

	static MotorBll* m_instance;
	MotorProject* m_motor;
	//BllMotorThread* m_thread;
};

