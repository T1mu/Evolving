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
	ui.labTitle->setText("X射线无损检测系统");
	ui.labTitle->setFont(QFont("Microsoft Yahei", 20));
	this->setWindowTitle(ui.labTitle->text());



	QSize icoSize(32, 32);
	int icoWidth = 85;
	int icoHeight = 85;
	//设置顶部导航按钮
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
	//此段代码是为了解决切换窗口后按钮点击不显示的bug（加入VTKwidget后出现），此bug只有切换窗口大小后才能解决，因此采用如下代码解决。
	if (event->type() == QEvent::WindowStateChange)
	{
		QRect location_temp;
		location_temp = this->geometry();
		if (location_temp == qApp->desktop()->availableGeometry())//如果目前是最大化，则最小化后最大化
		{
			this->setGeometry(location);
		}
		else
		{
			this->setGeometry(qApp->desktop()->availableGeometry());//如果目前是最小化，则最大化后最小化
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
		if (name == "本地文件")
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
	if (name == "主界面")
	{
		m_bllDataFlow->sendTwoDim();
	}
	if (name == "三维视图")
	{
		m_bllDataFlow->sendThreeDim();
		qDebug() << "点击了三维视图";
	}
	if (name == "测量工具")
	{
		m_bllDataFlow->sendMeasure();
		qDebug() << "点击了测量工具";
	}
	if (name == "标注工具")
	{
		m_bllDataFlow->sendPaint();
		qDebug() << "点击了标注工具";
	}
	if (name == "灰度调整")
	{
		m_bllDataFlow->sendAdjust();
		qDebug() << "点击了灰度调整";
	}
	if (name == "硬件控制")
	{
		m_bllDataFlow->sendHardware();
		qDebug() << "点击了硬件控制";
	}
	if (name == "本地文件")
	{
		m_bllDataFlow->sendFile();
		qDebug() << "点击了本地文件";
	}
	if (name == "数据管理")
	{
		m_bllDataFlow->sendData();
		qDebug() << "点击了数据管理";
	}
}

