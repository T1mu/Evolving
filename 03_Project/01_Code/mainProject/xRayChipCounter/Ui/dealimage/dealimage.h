#ifndef DEALIMAGE_H
#define DEALIMAGE_H

#include <QWidget>
#include "ui_dealimage.h"
#include <qfiledialog.h>
#include <qlabel.h>
#include "../../BllProject/BllDetectorKZ/DetectorThread.h"

//只能放在头文件当中
Q_DECLARE_METATYPE(Mat);

class dealimage : public QWidget
{
	Q_OBJECT

public:
	dealimage(QWidget *parent = 0);
	~dealimage();

	public slots:
	void dealmat(Mat);
	void dealcenter_signal(double *);


private:
	Ui::dealimage ui;
	DetectorThread *m_detectorThread;
};

#endif // DEALIMAGE_H
