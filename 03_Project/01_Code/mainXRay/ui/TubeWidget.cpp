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
	//�ۺ�������
	connect(ui.spinBoxSetV, SIGNAL(valueChanged(int)), this, SLOT(setXrayV(int)));
	connect(ui.spinBoxSetI, SIGNAL(valueChanged(int)), this, SLOT(setXrayI(int)));
	//��ʼ���˵���������ʹ��
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
	//��ʼ����ܣ���ѯ����
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
	//������ܷ�������
	QByteArray buf_temp;
	quint8 abc[12];
	int t[12];
	int i = 0;
	buf_temp = serialPort->readAll();
	if (!buf_temp.isEmpty())
	{
		if (!buf_temp.contains("\n"))//�ж��Ƿ����ݶ���ֹ
		{
			buf.append(buf_temp);
		}
		else
		{
			buf.append(buf_temp);
			for (i = 0; i < buf.size(); i++)
			{
				abc[i] = buf[i];
				t[i] = abc[i];//�����������ڶԱ��ж�
			}
			if (buf.size() != 0)
			{
				//���÷���
				if (t[0] == 2 && t[1] == 59 && t[2] == 69 && buf.size() == 5)//��������Ϊ\0x02\0x3B\0x45\0x0D\0x0A
				{
					if (FlagSetV == 1)//��ѹ���÷���
					{
						ui.labelStatus->setText("���õ�ѹ�ɹ�");
						FlagSetV = 0;
					}
					else if (FlagSetI == 1)//�������÷���
					{
						ui.labelStatus->setText("���õ����ɹ�");
						FlagSetI = 0;
					}
					else if (FlagOn == 1)//�������߷���
					{
						QMessageBox::information(NULL, "Warnning", tr("���߿���"));
						ui.labelStatus->setText("���߿���");
						ui.labelXray->setText("���߿���");
						ui.spinBoxSetV->setEnabled(true);
						ui.spinBoxSetI->setEnabled(true);
						FlagOn = 0;
					}
					else if (FlagOff == 1)//�ر����߷���
					{
						QMessageBox::information(NULL, "Warnning", tr("���߹ر�"));
						ui.labelStatus->setText("���߹ر�");
						ui.labelXray->setText("���߹أ�");
						ui.spinBoxSetV->setEnabled(false);
						ui.spinBoxSetI->setEnabled(false);
						FlagOff = 0;
					}
					else if (FlagErrorClear == 1)//���������Ϣ
					{
						QMessageBox::information(NULL, "��ʾ", tr("������Ϣ���"));
						ui.labelStatus->clear();
						FlagErrorClear = 0;
					}

				}
				//��ѹ������ⷴ��
				else if (t[0] == 2 && t[5] == 59 && buf.size() == 9)
				{
					quint8 CSvalue = (0xff - ((abc[1] + abc[2] + abc[3] + abc[4] + 0x3B) & 0xff) + 1) & 0x7f | 0x40; //У��λ���ݼ���
					int csc = CSvalue;
					if (t[6] == csc)//У��λ��ȷ
					{
						QString str1;
						QString Ivalue;
						if (FlagCurV == 1)
						{
							for (int i = 1; i < 5; i++)
							{
								char c = (quint8)abc[i];//ASCII��ת��Ϊ�ַ�
								Ivalue += c;//��ȡʵ�ʶ�Ӧ����
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
							ui.labelStatus->setText(Ivalue + "��A");
							FlagCurI = 0;
						}
						else if (FlagCurTemp == 1)
						{
							for (int i = 1; i < 5; i++)
							{
								char c = (quint8)abc[i];
								Ivalue += c;
							}
							ui.labelStatus->setText(Ivalue + "��");
							FlagCurTemp = 0;
						}
					}

				}

				else if (FlagError == 1 && t[0] == 2 && t[1] == 48 && t[2] == 48 && t[4] == 59 && buf.size() == 8)
				{
					QString str1;
					if (t[3] == 48 && t[5] == 117)
					{
						ui.labelStatus->setText("�޹���");
						FlagError = 0;//�޹��ϣ���־λ��0
					}
					else if (t[3] == 49 && t[5] == 116)
					{
						ui.labelStatus->setText("����");
					}
					else if (t[3] == 50 && t[5] == 115)
					{
						ui.labelStatus->setText("ARC����");
					}
					else if (t[3] == 51 && t[5] == 114)
					{
						ui.labelStatus->setText("����");
					}
					else if (t[3] == 52 && t[5] == 113)
					{
						ui.labelStatus->setText("Ƿ��");
					}
					else if (t[3] == 53 && t[5] == 112)
					{
						ui.labelStatus->setText("Ƿѹ");
					}
					else if (t[3] == 54 && t[5] == 111)
					{
						ui.labelStatus->setText("��ѹ");
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
	//���ڿ���
	QString m = ui.btnConnectTube->text();
	QString t = tr("�������");
	if (ui.btnConnectTube->text() == t)
	{
		serialPort = new QSerialPort;
		//���ô�����
		serialPort->setPortName(ui.comboBoxConnect->currentText());
		//�򿪴��ڣ���д
		serialPort->open(QIODevice::ReadWrite);
		//��������Э��
		serialPort->setBaudRate(QSerialPort::Baud9600);  //������9600
		serialPort->setDataBits(QSerialPort::Data8);     //����λ8
		serialPort->setParity(QSerialPort::EvenParity);    //żУ��
		serialPort->setStopBits(QSerialPort::OneStop);   //ֹͣλ1
		serialPort->setFlowControl(QSerialPort::NoFlowControl);  //�޿���
		//�������ò˵�ʹ��
		ui.comboBoxConnect->setEnabled(false);
		ui.btnConnectTube->setText(tr("�Ͽ�����"));
		ui.btnXrayOn->setEnabled(true);
		ui.btnXrayOff->setEnabled(true);
		ui.btnGetV->setEnabled(true);
		ui.btnGetI->setEnabled(true);
		ui.btnGetT->setEnabled(true);
		ui.btnGetErr->setEnabled(true);
		ui.btnClearErr->setEnabled(true);

		//���Ӷ�ȡ���ݲۺ���
		QObject::connect(serialPort, &QSerialPort::readyRead, this, &TubeWidget::ReadData);
	}
	else
	{
		//�رմ���
		serialPort->clear();
		serialPort->close();
		serialPort->deleteLater();
		//�ر�����ʹ��
		ui.comboBoxConnect->setEnabled(true);
		ui.btnConnectTube->setText(tr("�������"));
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
	//��������
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
	//�ر�����
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
	//��ȡ��ǰ��ѹֵ���޸���ֵ
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
	//��ȡ��ǰ����ֵ���޸���ֵ
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
	//��ȡ��ǰ�¶�ֵ���޸���ֵ
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
	//��ȡ��ܹ�����Ϣ���޸���ֵ
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
	//�����ܹ�����Ϣ���޸���ֵ
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
	//������ܵ�ѹ
	FlagSetV = 1;
	quint16 CPValue = value * 10;;
	char SetTubeValue[4];
	SetTubeValue[3] = DecToHex((CPValue / 1000) % 10);
	SetTubeValue[2] = DecToHex((CPValue / 100) % 10);
	SetTubeValue[1] = DecToHex((CPValue / 10) % 10);
	SetTubeValue[0] = DecToHex(CPValue % 10);
	//���У��λ
	quint16 CSvalue = 0xff - ((SetTubeValue[3] + SetTubeValue[2] + SetTubeValue[1] + SetTubeValue[0] + 0x56 + 0x52 + 0x45 + 0x46 + 0x20 + 0x3B) & 0xff) + 1;//��������ͣ�������λȡ����
	//���õ�ѹ����
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
	cmdInt[11] = CSvalue & 0x7f | 0x40;//�������λ��0����6λ��1����У��λ
	cmdInt[12] = 0x0D;
	cmdInt[13] = 0x0A;

	serialPort->write((char*)cmdInt, 14);
}

void TubeWidget::setXrayI(int value){
	//������ܵ���
	FlagSetI = 1;
	quint16 CPValue = value * 10;
	char SetTubeValue[4];
	SetTubeValue[3] = DecToHex((CPValue / 1000) % 10);
	SetTubeValue[2] = DecToHex((CPValue / 100) % 10);
	SetTubeValue[1] = DecToHex((CPValue / 10) % 10);
	SetTubeValue[0] = DecToHex(CPValue % 10);
	//��У��λ
	quint16 CSvalue = 0xff - ((SetTubeValue[3] + SetTubeValue[2] + SetTubeValue[1] + SetTubeValue[0] + 0x49 + 0x52 + 0x45 + 0x46 + 0x20 + 0x3B) & 0xff) + 1;
	//�������õ�������
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

