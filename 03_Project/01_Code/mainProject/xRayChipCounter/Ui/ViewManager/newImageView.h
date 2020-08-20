#ifndef NEWIMAGEVIEW_H
#define NEWIMAGEVIEW_H

#include <QWidget>
#include "ui_newImageView.h"
#include "showimage.h"
#include "Library/Global.h"
#include "../../Ui/ImageTool/CircleWidget.h"
#include "../../Ui/ImageTool/Line.h"
#include "../../Ui/ImageTool/LinePointWidget.h"
#include "../../Ui/ImageTool/RectPointWidget.h"
#include "../../Ui/ImageTool/RectWidget.h"
#include "../../BllProject/BllDetectorKZ/BllDetectorKZ.h"
#include "../BllProject/BllDataFlow.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>  
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")

#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")

#endif 
class newImageView : public QWidget
{
	Q_OBJECT

public:
	newImageView(QWidget *parent = 0);
	~newImageView();
	//	QImage Matchange(const cv::Mat& mat);
	//	cv::Mat QImagechange(QImage image);
	//	void MatchangeQuint(int size, int serial);
	//	void SizeOverLimit(int size);
	//	void BlurMethod(int size);
	//	void medianBlurMethod(int size);
	//	void GaussianBlurMethod(int size);
	//	void SliderchangeMethod(int vcontrast, int vlight);
	//
	//	//-------------------------测量工具
	//	bool judgeDistanceToMove(QPoint);
	//	void moveCalPoint(int dis, QPoint pos);
	//	bool judgeDeleteLine(QPoint pos);
	//	void deleteLine(int serial);
	//	void paintImgTools();
	//	//-------------------------测量工具
	//
	//	void toPos_Value(QPoint);
	//public slots:
	//	void returnImgSlot(int, int);
	//	void updateSizeSlot(int);
	//	void updateGrayImageSlot();
	//	//void paintGraySlot();
	//	//绘制灰度图
	//	//void moveRepaintGrayImgSlot(QVector<QPointF>);
	//	//void updateImgSlot();
	//	void setBlursizeSlot(int, int);
	//	void LightContrastChangeSlot(int, int);
	//	//-------------------------测量工具
	//	void setLineEnableSlot();
	//	void LinepointMoveSlot(int lineOrder, int flag, QPoint pos);
	//	void setRectEnableSlot();
	//	void iniRectPointSlot(QPoint, QPoint, QPoint, QPoint, int);
	//	void setCircleEnableSlot();
	//	void setRadiousSlot(int);
	//	void setCancelEnableSlot();
	//	void cancelCircleSlot(int);
	//	void cancelRectSlot(int);
	//	//-------------------------测量工具
	//	void getPosSlots();
	//	void getPosCancelSlots();
	//	void lineMoveSlot(QVector<QPointF>);
	//	void readyAdjustpaintSlot(int, int);
	//protected:
	//	virtual void mouseMoveEvent(QMouseEvent * event);
	//	virtual void mousePressEvent(QMouseEvent * event);
	//	virtual void mouseReleaseEvent(QMouseEvent * event);
	//	virtual void resizeEvent(QResizeEvent * event);
	//	virtual void paintEvent(QPaintEvent * event);
public slots:
    void dealSignal(Para);

private:
	Ui::newImageView ui;
	//BllDetectorKZ* m_bll;
	//BllDataFlow* m_bllDataFlow;
	//uchar* m_8bitgrayImg;
	//int radious;
	//int displayW;
	//int displayH;
	//int pointorder; //判断start和end point
	//int pointcount;//判断是start or end
	//int linenumber;//记录是第几条线
	//int circleNum;
	//int rectnum;
	//int row;
	//int maxp;
	//int minp;
	//int m_width;
	//int m_center;
	//int adjustWidth;
	//int adjustCenter;
	//int light;
	//int contrast;
	//int clickcount;
	//int lineMoveSerial;
	//int lineDeleteSerial;
	//bool Sliderchange;
	//bool updateEnable;
	//bool moveChange;
	//bool adjustEnable;
	//bool drawline;
	//bool lineEnable;
	//bool rectEnable;
	//bool circleEnable;
	//bool cancelEnable;
	//bool moveline;
	//bool getposE;
	//cv::Mat srcImg;
	//cv::Mat dstImg;

	//QPointF tmpPoint;
	//QVector<QPointF> vec;
	//QVector<QPointF> m_vector;
	//QVector<Line*> vectorLine;
	//QVector<LinePointWidget*> vectorPoint;
	//QVector<RectPointWidget*> vectorRectP;
	//QVector<CircleWidget*> vectorCircle;
	//QVector<RectWidget*> vectorRect;
	//QImage tempImg;


};

#endif // NEWIMAGEVIEW_H
