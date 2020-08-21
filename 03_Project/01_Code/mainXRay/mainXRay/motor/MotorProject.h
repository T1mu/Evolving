#pragma once

#include <QObject>
#include "gts.h"

class MotorProject : public QObject
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
	bool openMotorCard();

private:
	explicit MotorProject(QObject *parent);
	~MotorProject();
	static MotorProject* m_motor;
};
