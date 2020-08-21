#pragma once
#pragma execution_character_set("utf-8")

#ifndef MOTORPROJECT_H
#define MOTORPROJECT_H

#include <QtWidgets/QMainWindow>
#include "ui_MotorProject.h"
#include "gts.h"
//#include "config.h"
#include <qdebug.h>
#include <MotorThread.h>
#include <GlobalData.h>
#include <qtimer.h>
#include <MotorOnceThread.h>

class MotorProject : public QMainWindow
{
	Q_OBJECT

public:
	MotorProject(QWidget *parent = Q_NULLPTR);
	static QString CurPos_X;
	

private slots:
	void on_btnOnOff_clicked();
	void on_btnReset_clicked();

	void on_btnStatus_X_clicked();
	void on_btnStatus_Y_clicked();

	void on_CheckBoxAxisOnOff_clicked(bool checked);
	void on_btnClrSts_clicked();

	//正负限位
	//void on_btnLimitOff_X_clicked();
	void on_btnLimitOn_X_clicked();
	void on_btnSetLimit_X_clicked();

	//void on_btnLimitOff_Y_clicked();
	void on_btnLimitOn_Y_clicked();
	void on_btnSetLimit_Y_clicked();


	//各轴状态查询
	void on_btnZeroPos_X_clicked();
	void on_btnZeroPos_Y_clicked();
	
	//Trap运动模式
	void on_btnTrapUpdate_X_clicked();
	void on_btnTrapUpdate_Y_clicked();

	void on_btnCurPosOnce_X_clicked();

	void on_btnOneDegree_X_clicked();

	//Jog运动模式
	void on_btnJogUpdate_X_clicked();
	void on_btnJogUpdate_Y_clicked();

	void on_btnStopSudden_clicked();

	void readOne_X(QString);
	void motorStatus_X(long);

	void on_btnLimitOff_clicked();

	void on_btnSmoothStop_X_clicked();



private:
	Ui::MotorProjectClass ui;
	bool connectFlag;//是否连接标识符
	bool AxisOnFlag;
	MotorThread *x_thread;
	QTimer *timer;
	MotorOnceThread *onceMove_X; 

};
#endif