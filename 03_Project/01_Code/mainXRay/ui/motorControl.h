#pragma once

#include <QWidget>
#include "ui_motorControl.h"
#include <QDebug>
#include "..\BllProject\BllMotor.h"
#pragma execution_character_set("utf-8")
class motorControl : public QWidget
{
	Q_OBJECT

public:
	motorControl(QWidget *parent = Q_NULLPTR);
	~motorControl();
	void initUi();

public slots:
	void on_btnStart_clicked();
	void on_btnClose_clicked();
	void on_btnReset_clicked();
	void on_btnForward_clicked();
	void on_btnReverse_clicked();
private:
	Ui::motorControl ui;
	BllMotor *m_bllMotor;
	double xSpeed;
	double ySpeed;

};
