#include "MeasureWidget.h"
#include <QDebug>
#include <QFileDialog>
MeasureWidget::MeasureWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	m_bllDataFlow = BllDataFlow::instance();
	m_enable = false;
	m_state = 0;
	ui.enableBtn->setIcon(QIcon(QPixmap("image/grey.ico")));
	ui.enableBtn->setIconSize(QSize(32, 32));
	connect(ui.selectCb, SIGNAL(currentIndexChanged(int)), this, SLOT(currentIndexChangedSlot(int)));
}

MeasureWidget::~MeasureWidget()
{

}

void MeasureWidget::on_openBtn_clicked()
{
	//QString str = "打开文件";
	//QString filepath = QFileDialog::getOpenFileName(this, str);
	//QByteArray cdata = filepath.toLocal8Bit();
	//m_src = imread(string(cdata), CV_LOAD_IMAGE_UNCHANGED);
	//quint16* img = BllData::getImg();
	//for (int i = 0; i < m_src.rows; i++)
	//{
	//	for (int j = 0; j < m_src.cols; j++)
	//	{
	//		int data = m_src.at<ushort>(i, j);
	//		img[i * 1536 + j] = data;
	//	}
	//}

	//m_bll->readyPaintImg();

}


void MeasureWidget::on_cancelBtn_clicked()
{
	m_bllDataFlow->cancelMeasureShape();
}
void MeasureWidget::on_clearBtn_clicked()
{
	m_bllDataFlow->clearShape();
}

void MeasureWidget::currentIndexChangedSlot(int index)
{

	m_state = index;
	on_enableBtn_clicked();
}
void MeasureWidget::on_enableBtn_clicked()
{

	if (!m_enable)
	{
		ui.enableBtn->setIcon(QIcon(QPixmap("image/green.ico")));
		ui.enableBtn->setIconSize(QSize(32, 32));
		switch (m_state)
		{
		case 0:
			//qDebug() << "nothing==";
			m_bllDataFlow->setDisenable();
			break;
		case 1:
			//qDebug() << "1==";
			m_bllDataFlow->setLineAngleEnable();
			break;
		case 2:
			//qDebug() << "2==";
			m_bllDataFlow->setperdenEnable();
			break;
		case 3:
			//qDebug() << "3==";
			m_bllDataFlow->setperpenEnable();
			break;
		case 4:
			//qDebug() << "5==";
			m_bllDataFlow->setpixEnable();
			break;
		default:
			break;
		}
		ui.selectCb->setEnabled(false);

	}
	else
	{
		ui.enableBtn->setIcon(QIcon(QPixmap("image/grey.ico")));
		ui.enableBtn->setIconSize(QSize(32, 32));
		ui.selectCb->setEnabled(true);

	}
	m_enable = !m_enable;

}