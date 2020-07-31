#include "canvas.h"
#include "ui_canvas.h"

canvas::canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
    m_canvas_width=910;     //set接口
    m_canvas_height=910;    //set接口
    initUi();

    this->SetMat(QString("D:\\2020.6.3\\xRayChipCounter\\mode2\\2020-06-08_09-52-29\\24.tif"));
    this->DisplayMat(m_src_mat);
}

canvas::~canvas()
{
    delete ui;
}

void canvas::setCanvasSize(const int width,const int height)
{
    if(width<=0||height<=0){
        QMessageBox mesg;
        mesg.warning(this,"width or height Error!","width or height number lower than 0");
    }else{
        this->setMinimumSize(width,height);
        this->setMaximumSize(width,height);
    }
}

void canvas::setCanvasWidth(int w)
{
    if(w<=0){
        QMessageBox mesg;
        mesg.warning(this, "width Error!", "width lower than 0");
    }else{
        this->setMaximumWidth(w);
        this->setMinimumWidth(w);
    }
}

void canvas::setCanvasHeight(int h)
{
    if(h<=0){
        QMessageBox mesg;
        mesg.warning(this,"height Error!","width lower than 0");
    }
    else{
        this->setMaximumHeight(h);
        this->setMinimumHeight(h);
    }
}

void canvas::initUi()
{
    this->setCanvasSize(m_canvas_width,m_canvas_height);
    m_canvas_rect=QRect(0,0,m_canvas_width,m_canvas_height);
}

void canvas::SetMat(const Mat &mat)
{
    if(!mat.data){
        QMessageBox mesg;
        mesg.warning(this, "SetMat_WARNING", "mat.data is EMPTY!");
    }
    else{
        m_src_mat = mat;
        m_src_pix = Mat2Pix(m_src_mat);
    }
}

void canvas::SetMat(const QString &path)
{
    Mat mat =imread(path.toStdString(), CV_LOAD_IMAGE_UNCHANGED);
    if (!mat.data)
    {
        QMessageBox mesg;
        mesg.warning(this, "SetMat_WARNING", "mat.data is EMPTY!");
    }else{
        m_src_mat = mat;
        m_src_pix = Mat2Pix(m_src_mat);
    }
}

void canvas::DisplayMat(const Mat &mat)
{
    m_CanPAINT = true;
    m_src_mat = mat;
    m_src_pix = Mat2Pix(mat);
    m_statusInfo.depth = mat.depth()*8;
    m_statusInfo.width = mat.cols;
    m_statusInfo.height = mat.rows;
    m_pix_ratio = (double)this->width()/m_src_pix.width(); //设置缩放变量
}

void canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    qDebug()<<"initRatio:"<<m_pix_ratio;
    m_pix_width = m_src_pix.width();
    m_pix_height = m_src_pix.height();
    int crtWidth = m_pix_ratio *m_pix_width;
//    qDebug()<<"=====crtWidth:"<<crtWidth;
//    qDebug()<<"=====m_pix_ratio:"<<m_pix_ratio;
//    qDebug()<<"=====m_pix_width:"<<m_pix_width;
    int crtHeight = m_pix_ratio *m_pix_height;

    if(m_action==canvas::Shrink)           //缩小
    {
        m_pix_ratio-=0.05*m_pix_ratio;
        if(m_pix_ratio<(double)this->width()/m_src_pix.width())
            m_pix_ratio = (double)this->width()/m_src_pix.width();
        /*显示比例*/
        m_statusInfo.ratio = m_pix_ratio;
//        str.sprintf("%.0f%",m_pix_ratio*100);
//        label.setText(str) ;
        qDebug()<<"缩小ratio:"<<m_pix_ratio;
    }
    else if(m_action==canvas::Amplification)             //放大
    {
        m_pix_ratio+=0.05*m_pix_ratio;
        if(m_pix_ratio>4.5)
            m_pix_ratio = 5.000;
        /*显示比例*/
        m_statusInfo.ratio = m_pix_ratio;
    }
    if(m_action==canvas::Amplification || m_action==canvas::Shrink)     //更新图片
    {
        crtWidth = m_pix_ratio *m_pix_width;
        crtHeight = m_pix_ratio *m_pix_height;
        m_crt_pix = m_src_pix;                                               //重新装载,因为之前的图片已经被缩放过
        m_crt_pix = m_crt_pix.scaled(crtWidth, crtHeight,Qt::KeepAspectRatio);
        m_action=canvas::None;
    }
    if(m_action==canvas::Move)                    //移动
    {
        int offsetx=m_all_offsets.x()+m_single_offset.x();
        m_all_offsets.setX(offsetx);

        int offsety=m_all_offsets.y()+m_single_offset.y();
        m_all_offsets.setY(offsety);
        m_action=canvas::None;
    }

    if(abs(m_all_offsets.x())>=(this->width()/2 + crtWidth/2 -10))    //限制X偏移值
    {
        if(m_all_offsets.x()>0)
            m_all_offsets.setX(this->width()/2 + crtWidth/2 -10);
        else
            m_all_offsets.setX(-this->width()/2 + -crtWidth/2 +10);
    }
    if(abs(m_all_offsets.y())>=(this->height()/2 + crtHeight/2 -10))    //限制Y偏移值
    {
        if(m_all_offsets.y()>0)
            m_all_offsets.setY(this->height()/2 + crtHeight/2 -10);
        else
            m_all_offsets.setY(-this->height()/2 + -crtHeight/2 +10);
    }
//    qDebug()<<"____________INFO___________";
//    qDebug()<<"paint.width="<<this->width()<<" paint.height="<<this->height();
//    qDebug()<<"Alloffset.x="<<m_all_offsets.x()<<" Alloffset.y="<<m_all_offsets.y();
//    qDebug()<<"crtWidth=    "<<crtWidth<<"crtHeight= "<<crtHeight;
    int x = this->width()/2 + m_all_offsets.x() -crtWidth/2;
    if(x<0)
        x=0;
    int y = this->height()/2 + m_all_offsets.y() -crtHeight/2;
    if(y<0)
        y=0;
    int  sx = crtWidth/2 - this->width()/2 - m_all_offsets.x();
    if(sx<0)
        sx=0;
    int  sy = crtHeight/2 - this->height()/2 - m_all_offsets.y();
    if(sy<0)
        sy=0;

    int w =(crtWidth - sx)>this->width()? this->width() : (crtWidth - sx);
    if(w>(this->width()-x))
        w = this->width()-x;

    int h =(crtHeight - sy)>this->height()? this->height() : (crtHeight - sy);
    if(h>(this->height()-y))
        h = this->height()-y;

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
    qDebug()<<"==============绘制信息===============";
    qDebug()<<"画板起始点x:"<<x<<" 画板起始点y:"<<y<<" 画板宽度:"
           <<w<<" 画板高度:"<<h<<" 图像起始点x:"<<sx<<" 图像起始点y:"<<sy;
    painter.drawTiledPixmap(x,y,this->width(),this->height(),m_crt_pix,sx,sy);             //绘画图形

    //更新label信息
    ui->label->setText(QString(" Depth:%1  Size:[%2*%3]  Ratio: %4%").arg(m_statusInfo.depth).arg(m_statusInfo.width)
                       .arg(m_statusInfo.height).arg(m_statusInfo.ratio*100));
}

void canvas::wheelEvent(QWheelEvent *event)
{
    if (event->delta()<0) {      //上滑,缩小
        m_action=canvas::Shrink;
        this->update();
    } else {                    //下滑,放大
        m_action=canvas::Amplification;
        this->update();
    }
    event->accept();
}

bool canvas::event(QEvent *event)
{
    static bool ctrlLefbtnPressed=false;
    static bool ctrlIsPressed=false;
    static QPoint PreDot;
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
    if(event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
        if(mouse->button()==Qt::LeftButton &&m_canvas_rect.contains(mouse->pos()))
        {
//            qDebug()<<"=============MouseMove============";
//            qDebug()<<"ctrlIsPressed :"<<ctrlIsPressed;
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
            m_single_offset.setX(mouse->x() - PreDot.x());
            m_single_offset.setY(mouse->y() - PreDot.y());
            PreDot = mouse->pos();
            m_action = canvas::Move;
            this->update();
//            qDebug()<<"=============MouseMove============";
//            qDebug()<<"m_single_offset :"<<m_single_offset;

        }
    }
    return QWidget::event(event);
}

QPixmap canvas::Mat2Pix(const Mat &mat)
{
    Mat tempMat;
    mat.convertTo(tempMat, CV_8UC1,255/65535.0,0);	//将原图转换成CV_8U
    QImage img = QImage((const unsigned char*)(tempMat.data),
        tempMat.cols, tempMat.rows,
        tempMat.cols*tempMat.channels(),
        QImage::Format_Grayscale8);
    QPixmap imgPix = QPixmap::fromImage(img);
//    qDebug()<<"mat    Size:"<<mat.cols;
//    qDebug()<<"tempMatSize:"<<tempMat.cols;
//    qDebug()<<"img    Size:"<<img.size();
//    qDebug()<<"imgPix Size:"<<imgPix.size();
    return imgPix;
}
