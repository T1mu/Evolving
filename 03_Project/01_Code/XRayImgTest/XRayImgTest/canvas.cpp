#include "canvas.h"
#include "ui_canvas.h"

canvas::canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
    initUi();

    this->getImg(QString("D:\\2020.6.3\\xRayChipCounter\\mode2\\2020-06-08_09-52-29\\24.tif"));
    //D:\\2020.6.3\\xRayChipCounter\\mode2\\2020-06-08_09-52-29\\24.tif
    this->DisplayMat(m_src_mat);

    this->setMouseTracking(true);
}

canvas::~canvas()
{
    delete ui;
}

void canvas::setCanvasSize(const unsigned int width = 910,const unsigned int height = 930)
{
    m_canvas_width=width;
    m_canvas_height=height;
    this->setMinimumSize(width,height);
    this->setMaximumSize(width,height);
}

void canvas::setCanvasWidth(const unsigned int w = 910)
{
    m_canvas_width=w;
    this->setMaximumWidth(w);
    this->setMinimumWidth(w);
}

void canvas::setCanvasHeight(const unsigned int h = 910)
{
    m_canvas_height=h;
    this->setMaximumHeight(h);
    this->setMinimumHeight(h);

}

void canvas::initUi()
{
    this->setCanvasSize(910, 930);
    this->setCursor(Qt::CrossCursor);                                   //设置鼠标样式
    this->SetRatio(0.1, 1.0, 3.0);                                      //设置缩放和移动比例
    m_canvas_rect=QRect(0,0,m_canvas_width,m_canvas_height);

    //Ui界面底部控件位置的设置
    ui->ShortCutTipsLab->hide();
    ui->label->setGeometry(0,m_canvas_height-20,m_canvas_width,20);
    ui->helpBtn->setGeometry(m_canvas_width-ui->helpBtn->width(),m_canvas_height-20,ui->helpBtn->width(),20);
    ui->ShortCutTipsLab->setGeometry(ui->helpBtn->x()+ui->helpBtn->width()-ui->ShortCutTipsLab->width(),ui->helpBtn->y()-ui->ShortCutTipsLab->height(),
                                     ui->ShortCutTipsLab->width(),ui->ShortCutTipsLab->height());
}

void canvas::SetRatio(double zoom_ratio = 0.1, double move_ratio = 1.0, double max_ratio = 3.0)
{
    if(max_ratio<0 || zoom_ratio<0 || max_ratio<0){
        QMessageBox box;
        box.warning(this,"WARNING","max_ratio/zoom_ratio/max_ratio Can Not Below 0!");
    }else{
        this->m_zoomRatio = zoom_ratio;
        this->m_moveRatio = move_ratio;
        this->m_maxZoomRatio = max_ratio;
    }
}

void canvas::getMat(const cv::Mat &mat)
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

void canvas::getImg(const QString &path)
{
	cv::Mat mat = cv::imread(path.toStdString(), CV_LOAD_IMAGE_UNCHANGED);
    if (!mat.data)
    {
        QMessageBox mesg;
        mesg.warning(this, "SetMat_WARNING", "mat.data is EMPTY!");
    }else{
        m_src_mat = mat;
        m_src_pix = Mat2Pix(m_src_mat);
    }
}

void canvas::DisplayMat(const cv::Mat &mat)
{
    m_IsPAINTED = true;
    m_src_mat = mat;
    m_crt_mat = mat;
    m_src_pix = Mat2Pix(mat);
    m_crt_pix = m_src_pix;
    m_status.depth = mat.depth()*8;
    m_status.width = mat.cols;
    m_status.height = mat.rows;
    m_zoomRatio = (double)this->width()/m_src_pix.width(); //设置缩放变量
}

void canvas::paintEvent(QPaintEvent *event)
{
    if(m_IsPAINTED==false)
    {
        QMessageBox mesg;
        mesg.warning(this,"Can Not Paint","Can Not Find The File Imported!");
    }else{
        Q_UNUSED(event)
        QPainter painter(this);

        //获取源Mat信息
        m_srcPixWidth = m_src_pix.width();
        m_srcPixHeight = m_src_pix.height();
        int crtWidth = m_zoomRatio* m_srcPixWidth;
        int crtHeight = m_zoomRatio* m_srcPixHeight;

        m_crt_pix = m_crt_pix.scaled(crtWidth, crtHeight, Qt::KeepAspectRatio);

        if(m_action==canvas::Shrink)							//缩小
        {
            m_zoomRatio-= m_zoomStepRatio* m_zoomRatio;
            if(m_zoomRatio< (double)this-> width()/ m_src_pix.width())
                m_zoomRatio = (double)this->width()/ m_src_pix.width();
        }
        else if(m_action==canvas::Amplification)				//放大
        {
            m_zoomRatio+=m_zoomStepRatio*m_zoomRatio;
            if(m_zoomRatio > m_maxZoomRatio)
                m_zoomRatio = m_maxZoomRatio;
        }
        if(m_action==canvas::Amplification || m_action==canvas::Shrink)			//更新图片
        {
            crtWidth = m_zoomRatio *m_srcPixWidth;
            crtHeight = m_zoomRatio *m_srcPixHeight;
            m_crt_pix = m_src_pix;                                              //重新装载,因为之前的图片已经被缩放过
            m_crt_pix = m_crt_pix.scaled(crtWidth, crtHeight,Qt::KeepAspectRatio);
            m_action=canvas::None;
        }

        if(m_action==canvas::Move)                                          //移动 限制拖放不移出窗外
        {
            if( (m_pix_x+this->width()<crtWidth || m_single_offset.x()>0) && (m_pix_x>0 || m_single_offset.x()<0))
                m_all_offsets.setX(m_all_offsets.x()+m_single_offset.x());
            if((m_pix_y+this->height()<crtHeight || m_single_offset.y()>0)&&(m_pix_y>0 || m_single_offset.y()<0))
                m_all_offsets.setY(m_all_offsets.y()+m_single_offset.y());
            //qDebug()<<"=======总偏移的更新=======\n"<<m_all_offsets.x()<<"\n"<<m_all_offsets.y();
            m_action=canvas::None;
        }
        //    qDebug()<<"总偏移:"<<m_all_offsets.x();
        m_pix_x = crtWidth/2 - this->width()/2 - m_all_offsets.x();
        if(m_pix_x<0)
            m_pix_x=0;
        m_pix_y = crtHeight/2 - this->height()/2 - m_all_offsets.y();
        if(m_pix_y<0)
            m_pix_y=0;
        if(m_pix_x+this->width()>crtWidth)
            m_pix_x=crtWidth-this->width();
        if(m_pix_y+this->width()>crtHeight){
            m_pix_y=crtHeight-this->width();
        }

        //    qDebug()<<"==============绘制信息===============";
        qDebug()<<"\n图像起始点x:"<<m_pix_x<<" 图像起始点y:"<<m_pix_y;
        painter.drawTiledPixmap(0,0,this->width(),this->height(),m_crt_pix,m_pix_x,m_pix_y);             //绘画图形

        //更新label信息
        m_status.ratio = m_zoomRatio;
        ui->label->setText(QString(" 深度: %1 | 大小: [%2*%3] | 缩放率: %4% | 坐标: (%5, %6) | 灰度值: %7")
                           .arg(m_status.depth)
                           .arg(m_status.width).arg(m_status.height)
                           .arg(m_status.ratio*100, 3)
                           .arg((int)m_status.pos_x,5).arg((int)m_status.pos_y,5)
                           .arg(m_status.value,5));
    }
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
            SetRatio(1.0);
//            qDebug()<<"setInitRatio=1.0";
            update();
        }
    }
    //ctrl+1按下 设置缩放比例为布满画板
    if(event->type()==QEvent::KeyPress){
        QKeyEvent *keyBoard = dynamic_cast<QKeyEvent* >(event);
        if(keyBoard->key()==Qt::Key_1 && ctrlIsPressed){
            SetRatio(this->width()*1.0/m_src_pix.width());
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

        //鼠标移动 记录单次偏移量
        if(ctrlLefbtnPressed){
            //qDebug() << QString("%1").arg(m_is_X_Edge);
            m_single_offset.setX((mouse->x() - PreDot.x())*m_moveRatio);
            m_single_offset.setY((mouse->y() - PreDot.y())*m_moveRatio);
            //qDebug()<<mouse->x()<<PreDot.x()<<m_single_offset;
            PreDot = mouse->pos();
            m_action = canvas::Move;
        }
        //计算缩放后的坐标 和坐标处的灰度值
        if(m_zoomRatio>0){
            m_status.pos_x = m_pix_x/m_zoomRatio + mouse->pos().x()/m_zoomRatio;  //计算缩放后的坐标
            m_status.pos_y = m_pix_y/m_zoomRatio + mouse->pos().y()/m_zoomRatio;  //计算缩放后的坐标
            if(m_crt_mat.data){
                ushort* pxvec = m_crt_mat.ptr<ushort>(m_status.pos_y); //每行的头地址
                m_status.value = pxvec[(int)m_status.pos_x];                            //获取地址的灰度值
            }
        }
        update();
    }
    return QWidget::event(event);
}

QPixmap canvas::Mat2Pix(const cv::Mat &mat)
{
	cv::Mat tempMat;
    mat.convertTo(tempMat, CV_8UC1,255/65535.0,0);	//将原图转换成CV_8U
    QImage img = QImage((const unsigned char*)(tempMat.data),
        tempMat.cols, tempMat.rows,
        tempMat.cols*tempMat.channels(),
        QImage::Format_Grayscale8);
    QPixmap imgPix = QPixmap::fromImage(img);
    qDebug()<<"mat    Size:"<<mat.cols;
    qDebug()<<"tempMatSize:"<<tempMat.cols;
    qDebug()<<"img    Size:"<<img.size();
    qDebug()<<"imgPix Size:"<<imgPix.size();
    return imgPix;
}

void canvas::on_helpBtn_clicked(bool checked)
{
    if(checked)
        ui->ShortCutTipsLab->show();
    else
        ui->ShortCutTipsLab->hide();
}
