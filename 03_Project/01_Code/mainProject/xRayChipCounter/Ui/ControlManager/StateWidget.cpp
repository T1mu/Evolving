#include "StateWidget.h"

StateWidget::StateWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.opentubeBtn->setToolTip("kkkk");
	tubeopenEnable = false;
	doorstate = false;
	//m_blldetector = BllDetector::instance();
	m_blldata = BllDataFlow::instance();
	connect(m_blldata, SIGNAL(getPos_ValueSignal(int, int, int)), 
		this, SLOT(getPos_ValueSlots(int, int, int)));
	//connect(m_blldetector, SIGNAL(startSequenceSignal()), this, SLOT(startSequenceSlot()));
	ui.frameC->setText("4");
	ui.exporeT->setText("300.0");
}

StateWidget::~StateWidget()
{

}
void StateWidget::on_opentubeBtn_clicked(){
	if (!tubeopenEnable){
		QString str = QString::fromLocal8Bit("关闭球管");
		ui.opentubeBtn->setToolTip(str);
		tubeopenEnable = true;
		ui.opentubeBtn->setIcon(QIcon("image/tubeon.ico"));
		
	}
	else{
		ui.opentubeBtn->setIcon(QIcon("image/tubeclose.ico"));
		QString str = QString::fromLocal8Bit("打开球管");
		ui.opentubeBtn->setToolTip(str);
		tubeopenEnable = false;
	}
}
void StateWidget::on_opendoorBtn_clicked(){
	if (!doorstate){
		QString str = QString::fromLocal8Bit("门已开");
		ui.opendoorBtn->setToolTip(str);
		doorstate = true;
		ui.opendoorBtn->setIcon(QIcon("image/unlock.ico"));

	}
	else{
		ui.opendoorBtn->setIcon(QIcon("image/Lock.ico"));
		QString str = QString::fromLocal8Bit("门已关");
		ui.opendoorBtn->setToolTip(str);
		doorstate = false;
	}

}
void StateWidget::startSequenceSlot(){
	QString str_frameC = ui.frameC->text();
	QString str_exposureT = ui.exporeT->text();

	int framec = str_frameC.toInt();
	float exposuret = str_exposureT.toFloat();
	if (framec <= 0){
		framec = 4;
	}
	if (exposuret <= 0){
		exposuret = 1000.0f;
	}
	qDebug() << "----test-------" << framec;
	//m_blldetector->setframeC_exposureT(framec, exposuret);

}
void StateWidget::getPos_ValueSlots(int row, int col, int value){
	QString info = "Pixel info: (";
	QString rowstring = QString::number(row);
	QString colstring = QString::number(col);
	QString valuestring = QString::number(value);
	info.append(rowstring).append(",").append(colstring).append(") ").append(valuestring);
	ui.posLabel->setText(info);

}

