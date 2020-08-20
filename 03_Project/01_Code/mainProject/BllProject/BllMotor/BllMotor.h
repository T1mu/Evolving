#ifndef BLLMOTOR_H
#define BLLMOTOR_H

#include <QObject>
#include "../bllproject_global.h"
#include "../../xRayChipCounter/Include/Global.h"
#include "../../Motor/MotorProject.h"

#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/Motor.lib")
#else  
#pragma  comment(lib,"../x64/Release/Motor.lib")
#endif
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
	bool connectNetCardBll(int);
	bool disconnectNetCardBll();
	QString getNCErrStr();
	void stopBll();
	void moveDistBll(int,long, double);


private:
	explicit BllMotor(QObject *parent = 0);
	~BllMotor();
	static BllMotor* m_instance;

	MotorProject* m_motor;

};

#endif // BLLMOTOR_H
