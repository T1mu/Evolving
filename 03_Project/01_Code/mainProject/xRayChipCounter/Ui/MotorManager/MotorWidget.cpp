#include "MotorWidget.h"
#include "quiwidget.h"
MotorWidget::MotorWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_bllMotor = BllMotor::instance();
	m_bllDataFlow = BllDataFlow::instance();
	searchNetCard();
	connectFlag = m_bllDataFlow->getMotorFlag();
	connect(ui.xMoveSpinBox, SIGNAL(valueChanged(int)), ui.xSlider, SLOT(setValue(int)));
	connect(ui.xSlider, SIGNAL(valueChanged(int)), ui.xMoveSpinBox, SLOT(setValue(int)));

	connect(ui.yMoveSpinBox, SIGNAL(valueChanged(int)), ui.ySlider, SLOT(setValue(int)));
	connect(ui.ySlider, SIGNAL(valueChanged(int)), ui.yMoveSpinBox, SLOT(setValue(int)));

	connect(ui.zMoveSpinBox, SIGNAL(valueChanged(int)), ui.zSlider, SLOT(setValue(int)));
	connect(ui.zSlider, SIGNAL(valueChanged(int)), ui.zMoveSpinBox, SLOT(setValue(int)));

	connect(ui.rMoveSpinBox, SIGNAL(valueChanged(int)), ui.rSlider, SLOT(setValue(int)));
	connect(ui.rSlider, SIGNAL(valueChanged(int)), ui.rMoveSpinBox, SLOT(setValue(int)));

	connect(ui.tMoveSpinBox, SIGNAL(valueChanged(int)), ui.tSlider, SLOT(setValue(int)));
	connect(ui.tSlider, SIGNAL(valueChanged(int)), ui.tMoveSpinBox, SLOT(setValue(int)));
}

MotorWidget::~MotorWidget()
{

}



//搜寻网卡
void MotorWidget::searchNetCard(){
	char netCardInfo[16][256];
	QStringList netCardName;//网卡名称
	int netCardNum;//网卡数量
	netCardNum = 0;
	netCardInfo[16][256] = { 0 };

	PKG_IMC_FindNetCard(netCardInfo, &netCardNum);
	for (int i = 0; i<netCardNum; i++)
	{
		netCardName.append(netCardInfo[i]);
	}

	ui.netCardComboBox->clear();
	for (int i = 0; i<netCardNum; i++)
	{
		ui.netCardComboBox->addItem(netCardName[i]);
	}
	ui.netCardComboBox->setCurrentIndex(0);
}

//连接网卡
void MotorWidget::on_connectNetCardBtn_clicked(){
	QString str;
	if (ui.connectNetCardBtn->text() == "连接网卡")
	{		
		if (m_bllMotor->connectNetCardBll(ui.netCardComboBox->currentIndex()))
		{
			ui.connectNetCardBtn->setText("断开连接");
			m_bllDataFlow->setMotorFlagTrue();
			connectFlag = m_bllDataFlow->getMotorFlag();
			QUIWidget::showMessageBoxError("连接网卡成功！");
			
		}
		else
		{
			QUIWidget::showMessageBoxError("连接网卡失败！");
			return;
		}
	}
	else if (ui.connectNetCardBtn->text() == "断开连接")
	{

		if (m_bllMotor->disconnectNetCardBll())
		{
			ui.connectNetCardBtn->setText("连接网卡");
			m_bllDataFlow->setMotorFlagFalse();
			connectFlag = m_bllDataFlow->getMotorFlag();
			QUIWidget::showMessageBoxError("网卡断开成功！");

		}
		else
		{
			QUIWidget::showMessageBoxError("网卡断开失败！");
			return;
		}
	}
}

//停止运动
void MotorWidget::on_stopBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	m_bllMotor->stopBll();
}

//X轴正方向
void MotorWidget::on_xPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.xMoveSpinBox->value();
	double speed = ui.xSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(0, movstep, speed);
}

//X轴负方向
void MotorWidget::on_xNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.xMoveSpinBox->value();
	double speed = ui.xSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(0, -movstep, speed);
}

//Y轴正方向
void MotorWidget::on_yPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.yMoveSpinBox->value();
	double speed = ui.ySpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(1, movstep, speed);
}

//Y轴负方向
void MotorWidget::on_yNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.yMoveSpinBox->value();
	double speed = ui.ySpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(1, -movstep, speed);
}

//Z轴正方向
void MotorWidget::on_zPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.zMoveSpinBox->value();
	double speed = ui.zSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(2, movstep, speed);
}

//Z轴负方向
void MotorWidget::on_zNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.zMoveSpinBox->value();
	double speed = ui.zSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(2, -movstep, speed);
}

//角位移台正方向
void MotorWidget::on_tPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.tMoveSpinBox->value();
	double speed = ui.tSpeedSpinBox->value();
	movstep = movstep * 3200 / 0.9;
	speed = speed * 32 / 9;
	m_bllMotor->moveDistBll(3, movstep, speed);
}

//角位移台负方向
void MotorWidget::on_tNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.tMoveSpinBox->value();
	double speed = ui.tSpeedSpinBox->value();
	movstep = movstep * 3200 / 0.9;
	speed = speed * 32 / 9;
	m_bllMotor->moveDistBll(3, -movstep, speed);
}


//转台正方向
void MotorWidget::on_rPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.rMoveSpinBox->value();
	double speed = ui.rSpeedSpinBox->value();
	movstep = movstep * 10000 / 2.81;
	speed = speed * 10 / 2.81;
	m_bllMotor->moveDistBll(4, movstep, speed);
}

//转台负方向
void MotorWidget::on_rNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.rMoveSpinBox->value();
	double speed = ui.rSpeedSpinBox->value();
	movstep = movstep * 10000 / 2.81;
	speed = speed * 10 / 2.81;
	m_bllMotor->moveDistBll(4, -movstep, speed);
}