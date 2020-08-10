#include "dragzoom.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DragZoom w;
    w.show();

    return a.exec();
}
