#include "MotorProject.h"

#define AXIS_X 1
#define AXIS_Y 2

short bFlagAlarm = false; // 伺服报警标志
short bFlagMError = false; // 跟随误差越限标志
short bFlagPosLimit = false;// 正限位触发标志
short bFlagNegLimit = false;// 负限位触发标志
short bFlagSmoothStop = false; // 平滑停止标志
short bFlagAbruptStop = false; // 急停标志
short bFlagServoOn = false;// 伺服使能标志
short bFlagMotion = false; // 规划器运动标志

MotorProject::MotorProject(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	x_thread = new MotorThread(this);
	onceMove_X = new MotorOnceThread(this);
	connect(x_thread, SIGNAL(readOne_X(QString)), this, SLOT(readOne_X(QString)));
	connect(x_thread, SIGNAL(motorStatus_X(long)), this, SLOT(motorStatus_X(long)));
}

void MotorProject::motorStatus_X(long sts)
{
	if (sts & 0x400)
	{
		ui.MotorStop_X->setText("stop");
	}
	else
	{
		ui.MotorStop_X->setText("run");
	}
	if (sts & 0x2)
	{
		bFlagAlarm = true;
		ui.Alarm_X->setText("伺服报警");
	}
	else
	{
		bFlagAlarm = false;
		ui.Alarm_X->setText("伺服正常");
	}
	// 跟随误差越限标志
	if (sts & 0x10)
	{
		bFlagMError = true;
		ui.MotorMove_X->setText("运动出错");
	}
	else
	{
		bFlagMError = false;
		ui.MotorMove_X->setText("运动正常");
	}
	// 正向限位
	if (sts & 0x20)
	{
		bFlagPosLimit = true;
		ui.PosLimit_X->setText("正限位触发");
	}
	else
	{
		bFlagPosLimit = false;
		ui.PosLimit_X->setText("正限位未触发");
	}
	// 负向限位
	if (sts & 0x40)
	{
		bFlagNegLimit = true;
		ui.NegLimit_X->setText("负限位触发");
	}
	else
	{
		bFlagNegLimit = false;
		ui.NegLimit_X->setText("负限位未触发");
	}
	// 平滑停止
	if (sts & 0x80)
	{
		bFlagSmoothStop = true;
		ui.SmoothStopStatus_X->setText("平滑停止触发");
	}
	else
	{
		bFlagSmoothStop = false;
		ui.SmoothStopStatus_X->setText("平滑停止未触发");
	}
	// 急停标志
	if (sts & 0x100)
	{
		bFlagAbruptStop = true;
		ui.SudStopStatus_X->setText("急停触发");
	}
	else
	{
		bFlagAbruptStop = false;
		ui.SudStopStatus_X->setText("急停未触发");
	}
	// 伺服使能标志
	if (sts & 0x200)
	{
		bFlagServoOn = true;
		ui.Sifu_X->setText("伺服使能");
	}
	else
	{
		bFlagServoOn = false;
		ui.Sifu_X->setText("伺服关闭");
	}
}

void MotorProject::readOne_X(QString prfPos)
{
	ui.labelCurPos_X->setText(prfPos);
	GlobalData::Pos_X = prfPos.toDouble();
}



void MotorProject::on_btnOnOff_clicked()
{
	connectFlag = false;
	short sRtn;
	QString str;
	if (ui.btnOnOff->text() == "启动")
	{
		sRtn = GT_Open();
		qDebug() << "GT_Open()" << sRtn;
		if (sRtn == 0)
		{
			ui.btnOnOff->setText("停止");
			connectFlag = true;
			GT_AxisOn(AXIS_X);
			GT_AxisOn(AXIS_Y);
			ui.CheckBoxAxisOnOff->setChecked(true);
			GT_LmtsOff(AXIS_X);
			GT_LmtsOff(AXIS_Y);
			ui.textEdit->append("GT_启动成功！");
			GT_ZeroPos(AXIS_X);
			GT_ZeroPos(AXIS_Y);
			x_thread->start();
			
		}
		else
		{
			ui.textEdit->append("GT_启动失败！");
			connectFlag = false;
			return;
		}
		
	}
	else if (ui.btnOnOff->text() == "停止")
	{
		sRtn = GT_Close();
		qDebug() << "GT_Close()" << sRtn;
		if (sRtn == 0)
		{
			ui.btnOnOff->setText("启动");
			connectFlag = false;
			ui.textEdit->append("GT_停止成功！");
			x_thread->quit();
		}
		else
		{
			ui.textEdit->append("GT_停止失败！");
			connectFlag = true;
			return;
		}
	}
}

void MotorProject::on_btnReset_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		sRtn = GT_Reset();
		qDebug() << "GT_Reset()" << sRtn;
		if (sRtn != 0)
		{
			ui.textEdit->append("GT_复位成功");
		}
		else
		{
			ui.textEdit->append("GT_复位失败");
			return;
		}
	}
}

void MotorProject::on_btnStatus_X_clicked()
{
	double dPrfPos;// 规划位置
	double dPrfVel;// 规划速度
	double dPrfAcc;// 规划加速度
	long lPrfMode;// 运动模式
	char chPrfMode[20];// 运动模式，字符串变量
	short sRtn;// 指令返回值变量
	long lAxisStatus;// 轴状态
	sRtn = GT_GetSts(AXIS_X, &lAxisStatus);
	qDebug() << "GT_GetSts AXIS_X" << sRtn;
	// 伺服报警标志
	if (lAxisStatus & 0x2)
	{
		bFlagAlarm = true;
		ui.textEdit->append("伺服报警");
	}
	else
	{
		bFlagAlarm = false;
		ui.textEdit->append("伺服正常");
	}
	// 跟随误差越限标志
	if (lAxisStatus & 0x10)
	{
		bFlagMError = true;
		ui.textEdit->append("运动出错");
	}
	else
	{
		bFlagMError = false;
		ui.textEdit->append("运动正常");
	}
	// 正向限位
	if (lAxisStatus & 0x20)
	{
		bFlagPosLimit = true;
		ui.textEdit->append("正限位触发");
	}
	else
	{
		bFlagPosLimit = false;
		ui.textEdit->append("正限位未触发");
	}
	// 负向限位
	if (lAxisStatus & 0x40)
	{
		bFlagNegLimit = true;
		ui.textEdit->append("负限位触发");
	}
	else
	{
		bFlagNegLimit = false;
		ui.textEdit->append("负限位未触发");
	}
	// 平滑停止
	if (lAxisStatus & 0x80)
	{
		bFlagSmoothStop = true;
		ui.textEdit->append("平滑停止触发");
	}
	else
	{
		bFlagSmoothStop = false;
		ui.textEdit->append("平滑停止未触发");
	}
	// 急停标志
	if (lAxisStatus & 0x100)
	{
		bFlagAbruptStop = true;
		ui.textEdit->append("急停触发");
	}
	else
	{
		bFlagAbruptStop = false;
		ui.textEdit->append("急停未触发");
	}
	// 伺服使能标志
	if (lAxisStatus & 0x200)
	{
		bFlagServoOn = true;
		ui.textEdit->append("伺服使能");
	}
	else
	{
		bFlagServoOn = false;
		ui.textEdit->append("伺服关闭");
	}
	// 规划器正在运动标志
	if (lAxisStatus & 0x400)
	{
		bFlagMotion = true;
		ui.textEdit->append("规划器正在运动");
	}
	else
	{
		bFlagMotion = false;
		ui.textEdit->append("规划器已停止");
	}
	// 读取运动数据
	sRtn = GT_GetPrfPos(AXIS_X, &dPrfPos);
	qDebug()<<"GT_GetPrfPos AXIS_X"<<sRtn;
	qDebug() << ("AXIS_X 规划位置") << QString::number(dPrfPos, 'f', 2);
	sRtn = GT_GetPrfVel(AXIS_X, &dPrfVel);
	qDebug() << "GT_GetPrfVel AXIS_X" << sRtn;
	qDebug() << ("AXIS_X 规划速度") << QString::number(dPrfVel, 'f', 2);
	sRtn = GT_GetPrfAcc(AXIS_X, &dPrfAcc);
	qDebug() << "GT_GetPrfAcc AXIS_X" << sRtn;
	qDebug() << ("AXIS_X 规划加速度") << QString::number(dPrfAcc, 'f', 2);
	// 读取运动模式
	sRtn = GT_GetPrfMode(AXIS_X, &lPrfMode);
	qDebug() << "GT_GetPrfMode AXIS_X" << sRtn;
	// 清空字符串
	memset(chPrfMode, '\0', 20);
	QString str;
	for (int i = 0; i < 20; i++)
	{
		str += chPrfMode[i];
	}
	switch (lPrfMode)
	{
	case 0:
		ui.textEdit->append("Trap");
		break;
	case 1:
		ui.textEdit->append("Jog");
		break;
	case 2:
		ui.textEdit->append("PT");
		break;
	case 3:
		ui.textEdit->append("Gear");
		break;
	case 4:
		ui.textEdit->append("Follow");
		break;
	case 5:
		ui.textEdit->append("Interpolation");
		break;
	case 6:
		ui.textEdit->append("PVT");
		break;
	default:
		break;
	}
	printf("AXIS_X 运动模式 %s\n", chPrfMode);
}

void MotorProject::on_btnStatus_Y_clicked()
{
	double dPrfPos;// 规划位置
	double dPrfVel;// 规划速度
	double dPrfAcc;// 规划加速度
	long lPrfMode;// 运动模式
	char chPrfMode[20];// 运动模式，字符串变量
	short sRtn;// 指令返回值变量
	long lAxisStatus;// 轴状态
	sRtn = GT_GetSts(AXIS_Y, &lAxisStatus);
	qDebug() << "GT_GetSts AXIS_Y" << sRtn;
	// 伺服报警标志
	if (lAxisStatus & 0x2)
	{
		bFlagAlarm = true;
		ui.textEdit->append("伺服报警");
	}
	else
	{
		bFlagAlarm = false;
		ui.textEdit->append("伺服正常");
	}
	// 跟随误差越限标志
	if (lAxisStatus & 0x10)
	{
		bFlagMError = true;
		ui.textEdit->append("运动出错");
	}
	else
	{
		bFlagMError = false;
		ui.textEdit->append("运动正常");
	}
	// 正向限位
	if (lAxisStatus & 0x20)
	{
		bFlagPosLimit = true;
		ui.textEdit->append("正限位触发");
	}
	else
	{
		bFlagPosLimit = false;
		ui.textEdit->append("正限位未触发");
	}
	// 负向限位
	if (lAxisStatus & 0x40)
	{
		bFlagNegLimit = true;
		ui.textEdit->append("负限位触发");
	}
	else
	{
		bFlagNegLimit = false;
		ui.textEdit->append("负限位未触发");
	}
	// 平滑停止
	if (lAxisStatus & 0x80)
	{
		bFlagSmoothStop = true;
		ui.textEdit->append("平滑停止触发");
	}
	else
	{
		bFlagSmoothStop = false;
		ui.textEdit->append("平滑停止未触发");
	}
	// 急停标志
	if (lAxisStatus & 0x100)
	{
		bFlagAbruptStop = true;
		ui.textEdit->append("急停触发");
	}
	else
	{
		bFlagAbruptStop = false;
		ui.textEdit->append("急停未触发");
	}
	// 伺服使能标志
	if (lAxisStatus & 0x200)
	{
		bFlagServoOn = true;
		ui.textEdit->append("伺服使能");
	}
	else
	{
		bFlagServoOn = false;
		ui.textEdit->append("伺服关闭");
	}
	// 规划器正在运动标志
	if (lAxisStatus & 0x400)
	{
		bFlagMotion = true;
		ui.textEdit->append("规划器正在运动");
	}
	else
	{
		bFlagMotion = false;
		ui.textEdit->append("规划器已停止");
	}
	// 读取运动数据
	sRtn = GT_GetPrfPos(AXIS_Y, &dPrfPos);
	qDebug() << "GT_GetPrfPos AXIS_Y" << sRtn;
	qDebug() << ("AXIS_Y 规划位置") << QString::number(dPrfPos, 'f', 2);
	sRtn = GT_GetPrfVel(AXIS_Y, &dPrfVel);
	qDebug() << "GT_GetPrfVel AXIS_Y" << sRtn;
	qDebug() << ("AXIS_Y 规划速度") << QString::number(dPrfVel, 'f', 2);
	sRtn = GT_GetPrfAcc(AXIS_Y, &dPrfAcc);
	qDebug() << "GT_GetPrfAcc AXIS_Y" << sRtn;
	qDebug() << ("AXIS_Y 规划加速度") << QString::number(dPrfAcc, 'f', 2);
	// 读取运动模式
	sRtn = GT_GetPrfMode(AXIS_Y, &lPrfMode);
	qDebug() << "GT_GetPrfMode AXIS_Y" << sRtn;
	// 清空字符串
	memset(chPrfMode, '\0', 20);
	QString str;
	for (int i = 0; i < 20; i++)
	{
		str += chPrfMode[i];
	}
	switch (lPrfMode)
	{
	case 0:
		ui.textEdit->append("Trap");
		break;
	case 1:
		ui.textEdit->append("Jog");
		break;
	case 2:
		ui.textEdit->append("PT");
		break;
	case 3:
		ui.textEdit->append("Gear");
		break;
	case 4:
		ui.textEdit->append("Follow");
		break;
	case 5:
		ui.textEdit->append("Interpolation");
		break;
	case 6:
		ui.textEdit->append("PVT");
		break;
	default:
		break;
	}
	printf("AXIS_Y 运动模式 %s\n", chPrfMode);
}

//开启X轴正负限位
void MotorProject::on_btnLimitOn_X_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		if (ui.btnLimitOn_X->text() == "打开X轴正负限位")
		{
			sRtn = GT_LmtsOn(1, AXIS_X);
			qDebug() << "GT_BufLmtsOn AXIS_X" << sRtn;
			if (sRtn == 0)
			{
				ui.textEdit->append("X轴正负限位开启");
				ui.btnLimitOn_X->setText("关闭X轴正负限位");
			}
			else
			{
				ui.textEdit->append("X轴正负限位开启失败");
			}
		}
		else if (ui.btnLimitOn_X->text() == "关闭X轴正负限位")
		{
			sRtn = GT_LmtsOff(1, AXIS_X);
			qDebug() << "GT_BufLmtsOff AXIS_X" << sRtn;
			if (sRtn == 0)
			{
				ui.textEdit->append("X轴正负限位开启");
				ui.btnLimitOn_X->setText("关闭X轴正负限位");
			}
			else
			{
				ui.textEdit->append("X轴正负限位开启失败");
			}
		}
		
	}
}

//限位设置，X轴
void MotorProject::on_btnSetLimit_X_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_SetSoftLimit(AXIS_X, ui.SpinBoxLimit_X->value(), -ui.SpinBoxLimit_X->value());
		qDebug() << "GT_SetSoftLimit AXIS_X" << -ui.SpinBoxLimit_X->value() << "~" << ui.SpinBoxLimit_X->value();
		if (sRtn == 0)
		{
			ui.textEdit->append("AXIS_X 限位设置成功");
		}
		else
		{
			ui.textEdit->append("AXIS_X 限位设置失败");
		}
	}
}

//开启Y轴正负限位
void MotorProject::on_btnLimitOn_Y_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		sRtn = GT_BufLmtsOn(1, AXIS_Y, -1, 0);
		qDebug() << "GT_BufLmtsOn AXIS_Y" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("Y轴正负限位开启");
		}
		else
		{
			ui.textEdit->append("Y轴正负限位开启失败");
		}
	}
}

//限位设置，Y轴
void MotorProject::on_btnSetLimit_Y_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_SetSoftLimit(AXIS_Y, ui.SpinBoxLimit_Y->value(), -ui.SpinBoxLimit_Y->value());
		qDebug() << "GT_SetSoftLimit AXIS_Y" << -ui.SpinBoxLimit_Y->value() << "~" << ui.SpinBoxLimit_Y->value();
		if (sRtn == 0)
		{
			ui.textEdit->append("AXIS_Y 限位设置成功");
		}
		else
		{
			ui.textEdit->append("AXIS_Y 限位设置失败");
		}
	}
}




void MotorProject::on_CheckBoxAxisOnOff_clicked(bool checked)
{
	short sRtn_X;
	short sRtn_Y;
	short sRtn_Z;
	AxisOnFlag = false;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		if (checked)
		{
			sRtn_X = GT_AxisOn(AXIS_X);
			qDebug() << "GT_AxisOn(AXIS_X)" << sRtn_X;
			//sRtn_Y = GT_AxisOn(AXIS_Y);
			//qDebug() << "GT_AxisOn(AXIS_Y)" << sRtn_Y;
			//sRtn_Z = GT_AxisOn(AXIS_Z);
			//qDebug() << "GT_AxisOn(AXIS_Z)" << sRtn_Z;
			if (sRtn_X == 0 ) //&& sRtn_Y == 0 && sRtn_Z == 0)
			{
				AxisOnFlag = true;
				ui.textEdit->append("伺服开启成功");
			}
			else
			{
				AxisOnFlag = false;
				ui.textEdit->append("伺服开启失败");
				ui.CheckBoxAxisOnOff->setChecked(false);
				return;
			}
		}
		else
		{
			sRtn_X = GT_AxisOff(AXIS_X);
			qDebug() << "GT_AxisOff(AXIS_X)" << sRtn_X;
			//sRtn_Y = GT_AxisOff(AXIS_Y);
			//qDebug() << "GT_AxisOff(AXIS_Y)" << sRtn_Y;
			//sRtn_Z = GT_AxisOff(AXIS_Z);
			//qDebug() << "GT_AxisOff(AXIS_Z)" << sRtn_Z;
			if (sRtn_X == 0) // && sRtn_Y == 0 && sRtn_Z == 0)
			{
				AxisOnFlag = false;
				ui.textEdit->append("伺服关闭成功");
			}
			else
			{
				AxisOnFlag = true;
				ui.textEdit->append("伺服关闭失败");
				ui.CheckBoxAxisOnOff->setChecked(true);
				return;
			}
		}
	}
}

void MotorProject::on_btnZeroPos_X_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_ZeroPos(AXIS_X);
		qDebug() << "GT_ZeroPos AXIS_X";
		if (sRtn == 0)
		{
			ui.textEdit->append("X轴位置清零");
		}
		else
		{
			ui.textEdit->append("X轴位置清零失败");
		}
	}
}

void MotorProject::on_btnZeroPos_Y_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_ZeroPos(AXIS_Y);
		qDebug() << "GT_ZeroPos AXIS_Y";
		if (sRtn == 0)
		{
			ui.textEdit->append("Y轴位置清零");
		}
		else
		{
			ui.textEdit->append("Y轴位置清零失败");
		}
	}

}


void MotorProject::on_btnClrSts_clicked()
{
	short sRtn;
	sRtn = GT_LoadConfig("test.cfg");
	qDebug()<<"GT_LoadConfig"<<sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		sRtn = GT_ClrSts(1, 8);
		qDebug() << "GT_ClrSts" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("标志清除");
		}
		else
		{
			ui.textEdit->append("标志清除失败");
		}
	}
}

void MotorProject::on_btnSmoothStop_X_clicked()
{
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		GlobalData::shutDownFlag = 1;
		short sRtn;
		sRtn = GT_Stop(AXIS_X, 0);
		qDebug() << "GT_Stop AXIS_X" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("平滑停止");
		}
		else
		{
			ui.textEdit->append("平滑停止失败");
		}
	}
}

void MotorProject::on_btnStopSudden_clicked()
{
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		GlobalData::shutDownFlag = 1;
		short sRtn;
		sRtn = GT_Stop(AXIS_X, 1);
		qDebug() << "GT_Stop AXIS_X" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("急停");
		}
		else
		{
			ui.textEdit->append("急停失败");
		}
	}
}

void MotorProject::on_btnTrapUpdate_X_clicked()
{
	
	short sRtn;
	TTrapPrm trap;
	double acc_x;
	double dec_x;
	double vel_x;
	short smoothTime_x;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		// AXIS轴规划位置清零
		sRtn = GT_SetPrfPos(AXIS_X, 0);
		qDebug() << "GT_SetPrfPos AXIS_X" << sRtn;
		// 将 AXIS 轴设为点位模式
		sRtn = GT_PrfTrap(AXIS_X);
		qDebug() << "GT_PrfTrap AXIS_X" << sRtn;
		// 设置需要修改的运动参数
		acc_x = ui.SpinBoxTrapAcc_X->value();
		dec_x = ui.SpinBoxTrapDec_X->value();
		smoothTime_x = ui.SpinBoxTrapSmoothTime_X->value();
		// 设置点位运动参数
		trap.acc = acc_x;
		trap.dec = dec_x;
		trap.smoothTime = smoothTime_x;
		sRtn = GT_SetTrapPrm(AXIS_X, &trap);
		qDebug() << "GT_SetTrapPrm AXIS_X" << sRtn;
		// 设置 AXIS 轴的目标位置
		if (ui.comboBoxTrap_X->currentText() == "正向")
		{
			sRtn = GT_SetPos(AXIS_X, ui.SpinBoxTrapPos_X->value() * 5000 + GlobalData::Pos_X * 5000);
		}
		else if (ui.comboBoxTrap_X->currentText() == "负向")
		{
			sRtn = GT_SetPos(AXIS_X, -ui.SpinBoxTrapPos_X->value() * 5000 + GlobalData::Pos_X * 5000);
		}
		qDebug() << "GT_SetPos AXIS_X" << sRtn << ui.comboBoxTrap_X->currentText();
		// 设置AXIS轴的目标速度
		vel_x = ui.SpinBoxTrapVel_X->value()/0.2;
		sRtn = GT_SetVel(AXIS_X, vel_x);
		qDebug() << "GT_SetVel AXIS_X" << sRtn;
		// 启动AXIS轴的运动
		sRtn = GT_Update(1 << (AXIS_X - 1));
		qDebug() << "GT_Update AXIS_X" << sRtn;
		
		if (sRtn == 0)
		{
			
			ui.textEdit->append("X轴启动Trap成功");
		}
		else
		{
			ui.textEdit->append("X轴启动Trap失败");
			return;
		}

	}
}

void MotorProject::on_btnOneDegree_X_clicked()
{
	short sRtn; 
	int i = 0;
	TTrapPrm trap;
	int index = ui.SpinBoxOneDegree_X->value();
	GlobalData::SetPos_X = ui.SpinBoxOneDegree_X->value() * 5000;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		if (ui.comboBoxTrap_X->currentText() == "正向")
		{
			GlobalData::motorOnceMove = ui.SpinBoxOneDegree_X->value();
		}
		else if (ui.comboBoxTrap_X->currentText() == "负向")
		{
			GlobalData::motorOnceMove = -ui.SpinBoxOneDegree_X->value();
		}

		GlobalData::shutDownFlag = 0;
		onceMove_X->start();
		/*trap.acc = 0.25;
		trap.dec = 0.125;
		trap.smoothTime = 25;
		sRtn = GT_SetTrapPrm(AXIS_X, &trap);
		sRtn = GT_SetVel(AXIS_X, 50);
		for (i = 0; i < index; i++)
		{
			sRtn = GT_Update(1 << (AXIS_X - 1));
			timer->start(100);
		}*/
	}
}


void MotorProject::on_btnCurPosOnce_X_clicked()
{
	short sRtn;
	long sts;
	double prfPos;
	// 读取AXIS轴的状态
	sRtn = GT_GetSts(AXIS_X, &sts);
	// 读取AXIS轴的规划位置
	sRtn = GT_GetPrfPos(AXIS_X, &prfPos);
	qDebug() << "GT_GetPrfPos ONCE AXIS_X" << sRtn;
	ui.SpinBoxCurPosOnce_X->setValue(prfPos);
	printf("prfPos ONCE=%-10.1lf\n", prfPos);
}

void MotorProject::on_btnTrapUpdate_Y_clicked()
{
	short sRtn;
	TTrapPrm trap;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		// AXIS轴规划位置清零
		sRtn = GT_SetPrfPos(AXIS_Y, 0);
		qDebug() << "GT_SetPrfPos AXIS_Y" << sRtn;
		// 将 AXIS 轴设为点位模式
		sRtn = GT_PrfTrap(AXIS_Y);
		qDebug() << "GT_PrfTrap AXIS_Y" << sRtn;
		// 设置需要修改的运动参数
		trap.acc = ui.SpinBoxTrapAcc_Y->value();
		trap.dec = ui.SpinBoxTrapDec_Y->value();
		trap.smoothTime = ui.SpinBoxTrapSmoothTime_Y->value();
		// 设置点位运动参数
		sRtn = GT_SetTrapPrm(AXIS_Y, &trap);
		qDebug() << "GT_SetTrapPrm AXIS_Y" << sRtn;
		// 设置 AXIS 轴的目标位置
		if (ui.comboBoxTrap_Y->currentText() == "正向")
		{
			sRtn = GT_SetPos(AXIS_Y, ui.SpinBoxTrapPos_Y->value());
		}
		else if (ui.comboBoxTrap_Y->currentText() == "负向")
		{
			sRtn = GT_SetPos(AXIS_Y, -ui.SpinBoxTrapPos_Y->value());
		}
		qDebug() << "GT_SetPos AXIS_Y" << sRtn << ui.comboBoxTrap_Y->currentText();
		// 设置AXIS轴的目标速度
		sRtn = GT_SetVel(AXIS_Y, ui.SpinBoxTrapVel_Y->value());
		qDebug() << "GT_SetVel AXIS_Y" << sRtn;
		// 启动AXIS轴的运动
		sRtn = GT_Update(1 << (AXIS_Y - 1));
		qDebug() << "GT_Update AXIS_Y" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("Y轴启动Trap成功");
		}
		else
		{
			ui.textEdit->append("Y轴启动Trap失败");
			return;
		}
	}
}


void MotorProject::on_btnJogUpdate_X_clicked()
{
	short sRtn;
	TJogPrm jog;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		// 将 AXIS 轴设为 Jog 模式
		sRtn = GT_PrfJog(AXIS_X);
		qDebug() << "GT_PrfJog AXIS_X" << sRtn;
		// 读取 Jog 运动参数(需要读取全部运动参数到上位机变量)
		sRtn = GT_GetJogPrm(AXIS_X, &jog);
		qDebug() << "GT_GetJogPrm AXIS_X" << sRtn;
		//设置需要修改的运动参数
		jog.acc = ui.SpinBoxJogAcc_X->value();
		jog.dec = ui.SpinBoxJogDec_X->value();
		// 设置 Jog 运动参数
		sRtn = GT_SetJogPrm(AXIS_X, &jog);
		qDebug() << "GT_SetJogPrm AXIS_X" << sRtn;
		// 设置 AXIS 轴的目标速度
		sRtn = GT_SetVel(AXIS_X, ui.SpinBoxJogVel_X->value());
		qDebug() << "GT_SetVel AXIS_X" << sRtn;
		// 启动 AXIS 轴的运动
		sRtn = GT_Update(1 << (AXIS_X - 1));
		qDebug() << "GT_Update AXIS_X" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("X轴启动Jog成功");
		}
		else
		{
			ui.textEdit->append("X轴启动Jog失败");
			return;
		}
	}
}

void MotorProject::on_btnJogUpdate_Y_clicked()
{
	short sRtn;
	TJogPrm jog;
	if (!connectFlag)
	{
		ui.textEdit->append("请先启动");
	}
	else
	{
		// 将 AXIS 轴设为 Jog 模式
		sRtn = GT_PrfJog(AXIS_Y);
		qDebug() << "GT_PrfJog AXIS_Y" << sRtn;
		// 读取 Jog 运动参数(需要读取全部运动参数到上位机变量)
		sRtn = GT_GetJogPrm(AXIS_Y, &jog);
		qDebug() << "GT_GetJogPrm AXIS_Y" << sRtn;
		//设置需要修改的运动参数
		jog.acc = ui.SpinBoxJogAcc_Y->value();
		jog.dec = ui.SpinBoxJogDec_Y->value();
		// 设置 Jog 运动参数
		sRtn = GT_SetJogPrm(AXIS_Y, &jog);
		qDebug() << "GT_SetJogPrm AXIS_Y" << sRtn;
		// 设置 AXIS 轴的目标速度
		sRtn = GT_SetVel(AXIS_Y, ui.SpinBoxJogVel_Y->value());
		qDebug() << "GT_SetVel AXIS_Y" << sRtn;
		// 启动 AXIS 轴的运动
		sRtn = GT_Update(1 << (AXIS_Y - 1));
		qDebug() << "GT_Update AXIS_Y" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("Y轴启动Jog成功");
		}
		else
		{
			ui.textEdit->append("Y轴启动Jog失败");
			return;
		}
	}
}

void MotorProject::on_btnLimitOff_clicked()
{
	short sRtn;
	sRtn = GT_LmtsOn(1, AXIS_X);
	if (sRtn == 0)
	{
		ui.textEdit->append("AXIS_X 限位设置成功");
	}
	else
	{
		ui.textEdit->append("AXIS_X 限位设置失败");
	}
}



