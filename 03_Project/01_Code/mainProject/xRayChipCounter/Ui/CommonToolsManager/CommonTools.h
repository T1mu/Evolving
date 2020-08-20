#ifndef COMMONTOOLS_H
#define COMMONTOOLS_H

#include <QWidget>
#include "ui_CommonTools.h"
#include "TubeWidget.h"
class CommonTools : public QWidget
{
	Q_OBJECT
public:
	CommonTools(QWidget *parent = 0);
	~CommonTools();

private:
	Ui::CommonTools ui;
};

#endif // COMMONTOOLS_H
