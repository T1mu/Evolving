#ifndef MEASUREWIDGET_H
#define MEASUREWIDGET_H

#include <QWidget>
#include "ui_MeasureWidget.h"
#include "../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
#include <string>
using namespace std;
#pragma execution_character_set("utf-8")
class MeasureWidget : public QWidget
{
	Q_OBJECT
	public slots:
	void on_openBtn_clicked();
	void on_cancelBtn_clicked();
	void on_clearBtn_clicked();
	void currentIndexChangedSlot(int);
	void on_enableBtn_clicked();
public:
	MeasureWidget(QWidget *parent = 0);
	~MeasureWidget();


private:
	Ui::MeasureWidget ui;

	bool m_enable;
	int m_state;
	BllDataFlow* m_bllDataFlow;
};

#endif // MEASUREWIDGET_H
