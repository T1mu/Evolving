#include "CommonDevice.h"
#include "quiwidget.h"
#include "qdebug.h"
#include <QMetaType>

QSerialPort *serialPort;
bool tubeConnectFlag;
CommonDevice::CommonDevice(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	img->load(filename2);
	ui.label->setPixmap(QPixmap::fromImage(*img));
	img2->load(filename3);
	m_bllDataFlow = BllDataFlow::instance();
	m_bllDetectorKZ = BllDetectorKZ::instance();
	connectMotorFlag = m_bllDataFlow->getMotorFlag();
	connectDetectorFlag = m_bllDataFlow->getDetectorFlag();
	qRegisterMetaType<QSerialPort*>("QSerialPort*");
    connect(m_bllDataFlow, SIGNAL(VASignal(int, int)), this, SLOT(getVASlot(int, int)));
	connect(m_bllDataFlow, SIGNAL(serialSignal(QSerialPort*, bool)), this, SLOT(getSerialSlot(QSerialPort*, bool)));
	connect(m_bllDataFlow, SIGNAL(detectorSetSignal(int, int, int, int)), this, SLOT(getDetectorSetSlot(int, int, int, int)));
	connect(m_bllDataFlow, SIGNAL(detectorParamSignal(int, float, int, int, int,float,float)), this, SLOT(getDetectorParamSlot(int, float, int, int, int,float,float)));
	
}

CommonDevice::~CommonDevice()
{

}

void CommonDevice::getVASlot(int v,int a)
{
	ui.voltageSpinBox->setValue(v);
	ui.currentSpinBox->setValue(a);
}

void CommonDevice::getSerialSlot(QSerialPort* port, bool f)
{
	serialPort = port;
	tubeConnectFlag = f;
}

void CommonDevice::on_openXRayBtn_clicked()
{
	if (!tubeConnectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接串口！");
		return;
	}
	//设置电压
	int setVoltageValue = ui.voltageSpinBox->value() * 10;
	char voltageValue[4];
	voltageValue[3] = (setVoltageValue / 1000) % 10 + '0';
	voltageValue[2] = (setVoltageValue / 100) % 10 + '0';
	voltageValue[1] = (setVoltageValue / 10) % 10 + '0';
	voltageValue[0] = setVoltageValue % 10 + '0';
	quint8 cmdIntV[9];
	cmdIntV[0] = 0x50;
	cmdIntV[1] = 0x48;
	cmdIntV[2] = 0x56;
	cmdIntV[3] = 0x20;
	cmdIntV[4] = voltageValue[3];
	cmdIntV[5] = voltageValue[2];
	cmdIntV[6] = voltageValue[1];
	cmdIntV[7] = voltageValue[0];
	cmdIntV[8] = 0x0D;
	if (voltageValue[3] == 0x30)
	{
		//lsize = 3;
		cmdIntV[0] = 0x50;
		cmdIntV[1] = 0x48;
		cmdIntV[2] = 0x56;
		cmdIntV[3] = 0x20;
		cmdIntV[4] = voltageValue[2];
		cmdIntV[5] = voltageValue[1];
		cmdIntV[6] = voltageValue[0];
		cmdIntV[7] = 0x0D;
		serialPort->write((char*)cmdIntV, 8);
	}
	else
	{
		//lsize = 4;
		cmdIntV[4] = voltageValue[3];
		cmdIntV[5] = voltageValue[2];
		cmdIntV[6] = voltageValue[1];
		cmdIntV[7] = voltageValue[0];
		cmdIntV[8] = 0x0D;
		serialPort->write((char*)cmdIntV, 9);
	}


	//设置电流
	int setCurrentValue = ui.currentSpinBox->value();
	char currentValue[3];
	currentValue[2] = (setCurrentValue / 100) % 10 + '0';
	currentValue[1] = (setCurrentValue / 10) % 10 + '0';
	currentValue[0] = setCurrentValue % 10 + '0';
	quint8 cmdIntC[9];
	cmdIntC[0] = 0x50;
	cmdIntC[1] = 0x43;
	cmdIntC[2] = 0x55;
	cmdIntC[3] = 0x20;
	cmdIntC[4] = currentValue[2];
	cmdIntC[5] = currentValue[1];
	cmdIntC[6] = currentValue[0];
	cmdIntC[7] = 0x0D;
	serialPort->write((char*)cmdIntC, 8);
	

	//曝光
	quint8 cmdInt[9] = "\x58\x4F\x4E\x0D";
	serialPort->write((char*)cmdInt, 4);
	ui.openXRayBtn->setEnabled(false);
	ui.closeXRayBtn->setEnabled(true);
	img->load(filename1);
	ui.label->setPixmap(QPixmap::fromImage(*img));
}

void CommonDevice::on_closeXRayBtn_clicked()
{
	if (!tubeConnectFlag)
	{
		QUIWidget::showMessageBoxError("请先连接串口！");
		return;
	}
	quint8 cmdInt[9] = "\x58\x4F\x46\x0D";
	serialPort->write((char*)cmdInt, 4);
	ui.closeXRayBtn->setEnabled(false);
	ui.openXRayBtn->setEnabled(true);
	img->load(filename2);
	ui.label->setPixmap(QPixmap::fromImage(*img));
}

//轴正方向
void CommonDevice::on_zPositiveBtn_clicked()
{
	connectMotorFlag = m_bllDataFlow->getMotorFlag();
	if (!connectMotorFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.zMoveSpinBox->value();
	double speed = ui.zSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(ui.zhouComboBox->currentIndex(), movstep, speed);
}

//轴负方向
void CommonDevice::on_zNegativeBtn_clicked()
{
	connectMotorFlag = m_bllDataFlow->getMotorFlag();
	if (!connectMotorFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	long movstep = ui.zMoveSpinBox->value();
	double speed = ui.zSpeedSpinBox->value();
	movstep = movstep * 640;
	speed = 0.64*speed;
	m_bllMotor->moveDistBll(ui.zhouComboBox->currentIndex(), -movstep, speed);
}

void CommonDevice::on_stopBtn_clicked()
{
	connectMotorFlag = m_bllDataFlow->getMotorFlag();
	if (!connectMotorFlag)
	{
		QUIWidget::showMessageBoxError("请先连接网卡！");
		return;
	}
	m_bllMotor->stopBll();
}


void CommonDevice::on_startPulseBtn_clicked()
{
	connectDetectorFlag = m_bllDataFlow->getDetectorFlag();
	if (!connectDetectorFlag)
	{
		QUIWidget::showMessageBoxError("请先连接探测器！");
		return;
	}
	m_bllDetectorKZ->startPulse(99, 99, 0, 0, 0, 0, 0);
}

//停止PULSE
void CommonDevice::on_stopPulseBtn_clicked()
{
	connectDetectorFlag = m_bllDataFlow->getDetectorFlag();
	if (!connectDetectorFlag)
	{
		QUIWidget::showMessageBoxError("请先连接探测器！");
		return;
	}
	m_bllDetectorKZ->stopPulse();
}

void CommonDevice::on_getPicBtn_clicked()
{
	connectMotorFlag = m_bllDataFlow->getMotorFlag();
	connectDetectorFlag = m_bllDataFlow->getDetectorFlag();
	int picModeIndex = detectorGetPicModeIndex;
	int picNum = detectroPicNum;
	double tgvel = 0;
	long dist = 0;
	tgvel = ui.rSpeedSpinBox->value() * 10 / 2.81;
	dist = ui.rMoveSpinBox->value() * 10000 / 2.81;
	switch (picModeIndex)
	{
	case 0://空气曝光
		if (!connectDetectorFlag)
		{
			QUIWidget::showMessageBoxError("采图失败，请先连接探测器！");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先设置采图帧数！");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, 0, 0, 0, 0);
		break;

	case 1://几何校正
		if (!connectDetectorFlag)
		{
			QUIWidget::showMessageBoxError("采图失败，请先连接探测器！");
			break;
		}
		if (tgvel == 0 || dist == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先设置转台运动参数！");
			break;
		}
		if (detectorMin == 0 || detectorMax == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先设置阈值！");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先设置采图帧数！");
			break;
		}
		if (connectMotorFlag)
		{
			QUIWidget::showMessageBoxError("采图失败，请先连接电机！");
			break;
		}
		//image.show();
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, dist, detectorMin, detectorMax, detectroPicNum);
		break;

	case 2://连续采集

		if (!connectDetectorFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接探测器！");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先设置采图帧数！");
			break;
		}
		if (connectMotorFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接电机！");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, 0, 0, 0, 0);
		break;

	case 3://步进采集
		if (!connectDetectorFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接探测器！");
			break;
		}
		if (tgvel == 0 || dist == 0)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先设置转台运动参数！");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先设置采图帧数！");
			break;
		}
		if (connectMotorFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接电机！");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, dist, 0, 0, detectroPicNum);
		break;
	}

}

void CommonDevice::getDetectorSetSlot(int modeIndex, int Num, int min, int max)
{
	detectorGetPicModeIndex = modeIndex;
	detectroPicNum = Num;
	detectorMin = min;
	detectorMax = max;
}


void CommonDevice::getDetectorParamSlot(int size, float pFrameRate, int pExposureTime, int nTrigType, int nGainLevel, float rSpeed, float rMove)
{
	ui.modeDetectorComboBox->setCurrentIndex(size);
	ui.frameSpinBox->setValue(pFrameRate);
	ui.exposureSpinBox->setValue(pExposureTime);
	ui.trigComboBox->setCurrentIndex(nTrigType);
	ui.gainComboBox->setCurrentIndex(nGainLevel);
	ui.rSpeedSpinBox->setValue(rSpeed);
	ui.rMoveSpinBox->setValue(rMove);

}