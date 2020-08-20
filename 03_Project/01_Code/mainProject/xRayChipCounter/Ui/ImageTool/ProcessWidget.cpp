#include "ProcessWidget.h"
#include <QDebug>
ProcessWidget::ProcessWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	flag = 1000;
	light = 0;
	contrast = 0;
	posenable = false;
	m_bll = BllDataFlow::instance();
	list_widget = new QListWidget();
	setWidget(ui.GaussianBlur, list_widget, 0);
	list_widget_blur = new QListWidget();
	setWidget(ui.blur, list_widget_blur, 1);
	list_widget_midblur = new QListWidget();
	setWidget(ui.medianBlur, list_widget_midblur, 2);
	connect(m_bll, SIGNAL(DisplaySelsectTextSignal(QString, int)), this, SLOT(DisplaySelsectTextSlot(QString, int)));
	connect(m_bll, SIGNAL(removeNumberTextSignal(QString, int)), this, SLOT(removeNumberTextSlot(QString, int)));

	connect(ui.light, SIGNAL(valueChanged(int)), this, SLOT(SliderlightSlot(int)));
	connect(ui.contrast, SIGNAL(valueChanged(int)), this, SLOT(SlidercontrastSlot(int)));
	connect(ui.radious, SIGNAL(valueChanged(QString)),
		this, SLOT(RadiousChangedSlot(QString)));
}

ProcessWidget::~ProcessWidget()
{

}
void ProcessWidget::on_GaussianBlurBtn_clicked(){
	qDebug() << "=================on_okBtn_clicked";
	qDebug() << "thsi is value========" << ui.GaussianBlur->currentText();
	QString number = ui.GaussianBlur->currentText();
	addWidget(number, list_widget, 0);


}
void ProcessWidget::on_blurBtn_clicked(){
	QString number = ui.blur->currentText();
	addWidget(number, list_widget_blur, 1);
}
void ProcessWidget::on_medianBlurBtn_clicked(){
	QString number = ui.medianBlur->currentText();
	addWidget(number, list_widget_midblur, 2);

}



void ProcessWidget::DisplaySelsectTextSlot(QString str, int flagnumber){

	if (flagnumber == 0){
		ui.GaussianBlur->setEditText(str);
		ui.GaussianBlur->hidePopup();
		//qDebug() << "this is test change int----------" << QstringToInt(str);
		m_bll->setBlursize(QstringToInt(str), 0);
	}
	if (flagnumber == 1){
		ui.blur->setEditText(str);
		ui.blur->hidePopup();
		m_bll->setBlursize(QstringToInt(str), 1);
	}
	if (flagnumber == 2){
		ui.medianBlur->setEditText(str);
		ui.medianBlur->hidePopup();
		m_bll->setBlursize(QstringToInt(str), 2);
	}



}
void ProcessWidget::removeNumberTextSlot(QString number, int flagnumber){
	
	if (flagnumber == 0){
		ui.GaussianBlur->setEditText("");
		ui.GaussianBlur->hidePopup();
		removeNumber(list_widget, number);
	}
	if (flagnumber == 1){
		ui.blur->setEditText("");
		ui.blur->hidePopup();
		removeNumber(list_widget_blur, number);

	}
	if (flagnumber == 2){
		ui.medianBlur->setEditText("");
		ui.medianBlur->hidePopup();
		removeNumber(list_widget_midblur, number);

	}


}
void ProcessWidget::removeNumber(QListWidget* list, QString number){

	int list_count = list->count();
	for (int i = 0; i<list_count; i++)
	{
		QListWidgetItem *item = list->item(i);
		ItemWidget *account_item = (ItemWidget *)(list->itemWidget(item));
		QString account_number = account_item->getNumber();
		if (number == account_number)
		{
			list->takeItem(i);
			delete item;

			break;
		}
	}


}
void ProcessWidget::setWidget(QComboBox* combo, QListWidget* listwidget, int serial){
	//ui.GaussianBlur->setModel(list_widget->model());
	//ui.GaussianBlur->setView(list_widget);
	//ui.GaussianBlur->setEditable(true); //设置QComboBox可编辑

	combo->setModel(listwidget->model());
	combo->setView(listwidget);
	combo->setEditable(true);
	/*if (serial!= 2){*/
		for (int i = 3; i<12; i = i + 2)
		{
			ItemWidget *account_item = new ItemWidget(serial);
			account_item->setNumber(QString::number(i, 10));
			QListWidgetItem *list_item = new QListWidgetItem(listwidget);
			listwidget->setItemWidget(list_item, account_item);
		}
	//}
	/*else{
		for (int i = 3; i<6; i = i + 2)
		{
			ItemWidget *account_item = new ItemWidget(serial);
			account_item->setNumber(QString::number(i, 10));
			QListWidgetItem *list_item = new QListWidgetItem(listwidget);
			listwidget->setItemWidget(list_item, account_item);
		}
		
	}*/
	

}
void ProcessWidget::addWidget(QString number, QListWidget* listwidget, int serial){
	int list_count = listwidget->count();
	bool repeat = false;
	for (int i = 0; i<list_count; i++)
	{
		QListWidgetItem *item = listwidget->item(i);
		ItemWidget *account_item = (ItemWidget *)(listwidget->itemWidget(item));
		QString account_number = account_item->getNumber();
		if (number == account_number)
		{
			repeat = true;
			break;
		}
	}
	if (!repeat && number != ""){
		if (judgeNumber(number)){
			ItemWidget *account_item = new ItemWidget(serial);
			account_item->setNumber(number);
			QListWidgetItem *list_item = new QListWidgetItem(listwidget);
			listwidget->setItemWidget(list_item, account_item);
			m_bll->setBlursize(QstringToInt(number), serial);
		}
		else{
			MyHelper::ShowMessageBoxError("请输入数字！！！");
		
		}
		
	}
	//test
	


}
bool ProcessWidget::judgeNumber(QString number){
	bool ok;

	QString str(number);

	int tmp = str.toInt(&ok);

	return ok;
}
int ProcessWidget::QstringToInt(QString strs){
	QString str(strs);

	int tmp = str.toInt();
	return tmp;
}
void ProcessWidget::SliderlightSlot(int value){
	light = value;
	m_bll->LightContrastChange(light, contrast);
	
}
void ProcessWidget::SlidercontrastSlot(int value){
	contrast = value;
	m_bll->LightContrastChange(light, contrast);
}

void ProcessWidget::on_lineBtn_clicked(){
	m_bll->setLineEnable();
}
void ProcessWidget::on_rectBtn_clicked(){
	m_bll->setRectEnable();
}
void ProcessWidget::on_cancelBtn_clicked(){
	m_bll->setCancelEnable();
}
void ProcessWidget::on_okBtn_clicked(){
	int rad = radious.toInt();
	m_bll->RadiousChanged(rad);
}
void ProcessWidget::RadiousChangedSlot(QString str){
	//qDebug() << "this is get radious---" << str;
	radious = str;
}
void ProcessWidget::on_circleBtn_clicked(){
	m_bll->setCircleEnable();
	radious = ui.radious->text();
	int rad = radious.toInt();
	m_bll->setRadious(rad);
}
void ProcessWidget::on_posBtn_clicked(){
	if (!posenable){
		m_bll->getPos();
		posenable = true;
	}
	else{
		m_bll->getPosCancel();
		posenable = false;
	}

	
}