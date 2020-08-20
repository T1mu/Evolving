#ifndef THREEDIMIMAGEVIEW_H
#define THREEDIMIMAGEVIEW_H

#include <QWidget>
#include "ui_threeDimImageView.h"
#ifdef _DEBUG  
#pragma  comment(lib,"../x64/Debug/BllProject.lib")
#else  
#pragma  comment(lib,"../x64/Release/BllProject.lib")
#endif 
#include "../BllProject/BllDataFlow.h"
class threeDimImageView : public QWidget
{
	Q_OBJECT
	public slots:
	void setSliderNum(int num);
	void receivePicSlot();
public:
	threeDimImageView(QWidget *parent = 0);
	~threeDimImageView();
	
protected:
	virtual void paintEvent(QPaintEvent * event);
private:
	Ui::threeDimImageView ui;
	BllDataFlow *m_blldataflow;
	int sliderNum;//滑条对应的值
	uchar* m_8bitgrayImg;//8位图像
	qint16 *arrayData;//所有切片的数据
	qint16 *viewData;//当前显示的数据
	int ***arrThreeDim;
	int imgNum;
	int imgRow;
	int imgCol;
	int *pixelsCenter;
	int *pixelsWidth;
	double m_scale;
};

#endif // THREEDIMIMAGEVIEW_H
