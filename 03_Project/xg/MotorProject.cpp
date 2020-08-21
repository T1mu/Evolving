#include "MotorProject.h"

#define AXIS_X 1
#define AXIS_Y 2

short bFlagAlarm = false; // �ŷ�������־
short bFlagMError = false; // �������Խ�ޱ�־
short bFlagPosLimit = false;// ����λ������־
short bFlagNegLimit = false;// ����λ������־
short bFlagSmoothStop = false; // ƽ��ֹͣ��־
short bFlagAbruptStop = false; // ��ͣ��־
short bFlagServoOn = false;// �ŷ�ʹ�ܱ�־
short bFlagMotion = false; // �滮���˶���־

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
		ui.Alarm_X->setText("�ŷ�����");
	}
	else
	{
		bFlagAlarm = false;
		ui.Alarm_X->setText("�ŷ�����");
	}
	// �������Խ�ޱ�־
	if (sts & 0x10)
	{
		bFlagMError = true;
		ui.MotorMove_X->setText("�˶�����");
	}
	else
	{
		bFlagMError = false;
		ui.MotorMove_X->setText("�˶�����");
	}
	// ������λ
	if (sts & 0x20)
	{
		bFlagPosLimit = true;
		ui.PosLimit_X->setText("����λ����");
	}
	else
	{
		bFlagPosLimit = false;
		ui.PosLimit_X->setText("����λδ����");
	}
	// ������λ
	if (sts & 0x40)
	{
		bFlagNegLimit = true;
		ui.NegLimit_X->setText("����λ����");
	}
	else
	{
		bFlagNegLimit = false;
		ui.NegLimit_X->setText("����λδ����");
	}
	// ƽ��ֹͣ
	if (sts & 0x80)
	{
		bFlagSmoothStop = true;
		ui.SmoothStopStatus_X->setText("ƽ��ֹͣ����");
	}
	else
	{
		bFlagSmoothStop = false;
		ui.SmoothStopStatus_X->setText("ƽ��ֹͣδ����");
	}
	// ��ͣ��־
	if (sts & 0x100)
	{
		bFlagAbruptStop = true;
		ui.SudStopStatus_X->setText("��ͣ����");
	}
	else
	{
		bFlagAbruptStop = false;
		ui.SudStopStatus_X->setText("��ͣδ����");
	}
	// �ŷ�ʹ�ܱ�־
	if (sts & 0x200)
	{
		bFlagServoOn = true;
		ui.Sifu_X->setText("�ŷ�ʹ��");
	}
	else
	{
		bFlagServoOn = false;
		ui.Sifu_X->setText("�ŷ��ر�");
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
	if (ui.btnOnOff->text() == "����")
	{
		sRtn = GT_Open();
		qDebug() << "GT_Open()" << sRtn;
		if (sRtn == 0)
		{
			ui.btnOnOff->setText("ֹͣ");
			connectFlag = true;
			GT_AxisOn(AXIS_X);
			GT_AxisOn(AXIS_Y);
			ui.CheckBoxAxisOnOff->setChecked(true);
			GT_LmtsOff(AXIS_X);
			GT_LmtsOff(AXIS_Y);
			ui.textEdit->append("GT_�����ɹ���");
			GT_ZeroPos(AXIS_X);
			GT_ZeroPos(AXIS_Y);
			x_thread->start();
			
		}
		else
		{
			ui.textEdit->append("GT_����ʧ�ܣ�");
			connectFlag = false;
			return;
		}
		
	}
	else if (ui.btnOnOff->text() == "ֹͣ")
	{
		sRtn = GT_Close();
		qDebug() << "GT_Close()" << sRtn;
		if (sRtn == 0)
		{
			ui.btnOnOff->setText("����");
			connectFlag = false;
			ui.textEdit->append("GT_ֹͣ�ɹ���");
			x_thread->quit();
		}
		else
		{
			ui.textEdit->append("GT_ֹͣʧ�ܣ�");
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
		ui.textEdit->append("��������");
	}
	else
	{
		sRtn = GT_Reset();
		qDebug() << "GT_Reset()" << sRtn;
		if (sRtn != 0)
		{
			ui.textEdit->append("GT_��λ�ɹ�");
		}
		else
		{
			ui.textEdit->append("GT_��λʧ��");
			return;
		}
	}
}

void MotorProject::on_btnStatus_X_clicked()
{
	double dPrfPos;// �滮λ��
	double dPrfVel;// �滮�ٶ�
	double dPrfAcc;// �滮���ٶ�
	long lPrfMode;// �˶�ģʽ
	char chPrfMode[20];// �˶�ģʽ���ַ�������
	short sRtn;// ָ���ֵ����
	long lAxisStatus;// ��״̬
	sRtn = GT_GetSts(AXIS_X, &lAxisStatus);
	qDebug() << "GT_GetSts AXIS_X" << sRtn;
	// �ŷ�������־
	if (lAxisStatus & 0x2)
	{
		bFlagAlarm = true;
		ui.textEdit->append("�ŷ�����");
	}
	else
	{
		bFlagAlarm = false;
		ui.textEdit->append("�ŷ�����");
	}
	// �������Խ�ޱ�־
	if (lAxisStatus & 0x10)
	{
		bFlagMError = true;
		ui.textEdit->append("�˶�����");
	}
	else
	{
		bFlagMError = false;
		ui.textEdit->append("�˶�����");
	}
	// ������λ
	if (lAxisStatus & 0x20)
	{
		bFlagPosLimit = true;
		ui.textEdit->append("����λ����");
	}
	else
	{
		bFlagPosLimit = false;
		ui.textEdit->append("����λδ����");
	}
	// ������λ
	if (lAxisStatus & 0x40)
	{
		bFlagNegLimit = true;
		ui.textEdit->append("����λ����");
	}
	else
	{
		bFlagNegLimit = false;
		ui.textEdit->append("����λδ����");
	}
	// ƽ��ֹͣ
	if (lAxisStatus & 0x80)
	{
		bFlagSmoothStop = true;
		ui.textEdit->append("ƽ��ֹͣ����");
	}
	else
	{
		bFlagSmoothStop = false;
		ui.textEdit->append("ƽ��ֹͣδ����");
	}
	// ��ͣ��־
	if (lAxisStatus & 0x100)
	{
		bFlagAbruptStop = true;
		ui.textEdit->append("��ͣ����");
	}
	else
	{
		bFlagAbruptStop = false;
		ui.textEdit->append("��ͣδ����");
	}
	// �ŷ�ʹ�ܱ�־
	if (lAxisStatus & 0x200)
	{
		bFlagServoOn = true;
		ui.textEdit->append("�ŷ�ʹ��");
	}
	else
	{
		bFlagServoOn = false;
		ui.textEdit->append("�ŷ��ر�");
	}
	// �滮�������˶���־
	if (lAxisStatus & 0x400)
	{
		bFlagMotion = true;
		ui.textEdit->append("�滮�������˶�");
	}
	else
	{
		bFlagMotion = false;
		ui.textEdit->append("�滮����ֹͣ");
	}
	// ��ȡ�˶�����
	sRtn = GT_GetPrfPos(AXIS_X, &dPrfPos);
	qDebug()<<"GT_GetPrfPos AXIS_X"<<sRtn;
	qDebug() << ("AXIS_X �滮λ��") << QString::number(dPrfPos, 'f', 2);
	sRtn = GT_GetPrfVel(AXIS_X, &dPrfVel);
	qDebug() << "GT_GetPrfVel AXIS_X" << sRtn;
	qDebug() << ("AXIS_X �滮�ٶ�") << QString::number(dPrfVel, 'f', 2);
	sRtn = GT_GetPrfAcc(AXIS_X, &dPrfAcc);
	qDebug() << "GT_GetPrfAcc AXIS_X" << sRtn;
	qDebug() << ("AXIS_X �滮���ٶ�") << QString::number(dPrfAcc, 'f', 2);
	// ��ȡ�˶�ģʽ
	sRtn = GT_GetPrfMode(AXIS_X, &lPrfMode);
	qDebug() << "GT_GetPrfMode AXIS_X" << sRtn;
	// ����ַ���
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
	printf("AXIS_X �˶�ģʽ %s\n", chPrfMode);
}

void MotorProject::on_btnStatus_Y_clicked()
{
	double dPrfPos;// �滮λ��
	double dPrfVel;// �滮�ٶ�
	double dPrfAcc;// �滮���ٶ�
	long lPrfMode;// �˶�ģʽ
	char chPrfMode[20];// �˶�ģʽ���ַ�������
	short sRtn;// ָ���ֵ����
	long lAxisStatus;// ��״̬
	sRtn = GT_GetSts(AXIS_Y, &lAxisStatus);
	qDebug() << "GT_GetSts AXIS_Y" << sRtn;
	// �ŷ�������־
	if (lAxisStatus & 0x2)
	{
		bFlagAlarm = true;
		ui.textEdit->append("�ŷ�����");
	}
	else
	{
		bFlagAlarm = false;
		ui.textEdit->append("�ŷ�����");
	}
	// �������Խ�ޱ�־
	if (lAxisStatus & 0x10)
	{
		bFlagMError = true;
		ui.textEdit->append("�˶�����");
	}
	else
	{
		bFlagMError = false;
		ui.textEdit->append("�˶�����");
	}
	// ������λ
	if (lAxisStatus & 0x20)
	{
		bFlagPosLimit = true;
		ui.textEdit->append("����λ����");
	}
	else
	{
		bFlagPosLimit = false;
		ui.textEdit->append("����λδ����");
	}
	// ������λ
	if (lAxisStatus & 0x40)
	{
		bFlagNegLimit = true;
		ui.textEdit->append("����λ����");
	}
	else
	{
		bFlagNegLimit = false;
		ui.textEdit->append("����λδ����");
	}
	// ƽ��ֹͣ
	if (lAxisStatus & 0x80)
	{
		bFlagSmoothStop = true;
		ui.textEdit->append("ƽ��ֹͣ����");
	}
	else
	{
		bFlagSmoothStop = false;
		ui.textEdit->append("ƽ��ֹͣδ����");
	}
	// ��ͣ��־
	if (lAxisStatus & 0x100)
	{
		bFlagAbruptStop = true;
		ui.textEdit->append("��ͣ����");
	}
	else
	{
		bFlagAbruptStop = false;
		ui.textEdit->append("��ͣδ����");
	}
	// �ŷ�ʹ�ܱ�־
	if (lAxisStatus & 0x200)
	{
		bFlagServoOn = true;
		ui.textEdit->append("�ŷ�ʹ��");
	}
	else
	{
		bFlagServoOn = false;
		ui.textEdit->append("�ŷ��ر�");
	}
	// �滮�������˶���־
	if (lAxisStatus & 0x400)
	{
		bFlagMotion = true;
		ui.textEdit->append("�滮�������˶�");
	}
	else
	{
		bFlagMotion = false;
		ui.textEdit->append("�滮����ֹͣ");
	}
	// ��ȡ�˶�����
	sRtn = GT_GetPrfPos(AXIS_Y, &dPrfPos);
	qDebug() << "GT_GetPrfPos AXIS_Y" << sRtn;
	qDebug() << ("AXIS_Y �滮λ��") << QString::number(dPrfPos, 'f', 2);
	sRtn = GT_GetPrfVel(AXIS_Y, &dPrfVel);
	qDebug() << "GT_GetPrfVel AXIS_Y" << sRtn;
	qDebug() << ("AXIS_Y �滮�ٶ�") << QString::number(dPrfVel, 'f', 2);
	sRtn = GT_GetPrfAcc(AXIS_Y, &dPrfAcc);
	qDebug() << "GT_GetPrfAcc AXIS_Y" << sRtn;
	qDebug() << ("AXIS_Y �滮���ٶ�") << QString::number(dPrfAcc, 'f', 2);
	// ��ȡ�˶�ģʽ
	sRtn = GT_GetPrfMode(AXIS_Y, &lPrfMode);
	qDebug() << "GT_GetPrfMode AXIS_Y" << sRtn;
	// ����ַ���
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
	printf("AXIS_Y �˶�ģʽ %s\n", chPrfMode);
}

//����X��������λ
void MotorProject::on_btnLimitOn_X_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
	}
	else
	{
		if (ui.btnLimitOn_X->text() == "��X��������λ")
		{
			sRtn = GT_LmtsOn(1, AXIS_X);
			qDebug() << "GT_BufLmtsOn AXIS_X" << sRtn;
			if (sRtn == 0)
			{
				ui.textEdit->append("X��������λ����");
				ui.btnLimitOn_X->setText("�ر�X��������λ");
			}
			else
			{
				ui.textEdit->append("X��������λ����ʧ��");
			}
		}
		else if (ui.btnLimitOn_X->text() == "�ر�X��������λ")
		{
			sRtn = GT_LmtsOff(1, AXIS_X);
			qDebug() << "GT_BufLmtsOff AXIS_X" << sRtn;
			if (sRtn == 0)
			{
				ui.textEdit->append("X��������λ����");
				ui.btnLimitOn_X->setText("�ر�X��������λ");
			}
			else
			{
				ui.textEdit->append("X��������λ����ʧ��");
			}
		}
		
	}
}

//��λ���ã�X��
void MotorProject::on_btnSetLimit_X_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_SetSoftLimit(AXIS_X, ui.SpinBoxLimit_X->value(), -ui.SpinBoxLimit_X->value());
		qDebug() << "GT_SetSoftLimit AXIS_X" << -ui.SpinBoxLimit_X->value() << "~" << ui.SpinBoxLimit_X->value();
		if (sRtn == 0)
		{
			ui.textEdit->append("AXIS_X ��λ���óɹ�");
		}
		else
		{
			ui.textEdit->append("AXIS_X ��λ����ʧ��");
		}
	}
}

//����Y��������λ
void MotorProject::on_btnLimitOn_Y_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
	}
	else
	{
		sRtn = GT_BufLmtsOn(1, AXIS_Y, -1, 0);
		qDebug() << "GT_BufLmtsOn AXIS_Y" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("Y��������λ����");
		}
		else
		{
			ui.textEdit->append("Y��������λ����ʧ��");
		}
	}
}

//��λ���ã�Y��
void MotorProject::on_btnSetLimit_Y_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_SetSoftLimit(AXIS_Y, ui.SpinBoxLimit_Y->value(), -ui.SpinBoxLimit_Y->value());
		qDebug() << "GT_SetSoftLimit AXIS_Y" << -ui.SpinBoxLimit_Y->value() << "~" << ui.SpinBoxLimit_Y->value();
		if (sRtn == 0)
		{
			ui.textEdit->append("AXIS_Y ��λ���óɹ�");
		}
		else
		{
			ui.textEdit->append("AXIS_Y ��λ����ʧ��");
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
		ui.textEdit->append("��������");
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
				ui.textEdit->append("�ŷ������ɹ�");
			}
			else
			{
				AxisOnFlag = false;
				ui.textEdit->append("�ŷ�����ʧ��");
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
				ui.textEdit->append("�ŷ��رճɹ�");
			}
			else
			{
				AxisOnFlag = true;
				ui.textEdit->append("�ŷ��ر�ʧ��");
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
		ui.textEdit->append("��������");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_ZeroPos(AXIS_X);
		qDebug() << "GT_ZeroPos AXIS_X";
		if (sRtn == 0)
		{
			ui.textEdit->append("X��λ������");
		}
		else
		{
			ui.textEdit->append("X��λ������ʧ��");
		}
	}
}

void MotorProject::on_btnZeroPos_Y_clicked()
{
	short sRtn;
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
		ui.CheckBoxAxisOnOff->setChecked(false);
	}
	else
	{
		sRtn = GT_ZeroPos(AXIS_Y);
		qDebug() << "GT_ZeroPos AXIS_Y";
		if (sRtn == 0)
		{
			ui.textEdit->append("Y��λ������");
		}
		else
		{
			ui.textEdit->append("Y��λ������ʧ��");
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
		ui.textEdit->append("��������");
	}
	else
	{
		sRtn = GT_ClrSts(1, 8);
		qDebug() << "GT_ClrSts" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("��־���");
		}
		else
		{
			ui.textEdit->append("��־���ʧ��");
		}
	}
}

void MotorProject::on_btnSmoothStop_X_clicked()
{
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
	}
	else
	{
		GlobalData::shutDownFlag = 1;
		short sRtn;
		sRtn = GT_Stop(AXIS_X, 0);
		qDebug() << "GT_Stop AXIS_X" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("ƽ��ֹͣ");
		}
		else
		{
			ui.textEdit->append("ƽ��ֹͣʧ��");
		}
	}
}

void MotorProject::on_btnStopSudden_clicked()
{
	if (!connectFlag)
	{
		ui.textEdit->append("��������");
	}
	else
	{
		GlobalData::shutDownFlag = 1;
		short sRtn;
		sRtn = GT_Stop(AXIS_X, 1);
		qDebug() << "GT_Stop AXIS_X" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("��ͣ");
		}
		else
		{
			ui.textEdit->append("��ͣʧ��");
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
		ui.textEdit->append("��������");
	}
	else
	{
		// AXIS��滮λ������
		sRtn = GT_SetPrfPos(AXIS_X, 0);
		qDebug() << "GT_SetPrfPos AXIS_X" << sRtn;
		// �� AXIS ����Ϊ��λģʽ
		sRtn = GT_PrfTrap(AXIS_X);
		qDebug() << "GT_PrfTrap AXIS_X" << sRtn;
		// ������Ҫ�޸ĵ��˶�����
		acc_x = ui.SpinBoxTrapAcc_X->value();
		dec_x = ui.SpinBoxTrapDec_X->value();
		smoothTime_x = ui.SpinBoxTrapSmoothTime_X->value();
		// ���õ�λ�˶�����
		trap.acc = acc_x;
		trap.dec = dec_x;
		trap.smoothTime = smoothTime_x;
		sRtn = GT_SetTrapPrm(AXIS_X, &trap);
		qDebug() << "GT_SetTrapPrm AXIS_X" << sRtn;
		// ���� AXIS ���Ŀ��λ��
		if (ui.comboBoxTrap_X->currentText() == "����")
		{
			sRtn = GT_SetPos(AXIS_X, ui.SpinBoxTrapPos_X->value() * 5000 + GlobalData::Pos_X * 5000);
		}
		else if (ui.comboBoxTrap_X->currentText() == "����")
		{
			sRtn = GT_SetPos(AXIS_X, -ui.SpinBoxTrapPos_X->value() * 5000 + GlobalData::Pos_X * 5000);
		}
		qDebug() << "GT_SetPos AXIS_X" << sRtn << ui.comboBoxTrap_X->currentText();
		// ����AXIS���Ŀ���ٶ�
		vel_x = ui.SpinBoxTrapVel_X->value()/0.2;
		sRtn = GT_SetVel(AXIS_X, vel_x);
		qDebug() << "GT_SetVel AXIS_X" << sRtn;
		// ����AXIS����˶�
		sRtn = GT_Update(1 << (AXIS_X - 1));
		qDebug() << "GT_Update AXIS_X" << sRtn;
		
		if (sRtn == 0)
		{
			
			ui.textEdit->append("X������Trap�ɹ�");
		}
		else
		{
			ui.textEdit->append("X������Trapʧ��");
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
		ui.textEdit->append("��������");
	}
	else
	{
		if (ui.comboBoxTrap_X->currentText() == "����")
		{
			GlobalData::motorOnceMove = ui.SpinBoxOneDegree_X->value();
		}
		else if (ui.comboBoxTrap_X->currentText() == "����")
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
	// ��ȡAXIS���״̬
	sRtn = GT_GetSts(AXIS_X, &sts);
	// ��ȡAXIS��Ĺ滮λ��
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
		ui.textEdit->append("��������");
	}
	else
	{
		// AXIS��滮λ������
		sRtn = GT_SetPrfPos(AXIS_Y, 0);
		qDebug() << "GT_SetPrfPos AXIS_Y" << sRtn;
		// �� AXIS ����Ϊ��λģʽ
		sRtn = GT_PrfTrap(AXIS_Y);
		qDebug() << "GT_PrfTrap AXIS_Y" << sRtn;
		// ������Ҫ�޸ĵ��˶�����
		trap.acc = ui.SpinBoxTrapAcc_Y->value();
		trap.dec = ui.SpinBoxTrapDec_Y->value();
		trap.smoothTime = ui.SpinBoxTrapSmoothTime_Y->value();
		// ���õ�λ�˶�����
		sRtn = GT_SetTrapPrm(AXIS_Y, &trap);
		qDebug() << "GT_SetTrapPrm AXIS_Y" << sRtn;
		// ���� AXIS ���Ŀ��λ��
		if (ui.comboBoxTrap_Y->currentText() == "����")
		{
			sRtn = GT_SetPos(AXIS_Y, ui.SpinBoxTrapPos_Y->value());
		}
		else if (ui.comboBoxTrap_Y->currentText() == "����")
		{
			sRtn = GT_SetPos(AXIS_Y, -ui.SpinBoxTrapPos_Y->value());
		}
		qDebug() << "GT_SetPos AXIS_Y" << sRtn << ui.comboBoxTrap_Y->currentText();
		// ����AXIS���Ŀ���ٶ�
		sRtn = GT_SetVel(AXIS_Y, ui.SpinBoxTrapVel_Y->value());
		qDebug() << "GT_SetVel AXIS_Y" << sRtn;
		// ����AXIS����˶�
		sRtn = GT_Update(1 << (AXIS_Y - 1));
		qDebug() << "GT_Update AXIS_Y" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("Y������Trap�ɹ�");
		}
		else
		{
			ui.textEdit->append("Y������Trapʧ��");
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
		ui.textEdit->append("��������");
	}
	else
	{
		// �� AXIS ����Ϊ Jog ģʽ
		sRtn = GT_PrfJog(AXIS_X);
		qDebug() << "GT_PrfJog AXIS_X" << sRtn;
		// ��ȡ Jog �˶�����(��Ҫ��ȡȫ���˶���������λ������)
		sRtn = GT_GetJogPrm(AXIS_X, &jog);
		qDebug() << "GT_GetJogPrm AXIS_X" << sRtn;
		//������Ҫ�޸ĵ��˶�����
		jog.acc = ui.SpinBoxJogAcc_X->value();
		jog.dec = ui.SpinBoxJogDec_X->value();
		// ���� Jog �˶�����
		sRtn = GT_SetJogPrm(AXIS_X, &jog);
		qDebug() << "GT_SetJogPrm AXIS_X" << sRtn;
		// ���� AXIS ���Ŀ���ٶ�
		sRtn = GT_SetVel(AXIS_X, ui.SpinBoxJogVel_X->value());
		qDebug() << "GT_SetVel AXIS_X" << sRtn;
		// ���� AXIS ����˶�
		sRtn = GT_Update(1 << (AXIS_X - 1));
		qDebug() << "GT_Update AXIS_X" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("X������Jog�ɹ�");
		}
		else
		{
			ui.textEdit->append("X������Jogʧ��");
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
		ui.textEdit->append("��������");
	}
	else
	{
		// �� AXIS ����Ϊ Jog ģʽ
		sRtn = GT_PrfJog(AXIS_Y);
		qDebug() << "GT_PrfJog AXIS_Y" << sRtn;
		// ��ȡ Jog �˶�����(��Ҫ��ȡȫ���˶���������λ������)
		sRtn = GT_GetJogPrm(AXIS_Y, &jog);
		qDebug() << "GT_GetJogPrm AXIS_Y" << sRtn;
		//������Ҫ�޸ĵ��˶�����
		jog.acc = ui.SpinBoxJogAcc_Y->value();
		jog.dec = ui.SpinBoxJogDec_Y->value();
		// ���� Jog �˶�����
		sRtn = GT_SetJogPrm(AXIS_Y, &jog);
		qDebug() << "GT_SetJogPrm AXIS_Y" << sRtn;
		// ���� AXIS ���Ŀ���ٶ�
		sRtn = GT_SetVel(AXIS_Y, ui.SpinBoxJogVel_Y->value());
		qDebug() << "GT_SetVel AXIS_Y" << sRtn;
		// ���� AXIS ����˶�
		sRtn = GT_Update(1 << (AXIS_Y - 1));
		qDebug() << "GT_Update AXIS_Y" << sRtn;
		if (sRtn == 0)
		{
			ui.textEdit->append("Y������Jog�ɹ�");
		}
		else
		{
			ui.textEdit->append("Y������Jogʧ��");
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
		ui.textEdit->append("AXIS_X ��λ���óɹ�");
	}
	else
	{
		ui.textEdit->append("AXIS_X ��λ����ʧ��");
	}
}



