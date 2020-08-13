﻿#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPixmap>
#include <opencv.hpp>
#include <opencv2/opencv.hpp>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPoint>
#include <QRect>
#include <iostream>
#include <stdio.h>

#pragma execution_character_set("utf-8")

namespace Ui {
class canvas;
}


class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = 0);
    ~canvas();
    //界面接口
    void setCanvasSize(const unsigned int width, const unsigned int height);
    void setCanvasWidth(const unsigned int w);
    void setCanvasHeight(const unsigned int h);
    void initUi();
    //缩放接口
    void SetRatio(double zoom_ratio,
                  double move_ratio,
                  double max_ratio);            //接口 用于设置缩放比例 移动比例 放大率上限
    //数据接口
	void getMat(const cv::Mat &mat);            //设置m_src_mat 和 m_src_pix 参数类型为Mat
    void getImg(const QString &path);           //设置m_src_mat 和 m_src_pix 参数类型为QString
	void DisplayMat(const cv::Mat &mat);        //绘制m_src_pix 到画板上 并设置为 m_crt_pix

	//#imageData相关 共有方法
	void getArray(const ushort* arrayData, int width, int height);	//获得一维数组,并将其设置为imgData.srcArray
	void createArray(int width, int height);	
	void writeArray();

    // 事件
    bool event(QEvent *event);                  //Qt事件分发
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *e);


	QPixmap Mat2Pix(const cv::Mat &mat);
    enum  actionType {
        None          = 0,
        Amplification ,
        Shrink,
        Lift,
        Right,
        Up,
        Down,
        Move
    };

private slots:
    void on_helpBtn_clicked(bool checked);

private:

	//状态栏的结构 所需信息
	struct bottomStatus{
		double width;
		double height;
		int depth;
		double value;
		double pos_x;
		double pos_y;
		double ratio;
	};

	//#imageData相关 结构信息
	struct imageData{
		cv::Mat srcMat;
		cv::Mat crtMat;
		QPixmap srcPix;
		QPixmap crtPix;
		ushort *srcArray;	//一维数组指针
		int width = -1;		//图像宽度
		int height = -1;		//图像长度
		int bytes = 16;		//图像深度
	};

    //界面相关
    int m_canvas_width;
    int m_canvas_height;

    Ui::canvas *ui;
	
    int m_imgStartX;            //图像起始点的x
    int m_imgStartY;            //图像起始点的y
    //动作相关

	//#绘制参数结构
	struct drawParams{
		QRect canvsRect;
		double zoomRatio;
		double zoomStepRatio = 0.1;
		double moveRatio = 1;
		double maxZoomRatio;
		QPoint singOffset;
		QPoint sumOffset = QPoint(0, 0);

	};
    int m_action;                       //动作(放大,缩小,移动...)
//	QRect m_drawParams->canvsRect;
//	double m_drawParams->zoomRatio ;           //当前图与原图比例
//	double m_drawParams->zoomStepRatio = 0.1;
//    double m_drawParams->moveRatio = 1;
//    double m_drawParams->maxZoomRatio ;
//    QPoint m_drawParams->singOffset;             //单次偏移
//    QPoint m_drawParams->sumOffset=QPoint(0,0);   //总偏移

	// #结构私有成员
	imageData *m_imgData = new imageData();
	bottomStatus m_status;
	drawParams *m_drawParams = new drawParams(); 

    //标志位
    bool m_IsPAINTED = false;
};

#endif // CANVAS_H
