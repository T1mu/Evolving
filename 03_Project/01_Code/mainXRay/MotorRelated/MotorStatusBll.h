#pragma once

#include <QThread>
#include "MotorProject.h"

class MotorStatusBll : public QThread
{
	Q_OBJECT

public:
	MotorStatusBll(QObject *parent);
	~MotorStatusBll();

signals:
	void moveFlag_X(int);
	void servoFlag_X(int);
	void alarmFlag_X(int);

	void moveFlag_Y(int);
	void servoFlag_Y(int);
	void alarmFlag_Y(int);


private:
	void run();
	int moveFlagX;
	int servoFlagX;
	int alarmFlagX;
	int moveFlagY;
	int servoFlagY;
	int alarmFlagY;

	MotorProject* m_motor;
};
