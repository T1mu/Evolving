#ifndef TUBEWIDGET_H
#define TUBEWIDGET_H
#pragma execution_character_set("utf-8")  

#include <QtWidgets/QWidget>
#include "ui_TubeWidget.h"
#include "qglobal.h"
#include <qserialport.h>
#include <qserialportinfo.h>
#include <qserialportglobal.h>
#include <qwidget.h>
#include <QDebug>
#include <QLabel>
#include <QTimer>
#include <qglobal.h>
#include <qstring.h>
#include <qobject.h>
#include <qmessagebox.h>

class TubeWidget : public QWidget
{
	Q_OBJECT

public:
	TubeWidget(QWidget *parent = Q_NULLPTR);

public slots:

	void ReadData();
	void initialTube();
	
	void on_btnConnectTube_clicked();
	void on_btnXrayOn_clicked();
	void on_btnXrayOff_clicked();

	void setXrayV(int);
	void setXrayI(int);

	void on_btnGetV_clicked();
	void on_btnGetI_clicked();
	void on_btnGetT_clicked();
	void on_btnGetErr_clicked();

	void on_btnClearErr_clicked();

private:
	Ui::TubeWidgetClass ui;
	QSerialPort *serialPort;			//ÉùÃ÷´®¿ÚÀà
	QByteArray buf;
	QTimer *timer;

	int DecToHex(quint8 x);
};
#endif
