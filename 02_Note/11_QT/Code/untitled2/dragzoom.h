#ifndef DRAGZOOM_H
#define DRAGZOOM_H

#include <QWidget>
#include <opencv.hpp>

namespace Ui {
class DragZoom;
}

using namespace cv;
class DragZoom : public QWidget
{
    Q_OBJECT

public:
    explicit DragZoom(QWidget *parent = 0);
    ~DragZoom();
    void display(QString);
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    Ui::DragZoom *ui;
    qreal width = 910;
    qreal height = 910;
    qreal m_x=0;
    qreal m_y=0;
};

#endif // DRAGZOOM_H
