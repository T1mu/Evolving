#include "DetectorKZWidget.h"
#include "quiwidget.h"
DetectorKZWidget::DetectorKZWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.modeComboBox->setItemData(0, 100);
	ui.modeComboBox->setItemData(1, 102);
	ui.modeComboBox->setItemData(2, 103);

	ui.gainComboBox->setItemData(0, 4);
	ui.gainComboBox->setItemData(1, 5);
	ui.gainComboBox->setItemData(2, 6);
	ui.gainComboBox->setItemData(3, 7);

	ui.trigComboBox->setItemData(0, 9);
	ui.trigComboBox->setItemData(1, 8);
	m_bllDataFlow = BllDataFlow::instance();
	connect(ui.modeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(frameLimitSlot()));
	m_bllDetectorKZ = BllDetectorKZ::instance();
	connect(m_bllDetectorKZ, SIGNAL(returnModeParamSignal(float, int)), this, SLOT(receiveModeParamSlot(float,int)));
	connect(m_bllDetectorKZ, SIGNAL(returnNumSignal(int)), this, SLOT(receiveNumSlot(int)));
	connect(m_bllDetectorKZ, SIGNAL(returnStopSignal()), this, SLOT(receiveStopSlot()));
	

	//--------------------------------------------------
	//connect(ui.getPicModeComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(dealcurrentIndexChanged(int)));
	connect(ui.trigComboBox, SIGNAL(currentIndexChanged(int)), SLOT(dealvalueChanged(double)));
	connect(ui.gainComboBox, SIGNAL(currentIndexChanged(int)), SLOT(dealvalueChanged(double)));
	connect(ui.modeComboBox, SIGNAL(currentIndexChanged(int)), SLOT(dealvalueChanged(double)));
	connect(ui.frameSpinBox, SIGNAL(valueChanged(double)), SLOT(dealvalueChanged(double)));
	connect(ui.exposureSpinBox, SIGNAL(valueChanged(double)), SLOT(dealvalueChanged(double)));
	m_motor = MotorProject::instance();


}

DetectorKZWidget::~DetectorKZWidget()
{

}


void DetectorKZWidget::dealvalueChanged(double d)
{
	setModeBtnFlag = 0;
}


void DetectorKZWidget::receiveModeParamSlot(float frameR, int exposureT)
{
	ui.frameSpinBox->setValue(frameR);
	ui.exposureSpinBox->setValue(exposureT);
}

//����ģʽ�趨֡������
void DetectorKZWidget::frameLimitSlot()
{
	switch (ui.modeComboBox->currentData().toInt())
	{
	case 100:
		ui.frameSpinBox->setMaximum(15);
		break;
	case 102:
		ui.frameSpinBox->setMaximum(4.7);
		break;
	case 103:
		ui.frameSpinBox->setMaximum(1.2);
		break;
	}
}
//����̽����
void DetectorKZWidget::on_connectDetectorBtn_clicked()
{
	if (ui.connectDetectorBtn->text() == QStringLiteral("����̽����"))
	{		
		if (m_bllDetectorKZ->connectBll())
		{
			//����̽�����ɹ�
			ui.connectDetectorBtn->setText(QStringLiteral("�Ͽ�̽����"));
			m_bllDataFlow->setDetectorFlagTrue();
			connectDetectorBtnFlag = m_bllDataFlow->getDetectorFlag();

			ui.frameSpinBox->setValue(1.0);
			ui.rSpeedSpinBox->setValue(10.0);
			ui.rMoveSpinBox->setValue(6.0);
			ui.picNumSpinBox->setValue(66.0);
			ui.gainComboBox->setCurrentIndex(2);
			ui.modeComboBox->setCurrentIndex(2);

			QUIWidget::showMessageBoxError("����̽�����ɹ���");
		}
		else
		{
			//����̽����ʧ��
			QUIWidget::showMessageBoxError("����̽����ʧ�ܣ�");
		}
	}
	else
	{
		if (m_bllDetectorKZ->disconnectBll())
		{
			//�Ͽ�̽�����ɹ�
			ui.connectDetectorBtn->setText(QStringLiteral("����̽����"));
			m_bllDataFlow->setDetectorFlagFalse();
			connectDetectorBtnFlag = m_bllDataFlow->getDetectorFlag();
			QUIWidget::showMessageBoxError("�Ͽ�̽�����ɹ���");

		}
		else
		{
			//�Ͽ�̽����ʧ��
			QUIWidget::showMessageBoxError("�Ͽ�̽����ʧ�ܣ�");
		}
	}
}
//�趨ģʽ
void DetectorKZWidget::on_setModeBtn_clicked()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("����ʧ�ܣ���������̽������");
		return;
	}
	int modeIndex = ui.modeComboBox->currentData().toInt(); //ģʽ���
	int picSize = 0; //ͼ��ߴ�
	switch (modeIndex)
	{
	case 100:
		picSize = 704;
		break;
	case 102:
		picSize = 1408;
		break;
	case 103:
		picSize = 2816;
		break;
	}
	float pFrameRate = ui.frameSpinBox->value(); // ֡��
	int pExposureTime = ui.exposureSpinBox->value(); // �ع�ʱ��
	int nTrigType = ui.trigComboBox->currentData().toInt(); // ����ģʽ
	int nGainLevel = ui.gainComboBox->currentData().toInt(); // ����ȼ�
	if (m_bllDetectorKZ->setModeBll(modeIndex, pFrameRate, pExposureTime, nTrigType, nGainLevel))
	{
		BllDataFlow::setImageSize(picSize, picSize);
		BllDetectorKZ::setImageSize(picSize, picSize);
		BllDetectorKZ::setIfSizeChange();
		m_bllDetectorKZ->updateSize(picSize);
			
		QUIWidget::showMessageBoxInfo("���óɹ�!");
		//----------------------------------------------
		setModeBtnFlag = 1;
		m_bllDataFlow->sendDetectorParam(ui.modeComboBox->currentIndex(), pFrameRate, pExposureTime, ui.trigComboBox->currentIndex(), ui.gainComboBox->currentIndex(), ui.rSpeedSpinBox->value(),ui.rMoveSpinBox->value());
		
	}
	else
	{
		QUIWidget::showMessageBoxInfo("����ʧ��!");
	}

	
}
//����У׼
void DetectorKZWidget::on_darkAdjustBtn_clicked()
{
	m_darkAdjustBar = new DarkAdjustBar();
	m_darkAdjustBar->show();
	ui.gainAdjustBtn->setEnabled(true);
}
//����У׼
void DetectorKZWidget::on_gainAdjustBtn_clicked()
{
	m_gainAdjustBar = new GainAdjustBar();
	m_gainAdjustBar->show();
}
//ȡͼ
void DetectorKZWidget::on_getPicBtn_clicked()
{
	
	int picModeIndex = ui.getPicModeComboBox->currentIndex();
	int picNum = ui.picNumSpinBox->value();
	double tgvel = 0;
	long dist = 0;
	tgvel = ui.rSpeedSpinBox->value() * 10 / 2.81;
	dist = ui.rMoveSpinBox->value() * 10000 / 2.81;
	switch (picModeIndex)
	{
	case 0://�����ع�
		if (!connectDetectorBtnFlag)
		{		
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ���������̽������");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ����ȵ�����ò�����ť��");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ��������ò�ͼ֡����");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, 0, 0, 0, 0);
		break;

	case 1://����У��
		if (!connectDetectorBtnFlag)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ���������̽������");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ����ȵ�����ò�����ť��");
			break;
		}
		if (tgvel == 0 || dist == 0)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ���������ת̨�˶�������");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ��������ò�ͼ֡����");
			break;
		}
		if (m_motor->getMotorFlag() == 0)
		{
			QUIWidget::showMessageBoxError("��ͼʧ�ܣ��������ӵ����");
			break;
		}
		calibrationUI = new ImageCorrect();
		calibrationUI->setAttribute(Qt::WA_DeleteOnClose);
		calibrationUI->show();
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, dist, 0, 1, ui.frameSpinBox->value());
		break;

	case 2://�����ɼ�
		if (!connectDetectorBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ���������̽������");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ����ȵ�����ò�����ť��");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ��������ò�ͼ֡����");
			break;
		}
		if (m_motor->getMotorFlag() == 0)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ��������ӵ����");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, 0, 0, 0, 0);
		break;

	case 3://�����ɼ�
		if (!connectDetectorBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ���������̽������");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ����ȵ�����ò�����ť��");
			break;
		}
		if (tgvel == 0 || dist == 0)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ���������ת̨�˶�������");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ��������ò�ͼ֡����");
			break;
		}
		if (m_motor->getMotorFlag() == 0)
		{
			QUIWidget::showMessageBoxInfo("��ͼʧ�ܣ��������ӵ����");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, dist, 0, 0, ui.frameSpinBox->value());
		break;
	}
	m_bllDataFlow->sendDetectorSet(picModeIndex, picNum, 0, 0);

}



//��ȡ��ͼƬ������
void DetectorKZWidget::receiveNumSlot(int num)
{
	ui.picNumLabel->setText(QString::number(num));
}


//��ʼ����ȡͼ
void DetectorKZWidget::on_startPulseBtn_clicked()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("��������̽������");
		return;
	}
	m_bllDetectorKZ->startPulse(99, 99, 0, 0, 0, 0, 0);
}

//ֹͣ����ȡͼ
void DetectorKZWidget::on_stopPulseBtn_clicked()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("��������̽������");
		return;
	}
	m_bllDetectorKZ->stopPulse();
}

//ֹͣ��
void DetectorKZWidget::receiveStopSlot()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("��������̽������");
		return;
	}
	m_bllDetectorKZ->stopPulse();
}