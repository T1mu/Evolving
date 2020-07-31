#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <iostream>

class person : public QObject
{
    Q_OBJECT
public:
    explicit person(QObject *parent = 0);
    int age;
    double height;
    void shout();

signals:

public slots:
};

#endif // PERSON_H
