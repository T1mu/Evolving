#ifndef MYCUSTOMSLIDER_H
#define MYCUSTOMSLIDER_H

#include <QSlider>  
#include <QLabel>  
#include <QMouseEvent>  
#include "ui_MyCustomSlider.h"

class MyCustomSlider : public QSlider
{
	Q_OBJECT

public:
	MyCustomSlider(QWidget *parent = 0);
	~MyCustomSlider();

private:
	Ui::MyCustomSlider ui;
	QLabel* m_displayLabel;
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);


};

#endif // MYCUSTOMSLIDER_H
