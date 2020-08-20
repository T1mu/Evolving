#ifndef TOOLBARWIDGET_H
#define TOOLBARWIDGET_H

#include <QWidget>
#include "ui_ToolBarWidget.h"
#include <QToolbar>
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif  
#include "../BllProject/BllDataFlow.h"

class ToolBarWidget : public QWidget
{
	Q_OBJECT

public:
	ToolBarWidget(QWidget *parent = 0);
	~ToolBarWidget();

public slots:
	//显示点数结果界面
	void resultImgShowSlot();
	void setVisibleSlot(bool);

signals:
	//控制显示灰度图界面
	void grayImgBtnClicked(bool checked = false);
	//控制显示点数结果界面
	void resultImgBtnClicked(bool checked = false);
	//显示点数结果界面
	void resultImgShowSignal();

protected:
	void paintEvent(QPaintEvent *);

private:
	Ui::ToolBarWidget ui;
	QToolBar* m_toolBar;
	BllDataFlow* m_bllDataFlow;


};

#endif // TOOLBARWIDGET_H
