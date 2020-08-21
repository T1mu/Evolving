#include "MotorProject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MotorProject w;
	w.show();
	return a.exec();
}
