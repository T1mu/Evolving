#include "MainWidgetDisplay.h"

MainWidgetDisplay::MainWidgetDisplay(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	m_bllDataFlow = BllDataFlow::instance();
	m_bll = BllDetectorKZ::instance();
	
	ui.widget_Curve->setVisible(false);
	ui.widget_Hardware->setVisible(false);
	ui.widget_Measure->setVisible(false);
	ui.widget_Mark->setVisible(false);
	ui.widget_3DView->setHidden(true);

	connect(m_bllDataFlow, SIGNAL(twoDimSignal()), this, SLOT(receiveTwoDimSlot()));
	connect(m_bllDataFlow, SIGNAL(threeDimSignal()), this, SLOT(receiveThreeDimSlot()));
	connect(m_bllDataFlow, SIGNAL(measureSignal()), this, SLOT(receiveMeasureSlot()));
	connect(m_bllDataFlow, SIGNAL(paintSignal()), this, SLOT(receivePaintSlot()));
	connect(m_bllDataFlow, SIGNAL(adjustSignal()), this, SLOT(receiveAdjustSlot()));
	connect(m_bllDataFlow, SIGNAL(hardwareSignal()), this, SLOT(receiveHardwareSlot()));
	connect(m_bllDataFlow, SIGNAL(fileSignal()), this, SLOT(receiveFileSlot()));
	connect(m_bllDataFlow, SIGNAL(dataSignal()), this, SLOT(receiveDataSlot()));

}

MainWidgetDisplay::~MainWidgetDisplay()
{

}

//显示界面
void MainWidgetDisplay::receiveTwoDimSlot()
{	
	ui.widget_3DView->setVisible(false);
	ui.widget_2DView->setVisible(true);
}

void MainWidgetDisplay::receiveThreeDimSlot()
{
	ui.widget_2DView->setVisible(false);
	ui.widget_3DView->setVisible(true);
}


//测量工具界面
void MainWidgetDisplay::receiveMeasureSlot()
{
	ui.widget_File->setVisible(false);
	ui.widget_Hardware->setVisible(false);
	ui.widget_Curve->setVisible(false);
	ui.widget_Mark->setVisible(false);

	ui.widget_Measure->setVisible(true);

}

//标注工具界面
void MainWidgetDisplay::receivePaintSlot()
{
	ui.widget_File->setVisible(false);
	ui.widget_Hardware->setVisible(false);
	ui.widget_Curve->setVisible(false);
	ui.widget_Measure->setVisible(false);

	ui.widget_Mark->setVisible(true);

}

void MainWidgetDisplay::receiveAdjustSlot()
{
	ui.widget_File->setVisible(false);
	ui.widget_Hardware->setVisible(false);
	ui.widget_Measure->setVisible(false);
	ui.widget_Mark->setVisible(false);

	ui.widget_Curve->setVisible(true);
}

void MainWidgetDisplay::receiveHardwareSlot()
{
	ui.widget_File->setVisible(false);
	ui.widget_Curve->setVisible(false);
	ui.widget_Measure->setVisible(false);
	ui.widget_Mark->setVisible(false);

	ui.widget_Hardware->setVisible(true);
}

void MainWidgetDisplay::receiveDataSlot()
{
	ui.widget_Curve->setVisible(false);
	ui.widget_Hardware->setVisible(false);
	ui.widget_Measure->setVisible(false);
	ui.widget_Mark->setVisible(false);

	ui.widget_File->setVisible(true);
}

void MainWidgetDisplay::receiveFileSlot()
{
	QString str = "打开文件";
	QString filepath = QFileDialog::getOpenFileName(this, str, "F:", tr("标签图像文件格式(*tif);;""JPEG(*jpg);;""医学图像(*dcm);;""原始数据(*raw)"));

	qDebug() << "path--------------" << filepath;

	QByteArray cdata = filepath.toLocal8Bit();

	QStringList listfile = filepath.split('.');
	QString lastName = listfile.takeLast();

	if (lastName == "tif")
	{
		srcimg = imread(string(cdata), CV_LOAD_IMAGE_UNCHANGED);
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
		m_bll->returnImg(mindata, maxdata);
		m_bll->updateSize(srcimg.rows);
		m_bllDataFlow->updateGrayImg();
		m_bllDataFlow->readyGrayCurve();
		m_bll->readyAdjust(1);
		m_bll->resetCurve();

	}
	else if (lastName == "jpg")
	{
		srcimg = imread(string(cdata), CV_LOAD_IMAGE_UNCHANGED);
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
		m_bll->returnImg(mindata, maxdata);
		m_bll->updateSize(srcimg.rows);
		m_bllDataFlow->updateGrayImg();
		m_bllDataFlow->readyGrayCurve();
		m_bll->readyAdjust(1);
		m_bll->resetCurve();
	}
	else if (lastName == "png")
	{
		return;
	}
	else if (lastName == "dcm")
	{
		return;
	}
	else if (lastName == "dcm")
	{
		return;
	}
}