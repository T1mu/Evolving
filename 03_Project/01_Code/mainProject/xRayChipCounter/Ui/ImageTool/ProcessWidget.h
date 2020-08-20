#ifndef PROCESSWIDGET_H
#define PROCESSWIDGET_H

#include <QWidget>
#include "ui_ProcessWidget.h"
#include <QListWidget>
#include "ItemWidget.h" 
#include "../../Library/MyHelper.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  

#include "../../../BllProject/BllDataFlow.h"

class ProcessWidget : public QWidget
{
	Q_OBJECT

public:
	ProcessWidget(QWidget *parent = 0);
	~ProcessWidget();
	void removeNumber(QListWidget*, QString);
	void setWidget(QComboBox*, QListWidget*, int serial);
	void addWidget(QString, QListWidget*, int serial);
	bool judgeNumber(QString);
	int QstringToInt(QString);

	private slots:
	void on_GaussianBlurBtn_clicked();
	void on_blurBtn_clicked();
	void on_medianBlurBtn_clicked();
	//²â»æ¹¤¾ß
	void on_lineBtn_clicked();
	void on_rectBtn_clicked();
	void on_circleBtn_clicked();
	void on_cancelBtn_clicked();
	void on_okBtn_clicked();
	void RadiousChangedSlot(QString);



	void DisplaySelsectTextSlot(QString, int);
	void removeNumberTextSlot(QString, int);
	void SliderlightSlot(int value);
	void SlidercontrastSlot(int value);

	void on_posBtn_clicked();

private:
	Ui::ProcessWidget ui;
	QListWidget* list_widget;
	QListWidget* list_widget_blur;
	QListWidget* list_widget_midblur;

	ItemWidget* testitem;
	int flag;
	BllDataFlow* m_bll;
	int light;
	int contrast;
	QString radious;
	bool posenable;
};

#endif // PROCESSWIDGET_H
