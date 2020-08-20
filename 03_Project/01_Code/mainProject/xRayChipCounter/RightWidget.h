#ifndef RIGHTWIDGET_H
#define RIGHTWIDGET_H

#include <QWidget>
#include "ui_RightWidget.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif  
#include "../BllProject/BllDataFlow.h"
//#include "../../../BllProject/BllDetector/BllDetector.h"

//#include "Ui\CurveManager\GrayCurveWidget.h"
class RightWidget : public QWidget
{
	Q_OBJECT

public:
	RightWidget(QWidget *parent = 0);
	~RightWidget();
	private slots:
	void on_resetCurveBtn_clicked();
	void resetCurveEnableSlot(QString, QString);
private:
	Ui::RightWidget ui;
	//BllDetector* m_blldetector;

	//GrayCurveWidget* m_graycurve;
};

#endif // RIGHTWIDGET_H
