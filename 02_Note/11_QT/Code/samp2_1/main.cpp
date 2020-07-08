#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //定义并创建应用程序
    Widget w;                   //定义并创建窗体
    w.show();                   //显示窗体
    return a.exec();            //应用程序运行
}
