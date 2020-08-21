#include "motorControl.h"


motorControl::motorControl(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUi();
	m_bllMotor = BllMotor::instance();
}

motorControl::~motorControl()
{
}

void motorControl::initUi()
{
	ui.btnClose->setDisabled(true);
	ui.btnForward->setDisabled(true);
	ui.btnReverse->setDisabled(true);
	ui.btnUp->setDisabled(true);
	ui.btnDown->setDisabled(true);
}

void motorControl::on_btnStart_clicked()
{
	bool status = m_bllMotor->openCardBll();
	if (status)
		ui.labStatus->setText(QString("连接成功"));
	else
		ui.labStatus->setText(QString("连接失败"));
	ui.btnStart->setDisabled(status);
	ui.btnForward->setEnabled(status);
	ui.btnReverse->setEnabled(status);
	ui.btnUp->setEnabled(status);
	ui.btnDown->setEnabled(status);
	ui.btnClose->setEnabled(status);
}

void motorControl::on_btnClose_clicked()
{
	bool status = m_bllMotor->closeCardBll();
	if (status)
		ui.labStatus->setText(QString("关闭成功"));
	else
		ui.labStatus->setText(QString("关闭失败"));
}

void motorControl::on_btnReset_clicked()
{
	bool status = m_bllMotor->resetCardBll();
	if (status)
		ui.labStatus->setText(QString("重置成功"));
	else
		ui.labStatus->setText(QString("重置失败"));

}

void motorControl::on_btnForward_clicked()
{
	long pos = ui.spinboxX->value();
	m_bllMotor->moveMotorBll(1, 10, pos);
}

void motorControl::on_btnReverse_clicked()
{
	long pos = ui.spinboxX->value();
	m_bllMotor->moveMotorBll(1, 10, 0-pos);
}
