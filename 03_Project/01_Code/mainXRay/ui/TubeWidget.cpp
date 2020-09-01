#include "TubeWidget.h"

int FlagSetV = 0;
int FlagSetI = 0;
int FlagCurV = 0;
int FlagCurI = 0;
int FlagCurTemp = 0;
int FlagOn = 0;
int FlagOff = 0;
int FlagStatus = 0;
int FlagErrorClear = 0;
int FlagError = 0;
int FlagWdte0 = 0;
int FlagWdte1 = 0;
int FlagWdtt = 0;

TubeWidget::TubeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initialTube();
	timer = new QTimer(this);
	//槽函数连接
	connect(ui.spinBoxSetV, SIGNAL(valueChanged(int)), this, SLOT(setXrayV(int)));
	connect(ui.spinBoxSetI, SIGNAL(valueChanged(int)), this, SLOT(setXrayI(int)));
	//初始化菜单功能设置使能
	ui.comboBoxConnect->setEnabled(true);
	ui.btnXrayOn->setEnabled(false);
	ui.btnXrayOff->setEnabled(false);
	ui.spinBoxSetV->setEnabled(false);
	ui.spinBoxSetI->setEnabled(false);
	ui.btnGetV->setEnabled(false);
	ui.btnGetI->setEnabled(false);
	ui.btnGetT->setEnabled(false);
	ui.btnGetErr->setEnabled(false);
	ui.btnClearErr->setEnabled(false);
}

int TubeWidget::DecToHex(quint8 x)
{
	quint8 n;
	quint8 h[10] = { '0x30', '0x31', '0x32', '0x33', '0x34', '0x35', '0x36', '0x37', '0x38', '0x39' };
	n = h[x];
	return n;
}

void TubeWidget::initialTube(){
	//初始化球管，轮询串口
	ui.comboBoxConnect->clear();
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		QSerialPort serialPort;
		serialPort.setPort(info);
		if (serialPort.open(QIODevice::ReadWrite))
		{
			ui.comboBoxConnect->addItem(info.portName());
			serialPort.close();
		}

	}
}

void TubeWidget::ReadData(){
	//接收球管返回数据
	QByteArray buf_temp;
	quint8 abc[12];
	int t[12];
	int i = 0;
	buf_temp = serialPort->readAll();
	if (!buf_temp.isEmpty())
	{
		if (!buf_temp.contains("\n"))//判断是否数据段终止
		{
			buf.append(buf_temp);
		}
		else
		{
			buf.append(buf_temp);
			for (i = 0; i < buf.size(); i++)
			{
				abc[i] = buf[i];
				t[i] = abc[i];//整型数组用于对比判断
			}
			if (buf.size() != 0)
			{
				//设置反馈
				if (t[0] == 2 && t[1] == 59 && t[2] == 69 && buf.size() == 5)//返回数据为\0x02\0x3B\0x45\0x0D\0x0A
				{
					if (FlagSetV == 1)//电压设置反馈
					{
						ui.labelStatus->setText("设置电压成功");
						FlagSetV = 0;
					}
					else if (FlagSetI == 1)//电流设置反馈
					{
						ui.labelStatus->setText("设置电流成功");
						FlagSetI = 0;
					}
					else if (FlagOn == 1)//开启射线反馈
					{
						QMessageBox::information(NULL, "Warnning", tr("射线开启"));
						ui.labelStatus->setText("射线开启");
						ui.labelXray->setText("射线开！");
						ui.spinBoxSetV->setEnabled(true);
						ui.spinBoxSetI->setEnabled(true);
						FlagOn = 0;
					}
					else if (FlagOff == 1)//关闭射线反馈
					{
						QMessageBox::information(NULL, "Warnning", tr("射线关闭"));
						ui.labelStatus->setText("射线关闭");
						ui.labelXray->setText("射线关！");
						ui.spinBoxSetV->setEnabled(false);
						ui.spinBoxSetI->setEnabled(false);
						FlagOff = 0;
					}
					else if (FlagErrorClear == 1)//清除故障信息
					{
						QMessageBox::information(NULL, "提示", tr("故障信息清除"));
						ui.labelStatus->clear();
						FlagErrorClear = 0;
					}

				}
				//电压电流监测反馈
				else if (t[0] == 2 && t[5] == 59 && buf.size() == 9)
				{
					quint8 CSvalue = (0xff - ((abc[1] + abc[2] + abc[3] + abc[4] + 0x3B) & 0xff) + 1) & 0x7f | 0x40; //校验位数据计算
					int csc = CSvalue;
					if (t[6] == csc)//校验位正确
					{
						QString str1;
						QString Ivalue;
						if (FlagCurV == 1)
						{
							for (int i = 1; i < 5; i++)
							{
								char c = (quint8)abc[i];//ASCII码转换为字符
								Ivalue += c;//读取实际对应数据
							}
							ui.labelStatus->setText(Ivalue + "kV");
							FlagCurV = 0;
						}
						else if (FlagCurI == 1)
						{
							for (int i = 1; i < 5; i++)
							{
								char c = (quint8)abc[i];
								Ivalue += c;
							}
							ui.labelStatus->setText(Ivalue + "μA");
							FlagCurI = 0;
						}
						else if (FlagCurTemp == 1)
						{
							for (int i = 1; i < 5; i++)
							{
								char c = (quint8)abc[i];
								Ivalue += c;
							}
							ui.labelStatus->setText(Ivalue + "℃");
							FlagCurTemp = 0;
						}
					}

				}

				else if (FlagError == 1 && t[0] == 2 && t[1] == 48 && t[2] == 48 && t[4] == 59 && buf.size() == 8)
				{
					QString str1;
					if (t[3] == 48 && t[5] == 117)
					{
						ui.labelStatus->setText("无故障");
						FlagError = 0;//无故障，标志位置0
					}
					else if (t[3] == 49 && t[5] == 116)
					{
						ui.labelStatus->setText("过热");
					}
					else if (t[3] == 50 && t[5] == 115)
					{
						ui.labelStatus->setText("ARC故障");
					}
					else if (t[3] == 51 && t[5] == 114)
					{
						ui.labelStatus->setText("过流");
					}
					else if (t[3] == 52 && t[5] == 113)
					{
						ui.labelStatus->setText("欠流");
					}
					else if (t[3] == 53 && t[5] == 112)
					{
						ui.labelStatus->setText("欠压");
					}
					else if (t[3] == 54 && t[5] == 111)
					{
						ui.labelStatus->setText("过压");
					}
				}
				else
				{
					FlagSetV = 0;
					FlagSetI = 0;
					FlagCurV = 0;
					FlagCurI = 0;
					FlagCurTemp = 0;
					FlagOn = 0;
					FlagOff = 0;
					FlagStatus = 0;
					FlagErrorClear = 0;
					FlagError = 0;
				}

			}
			buf.clear();
		}
	}
	buf_temp.clear();
}

void TubeWidget::on_btnConnectTube_clicked(){
	//串口开关
	QString m = ui.btnConnectTube->text();
	QString t = tr("连接球管");
	if (ui.btnConnectTube->text() == t)
	{
		serialPort = new QSerialPort;
		//设置串口名
		serialPort->setPortName(ui.comboBoxConnect->currentText());
		//打开串口，读写
		serialPort->open(QIODevice::ReadWrite);
		//设置连接协议
		serialPort->setBaudRate(QSerialPort::Baud9600);  //波特率9600
		serialPort->setDataBits(QSerialPort::Data8);     //数据位8
		serialPort->setParity(QSerialPort::EvenParity);    //偶校验
		serialPort->setStopBits(QSerialPort::OneStop);   //停止位1
		serialPort->setFlowControl(QSerialPort::NoFlowControl);  //无控制
		//开启设置菜单使能
		ui.comboBoxConnect->setEnabled(false);
		ui.btnConnectTube->setText(tr("断开连接"));
		ui.btnXrayOn->setEnabled(true);
		ui.btnXrayOff->setEnabled(true);
		ui.btnGetV->setEnabled(true);
		ui.btnGetI->setEnabled(true);
		ui.btnGetT->setEnabled(true);
		ui.btnGetErr->setEnabled(true);
		ui.btnClearErr->setEnabled(true);

		//连接读取数据槽函数
		QObject::connect(serialPort, &QSerialPort::readyRead, this, &TubeWidget::ReadData);
	}
	else
	{
		//关闭串口
		serialPort->clear();
		serialPort->close();
		serialPort->deleteLater();
		//关闭设置使能
		ui.comboBoxConnect->setEnabled(true);
		ui.btnConnectTube->setText(tr("连接球管"));
		ui.btnXrayOn->setEnabled(false);
		ui.btnXrayOff->setEnabled(false);
		ui.btnGetV->setEnabled(false);
		ui.btnGetI->setEnabled(false);
		ui.btnGetT->setEnabled(false);
		ui.btnGetErr->setEnabled(false);
		ui.btnClearErr->setEnabled(false);
	}
}

void TubeWidget::on_btnXrayOn_clicked(){
	//开启射线
	FlagOn = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x45;
	cmdInt[2] = 0x4E;
	cmdInt[3] = 0x42;
	cmdInt[4] = 0x4C;
	cmdInt[5] = 0x20;
	cmdInt[6] = 0x31;
	cmdInt[7] = 0x3B;
	cmdInt[8] = 0x53;
	cmdInt[9] = 0x0D;
	cmdInt[10] = 0x0A;
	serialPort->write((char*)cmdInt, 11);
}

void TubeWidget::on_btnXrayOff_clicked(){
	//关闭射线
	FlagOff = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x45;
	cmdInt[2] = 0x4E;
	cmdInt[3] = 0x42;
	cmdInt[4] = 0x4C;
	cmdInt[5] = 0x20;
	cmdInt[6] = 0x30;
	cmdInt[7] = 0x3B;
	cmdInt[8] = 0x54;
	cmdInt[9] = 0x0D;
	cmdInt[10] = 0x0A;
	serialPort->write((char*)cmdInt, 11);
}

void TubeWidget::on_btnGetV_clicked(){
	//获取当前电压值，无附加值
	FlagCurV = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x56;
	cmdInt[2] = 0x4D;
	cmdInt[3] = 0x4F;
	cmdInt[4] = 0x4E;
	cmdInt[5] = 0x3B;
	cmdInt[6] = 0x45;
	cmdInt[7] = 0x0D;
	cmdInt[8] = 0x0A;
	serialPort->write((char*)cmdInt, 9);
}

void TubeWidget::on_btnGetI_clicked(){
	//获取当前电流值，无附加值
	FlagCurI = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x49;
	cmdInt[2] = 0x4D;
	cmdInt[3] = 0x4F;
	cmdInt[4] = 0x4E;
	cmdInt[5] = 0x3B;
	cmdInt[6] = 0x52;
	cmdInt[7] = 0x0D;
	cmdInt[8] = 0x0A;
	serialPort->write((char*)cmdInt, 9);
}

void TubeWidget::on_btnGetT_clicked(){
	//获取当前温度值，无附加值
	FlagCurTemp = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x54;
	cmdInt[2] = 0x4D;
	cmdInt[3] = 0x4F;
	cmdInt[4] = 0x4E;
	cmdInt[5] = 0x3B;
	cmdInt[6] = 0x47;
	cmdInt[7] = 0x0D;
	cmdInt[8] = 0x0A;
	serialPort->write((char*)cmdInt, 9);
}

void TubeWidget::on_btnGetErr_clicked(){
	//获取球管故障信息，无附加值
	FlagError = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x46;
	cmdInt[2] = 0x4C;
	cmdInt[3] = 0x54;
	cmdInt[4] = 0x3B;
	cmdInt[5] = 0x5F;
	cmdInt[6] = 0x0D;
	cmdInt[7] = 0x0A;
	serialPort->write((char*)cmdInt, 8);
}

void TubeWidget::on_btnClearErr_clicked(){
	//清楚球管故障信息，无附加值
	FlagErrorClear = 1;
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x43;
	cmdInt[2] = 0x4C;
	cmdInt[3] = 0x52;
	cmdInt[4] = 0x3B;
	cmdInt[5] = 0x64;
	cmdInt[6] = 0x0D;
	cmdInt[7] = 0x0A;
	serialPort->write((char*)cmdInt, 8);
}

void TubeWidget::setXrayV(int value){
	//设置球管电压
	FlagSetV = 1;
	quint16 CPValue = value * 10;;
	char SetTubeValue[4];
	SetTubeValue[3] = DecToHex((CPValue / 1000) % 10);
	SetTubeValue[2] = DecToHex((CPValue / 100) % 10);
	SetTubeValue[1] = DecToHex((CPValue / 10) % 10);
	SetTubeValue[0] = DecToHex(CPValue % 10);
	//求解校验位
	quint16 CSvalue = 0xff - ((SetTubeValue[3] + SetTubeValue[2] + SetTubeValue[1] + SetTubeValue[0] + 0x56 + 0x52 + 0x45 + 0x46 + 0x20 + 0x3B) & 0xff) + 1;//数据项求和，保留八位取补码
	//设置电压数据
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x56;
	cmdInt[2] = 0x52;
	cmdInt[3] = 0x45;
	cmdInt[4] = 0x46;
	cmdInt[5] = 0x20;
	cmdInt[6] = SetTubeValue[3];
	cmdInt[7] = SetTubeValue[2];
	cmdInt[8] = SetTubeValue[1];
	cmdInt[9] = SetTubeValue[0];
	cmdInt[10] = 0x3B;
	cmdInt[11] = CSvalue & 0x7f | 0x40;//补码第七位设0，第6位设1，求校验位
	cmdInt[12] = 0x0D;
	cmdInt[13] = 0x0A;

	serialPort->write((char*)cmdInt, 14);
}

void TubeWidget::setXrayI(int value){
	//设置球管电流
	FlagSetI = 1;
	quint16 CPValue = value * 10;
	char SetTubeValue[4];
	SetTubeValue[3] = DecToHex((CPValue / 1000) % 10);
	SetTubeValue[2] = DecToHex((CPValue / 100) % 10);
	SetTubeValue[1] = DecToHex((CPValue / 10) % 10);
	SetTubeValue[0] = DecToHex(CPValue % 10);
	//求校验位
	quint16 CSvalue = 0xff - ((SetTubeValue[3] + SetTubeValue[2] + SetTubeValue[1] + SetTubeValue[0] + 0x49 + 0x52 + 0x45 + 0x46 + 0x20 + 0x3B) & 0xff) + 1;
	//传输设置电流数据
	quint8 cmdInt[24];
	cmdInt[0] = 0x02;
	cmdInt[1] = 0x49;
	cmdInt[2] = 0x52;
	cmdInt[3] = 0x45;
	cmdInt[4] = 0x46;
	cmdInt[5] = 0x20;
	cmdInt[6] = SetTubeValue[3];
	cmdInt[7] = SetTubeValue[2];
	cmdInt[8] = SetTubeValue[1];
	cmdInt[9] = SetTubeValue[0];
	cmdInt[10] = 0x3B;
	cmdInt[11] = CSvalue & 0x7f | 0x40;
	cmdInt[12] = 0x0D;
	cmdInt[13] = 0x0A;

	serialPort->write((char*)cmdInt, 14);
}

