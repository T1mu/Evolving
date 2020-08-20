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



//��Ѱ����
void MotorWidget::searchNetCard(){
	char netCardInfo[16][256];
	QStringList netCardName;//��������
	int netCardNum;//��������
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

//��������
void MotorWidget::on_connectNetCardBtn_clicked(){
	QString str;
	if (ui.connectNetCardBtn->text() == "��������")
	{		
		if (m_bllMotor->connectNetCardBll(ui.netCardComboBox->currentIndex()))
		{
			ui.connectNetCardBtn->setText("�Ͽ�����");
			m_bllDataFlow->setMotorFlagTrue();
			connectFlag = m_bllDataFlow->getMotorFlag();
			QUIWidget::showMessageBoxError("���������ɹ���");
			
		}
		else
		{
			QUIWidget::showMessageBoxError("��������ʧ�ܣ�");
			return;
		}
	}
	else if (ui.connectNetCardBtn->text() == "�Ͽ�����")
	{

		if (m_bllMotor->disconnectNetCardBll())
		{
			ui.connectNetCardBtn->setText("��������");
			m_bllDataFlow->setMotorFlagFalse();
			connectFlag = m_bllDataFlow->getMotorFlag();
			QUIWidget::showMessageBoxError("�����Ͽ��ɹ���");

		}
		else
		{
			QUIWidget::showMessageBoxError("�����Ͽ�ʧ�ܣ�");
			return;
		}
	}
}

//ֹͣ�˶�
void MotorWidget::on_stopBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	m_bllMotor->stopBll();
}

//X��������
void MotorWidget::on_xPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.xMoveSpinBox->value();
	double speed = ui.xSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(0, movstep, speed);
}

//X�Ḻ����
void MotorWidget::on_xNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.xMoveSpinBox->value();
	double speed = ui.xSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(0, -movstep, speed);
}

//Y��������
void MotorWidget::on_yPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.yMoveSpinBox->value();
	double speed = ui.ySpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(1, movstep, speed);
}

//Y�Ḻ����
void MotorWidget::on_yNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.yMoveSpinBox->value();
	double speed = ui.ySpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(1, -movstep, speed);
}

//Z��������
void MotorWidget::on_zPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.zMoveSpinBox->value();
	double speed = ui.zSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(2, movstep, speed);
}

//Z�Ḻ����
void MotorWidget::on_zNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.zMoveSpinBox->value();
	double speed = ui.zSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(2, -movstep, speed);
}

//��λ��̨������
void MotorWidget::on_tPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.tMoveSpinBox->value();
	double speed = ui.tSpeedSpinBox->value();
	movstep = movstep * 3200 / 0.9;
	speed = speed * 32 / 9;
	m_bllMotor->moveDistBll(3, movstep, speed);
}

//��λ��̨������
void MotorWidget::on_tNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.tMoveSpinBox->value();
	double speed = ui.tSpeedSpinBox->value();
	movstep = movstep * 3200 / 0.9;
	speed = speed * 32 / 9;
	m_bllMotor->moveDistBll(3, -movstep, speed);
}


//ת̨������
void MotorWidget::on_rPositiveBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.rMoveSpinBox->value();
	double speed = ui.rSpeedSpinBox->value();
	movstep = movstep * 10000 / 2.81;
	speed = speed * 10 / 2.81;
	m_bllMotor->moveDistBll(4, movstep, speed);
}

//ת̨������
void MotorWidget::on_rNegativeBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("��������������");
		return;
	}
	long movstep = ui.rMoveSpinBox->value();
	double speed = ui.rSpeedSpinBox->value();
	movstep = movstep * 10000 / 2.81;
	speed = speed * 10 / 2.81;
	m_bllMotor->moveDistBll(4, -movstep, speed);
}