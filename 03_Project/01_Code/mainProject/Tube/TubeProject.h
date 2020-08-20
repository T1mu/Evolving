#ifndef TUBEPROJECT_H
#define TUBEPROJECT_H

#include "tube_global.h"
#include <QObject>
#include <QDebug>
#include <QSerialPort>
class TubeProject : public QObject
{
	Q_OBJECT

public:
	TubeProject(QObject *parent);
	~TubeProject();
	void checkSerialPortTube();
private:
	
};

#endif // TUBEPROJECT_H
