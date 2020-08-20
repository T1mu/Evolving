#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QWidget>
#include "ui_MenuWidget.h"
#include <qmenubar.h>
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../BllProject/BllDataFlow.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
//#include "Ui/AdjustManager/AdjustWidget.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>  

class MenuWidget : public QWidget
{
	Q_OBJECT

public:
	MenuWidget(QWidget *parent = 0);
	~MenuWidget();

public slots:
	void setToolBarVisible(bool visible);
	void helpActionSlot(bool visiable);
	void openActionSlot(bool visiable);
	void saveActionSlot(bool visiable);
	void adjustActionSlot(bool visiable);
	void countActionSlot(bool visiable);
	void motorControlSlot(bool visiable);
signals:
	void toolBarVisible(bool);

protected:
	void paintEvent(QPaintEvent *);

private:
	Ui::MenuWidget ui;

	//菜单栏
	QMenuBar* m_menuBar;

	//打开
	QAction* m_openQct;
	//关闭
	QAction* m_closeQct;
	//保存
	QAction* m_saveQct;
	//退出
	QAction* m_exitQct;
	//帮助
	QAction* m_helpQct;
	//灰度直方图调整
	QAction* m_adjustQct;
	//点料
	QAction* m_countQct;
	QAction* m_motorQct;

	//AdjustWidget* m_adjust;
	//BllDetector* m_blldetector;
	BllDataFlow* m_bllDataFlow;
	cv::Mat srcimg;
	BllDetectorKZ* m_bll;
	int count;
};

#endif // MENUWIDGET_H
