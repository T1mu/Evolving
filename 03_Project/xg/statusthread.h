#ifndef STATUSTHREAD_H
#define STATUSTHREAD_H

#include <QThread>
#include <gts.h>
#include <qdebug.h>


class StatusThread : public QThread
{
	Q_OBJECT

public:
	StatusThread(QObject *parent);
	~StatusThread();

protected:
	void run();

private:

signals :
	void motorStop(int);
	
};

#endif // STATUSTHREAD_H
