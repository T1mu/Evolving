#include "ControlMenuWidget.h"
#include <QDebug>
#include <QTextCodec>
#include <QFileDialog>
ControlMenuWidget::ControlMenuWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	detectopenEnable = false;
	pulseEnable = false;
	m_blldataflow = BllDataFlow::instance();
	//m_blldetector = BllDetector::instance();

	//qDebug() << "---------------------------" << ui.widget->width() << ";;;" << ui.widget->height();
	//QPoint p(ui.widget->width() / 2, ui.widget->height()/2);
	//m_move = new MoveWidget(p, ui.widget);

	//connect(m_blldetector, SIGNAL(returnSingleSignal()), this, SLOT(returnSingleSlot()));

	//connect(m_blldetector, SIGNAL(returnSequenceSignal()), this, SLOT(returnSequenceSlot()));
	//connect(m_blldetector, SIGNAL(returnPulseSignal()), this, SLOT(returnPluseSlot()));


	connect(ui.darkCb, SIGNAL(stateChanged(int)), this, SLOT(on_darkCb_checked(int)));
	connect(ui.floodCb, SIGNAL(stateChanged(int)), this, SLOT(on_floodCb_checked(int)));
	connect(ui.defectCb, SIGNAL(stateChanged(int)), this, SLOT(on_defectCb_checked(int)));

	//ui.pdataCb
	connect(ui.pdataCb, SIGNAL(currentIndexChanged(int)), this, SLOT(datachanged(int)));


	//qDebug() << "----" << ui.pdataCb->currentIndex() << ";;;" << ui.pdataCb->currentText();

	ui.captureBtn->setEnabled(false);
	//ui.sequenceBtn->setEnabled(false);
	ui.pulseBtn->setEnabled(false);

	ui.saveBtn->setEnabled(false);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK")); // 关键是这句
}

ControlMenuWidget::~ControlMenuWidget()
{

}
//打开/关闭探测器
//void ControlMenuWidget::on_opendetectBtn_clicked(){
//	//(QIcon("image/Xray_red.png"));
//	if (!detectopenEnable){
//
//		if (!m_blldetector->openDetector())
//		{
//			MyHelper::ShowMessageBoxError("平板探测器，打开失败！");
//			return;
//		}
//
//		
//
//		QString str = "关闭探测器";
//		ui.opendetectBtn->setToolTip(str);
//		detectopenEnable = true;
//		ui.opendetectBtn->setIcon(QIcon("image/switch_close.ico"));
//		ui.captureBtn->setEnabled(true);
//		//ui.sequenceBtn->setEnabled(true);
//		ui.pulseBtn->setEnabled(true);
//		
//	}
//	else{
//		m_blldetector->closeDetector();
//		QString str = "打开探测器";
//		ui.opendetectBtn->setToolTip(str);
//		detectopenEnable = false;
//		ui.opendetectBtn->setIcon(QIcon("image/switch.ico"));
//		ui.captureBtn->setEnabled(false);
//		//ui.sequenceBtn->setEnabled(false);
//		ui.pulseBtn->setEnabled(false);
//
//	}
//	
//
//}
//
//void ControlMenuWidget::on_captureBtn_clicked(){
//	
//	
//	ui.opendetectBtn->setEnabled(false);
//	if (!m_blldetector->acqSingleImage()){
//		MyHelper::ShowMessageBoxError("平板探测器未打开，单帧采集失败！");
//		ui.captureBtn->setEnabled(true);
//		ui.opendetectBtn->setEnabled(true);
//	}
//
//}
//
//void ControlMenuWidget::returnSingleSlot(){
//
//	
//	ui.captureBtn->setEnabled(true);
//	ui.opendetectBtn->setEnabled(true);
//	ui.saveBtn->setEnabled(true);
//
//}
//
//
//
//
////void ControlMenuWidget::on_sequenceBtn_clicked(){
////	m_blldetector->startSequence();
////	if (m_blldetector->acqSequenceImage())
////	{
////		
////		ui.opendetectBtn->setEnabled(false);
////		ui.captureBtn->setEnabled(false);
////		ui.pulseBtn->setEnabled(false);
////	}
////	else
////	{
////		MyHelper::ShowMessageBoxError("平板探测器未打开，连续采集失败！");
////	}
////
////}
//void ControlMenuWidget::on_pulseBtn_clicked(){
//	
//	if (!pulseEnable){
//		if (!m_blldetector->acqPulseImage())
//		{
//			MyHelper::ShowMessageBoxError("平板探测器未打开，连续采集失败！");
//			return;
//		}
//
//		ui.pulseBtn->setIcon(QIcon("image/pulse_on.ico"));
//		QString str = "停止连续采集";
//		ui.pulseBtn->setToolTip(str);
//		pulseEnable = true;
//
//		ui.opendetectBtn->setEnabled(false);
//		ui.captureBtn->setEnabled(false);
//		ui.pdataCb->setEditable(false);
//		//ui.sequenceBtn->setEnabled(false);
//	}
//	else{
//
//		m_blldetector->stopLiveThread();
//		ui.pulseBtn->setIcon(QIcon("image/pulseCapture.png"));
//		QString str = "开始连续采集";
//		ui.pulseBtn->setToolTip(str);
//		pulseEnable = false;
//		ui.opendetectBtn->setEnabled(true);
//		ui.captureBtn->setEnabled(true);
//		//ui.sequenceBtn->setEnabled(true);
//		ui.saveBtn->setEnabled(true);
//		ui.pdataCb->setEditable(true);
//	}
//
//
//
//}
//
//void ControlMenuWidget::returnSequenceSlot(){
//	ui.opendetectBtn->setEnabled(true);
//	ui.captureBtn->setEnabled(true);
//	ui.pulseBtn->setEnabled(true);
//	ui.saveBtn->setEnabled(true);
//
//}
//void ControlMenuWidget::returnPluseSlot(){
//
//
//}
//
//
//
//void ControlMenuWidget::on_resetBtn_clicked(){
//
//	//QPoint p(ui.widget->width() / 2, ui.widget->height() / 2);
//	//m_blldataflow->ResetPoint(p);
//}
//void ControlMenuWidget::on_darkCb_checked(int state){
//	qDebug() << "this is =================on_darkCb_checked";
//	if (state == Qt::Checked) // "选中"
//	{
//		qDebug() << "======dark dark dark state == Qt::Checked";
//		m_blldetector->setDarkCorrection();
//		ui.floodCb->setEnabled(false);
//		ui.defectCb->setEnabled(false);
//
//	}
//
//	else // 未选中 - Qt::Unchecked
//	{
//		qDebug() << "======dark dark dark state == Qt::Unchecked";
//		m_blldetector->resetCorrection();
//		ui.floodCb->setEnabled(true);
//		ui.defectCb->setEnabled(true);
//	}
//
//}
//void ControlMenuWidget::on_floodCb_checked(int state){
//	qDebug() << "this is =================on_floodCb_checked";
//	if (state == Qt::Checked) // "选中"
//	{
//		qDebug() << "======flood flood flood state == Qt::Checked";
//		m_blldetector->resetCorrection();
//		ui.darkCb->setEnabled(false);
//		ui.defectCb->setEnabled(false);
//
//	}
//
//	else // 未选中 - Qt::Unchecked
//	{
//		qDebug() << "======flood flood flood state == Qt::Unchecked";
//		m_blldetector->resetCorrection();
//		ui.darkCb->setEnabled(true);
//		ui.defectCb->setEnabled(true);
//	}
//
//
//}
//void ControlMenuWidget::on_defectCb_checked(int state){
//	qDebug() << "this is =================on_defectCb_checked";
//
//	if (state == Qt::Checked) // "选中"
//	{
//		qDebug() << "======defect defect defect state == Qt::Checked";
//		m_blldetector->setDefectCorrection();
//		ui.darkCb->setEnabled(false);
//		ui.floodCb->setEnabled(false);
//	}
//
//	else // 未选中 - Qt::Unchecked
//	{
//		qDebug() << "======defect defect defect state == Qt::Unchecked";
//		m_blldetector->resetCorrection();
//		ui.darkCb->setEnabled(true);
//		ui.floodCb->setEnabled(true);
//	}
//
//}
//void ControlMenuWidget::on_saveBtn_clicked(){
//	qDebug() << "=============this is on_saveBtn_clicked ==============";
//	QString fileName = QFileDialog::getSaveFileName(this, tr("保存文件"), "./", tr("Images (*.tif)"));
//	qDebug() << "====================fileName" << fileName;
//	QStringList listfile = fileName.split('.');
//	QString filelast = listfile.takeLast();
//
//	if (filelast != "tif"){
//		MyHelper::ShowMessageBoxError("文件格式错误，请将文件保存为：*.tif 文件！");
//	}
//	else{
//		quint16* m_grayImg = BllDetector::getSingleImg();
//		if (m_grayImg == NULL){
//			return;
//		}
//
//		Mat saveImg(Size(1536, 864), CV_16U);
//		//Mat image(Size(100, 200), CV16UC2);
//
//		for (int i = 0; i < 1536 * 864; i++){
//			int row = i / 1536;
//			int col = i % 1536;
//			int data = m_grayImg[i];
//			saveImg.at<ushort>(row, col) = data;
//		
//		}
//
//		if (imwrite(string(fileName.toLocal8Bit()),  saveImg)){
//			qDebug() << "=========file save successfully----------------";
//
//			qDebug() << "==========this is save img depeth====" << saveImg.depth();
//		
//		}
//
//
//		
//	}
//
//
//}
//void ControlMenuWidget::datachanged(int index){
//
//	if (index == 0){
//		m_blldetector->setLiveEnable();
//	}
//	else{
//		QString value = ui.pdataCb->itemText(index);
//		int data = value.toInt();
//		m_blldetector->setliveDataEnable(data);
//	
//	}
//	
//	
//
//
//}