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

//根据模式设定帧率上限
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
//连接探测器
void DetectorKZWidget::on_connectDetectorBtn_clicked()
{
	if (ui.connectDetectorBtn->text() == QStringLiteral("连接探测器"))
	{		
		if (m_bllDetectorKZ->connectBll())
		{
			//连接探测器成功
			ui.connectDetectorBtn->setText(QStringLiteral("断开探测器"));
			m_bllDataFlow->setDetectorFlagTrue();
			connectDetectorBtnFlag = m_bllDataFlow->getDetectorFlag();

			ui.frameSpinBox->setValue(1.0);
			ui.rSpeedSpinBox->setValue(10.0);
			ui.rMoveSpinBox->setValue(6.0);
			ui.picNumSpinBox->setValue(66.0);
			ui.gainComboBox->setCurrentIndex(2);
			ui.modeComboBox->setCurrentIndex(2);

			QUIWidget::showMessageBoxError("连接探测器成功！");
		}
		else
		{
			//连接探测器失败
			QUIWidget::showMessageBoxError("连接探测器失败！");
		}
	}
	else
	{
		if (m_bllDetectorKZ->disconnectBll())
		{
			//断开探测器成功
			ui.connectDetectorBtn->setText(QStringLiteral("连接探测器"));
			m_bllDataFlow->setDetectorFlagFalse();
			connectDetectorBtnFlag = m_bllDataFlow->getDetectorFlag();
			QUIWidget::showMessageBoxError("断开探测器成功！");

		}
		else
		{
			//断开探测器失败
			QUIWidget::showMessageBoxError("断开探测器失败！");
		}
	}
}
//设定模式
void DetectorKZWidget::on_setModeBtn_clicked()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("设置失败，请先连接探测器！");
		return;
	}
	int modeIndex = ui.modeComboBox->currentData().toInt(); //模式编号
	int picSize = 0; //图像尺寸
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
	float pFrameRate = ui.frameSpinBox->value(); // 帧率
	int pExposureTime = ui.exposureSpinBox->value(); // 曝光时间
	int nTrigType = ui.trigComboBox->currentData().toInt(); // 触发模式
	int nGainLevel = ui.gainComboBox->currentData().toInt(); // 增益等级
	if (m_bllDetectorKZ->setModeBll(modeIndex, pFrameRate, pExposureTime, nTrigType, nGainLevel))
	{
		BllDataFlow::setImageSize(picSize, picSize);
		BllDetectorKZ::setImageSize(picSize, picSize);
		BllDetectorKZ::setIfSizeChange();
		m_bllDetectorKZ->updateSize(picSize);
			
		QUIWidget::showMessageBoxInfo("设置成功!");
		//----------------------------------------------
		setModeBtnFlag = 1;
		m_bllDataFlow->sendDetectorParam(ui.modeComboBox->currentIndex(), pFrameRate, pExposureTime, ui.trigComboBox->currentIndex(), ui.gainComboBox->currentIndex(), ui.rSpeedSpinBox->value(),ui.rMoveSpinBox->value());
		
	}
	else
	{
		QUIWidget::showMessageBoxInfo("设置失败!");
	}

	
}
//暗场校准
void DetectorKZWidget::on_darkAdjustBtn_clicked()
{
	m_darkAdjustBar = new DarkAdjustBar();
	m_darkAdjustBar->show();
	ui.gainAdjustBtn->setEnabled(true);
}
//增益校准
void DetectorKZWidget::on_gainAdjustBtn_clicked()
{
	m_gainAdjustBar = new GainAdjustBar();
	m_gainAdjustBar->show();
}
//取图
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
	case 0://空气曝光
		if (!connectDetectorBtnFlag)
		{		
			QUIWidget::showMessageBoxError("采图失败，请先连接探测器！");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxError("采图失败，请先点击设置参数按钮！");
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
		if (!connectDetectorBtnFlag)
		{
			QUIWidget::showMessageBoxError("采图失败，请先连接探测器！");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxError("采图失败，请先点击设置参数按钮！");
			break;
		}
		if (tgvel == 0 || dist == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先设置转台运动参数！");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先设置采图帧数！");
			break;
		}
		if (m_motor->getMotorFlag() == 0)
		{
			QUIWidget::showMessageBoxError("采图失败，请先连接电机！");
			break;
		}
		calibrationUI = new ImageCorrect();
		calibrationUI->setAttribute(Qt::WA_DeleteOnClose);
		calibrationUI->show();
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, dist, 0, 1, ui.frameSpinBox->value());
		break;

	case 2://连续采集
		if (!connectDetectorBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接探测器！");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先点击设置参数按钮！");
			break;
		}
		if (picNum == 0)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先设置采图帧数！");
			break;
		}
		if (m_motor->getMotorFlag() == 0)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接电机！");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, 0, 0, 0, 0);
		break;

	case 3://步进采集
		if (!connectDetectorBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接探测器！");
			break;
		}
		if (!setModeBtnFlag)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先点击设置参数按钮！");
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
		if (m_motor->getMotorFlag() == 0)
		{
			QUIWidget::showMessageBoxInfo("采图失败，请先连接电机！");
			break;
		}
		m_bllDetectorKZ->startPulse(picModeIndex, picNum, tgvel, dist, 0, 0, ui.frameSpinBox->value());
		break;
	}
	m_bllDataFlow->sendDetectorSet(picModeIndex, picNum, 0, 0);

}



//已取得图片的数量
void DetectorKZWidget::receiveNumSlot(int num)
{
	ui.picNumLabel->setText(QString::number(num));
}


//开始连续取图
void DetectorKZWidget::on_startPulseBtn_clicked()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("请先连接探测器！");
		return;
	}
	m_bllDetectorKZ->startPulse(99, 99, 0, 0, 0, 0, 0);
}

//停止连续取图
void DetectorKZWidget::on_stopPulseBtn_clicked()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("请先连接探测器！");
		return;
	}
	m_bllDetectorKZ->stopPulse();
}

//停止槽
void DetectorKZWidget::receiveStopSlot()
{
	if (!connectDetectorBtnFlag)
	{
		QUIWidget::showMessageBoxError("请先连接探测器！");
		return;
	}
	m_bllDetectorKZ->stopPulse();
}