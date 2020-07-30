#ifndef POTATOTIMER_H
#define POTATOTIMER_H

#include <QObject>

class potatoTimer
{
    Q_OBJECT
private:
    int workTime;
    int sleepTime;
    int remainTime;
public:
    potatoTimer();

    int getWorkTime(){return workTime;}
    int getSleepTime(){return sleepTime;}
    int getCurrentTime(){return remainTime;}

    void setWorkTime(int time){this->workTime=time;}
    void setSleepTime(int time){this->sleepTime=time;}
    void setRemainTime(int time){this->remainTime=time;}


};

#endif // POTATOTIMER_H
