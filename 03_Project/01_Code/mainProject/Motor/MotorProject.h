#ifndef MOTORPROJECT_H
#define MOTORPROJECT_H

#include <QObject>
#include "motor_global.h"
#include "../xRayChipCounter/Include/IMC_Def.h"
#include "../xRayChipCounter/Include/IMC_Pkg.h"
#include "../xRayChipCounter/Include/ParamDef.h"
#include "../xRayChipCounter/Include/Global.h"

class MOTOR_EXPORT MotorProject : public QObject
{
	Q_OBJECT

public:
	static MotorProject* instance()
	{
		static QMutex mutex;//ֻ��ʼ��һ�Σ��´ε������ϴε�ֵ
		if (!m_motor) {
			QMutexLocker locker(&mutex);
			if (!m_motor) {
				m_motor = new MotorProject();
			}
		}
		return m_motor;
	}
	bool connectNetCardMotor(int);
	bool disconnectNetCardMotor();
	bool initNetCard();
	QString getErrStr();
	int getAxisNumber();
	void stopMotor();
	void moveDistMotor(long,double,double,int,int);
	void moveVelMotor(double,double,int);
	void setAccelMotor(double,double);

	int getMotorFlag();

private:
	explicit MotorProject(QObject *parent = 0);
	~MotorProject();
	static MotorProject* m_motor;
	IMC_HANDLE g_handle;//�������
	int g_naxis;//���ƿ���������

	int motorflag = 0;
};

#endif // MOTORPROJECT_H
