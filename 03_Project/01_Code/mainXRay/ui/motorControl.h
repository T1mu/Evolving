#pragma once

#include <QWidget>
#include "ui_motorControl.h"
#include <QDebug>

class motorControl : public QWidget
{
	Q_OBJECT

public:
	motorControl(QWidget *parent = Q_NULLPTR);
	~motorControl();

public slots:
	void on_btnStart_clicked();

private:
	Ui::motorControl ui;

};
