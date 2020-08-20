#include "MenuWidget.h"
#include <QPainter>
#include <QMenu>
#include <qt_windows.h>
#include <QProcess>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <qpushbutton.h>
#include <QHBoxLayout>
#include <QFileDialog>
#include "Global.h"
using namespace cv;
MenuWidget::MenuWidget(QWidget *parent)
	: QWidget(parent)
{
	count = 0;
	ui.setupUi(this);
	//m_blldetector = BllDetector::instance();

	//菜单栏
	m_menuBar = new QMenuBar();

	//文件菜单
	
	QMenu* m_fileMenu = new QMenu(tr("文件(&F)"));

	m_menuBar->addMenu(m_fileMenu);

	
	//m_fileMenu->resize(75, 30);
	

	//m_fileMenu->setIcon(QIcon("image/file.png"));
	//m_fileMenu->setTitle("file");
	m_openQct = m_fileMenu->addAction(tr("打开(&O)"));

	m_closeQct = m_fileMenu->addAction(tr("关闭(&C)"));
	m_saveQct = m_fileMenu->addAction(tr("保存(&S)"));
	m_exitQct = m_fileMenu->addAction(tr("退出(&E)"));
	QObject::connect(m_openQct, &QAction::triggered, this, &MenuWidget::openActionSlot);

	//视图菜单
	//QMenu* m_viewMenu = m_menuBar->addMenu(tr("视图(&V)"));
	//QAction* m_2DQct = m_viewMenu->addAction(tr("2D(&N)"));
	//QAction* m_3DQct = m_viewMenu->addAction(tr("3D(&K)"));
	//QAction* m_toolBarQct = m_viewMenu->addAction(tr("工具栏(&G)"));
	//m_toolBarQct->setCheckable(true);
	////m_toolBarQct->setVisible(false);
	//connect(m_toolBarQct, SIGNAL(toggled(bool)), this, SLOT(setToolBarVisible(bool)));

	//工具菜单
	QMenu* m_toolMenu = m_menuBar->addMenu(tr("工具(&T)"));
	m_adjustQct = m_toolMenu->addAction(tr("曲线图调整(&A)"));
	m_adjustQct->setCheckable(true);
	//m_adjust = 0;
	QObject::connect(m_adjustQct, &QAction::triggered, this, &MenuWidget::adjustActionSlot);
	//m_countQct = m_toolMenu->addAction(tr("自动点数(&Z)"));
	//m_countQct->setCheckable(true);
	//QObject::connect(m_countQct, &QAction::triggered, this, &MenuWidget::autoCountQctSlot);
	//motorControlSlot
	/*m_motorQct = m_toolMenu->addAction(tr("电机控制(&A)"));
	m_motorQct->setCheckable(true);
	QObject::connect(m_motorQct, &QAction::triggered, this, &MenuWidget::motorControlSlot);*/
	//帮助菜单
	QMenu* m_helpMenu = m_menuBar->addMenu(tr("帮助(&H)"));
	m_helpQct = m_helpMenu->addAction(tr("关于软件(&G)"));
	m_helpQct->setCheckable(true);
	QObject::connect(m_helpQct, &QAction::triggered, this, &MenuWidget::helpActionSlot);

	ui.horizontalLayout->addWidget(m_menuBar);


	m_bllDataFlow = BllDataFlow::instance();
	m_bll = BllDetectorKZ::instance();
	
}

MenuWidget::~MenuWidget()
{

}
void MenuWidget::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void MenuWidget::setToolBarVisible(bool visible)
{
	emit toolBarVisible(visible);
}

void MenuWidget::helpActionSlot(bool visiable)
{

}

void MenuWidget::openActionSlot(bool visiable)
{
	if (!visiable)
	{
		QString str = "打开文件";
		QString filepath = QFileDialog::getOpenFileName(this, str);

		qDebug() << "path--------------" << filepath;

		QByteArray cdata = filepath.toLocal8Bit();

		QStringList listfile = filepath.split('.');
		QString hou = listfile.takeLast();

		if (hou == "tif")
		{
			srcimg = imread(string(cdata), CV_LOAD_IMAGE_UNCHANGED);

		}
		else
		{
			return;
		}



		BllDataFlow::setImageSize(srcimg.rows, srcimg.rows);
		BllDetectorKZ::setImageSize(srcimg.rows, srcimg.rows);
		BllDetectorKZ::setIfSizeChange();
		quint16* img = BllDetectorKZ::getSingleImg();

	
		int mindata = 20000;
		int maxdata = 0;
		
		for (int i = 0; i<srcimg.rows; i++)
		{
			for (int j = 0; j<srcimg.cols; j++)
			{
				int data = srcimg.at<ushort>(i, j);
				img[i * srcimg.rows + j] = data;
				if (data>maxdata)
				{
					maxdata = data;
				}
				if (data < mindata)
				{
					mindata = data;
				}
			}
		}
		qDebug() << "----this is srcimg rows and cols------>" << srcimg.rows << ";;" << srcimg.cols;
		m_bll->returnImg(mindata,maxdata);
		m_bll->updateSize(srcimg.rows);
		m_bllDataFlow->updateGrayImg();
		m_bllDataFlow->readyGrayCurve();
		m_bll->resetCurve();
		
	
	}
}

void MenuWidget::saveActionSlot(bool visiable)
{

}

void MenuWidget::adjustActionSlot(bool visiable)
{
	if (visiable)
	{
		count++;
		m_bllDataFlow->openAdjust(count);
	}
	else
	{
		m_bllDataFlow->closeAdjust();
	}

}

void MenuWidget::countActionSlot(bool visiable)
{

}
void MenuWidget::motorControlSlot(bool visiable){

}


