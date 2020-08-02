#include "canvas.h"
#include "ui_canvas.h"

canvas::canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
    initUi();

    this->SetMat(QString("D:\\11_XProject\\imgST\\imgST\\default.tif"));
    //D:\\2020.6.3\\xRayChipCounter\\mode2\\2020-06-08_09-52-29\\24.tif
    this->DisplayMat(m_src_mat);
    this->setMouseTracking(true);
}

canvas::~canvas()
{
    delete ui;
}

void canvas::setCanvasSize(const int width = 910,const int height = 910)
{
    if(width<=0||height<=0){
        QMessageBox mesg;
        mesg.warning(this,"width or height Error!","width or height number lower than 0");
    }else{
        this->setMinimumSize(width,height);
        this->setMaximumSize(width,height);
        m_canvas_width=width;
        m_canvas_height=height;
    }
}

void canvas::setCanvasWidth(int w = 910)
{
    if(w<=0){
        QMessageBox mesg;
        mesg.warning(this, "width Error!", "width lower than 0");
    }else{
        this->setMaximumWidth(w);
        this->setMinimumWidth(w);
        m_canvas_width=w;
    }
}

void canvas::setCanvasHeight(int h = 910)
{
    if(h<=0){
        QMessageBox mesg;
        mesg.warning(this,"height Error!","width lower than 0");
    }
    else{
        this->setMaximumHeight(h);
        this->setMinimumHeight(h);
        m_canvas_height=h;
    }
}

void canvas::initUi()
{
    this->setCanvasSize();
    this->setCursor(Qt::CrossCursor);				//设置鼠标样式
    m_canvas_rect=QRect(0,0,m_canvas_width,m_canvas_height);
    ui->ShortCutTipsLab->hide();
    ui->label->setGeometry(0,m_canvas_height-20,m_canvas_width,20);
    ui->helpBtn->setGeometry(m_canvas_width-ui->helpBtn->width(),m_canvas_height-20,ui->helpBtn->width(),20);
    ui->ShortCutTipsLab->setGeometry(ui->helpBtn->x()+ui->helpBtn->width()-ui->ShortCutTipsLab->width(),ui->helpBtn->y()-ui->ShortCutTipsLab->height(),
                                     ui->ShortCutTipsLab->width(),ui->ShortCutTipsLab->height());
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
    m_crt_mat = mat;
    m_src_pix = Mat2Pix(mat);
    m_crt_pix = m_src_pix;
    m_statusInfo.depth = mat.depth()*8;
    m_statusInfo.width = mat.cols;
    m_statusInfo.height = mat.rows;
    m_crt_zoom_ratio = (double)this->width()/m_src_pix.width(); //设置缩放变量
}

void canvas::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);

    //qDebug()<<"initRatio:"<<m_init_zoom_ratio;
    m_pix_width = m_src_pix.width();
    m_pix_height = m_src_pix.height();
    int crtWidth = m_crt_zoom_ratio *m_pix_width;
    int crtHeight = m_crt_zoom_ratio *m_pix_height;

    m_crt_pix = m_crt_pix.scaled(crtWidth, crtHeight,Qt::KeepAspectRatio);

    if(m_action==canvas::Shrink)           //缩小
    {
        m_crt_zoom_ratio-=m_zoom_ratio*m_crt_zoom_ratio;
        if(m_crt_zoom_ratio<(double)this->width()/m_src_pix.width())
            m_crt_zoom_ratio = (double)this->width()/m_src_pix.width();
    }
    else if(m_action==canvas::Amplification)             //放大
    {
        m_crt_zoom_ratio+=m_zoom_ratio*m_crt_zoom_ratio;
        if(m_crt_zoom_ratio > 3)
            m_crt_zoom_ratio = 3;
    }
    if(m_action==canvas::Amplification || m_action==canvas::Shrink)     //更新图片
    {
        crtWidth = m_crt_zoom_ratio *m_pix_width;
        crtHeight = m_crt_zoom_ratio *m_pix_height;
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

//        qDebug()<<"=======offset=======\noffsetx:"<<offsetx<<"\noffsety:"<<offsety;
//        qDebug()<<"=======m_all_offsets=======\nm_all_offsets x:"<<m_all_offsets.x()<<"\n m_all_offsets y:"<<m_all_offsets.y();
        m_action=canvas::None;
    }

    //限制图片不移出框外
    int x = this->width()/2 + m_all_offsets.x() -crtWidth/2;
    if(x<0){
        x=0;
//        m_is_X_Edge = true;
        //TODO: 移动到边界多了 需要同样的反向操作
    }

    int y = this->height()/2 + m_all_offsets.y() -crtHeight/2;
    if(y<0){
        y=0;
//        m_is_Y_Edge = true;
    }
//    qDebug()<< QString("窗体宽度:%1 \n 总偏移量:(%2,%3) \n(%4,%5)").arg(this->width()).arg(m_all_offsets.x()).arg(m_all_offsets.y()).arg(x).arg(y);
    m_pix_x = crtWidth/2 - this->width()/2 - m_all_offsets.x();
    if(m_pix_x<0)
        m_pix_x=0;
    m_pix_y = crtHeight/2 - this->height()/2 - m_all_offsets.y();
    if(m_pix_y<0)
        m_pix_y=0;

//    int w =(crtWidth - m_pix_x)>this->width()? this->width() : (crtWidth - m_pix_x);
//    if(w>(this->width()-x))
//        w = this->width()-x;

//    int h =(crtHeight - m_pix_y)>this->height()? this->height() : (crtHeight - m_pix_y);
//    if(h>(this->height()-y))
//        h = this->height()-y;
    if(x>0)
        x=0;
    if(y>0)
        y=0;
    if(m_pix_x+this->width()>crtWidth){
        m_pix_x=crtWidth-this->width();
    }
    if(m_pix_y+this->width()>crtHeight){
        m_pix_y=crtHeight-this->width();
    }
//    qDebug()<<"==============绘制信息===============";
//    qDebug()<<"画板x:"<<x<<" 画板y:"<<" \n图像起始点x:"<<m_pix_x<<" 图像起始点y:"<<m_pix_y;
    painter.drawTiledPixmap(x,y,this->width(),this->height(),m_crt_pix,m_pix_x,m_pix_y);             //绘画图形

    //更新label信息
    m_statusInfo.ratio = m_crt_zoom_ratio;
    ui->label->setText(QString(" 深度: %1 | 大小: [%2*%3] | 缩放率: %4% | 坐标: (%5, %6) | 灰度值: %7")
                       .arg(m_statusInfo.depth)
                       .arg(m_statusInfo.width).arg(m_statusInfo.height)
                       .arg(m_statusInfo.ratio*100)
                       .arg((int)m_statusInfo.pos_x,5).arg((int)m_statusInfo.pos_y,5)
                       .arg(m_statusInfo.value,5));
}

void canvas::wheelEvent(QWheelEvent *event)
{
    if (event->delta()<0) {         //下滑,缩小
        m_action=canvas::Shrink;
        this->update();
    } else {                        //上滑,放大
        m_action=canvas::Amplification;
        this->update();
    }
    event->accept();
}

void canvas::SetInitRatio(double ratio)
{
    this->m_crt_zoom_ratio = ratio;
}

bool canvas::event(QEvent *event)
{
    static bool ctrlLefbtnPressed=false;
    static bool ctrlIsPressed=false;
    static QPoint PreDot;
    //ctrl按下与松开的标志位设置
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
            QApplication::setOverrideCursor(Qt::CrossCursor);   //改回鼠标样式
        }
    }
    //ctrl+0按下 设置初始缩放比例为1.0 即原图大小
    if(event->type()==QEvent::KeyPress){
        QKeyEvent *keyBoard = dynamic_cast<QKeyEvent* >(event);
        if(keyBoard->key()==Qt::Key_0 && ctrlIsPressed){        //ctrl+0 原图比例
            SetInitRatio(1.0);
//            qDebug()<<"setInitRatio=1.0";
            update();
        }
    }
    //ctrl+1按下 设置缩放比例为布满画板
    if(event->type()==QEvent::KeyPress){
        QKeyEvent *keyBoard = dynamic_cast<QKeyEvent* >(event);
        if(keyBoard->key()==Qt::Key_1 && ctrlIsPressed){
            SetInitRatio(this->width()*1.0/m_src_pix.width());
//            qDebug()<<"full of canvas";
            update();
        }
    }
    if(event->type() == QEvent::MouseButtonPress )
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        //判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
        if(mouse->button()==Qt::LeftButton && m_canvas_rect.contains(mouse->pos()))
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
        if(mouse->button()==Qt::LeftButton && ctrlLefbtnPressed )
        {
            ctrlLefbtnPressed=false;
        }

    }
    if(event->type() == QEvent::MouseMove)              //移动图片
    {
        QMouseEvent *mouse = dynamic_cast<QMouseEvent* >(event);
        if(ctrlLefbtnPressed)
        {
            qDebug() << QString("%1").arg(m_is_X_Edge);


            m_single_offset.setX(mouse->x() - PreDot.x());



            m_single_offset.setY(mouse->y() - PreDot.y());
            qDebug()<<mouse->x()<<PreDot<<m_single_offset;
            PreDot = mouse->pos();

            m_action = canvas::Move;
        }

        m_statusInfo.pos_x = m_pix_x/m_crt_zoom_ratio + mouse->pos().x()/m_crt_zoom_ratio;
        m_statusInfo.pos_y = m_pix_y/m_crt_zoom_ratio + mouse->pos().y()/m_crt_zoom_ratio;
        if(m_crt_mat.data){
            ushort* pxvec = m_crt_mat.ptr<ushort>(m_statusInfo.pos_y); //每行的头地址
            m_statusInfo.value = pxvec[(int)m_statusInfo.pos_x];

        }
        update();
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

void canvas::on_helpBtn_clicked(bool checked)
{
    if(checked)
        ui->ShortCutTipsLab->show();
    else
        ui->ShortCutTipsLab->hide();
}
