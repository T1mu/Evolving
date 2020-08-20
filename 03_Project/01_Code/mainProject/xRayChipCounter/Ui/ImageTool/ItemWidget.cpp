#include "ItemWidget.h"
#include <QPixmap>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QDebug>
ItemWidget::ItemWidget(int flagnumber, QWidget *parent)
: QWidget(parent)
{
	ui.setupUi(this);
	flag = flagnumber;
	number = new QLabel();
	delete_button = new QPushButton();
	/*m_bll = BllData::instance();*/
	m_bll = BllDataFlow::instance();
	delete_button->setStyleSheet("border:none");
	QPixmap pixmap("./image/delete.ico");
	delete_button->setIcon(pixmap);
	delete_button->setIconSize(pixmap.size());
	delete_button->setStyleSheet("background:transparent;");
	connect(delete_button, SIGNAL(clicked()), this, SLOT(DeletdItemSlot()));

	QHBoxLayout *main_layout = new QHBoxLayout();
	main_layout->addWidget(number);
	main_layout->addStretch();
	main_layout->addWidget(delete_button);
	main_layout->setContentsMargins(5, 5, 5, 5);
	main_layout->setSpacing(5);
	this->setLayout(main_layout);

}

ItemWidget::~ItemWidget()
{

}
void ItemWidget::DeletdItemSlot(){
	qDebug() << "==============delete" << number->text();
	QString itemText = number->text();
	m_bll->removeNumberText(itemText, flag);
}
void ItemWidget::mousePressEvent(QMouseEvent * event){
	if (event->button() == Qt::LeftButton)
	{
		QString itemText = number->text();
		m_bll->DisplaySelsectText(itemText, flag);
	}

}
void ItemWidget::setNumber(QString str){
	number->setText(str);

}
QString ItemWidget::getNumber(){
	QString itemText = number->text();
	return itemText;

}
void ItemWidget::removeNumber(){

}