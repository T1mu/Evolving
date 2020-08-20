#ifndef SHOWIMAGE_H
#define SHOWIMAGE_H

#include <QWidget>
#include "Library/Global.h"
#include "../../Ui/ImageTool/CircleWidget.h"
#include "../../Ui/ImageTool/Line.h"
#include "../../Ui/ImageTool/LinePointWidget.h"
#include "../../Ui/ImageTool/RectPointWidget.h"
#include "../../Ui/ImageTool/RectWidget.h"


#include "../../Ui/MeasureManager/LAPointWidget.h"
#include "../../Ui/MeasureManager/LAClass.h"

#include "../../Ui/MeasureManager/MeasurePointWidget.h"
#include "../../Ui/MeasureManager/PerpenWireClass.h"
#include "../../Ui/MeasureManager/PPClass.h"
#include "../../Ui/MeasureManager/PixClass.h"
#include "../../Ui/MeasureManager/PixChartWidget.h"

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

using namespace cv;

struct Para
{
	int x;
	int y;
	ushort pixel;
};

class showImage : public QWidget
{
	Q_OBJECT

public:
	showImage(QWidget *parent = 0);
	~showImage();

	QImage Matchange(const cv::Mat& mat);
	cv::Mat QImagechange(QImage image);
	void MatchangeQuint(int size, int serial);
	void SizeOverLimit(int size);
	void BlurMethod(int size);
	void medianBlurMethod(int size);
	void GaussianBlurMethod(int size);
	void SliderchangeMethod(int vcontrast, int vlight);

	//-------------------------测量工具
	bool judgeDistanceToMove(QPoint);
	void moveCalPoint(int dis, QPoint pos);
	bool judgeDeleteLine(QPoint pos);
	void deleteLine(int serial);
	void paintImgTools();
	//-------------------------测量工具

	void toPos_Value(QPoint);






	public slots:
	void returnImgSlot(int, int);
	void updateSizeSlot(int);
	void updateGrayImageSlot();
	//void paintGraySlot();
	//绘制灰度图
	//void moveRepaintGrayImgSlot(QVector<QPointF>);
	//void updateImgSlot();
	void setBlursizeSlot(int, int);
	void LightContrastChangeSlot(int, int);
	//-------------------------测量工具
	void setLineEnableSlot();
	void LinepointMoveSlot(int lineOrder, int flag, QPoint pos);
	void setRectEnableSlot();
	void iniRectPointSlot(QPoint, QPoint, QPoint, QPoint, int);
	void setCircleEnableSlot();
	void setRadiousSlot(int);
	void setCancelEnableSlot();
	void cancelCircleSlot(int);
	void cancelRectSlot(int);
	//-------------------------测量工具
	void getPosSlots();
	void getPosCancelSlots();
	void lineMoveSlot(QVector<QPointF>);
	void readyAdjustpaintSlot(int, int);

	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
	void setLineAngleEnableSlot();
	void setperpenEnableSlot();
	void setperdenEnableSlot();
	void setpixEnableSlot();
	void setMoveLimitSlot();
	void setLaMoveSlot(ShapeMode, int, int);
	void cancelMoveLimitSlot();
	void setDisenableSlot();
	void cancelShapeSlot();
	void clearShapeSlot();
	void setlaCancelSlot(int);

	void setPmoveSlot(ShapeMode, int, int);
	void setPcancelSlot(ShapeMode, int);
	void setPixReleaseSlot();
	//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++++++++++++


	//++++++++++++++++++++++++++++++++++++++++局部放大 start++++++++++++++++++++++++++++++++++++++++
	void ifMouseMoveSlot(bool);
	//++++++++++++++++++++++++++++++++++++++++局部放大 end++++++++++++++++++++++++++++++++++++++++
signals:
	void paraSignal(Para);

protected:
	virtual void mouseMoveEvent(QMouseEvent * event);
	virtual void mousePressEvent(QMouseEvent * event);
	virtual void mouseReleaseEvent(QMouseEvent * event);
	virtual void resizeEvent(QResizeEvent * event);
	virtual void paintEvent(QPaintEvent * event);
	virtual void wheelEvent(QWheelEvent *event);

private:
	BllDetectorKZ* m_bll;
	BllDataFlow* m_bllDataFlow;
	uchar* m_8bitgrayImg;
	int radious;
	int displayW;
	int displayH;
	int pointorder; //判断start和end point
	int pointcount;//判断是start or end
	int linenumber;//记录是第几条线
	int circleNum;
	int rectnum;
	int row;
	int maxp;
	int minp;
	int m_width;
	int m_center;
	int adjustWidth;
	int adjustCenter;
	int light;
	int contrast;
	int clickcount;
	int lineMoveSerial;
	int lineDeleteSerial;
	bool Sliderchange;
	bool updateEnable;
	bool moveChange;
	bool adjustEnable;
	bool drawline;
	bool lineEnable;
	bool rectEnable;
	bool circleEnable;
	bool cancelEnable;
	bool moveline;
	bool getposE;
	cv::Mat srcImg;
	cv::Mat dstImg;

	QPointF tmpPoint;
	QVector<QPointF> vec;
	QVector<QPointF> m_vector;
	QVector<Line*> vectorLine;
	QVector<LinePointWidget*> vectorPoint;
	QVector<RectPointWidget*> vectorRectP;
	QVector<CircleWidget*> vectorCircle;
	QVector<RectWidget*> vectorRect;
	QImage tempImg;

	//--------------------------------
	double m_scale;
	bool mainImageFlag = 0;

	//++++++++++++++++++++++++++++++++++++++++测量工具 start++++++++++++++++++++++++++++++
	int m_Count;
	int m_la;
	int m_ppCount;;
	int m_perdenCount;


	bool m_laEnable;
	bool m_perpenEnable;
	bool m_perdenwireEnable;

	bool m_pixEnable;
	QVector<LAPointWidget*> m_vecLaP;
	QVector<LAClass*> m_vecLa;

	QVector<MeasurePointWidget*> m_vecpwP;
	QVector<PerpenWireClass*> m_vecpw;

	QVector<PPClass*> m_vecpp;
	QVector<MeasurePointWidget*> m_vecppP;


	QVector<MeasurePointWidget*> m_vecPixP;
	PixClass* m_pix;
	PixChartWidget* m_chartWidget;
	//++++++++++++++++++++++++++++++++++++++++测量工具 end++++++++++++++++++++++++++++++
};

#endif // SHOWIMAGE_H
