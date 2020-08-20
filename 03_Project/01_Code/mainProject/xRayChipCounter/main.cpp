#include "MainWidget.h"
#include <QtWidgets/QApplication>

#include "quiwidget.h"
#include <appinit.h>
int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,6,0))
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
	QApplication a(argc, argv);
	a.setFont(QFont("Microsoft Yahei", 9));
	a.setWindowIcon(QIcon("./UIframe/main.ico"));
	QUIWidget::setCode();
	QUIWidget::setStyle(QUIWidget::Style_PSBlack);
	QUIWidget::setTranslator("./UIframe/image/qt_zh_CN.qm");
	QUIWidget::setTranslator("./UIframe/image/widgets.qm");
	AppInit::Instance()->start();

	MainWidget w;
	w.setSizeGripEnabled(true);
	w.show();
	return a.exec();
}