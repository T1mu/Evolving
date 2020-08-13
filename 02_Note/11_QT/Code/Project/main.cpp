#include "union.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Union w;
    w.show();

    return a.exec();
}
