#include "MyCustomSlider.h"
#include <QPalette> 
#include <QDebug>
MyCustomSlider::MyCustomSlider(QWidget *parent) :QSlider(parent)
{
	this->setOrientation(Qt::Horizontal);
	m_displayLabel = new QLabel(this);
	m_displayLabel->setFixedSize(QSize(20, 20));
	//设置游标背景为白色  
	m_displayLabel->setAutoFillBackground(true);
	QPalette palette;
	palette.setColor(QPalette::Background, Qt::white);
	m_displayLabel->setPalette(palette);

	m_displayLabel->setAlignment(Qt::AlignCenter);

	m_displayLabel->setVisible(false);
	int heightcomp = 0;
	if (this->height() < 120){
		heightcomp = 32;
	}
	else{
		heightcomp = 60;
	}
	m_displayLabel->move(3, heightcomp);
}

MyCustomSlider::~MyCustomSlider()
{

}

void MyCustomSlider::mousePressEvent(QMouseEvent *event)
{
	if (!m_displayLabel->isVisible())
	{
		m_displayLabel->setVisible(true);
		m_displayLabel->setText(QString::number(this->value()));
	}
	QSlider::mousePressEvent(event);
}

void MyCustomSlider::mouseReleaseEvent(QMouseEvent *event)
{
	if (m_displayLabel->isVisible())
	{
		m_displayLabel->setVisible(false);
	}
	QSlider::mouseReleaseEvent(event);
}

void MyCustomSlider::mouseMoveEvent(QMouseEvent *event)
{
	int heightcomp = 0;
	if (this->height() < 160){
		heightcomp = 10;
	}
	else{
		heightcomp = 70;
	}
	m_displayLabel->setText(QString::number(this->value()));
	m_displayLabel->move((this->width() - m_displayLabel->width() + 3)*this->value() / (this->maximum() - this->minimum()), heightcomp);
	QSlider::mouseMoveEvent(event);
	qDebug()<<"=============================>"<< this->height();
}
