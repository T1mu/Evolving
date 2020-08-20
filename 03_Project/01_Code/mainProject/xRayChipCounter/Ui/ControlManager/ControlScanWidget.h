#ifndef CONTROLSCANWIDGET_H
#define CONTROLSCANWIDGET_H

#include <QWidget>
#include "ui_ControlScanWidget.h"

class ControlScanWidget : public QWidget
{
	Q_OBJECT

public:
	ControlScanWidget(QWidget *parent = 0);
	~ControlScanWidget();

private:
	Ui::ControlScanWidget ui;
};

#endif // CONTROLSCANWIDGET_H
