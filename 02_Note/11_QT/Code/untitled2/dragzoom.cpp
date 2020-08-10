#include "dragzoom.h"
#include "ui_dragzoom.h"
#include "QPainter"
#include <QWheelEvent>
#include <QMouseEvent>
#include <QDebug>
DragZoom::DragZoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragZoom)
{
    ui->setupUi(this);
    this->setMinimumSize(910,910);
    this->setMaximumSize(910,910);

    //display(QString("C:\\opencv3.4.0\\sources\\doc\\tutorials\\dnn\\dnn_yolo\\images\\yolo.jpg"));
}

DragZoom::~DragZoom()
{
    delete ui;
}

void DragZoom::display(QString path)
{
    QPalette palette;
    palette.setBrush(/*QPalette::Background*/this->backgroundRole(),
                         QBrush(QPixmap(path)));
    this->setPalette(palette);
}

void DragZoom::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter pBack(this);
    QPixmap pix;
    pix.load("C:\\opencv3.4.0\\sources\\doc\\tutorials\\dnn\\dnn_yolo\\images\\yolo.jpg");
    pix = pix.scaled(width, height, Qt::KeepAspectRatio);
    //将图片的宽和高都扩大两倍，并且在给定的矩形内保持宽高的比值
    pBack.drawPixmap(m_x,m_y,pix);
}

void DragZoom::wheelEvent(QWheelEvent *event)
{
    if(event->delta()>0){
        width *=1.2;
        height *=1.2;
    }
    else{
        if(height>910){
            width /=1.2;
            height /=1.2;
        }
    }
    qDebug()<<"width:"<<width;
    update();
}

void DragZoom::mouseMoveEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        m_x = event->
        m_y = event->pos().y();
    }
}
