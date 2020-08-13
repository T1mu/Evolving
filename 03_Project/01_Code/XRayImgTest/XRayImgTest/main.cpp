#include "XRayImgTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	XRayImgTest w;
	w.show();
	return a.exec();
}
