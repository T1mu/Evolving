#include "imgmodule.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImgModule w;
    w.show();

    return a.exec();
}
