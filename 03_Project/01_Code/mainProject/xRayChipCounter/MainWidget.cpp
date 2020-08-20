#include "MainWidget.h"
//#include "Library/IconHelper.h"
//#include "Library/MyHelper.h"
#include "quiwidget.h"
MainWidget::MainWidget(QWidget *parent) :
QDialog(parent)
{
	ui.setupUi(this);

	this->max = false;
	this->location = this->geometry();
	this->setProperty("form", true);
	this->setProperty("canMove", true);
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint | Qt::WindowMinMaxButtonsHint);

	IconHelper::Instance()->setIcon(ui.labIco, QChar(0xF0e7), 30);
	IconHelper::Instance()->setIcon(ui.btnMenu_Min, QChar(0xF068));
	IconHelper::Instance()->setIcon(ui.btnMenu_Max, QChar(0xF067));
	IconHelper::Instance()->setIcon(ui.btnMenu_Close, QChar(0xF00d));

	ui.widgetTitle->setProperty("form", "title");
	ui.widgetTop->setProperty("nav", "top");
	ui.labTitle->setText("X����������ϵͳ");
	ui.labTitle->setFont(QFont("Microsoft Yahei", 20));
	this->setWindowTitle(ui.labTitle->text());



	QSize icoSize(32, 32);
	int icoWidth = 85;
	int icoHeight = 85;
	//���ö���������ť
	QList<QToolButton *> tbtns = ui.widgetTop->findChildren<QToolButton *>();
	foreach(QToolButton *btn, tbtns)
	{
		btn->setIconSize(icoSize);
		btn->setMinimumWidth(icoWidth);
		btn->setMinimumHeight(icoHeight);
		btn->setCheckable(true);
		connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
	}


	ui.mainBtn->setIcon(QIcon("./icon/bolt.png"));
	ui.threeDimBtn->setIcon(QIcon("./icon/frames.png"));
	ui.measureBtn->setIcon(QIcon("./icon/rulertriangle.png"));
	ui.paintBtn->setIcon(QIcon("./icon/brush.png"));
	ui.curveBtn->setIcon(QIcon("./icon/contrast.png"));
	ui.hardwareBtn->setIcon(QIcon("./icon/tools.png"));
	ui.fileBtn->setIcon(QIcon("./icon/folder.png"));
	ui.dataBtn->setIcon(QIcon("./icon/compose.png"));
	
	m_bllDataFlow = BllDataFlow::instance();

}

MainWidget::~MainWidget()
{
}
void MainWidget::changeEvent(QEvent* event)
{
	//�˶δ�����Ϊ�˽���л����ں�ť�������ʾ��bug������VTKwidget����֣�����bugֻ���л����ڴ�С����ܽ������˲������´�������
	if (event->type() == QEvent::WindowStateChange)
	{
		QRect location_temp;
		location_temp = this->geometry();
		if (location_temp == qApp->desktop()->availableGeometry())//���Ŀǰ����󻯣�����С�������
		{
			this->setGeometry(location);
		}
		else
		{
			this->setGeometry(qApp->desktop()->availableGeometry());//���Ŀǰ����С��������󻯺���С��
		}		
		this->setGeometry(location_temp);	
	}
}

void MainWidget::on_btnMenu_Min_clicked()
{
	showMinimized();
}

void MainWidget::on_btnMenu_Max_clicked()
{
	if (max)
	{
		this->setGeometry(location);
		this->setProperty("canMove", true);
	}
	else
	{
		location = this->geometry();
		this->setGeometry(qApp->desktop()->availableGeometry());
		this->setProperty("canMove", false);
	}

	max = !max;
}

void MainWidget::on_btnMenu_Close_clicked()
{
	close();
}


void MainWidget::buttonClick()
{
	QToolButton *b = (QToolButton *)sender();
	QString name = b->text();

	QList<QToolButton *> btns = ui.widgetTop->findChildren<QToolButton *>();
	foreach(QToolButton *btn, btns)
	{	
		if (name == "�����ļ�")
		{
			m_bllDataFlow->sendFile();
			b->setChecked(false);
			return;
		}
		if (btn == b)
		{
			btn->setChecked(true);	
		}
		else
		{
			btn->setChecked(false);
		}
	}
	if (name == "������")
	{
		m_bllDataFlow->sendTwoDim();
	}
	if (name == "��ά��ͼ")
	{
		m_bllDataFlow->sendThreeDim();
		qDebug() << "�������ά��ͼ";
	}
	if (name == "��������")
	{
		m_bllDataFlow->sendMeasure();
		qDebug() << "����˲�������";
	}
	if (name == "��ע����")
	{
		m_bllDataFlow->sendPaint();
		qDebug() << "����˱�ע����";
	}
	if (name == "�Ҷȵ���")
	{
		m_bllDataFlow->sendAdjust();
		qDebug() << "����˻Ҷȵ���";
	}
	if (name == "Ӳ������")
	{
		m_bllDataFlow->sendHardware();
		qDebug() << "�����Ӳ������";
	}
	if (name == "�����ļ�")
	{
		m_bllDataFlow->sendFile();
		qDebug() << "����˱����ļ�";
	}
	if (name == "���ݹ���")
	{
		m_bllDataFlow->sendData();
		qDebug() << "��������ݹ���";
	}
}

