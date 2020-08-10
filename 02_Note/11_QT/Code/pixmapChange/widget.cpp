#include "widget.h"
#include <QDebug>

Widget::Widget():
    BigButton("放大",this),
    LittleButton("缩小",this),
    LiftButton("向左",this),
    RightButton("向右",this),
    UpButton("向上",this),
    DownButton("向下",this),
    Paint(5,5,910,910),
    m_all_offsets(0,0),
    label("100%",this)
{
    m_pix_ratio= 1.0;             //初始化图片缩放比例
    action = Widget::None;
    m_pix_width = 910;            //设置图片尺寸为985*740
    m_pix_height = 910;
    Mat mat =imread("C:\\28.tif",CV_LOAD_IMAGE_UNCHANGED);
    pix = Mat2Pix(mat);
    srcPix = pix.copy();
//    pix->load("C:\\test.tif");

    BigButton.setGeometry(920,10,60,25);
    connect(&BigButton,SIGNAL(clicked()),this,SLOT(onBigClicked()));

    LittleButton.setGeometry(920,40,60,25);
    connect(&LittleButton,SIGNAL(clicked()),this,SLOT(onLittleClicked()));

    LiftButton.setGeometry(920,70,60,25);
    connect(&LiftButton,SIGNAL(clicked()),this,SLOT(OnLiftClicked()));
    RightButton.setGeometry(920,100,60,25);
    connect(&RightButton,SIGNAL(clicked()),this,SLOT(OnRightClicked()));
    UpButton.setGeometry(920,130,60,25);
    connect(&UpButton,SIGNAL(clicked()),this,SLOT(onUpClicked()));
    DownButton.setGeometry(920,160,60,25);
    connect(&DownButton,SIGNAL(clicked()),this,SLOT(onDownClicked()));
    label.move(920,200);
    resize(1000,930);

}

//事件分发
bool Widget::event(QEvent * event)
{
    static bool ctrlLefbtnPressed=false;
    static QPoint PreDot;
    static bool ctrlIsPressed=false;

    if(event->type()==QEvent::KeyPress){
        QKeyEvent *keyBoard = dynamic_cast<QKeyEvent* >(event);
        if(keyBoard->key()==Qt::Key_Control){
            ctrlIsPressed=true;
            QApplication::setOverrideCursor(Qt::OpenHandCursor); //设置鼠标样式
        }
    }
    else if(event->type()==QEvent::KeyRelease){
        QKeyEvent *keyBoard = dynamic_cast<QKeyEvent* >(event);
        if(keyBoard->key()==Qt::Key_Control){
            ctrlIsPressed=false;
            QApplication::setOverrideCursor(Qt::ArrowCursor);   //改回鼠标样式
        }
    }
    else if(event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
        if(mouse->button()==Qt::LeftButton &&Paint.contains(mouse->pos()))
        {
            if(ctrlIsPressed){
                ctrlLefbtnPressed=true;                 //ctrl+鼠标左键同时按下 设置标志位
                PreDot = mouse->pos();                  //记录左键按下的坐标
            }
        }
    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        //判断鼠标是否是左键释放,且之前是在绘画区域
        if(mouse->button()==Qt::LeftButton && ctrlLefbtnPressed )
        {
            ctrlLefbtnPressed=false;
        }
    }
    if(event->type() == QEvent::MouseMove)              //移动图片
    {
        if(ctrlLefbtnPressed)
        {
            QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
            offset.setX(mouse->x() - PreDot.x());
            offset.setY(mouse->y() - PreDot.y());
            PreDot = mouse->pos();
            action = Widget::Move;
            this->update();
        }
    }
    return QWidget::event(event);
}

void Widget::wheelEvent(QWheelEvent* event)     //鼠标滑轮事件
{
    if (event->delta()>0) {      //上滑,缩小
        action=Widget::Shrink;
        this->update();
    } else {                    //下滑,放大
        action=Widget::Amplification;
        this->update();
    }
    event->accept();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    int crtWidth = m_pix_ratio *m_pix_width;
    int crtHeight = m_pix_ratio *m_pix_height;

    if(action==Widget::Amplification)           //缩小
    {
        m_pix_ratio-=0.05*m_pix_ratio;
        if(m_pix_ratio<1)
            m_pix_ratio = 1;
        /*显示比例*/
        QString str;
        str.sprintf("%.0f%",m_pix_ratio*100);
        label.setText(str) ;
    }
    else if(action==Widget::Shrink)             //放大
    {
        m_pix_ratio+=0.05*m_pix_ratio;
        if(m_pix_ratio>4.5)
            m_pix_ratio = 5.000;
        /*显示比例*/
        QString str;
        str.sprintf("%.0f%",m_pix_ratio*100);
        label.setText(str);
    }
    if(action==Widget::Amplification || action==Widget::Shrink)     //更新图片
    {
        crtWidth = m_pix_ratio *m_pix_width;
        crtHeight = m_pix_ratio *m_pix_height;
        pix = srcPix;                                               //重新装载,因为之前的图片已经被缩放过
        pix = pix.scaled(crtWidth, crtHeight,Qt::KeepAspectRatio);
        action=Widget::None;
    }
    if(action==Widget::Move)                    //移动
    {
        int offsetx=m_all_offsets.x()+offset.x();
        m_all_offsets.setX(offsetx);

        int offsety=m_all_offsets.y()+offset.y();
        m_all_offsets.setY(offsety);
        action=Widget::None;
    }

    if(abs(m_all_offsets.x())>=(Paint.width()/2 + crtWidth/2 -10))    //限制X偏移值
    {
        if(m_all_offsets.x()>0)
            m_all_offsets.setX(Paint.width()/2 + crtWidth/2 -10);
        else
            m_all_offsets.setX(-Paint.width()/2 + -crtWidth/2 +10);
    }
    if(abs(m_all_offsets.y())>=(Paint.height()/2 + crtHeight/2 -10))    //限制Y偏移值
    {
        if(m_all_offsets.y()>0)
            m_all_offsets.setY(Paint.height()/2 + crtHeight/2 -10);
        else
            m_all_offsets.setY(-Paint.height()/2 + -crtHeight/2 +10);
    }

    qDebug()<<"paint.width="<<Paint.width()<<" paint.height="<<Paint.height();
    qDebug()<<"Alloffset.x="<<m_all_offsets.x()<<" Alloffset.y="<<m_all_offsets.y();
    qDebug()<<"crtWidth=    "<<crtWidth<<"crtHeight= "<<crtHeight;
    int x = Paint.width()/2 + m_all_offsets.x() -crtWidth/2;
    if(x<0)
        x=0;

    int y = Paint.height()/2 + m_all_offsets.y() -crtHeight/2;
    if(y<0)
        y=0;

    int  sx = crtWidth/2 - Paint.width()/2 - m_all_offsets.x();
    if(sx<0)
        sx=0;

    int  sy = crtHeight/2 - Paint.height()/2 - m_all_offsets.y();
    if(sy<0)
        sy=0;

    int w =(crtWidth - sx)>Paint.width()? Paint.width() : (crtWidth - sx);
    if(w>(Paint.width()-x))
        w = Paint.width()-x;

    int h =(crtHeight - sy)>Paint.height()? Paint.height() : (crtHeight - sy);
    if(h>(Paint.height()-y))
        h = Paint.height()-y;

    if(x>0)
        x=0;
    if(y>0)
        y=0;
    if(sx+910>crtWidth){
        sx=crtWidth-910;
    }
    if(sy+910>crtHeight){
        sy=crtHeight-910;
    }
    qDebug()<<"x="<<x<<" y="<<y<<" w="<<w<<" h="<<h<<" sx="<<sx<<" sy="<<sy;

    painter.drawRect(Paint.x()-1,Paint.y()-1,Paint.width()+1,Paint.height()+1);     //画框
    painter.drawTiledPixmap(x+Paint.x(),y+Paint.y(),910,910,pix,sx,sy);             //绘画图形
}


void  Widget::onLittleClicked()
{
    action=Widget::Amplification;
    this->update();
}

void  Widget::onBigClicked()
{
    action=Widget::Shrink;
    this->update();
}
void Widget::onUpClicked()
{
    action=Widget::Move;
    offset.setX(0);
    offset.setY(-20);

    this->update();
}
void Widget::onDownClicked()
{
    action=Widget::Move;
    offset.setX(0);
    offset.setY(20);
    this->update();
}
void Widget::OnLiftClicked()
{
    action=Widget::Move;
    offset.setX(-20);
    offset.setY(0);

    this->update();
}
void Widget::OnRightClicked()
{
    action=Widget::Move;
    offset.setX(20) ;
    offset.setY(0) ;

    this->update();
}

QPixmap Widget::Mat2Pix(const Mat &mat)
{
    Mat tempMat;
    mat.convertTo(tempMat, CV_8UC1,255/65535.0,0);	//将原图转换成CV_8U
    QImage img = QImage((const unsigned char*)(tempMat.data),
        tempMat.cols, tempMat.rows,
        tempMat.cols * tempMat.channels(),
        QImage::Format_Grayscale8);
    QPixmap imgPix = QPixmap::fromImage(img.scaled(QSize(910,910), Qt::KeepAspectRatio));
    return imgPix;

}
