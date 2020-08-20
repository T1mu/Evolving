#ifndef MainWidget_H
#define MainWidget_H

#include <QDialog>
#include "ui_MainWidget.h"
#include "../../BllProject/BllDataFlow.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
class MainWidget : public QDialog
{
    Q_OBJECT
	public slots:
	void buttonClick();
	void on_btnMenu_Min_clicked();
	void on_btnMenu_Max_clicked();
	void on_btnMenu_Close_clicked();
public:
	explicit MainWidget(QWidget *parent = 0);
	~MainWidget();
protected:
	void changeEvent(QEvent* event);
private:
    Ui::MainWidgetClass ui;
 //   QPoint mousePoint;
 //   bool mousePressed;
    bool max;
    QRect location;
 //   void InitStyle();
	BllDataFlow* m_bllDataFlow;
};

#endif // MainWidget_H
