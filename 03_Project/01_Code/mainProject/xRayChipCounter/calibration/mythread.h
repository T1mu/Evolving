//#ifndef MYTHREAD_H
//#define MYTHREAD_H
//
//#include <QThread>
//#include <qfiledialog.h>
//#include <qlabel.h>
//#include <iostream>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp> 
////#include "calibration.h"
//
//using namespace cv;
//using namespace std;
//
//class MyThread : public QThread
//{
//	Q_OBJECT
//
//public:
//	MyThread(QObject *parent);
//	~MyThread();
//	void startThread(int, unsigned short, unsigned short, QStringList, int, int);
//	void stopThread();
//	static bool sortFun(const Point2d &p1, const Point2d &p2)
//	{
//		return p1.y < p2.y;//ÉýÐòÅÅÁÐ
//	}
//
//signals:
//	void mat_signal(Mat);
//	void center_signal(double *);
//	void free_signal();
//
//protected:
//	void run();
//
//private:
//	int dir_count;
//	unsigned short minnum;
//	unsigned short maxnum;
//	QStringList list;
//	int row;
//	int col;
//	bool isStop = false;
//	//Calibration cal;
//};
//
//#endif // MYTHREAD_H
