#ifndef MOTORPROJECT_H
#define MOTORPROJECT_H

#include <QObject>
#include "..\include\gts.h"
#include "motor_global.h"

class MOTOR_EXPORT MotorProject : public QObject
{
	Q_OBJECT

public:
	static MotorProject* instance()
	{
		static QMutex mutex;
		if (!m_motor) {
			QMutexLocker locker(&mutex);
			if (!m_motor) {
				m_motor = new MotorProject();
			}
		}
		return m_motor;
	}

	int getMotorFlag();

	bool openMotorCard();
	bool closeMotorCard();
	bool resetMotorCard();

	long getStatus(int);
	double getPos(int);

	void setServoOn(int);
	void setLimitOff(int);
	void setZeroPos(int);

	void setAccelMotor(int, double, double, int);
	void moveDistMotor(int, double, long);

	void emergencyStopMotor(int);
	void smoothStopMotor(int);

private:
	explicit MotorProject(QObject *parent = 0);
	~MotorProject();
	static MotorProject* m_motor;
	int motorFlag;
};
#endif
