#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QApplication>
#include <QComboBox>
#include <opencv.hpp>
#include <QPixmap>
#pragma execution_character_set("utf-8")

using namespace cv;

class Widget : public QWidget
{
    Q_OBJECT

private :
    QPixmap  pix;
    QPixmap srcPix;
    int action;             //动作(放大,缩小,移动...)
    int m_pix_width;               //图片宽
    int m_pix_height;               //图片高

    QRect Paint;            //绘画区域

    float m_pix_ratio;                //比例
    QPoint offset;              //一次的图片偏移值
    QPoint m_all_offsets;           //总偏移
    QLabel label;

    QPushButton  BigButton;
    QPushButton  LittleButton;
    QPushButton  LiftButton;
    QPushButton  RightButton;
    QPushButton  UpButton;
    QPushButton  DownButton;

    void AddComboItem(QComboBox* cmbo);
    bool event(QEvent * event);
    void wheelEvent(QWheelEvent* e);     //鼠标滑轮事件
    QPixmap Mat2Pix(const Mat &mat);
private slots:
    void    onUpClicked();
    void    onDownClicked();
    void    OnLiftClicked();
    void    OnRightClicked();
    void    onLittleClicked();
    void    onBigClicked();


   void paintEvent(QPaintEvent *event);
public:
    explicit Widget();

   enum  Type {
       None          = 0,
       Amplification ,
       Shrink,
       Lift,
       Right,
       Up,
       Down,
       Move
   };

};
#endif // WIDGET_H

