#include "mainXRay.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	mainXRay w;
	w.show();
	return a.exec();
}
