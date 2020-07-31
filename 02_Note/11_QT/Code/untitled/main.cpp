#include "mainwindow.h"
#include <QApplication>
#include <person.h>

int main(int argc, char *argv[])
{
    person a;
    a.age=10;
    a.height=175.1;
    a.shout();

    return 0;
}
