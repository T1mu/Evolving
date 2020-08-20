#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QWidget>
#include "ui_ItemWidget.h"
#include <QLabel>
#include <QPushButton>
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"
class ItemWidget : public QWidget
{
	Q_OBJECT

public:
	ItemWidget(int flag = 10, QWidget *parent = 0);
	~ItemWidget();
	void setNumber(QString);
	QString getNumber();
	void removeNumber();

	private slots:
	void DeletdItemSlot();
protected:
	virtual void mousePressEvent(QMouseEvent * event);


private:
	Ui::ItemWidget ui;
	QLabel* number;
	QPushButton* delete_button;

	int flag;
	BllDataFlow* m_bll;
};

#endif // ITEMWIDGET_H
