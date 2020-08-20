#ifndef BLLTUBE_H
#define BLLTUBE_H

#include <QObject>
#include "../../Tube/TubeProject.h"
#include "../bllproject_global.h"

#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/Tube.lib")

#else  
#pragma  comment(lib,"../x64/Release/Tube.lib")

#endif
class BLLPROJECT_EXPORT BllTube : public QObject
{
	Q_OBJECT

public:
	BllTube(QObject *parent = 0);
	~BllTube();
	
	static BllTube* instance()
	{
		static QMutex mutex;//只初始化一次，下次调用是上次的值
		if (!m_instance) {
			QMutexLocker locker(&mutex);
			if (!m_instance) {
				m_instance = new BllTube();
			}
		}
		return m_instance;
	}

	void checkSerialPortBll();
private:
	static BllTube* m_instance;
	TubeProject* m_tube;
};

#endif // BLLTUBE_H
