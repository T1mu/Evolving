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

	void initUi(int w, int h);			//#界面:设置大小 控件摆放位置
	void setRatio(double zoom_ratio,
		double move_ratio,
		double max_ratio);				//#处理: 用于设置缩放比例 移动比例 放大率上限

	void prepareDisplay();				//#界面 准备工作

	void getArray(const ushort* arrayData, int width, int height);		//#处理 获得一维数组,并将其设置为imgData.srcArray
	void createArray16(int width, int height);							//#处理 生成递增一维数组
	void calcMapTable(
		int bottom = 0,
		int top = 65535,
		const int srcBytes = 16,
		const int dstBytes = 8
		);//#处理 计算灰度映射图
	void Array16to8(int bottom = 0, int top = 65535);

	//#测试 输出array Mat 到本地
	void writeData(int width, int height);
	void writeArray(ushort* &array);									//将array输出到外部
	void writeArray(uchar* &array);
	void writeMat(const cv::Mat &mat);


	bool event(QEvent *event);                  //#界面 Qt的事件分发集合
	inline void paintEvent(QPaintEvent *event);	//#界面 绘制事件
	void wheelEvent(QWheelEvent *e);			//#界面 滚轮


	QPixmap Mat16toPix8(const cv::Mat &mat);	//#处理  Mat2Pix
	cv::Mat Array16toMat(ushort* array, int w, int h);//#处理  Array2Mat
	QPixmap Array8toPix();						//#处理  Array2Pix

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

	//#数据 状态栏struct
	struct BottomStatus{
		double width;
		double height;
		int depth;
		double value;
		double pos_x;
		double pos_y;
		double ratio;
	};

	//#数据 图像struct
	struct ImgData{
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

	//#界面
	Ui::canvas *ui;
	int m_imgStartX;            //图像起始点的x
	int m_imgStartY;            //图像起始点的y

	//#数据 绘制参数结构
	struct DrawParams{
		QRect canvsRect;			//画板大小
		double zoomRatio;			//缩放大小
		double zoomStepRatio = 0.1;	//缩放改变率
		double moveRatio = 1;		//移动改变比率
		double maxZoomRatio;		//最大放大率
		QPoint singOffset;			//单次鼠标偏移距离
		QPoint sumOffset = QPoint(0, 0);//最终偏移距离
	};
	//#数据 操作enum
	int m_action;                       //动作(放大,缩小,移动...)


	ImgData *m_imgData = new ImgData();
	BottomStatus m_status;
	DrawParams *m_drawParams = new DrawParams();

	//标志位
	bool m_readyDisplay = false;
};

#endif // CANVAS_H
