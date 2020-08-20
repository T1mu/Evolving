#ifndef PARAMEMTER_H
#define PARAMEMTER_H

#include <QWidget>
#include "ui_ParaMemter.h"
#include "../../BllProject/BllDetectorKZ/DetectorThread.h"

class ParaMemter : public QWidget
{
	Q_OBJECT

public:
	ParaMemter(QWidget *parent = 0);
	~ParaMemter();

	public slots:
	void dealcentersignal(double *);

private:
	Ui::ParaMemter ui;
	DetectorThread *m_detectorThread;
};

#endif // PARAMEMTER_H
