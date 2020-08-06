#include "calibration_test1.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calibration w;
    w.show();

    return a.exec();
}
