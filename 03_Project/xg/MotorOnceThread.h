#pragma once

#include <QThread>
#include <gts.h>
#include <GlobalData.h>
#include <qtimer.h>
#include <qdebug.h>

class MotorOnceThread : public QThread
{
	Q_OBJECT

public:
	MotorOnceThread(QObject *parent);
	~MotorOnceThread();

protected:
	void run();

private:
	QTimer *timer;
};
