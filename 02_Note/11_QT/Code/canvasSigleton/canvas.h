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

#pragma execution_character_set("utf-8")

namespace Ui {
class canvas;
}
using namespace cv;

struct statusInfo{
    double width;
    double height;
    int depth;
    double value;
    double pos_x;
    double pos_y;
    double ratio=1.0;
};

class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = 0);
    ~canvas();
    //界面相关
    void setCanvasSize(const int width,const int height);
    void setCanvasWidth(int w);
    void setCanvasHeight(int h);
    void initUi();
    //接口函数
    void SetMat(const Mat &mat);                //设置m_src_mat 和 m_src_pix 参数类型为Mat
    void SetMat(const QString &path);           //设置m_src_mat 和 m_src_pix 参数类型为QString
    void DisplayMat(const Mat &mat);            //绘制m_src_pix 到画板上 并设置为 m_crt_pix
    //事件
    bool event(QEvent *event);                  //Qt事件分发
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *e);

    QPixmap Mat2Pix(const Mat &mat);
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
private:
    //界面相关
    int m_canvas_width;
    int m_canvas_height;

    Ui::canvas *ui;

    //Mat相关
    Mat m_src_mat;      //源Mat
    Mat m_crt_mat;      //当前显示Mat
    Mat m_changed_mat;  //修改后的Mat
    QPixmap m_src_pix;      //源
    QPixmap m_crt_pix;      //当前
    QPixmap m_changed_pix;  //修改

    //pix相关
    int m_pix_width;
    int m_pix_height;
    //动作相关
    int m_action;                       //动作(放大,缩小,移动...)
    QRect m_canvas_rect;
    double m_pix_ratio ;           //与原图比例
    QPoint m_single_offset;             //单次偏移
    QPoint m_all_offsets=QPoint(0,0);   //总偏移


    statusInfo m_statusInfo;
    bool m_CanPAINT = false;


};

#endif // CANVAS_H
