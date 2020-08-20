#include "BllTube.h"

BllTube::BllTube(QObject *parent)
	: QObject(parent)
{

}

BllTube::~BllTube()
{

}

void BllTube::checkSerialPortBll(){
	m_tube->checkSerialPortTube();
}