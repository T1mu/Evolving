#ifndef MOTORWIDGET_H
#define MOTORWIDGET_H

#include <QWidget>
#include "ui_MotorWidget.h"
#include "../../BllProject/BllMotor/BllMotor.h"
#include "../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#pragma execution_character_set("utf-8")

class MotorWidget : public QWidget
{
	Q_OBJECT
	public slots:
	void on_connectNetCardBtn_clicked();
	void on_stopBtn_clicked();
	void on_rPositiveBtn_clicked();
	void on_rNegativeBtn_clicked();
	void on_xPositiveBtn_clicked();
	void on_xNegativeBtn_clicked();
	void on_yPositiveBtn_clicked();
	void on_yNegativeBtn_clicked();
	void on_zPositiveBtn_clicked();
	void on_zNegativeBtn_clicked();

	void on_tPositiveBtn_clicked();
	void on_tNegativeBtn_clicked();
public:
	MotorWidget(QWidget *parent = 0);
	~MotorWidget();
	void searchNetCard();

private:
	Ui::MotorWidget ui;
	IMC_HANDLE g_handle;//Íø¿¨¾ä±ú
	int g_naxis;//¿ØÖÆ¿¨ÖáÊý
	bool connectFlag ;//ÅÐ¶ÏÊÇ·ñÁ¬½ÓÍø¿¨
	BllMotor* m_bllMotor;
	BllDataFlow* m_bllDataFlow;

};

#endif // MOTORWIDGET_H
