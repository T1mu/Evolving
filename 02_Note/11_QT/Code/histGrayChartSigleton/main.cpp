#include "histgraychart.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    histGrayChart w;
    w.show();

    return a.exec();
}
