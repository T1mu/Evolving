#include "dragchartsigleton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dragChartSigleton w;
    w.show();

    return a.exec();
}
