#pragma once

#include <QtWidgets/QWidget>
#include "ui_MotorWidget.h"

class MotorWidget : public QWidget
{
	Q_OBJECT

public:
	MotorWidget(QWidget *parent = Q_NULLPTR);

private:
	Ui::MotorWidgetClass ui;
};
