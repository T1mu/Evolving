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
    void SetRatio(double zoom_ratio, double move_ratio, double max_ratio);            //接口 用于设置缩放比例 移动比例 放大率上限
    //数据接口
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

private slots:
    void on_helpBtn_clicked(bool checked);

private:
    //界面相关
    int m_canvas_width;
    int m_canvas_height;

    Ui::canvas *ui;

    //Mat相关
    Mat m_src_mat;              //源Mat
    Mat m_crt_mat;              //当前显示Mat
    Mat m_changed_mat;          //修改后的Mat
    QPixmap m_src_pix;          //源
    QPixmap m_crt_pix;          //当前
    QPixmap m_changed_pix;      //修改

    //pix相关
    int m_srcPixWidth;
    int m_srcPixHeight;
    int m_pix_x;            //图像起始点的x
    int m_pix_y;            //图像起始点的y
    //动作相关
    int m_action;                       //动作(放大,缩小,移动...)
    QRect m_canvas_rect;
    double m_zoomRatio ;           //当前图与原图比例
    double m_zoomStepRatio = 0.1;
    double m_moveRatio = 1;
    double m_maxZoomRatio ;
    QPoint m_single_offset;             //单次偏移
    QPoint m_all_offsets=QPoint(0,0);   //总偏移

    bottomStatus m_status;

    //标志位
    bool m_IsPAINTED = false;
//    bool m_is_X_Edge = false;
//    bool m_is_Y_Edge = false;


};

#endif // CANVAS_H
