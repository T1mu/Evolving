#include "TubeWidget.h"
#include "quiwidget.h"
TubeWidget::TubeWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	checkSerialPort();
	m_bllDataFlow = BllDataFlow::instance();
	img->load(filename2);
	ui.label->setPixmap(QPixmap::fromImage(*img));
	img2->load(filename3);
	ui.connectBtn->setIcon(QPixmap::fromImage(*img2));
	ui.connectBtn->setStyleSheet("background:rgb(255,255,255)");
	serialPort = TubeWidget::m_serialport();
	connectFlag = 0;

}

QSerialPort* TubeWidget::serialPort = 0;


TubeWidget::~TubeWidget()
{

}





void TubeWidget::on_clearBtn_clicked(){
	//ui.statusEdit->clear();
}

void TubeWidget::checkSerialPort(){

	ui.connectComboBox->clear(); 
	foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		QSerialPort serialPort;
		serialPort.setPort(info);
		if (serialPort.open(QIODevice::ReadWrite))
		{
			ui.connectComboBox->addItem(info.portName());
			serialPort.close();			
		}
	}
}

void TubeWidget::on_connectBtn_clicked(){

	if (ifCon)
	{
		//���ô�����
		serialPort->setPortName(ui.connectComboBox->currentText());
		//�򿪴���
		serialPort->open(QIODevice::ReadWrite);
		//���ò�����
		serialPort->setBaudRate(QSerialPort::Baud9600);  //������
		serialPort->setDataBits(QSerialPort::Data8);     //����λ
		serialPort->setParity(QSerialPort::NoParity);    //����żУ��
		serialPort->setStopBits(QSerialPort::OneStop);   //��ֹͣλ
		serialPort->setFlowControl(QSerialPort::NoFlowControl);  //�޿���
		//�ر����ò˵�ʹ��	
		ifCon = false;
		ui.connectComboBox->setEnabled(false);
		ui.statusEdit->append(QStringLiteral("�򿪴��ڳɹ�"));
		img2->load(filename4);
		ui.connectBtn->setIcon(QPixmap::fromImage(*img2));

		//�����źŲ�
		QObject::connect(serialPort, &QSerialPort::readyRead, this, &TubeWidget::Read_Data);
		connectFlag = 1;
		m_bllDataFlow->sendSerial(serialPort, connectFlag);
	}
	else if (!ifCon)
	{
		//�رմ���
		serialPort->clear();
		serialPort->close();
		//serialPort->deleteLater();
		//�ָ�����ʹ��	
		ifCon = true;
		ui.connectComboBox->setEnabled(true);
		ui.statusEdit->append(QStringLiteral("�رմ��ڳɹ�"));
		img2->load(filename3);
		ui.connectBtn->setIcon(QPixmap::fromImage(*img2));
		connectFlag = 0;
	}


}

void TubeWidget::Read_Data(){
	QByteArray bufAccept;//���մ��ڷ���������
	quint8 bufIf[24];
	int i = 0;
	bufAccept = serialPort->readAll();
	if (!bufAccept.isEmpty())
	{
		if (!bufAccept.contains("\r"))//�ж��Ƿ����������
		{
			bufTemp.append(bufAccept);
		}
		else
		{
			bufTemp.append(bufAccept);
			for (i = 0; i < bufTemp.size(); i++)
			{
				bufIf[i] = bufTemp[i];
			}
			if (bufTemp.size() != 0)
			{

				//��ѹֵ
				if (bufIf[0] == 0x50 && bufIf[1] == 0x48 && bufIf[2] == 0x56 && bufIf[3] == 0x20)
				{
					if (lsize == 3){
						lsize = 0;
						buf2.clear();
						buf2[0] = bufTemp[4];
						buf2[1] = bufTemp[5];
						ui.voltageEdit->setText(QString(buf2));
					}
					else if (lsize == 4){
						lsize = 0;
						buf1.clear();
						buf1[0] = bufTemp[4];
						buf1[1] = bufTemp[5];
						buf1[2] = bufTemp[6];
						ui.voltageEdit->setText(QString(buf1));
					}
				}
				//����ֵ
				else if (bufIf[0] == 0x50 && bufIf[1] == 0x43 && bufIf[2] == 0x55 && bufIf[3] == 0x20)
				{
					buf1.clear();
					buf1[0] = bufTemp[4];
					buf1[1] = bufTemp[5];
					buf1[2] = bufTemp[6];

					ui.currentEdit->setText(QString(buf1));
				}


			}
			bufTemp.clear();
		}
	}
	bufAccept.clear();
}


void TubeWidget::on_modeSetBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("�������Ӵ��ڣ�");
		return;
	}
	quint8 cmdInt[9];
	cmdInt[0] = 0x43;
	cmdInt[1] = 0x46;
	//cmdInt[2] = 0x53;
	//cmdInt[3] = 0x20;
	cmdInt[3] = 0x0D;

	switch (ui.modeComboBox->currentIndex()){
	case 0:
		cmdInt[2] = 0x4C;
		serialPort->write((char*)cmdInt, 4);
		ui.statusEdit->append("������Ϊ�󽹵�ģʽ");
		break;
	case 1:
		cmdInt[2] = 0x4D;
		serialPort->write((char*)cmdInt, 4);
		ui.statusEdit->append("������Ϊ�н���ģʽ");
		break;
	case 2:
		cmdInt[2] = 0x53;
		serialPort->write((char*)cmdInt, 4);
		ui.statusEdit->append("������ΪС����ģʽ");
		break;
	}
}

void TubeWidget::on_openXRayBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("�������Ӵ��ڣ�");
		return;
	}
	//���õ�ѹ
	int setVoltageValue = ui.voltageSpinBox->value() * 10;
	//setV(ui.voltageSpinBox->value());
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
		lsize = 3;
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
		lsize = 4;
		cmdIntV[4] = voltageValue[3];
		cmdIntV[5] = voltageValue[2];
		cmdIntV[6] = voltageValue[1];
		cmdIntV[7] = voltageValue[0];
		cmdIntV[8] = 0x0D;
		serialPort->write((char*)cmdIntV, 9);
	}
	//ui.statusEdit->setText(QStringLiteral("���õ�ѹ�ɹ�"));


	//���õ���
	int setCurrentValue = ui.currentSpinBox->value();
	//setA(ui.currentSpinBox->value());
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
	//ui.statusEdit->setText(QStringLiteral("���õ����ɹ�"));
	m_bllDataFlow->sendVA(ui.voltageSpinBox->value(), ui.currentSpinBox->value());
	//�ع�
	quint8 cmdInt[9] = "\x58\x4F\x4E\x0D";
	serialPort->write((char*)cmdInt, 4);
	ui.openXRayBtn->setEnabled(false);
	ui.closeXRayBtn->setEnabled(true);
	img->load(filename1);
	ui.label->setPixmap(QPixmap::fromImage(*img));
	//ui.statusEdit->append(QStringLiteral("��ʼ�ع�"));
}

void TubeWidget::on_closeXRayBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("�������Ӵ��ڣ�");
		return;
	}
	quint8 cmdInt[9] = "\x58\x4F\x46\x0D";
	serialPort->write((char*)cmdInt, 4);
	ui.closeXRayBtn->setEnabled(false);
	ui.openXRayBtn->setEnabled(true);
	img->load(filename2);
	ui.label->setPixmap(QPixmap::fromImage(*img));
	//ui.statusEdit->append(QStringLiteral("ֹͣ�ع�"));
}

void TubeWidget::on_queryBtn_clicked(){
	if (!connectFlag)
	{
		QUIWidget::showMessageBoxError("�������Ӵ��ڣ�");
		return;
	}
	//��ѹ��ѯ
	quint8 cmdInt[9] = "\x53\x48\x56\x0D";
	serialPort->write((char*)cmdInt, 4);
	Sleep(1000);
	//������ѯ
	quint8 cmdInt1[9] = "\x53\x43\x55\x0D";
	serialPort->write((char*)cmdInt1, 4);
	ui.statusEdit->append(QStringLiteral("��ѯָ���ѷ���"));
}
