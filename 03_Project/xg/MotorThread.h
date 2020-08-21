#pragma once
#ifndef MOTORTHREAD_H
#define MOTORTHREAD_H

#include <QThread>
#include <gts.h>
#include <qdebug.h>
#include <GlobalData.h>

class MotorThread : public QThread
{
	Q_OBJECT

public:
	MotorThread(QObject *parent);
	~MotorThread();
	void stop();

protected:
	void run();

private:
	QMutex mutex;
	volatile bool stopped;

signals:
	void readOne_X(QString);
	void motorStatus_X(long);
	void proBar_X(double);
};

#endif
