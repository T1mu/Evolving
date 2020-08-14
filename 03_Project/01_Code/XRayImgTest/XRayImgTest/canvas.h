#ifndef CANVAS_H
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
	void initUi(int w, int h);		//设置大小 控件摆放位置
	//缩放接口
	void setRatio(double zoom_ratio,
		double move_ratio,
		double max_ratio);            //接口 用于设置缩放比例 移动比例 放大率上限
	//初始化状态栏信息 缩放信息
	void prepareDisplay();
	//#imageData相关 共有方法
	void getArray(const ushort* arrayData, int width, int height);	//#接口:获得一维数组,并将其设置为imgData.srcArray
	void createArray16(int width, int height);					//生成递增一维数组
	void writeArray(ushort* &array);									//将array输出到外部
	void writeArray(uchar* &array);
	void writeMat(const cv::Mat &mat);

	void calcMapTable(
		int bottom = 0,
		int top = 65535,
		const int srcBytes = 16,
		const int dstBytes = 8
		);
	void Array16to8(int bottom = 0, int top = 65535);

	//#测试函数 输出array Mat 到本地
	void writeData(int width, int height);

	// #事件
	bool event(QEvent *event);                  //Qt的事件分发集合
	inline void paintEvent(QPaintEvent *event);
	void wheelEvent(QWheelEvent *e);

	//#储存格式转换 Mat2Pix
	QPixmap Mat16toPix8(const cv::Mat &mat);
	//#储存格式转换 Array2Mat
	cv::Mat Array16toMat(ushort* array, int w, int h);
	//#储存格式转换 Array2Pix
	QPixmap Array8toPix();

	enum  actionType {
		None = 0,
		Amplification,
		Shrink,
		Move
	};

	private slots:
	void on_helpBtn_clicked(bool checked);

	public slots:
	void getMapRange(const int bottom, const int top);

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

	//#imageData相关 图像储存结构
	struct imageData{
		cv::Mat _mat;
		QPixmap _srcPix;
		QPixmap _crtPix;
		int *_mapTable = nullptr;
		ushort *_array16 = nullptr;		//一维数组指针
		uchar *_array8 = nullptr;
		int _width = -1;			//图像宽度
		int _height = -1;		//图像长度
		int _bytes = 16;			//图像深度
	};

	//界面相关
	Ui::canvas *ui;
	int m_imgStartX;            //图像起始点的x
	int m_imgStartY;            //图像起始点的y

	//#绘制参数结构
	struct drawParams{
		QRect canvsRect;			//画板大小
		double zoomRatio;			//缩放大小
		double zoomStepRatio = 0.1;	//缩放改变率
		double moveRatio = 1;		//移动比率
		double maxZoomRatio;		//移动改变比率
		QPoint singOffset;			//单次鼠标偏移距离
		QPoint sumOffset = QPoint(0, 0);//最终偏移距离
	};
	int m_action;                       //动作(放大,缩小,移动...)
	// #私有结构对象
	imageData *m_imgData = new imageData();
	bottomStatus m_status;
	drawParams *m_drawParams = new drawParams();

	//标志位
	bool m_readyDisplay = false;
};

#endif // CANVAS_H
