#include "MotorWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MotorWidget w;
	w.show();
	return a.exec();
}
