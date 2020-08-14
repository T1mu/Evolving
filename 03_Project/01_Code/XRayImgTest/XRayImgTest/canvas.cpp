#include "canvas.h"
#include "ui_canvas.h"

canvas::canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::canvas)
{
    ui->setupUi(this);
    initUi(910, 930);
	//
	writeData(20, 20);
	//
	getArray(NULL, 3072, 3072);

	prepareDisplay();
    this->setMouseTracking(true);
}

canvas::~canvas()
{
    delete ui;
}

void canvas::initUi(int h, int w)
{

	this->setMinimumSize(h, w);
	this->setMaximumSize(h, w);
	this->setRatio(0.1, 1.0, 3.0);                                      //设置缩放和移动比例
    m_drawParams->canvsRect=QRect(0,0,this->width(),this->height());

    //Ui界面底部控件位置的设置
    ui->ShortCutTipsLab->hide();
    ui->label->setGeometry(0,this->height()-20,this->width(),20);
    ui->helpBtn->setGeometry(this->width()-ui->helpBtn->width(),this->height()-20,ui->helpBtn->width(),20);
    ui->ShortCutTipsLab->setGeometry(ui->helpBtn->x()+ui->helpBtn->width()-ui->ShortCutTipsLab->width(),ui->helpBtn->y()-ui->ShortCutTipsLab->height(),
                                     ui->ShortCutTipsLab->width(),ui->ShortCutTipsLab->height());
}

void canvas::setRatio(double zoom_ratio = 0.1, double move_ratio = 1.0, double max_ratio = 3.0)
{
    if(max_ratio<0 || zoom_ratio<0 || max_ratio<0){
        QMessageBox box;
        box.warning(this,"WARNING","max_ratio/zoom_ratio/max_ratio Can Not Below 0!");
    }else{
        this->m_drawParams->zoomRatio = zoom_ratio;
        this->m_drawParams->moveRatio = move_ratio;
        this->m_drawParams->maxZoomRatio = max_ratio;
    }
}


void canvas::getArray(const ushort* arrayData, int width, int height)
{
	if (arrayData != NULL){
		//拷贝传入实参数组内存到imgData的srcArray中
		memcpy(m_imgData->_array16, arrayData, sizeof(ushort)*width*height);
		m_imgData->_width = width;
		m_imgData->_height = height;
		m_imgData->_mat = Array16toMat(m_imgData->_array16,m_imgData->_width,m_imgData->_height);
		m_imgData->_srcPix = Array8toPix();
		m_imgData->_crtPix = QPixmap(m_imgData->_srcPix);
	}
	else{
		createArray16(width, height);
	}
}


void canvas::prepareDisplay()
{
	m_readyDisplay = true;
	m_status.depth = m_imgData->_bytes;
	m_status.width = m_imgData->_width;
	m_status.height = m_imgData->_height;
	m_drawParams->zoomRatio = (double)this->width() / m_imgData->_srcPix.width(); //设置缩放变量
}

void canvas::createArray16(int width=3072, int height=3072)
{
	//生成渐变图像
	int bytes = 16;
	ushort* array = new ushort[width*height];
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			array[width*j + i] = (int)(((i + j) * ((1 << bytes) - 1.0) / (width + height))) % ((1 << bytes) - 1);
		}
	}
	//设置imgData的成员信息
	m_imgData->_array16 = array;
	m_imgData->_width = width;
	m_imgData->_height = height;	
	m_imgData->_mat = Array16toMat(m_imgData->_array16, m_imgData->_width, m_imgData->_height);
	Array16to8();
	m_imgData->_srcPix = Array8toPix();
	m_imgData->_crtPix = QPixmap(m_imgData->_srcPix);
}

void canvas::calcMapTable(int bottom, int top, const int srcBytes, const int dstBytes)
{
	if (m_imgData->_mapTable != NULL){
		m_imgData->_mapTable = NULL;
	}
	if (bottom > top)
	{
		int temp = bottom;
		bottom = top;
		top = temp;
	}
	int srcRange = (1 << srcBytes) - 1;
	int dstRange = (1 << dstBytes) - 1;
	m_imgData->_mapTable = new int[srcRange];

	for (int i = 0; i < srcRange; i++){
		if (i <= bottom)
			m_imgData->_mapTable[i] = 0;
		else if (i>bottom && i < top)
			m_imgData->_mapTable[i] = (i - bottom)* 1.0 * dstRange / (top - bottom);
		else{
			m_imgData->_mapTable[i] = dstRange;
		}
	}
}

void canvas::Array16to8(int bottom , int top )
{
	//更新mapTabale映射表
	if (m_imgData->_mapTable != nullptr)
		m_imgData->_mapTable = nullptr;
	calcMapTable(bottom, top);
	//判断_array8是否有内容,若有则清空再赋值
	if (m_imgData->_array8 != NULL){
		m_imgData->_array8 = NULL;
	}
	m_imgData->_array8 = new uchar[m_imgData->_width*m_imgData->_height];
	for (int i = 0; i < m_imgData->_width*m_imgData->_height; i++){
		m_imgData->_array8[i] = m_imgData->_mapTable[(int)m_imgData->_array16[i]];	//m_imgData->array8 赋值成功
	}
}


QPixmap canvas::Mat16toPix8(const cv::Mat &mat)
{
	cv::Mat tempMat;
    mat.convertTo(tempMat, CV_8UC1,255/65535.0,0);	//将原图转换成CV_8U
    QImage img = QImage((const unsigned char*)(tempMat.data),
        tempMat.cols, tempMat.rows,
        tempMat.cols*tempMat.channels(),
        QImage::Format_Grayscale8);
    QPixmap imgPix = QPixmap::fromImage(img);

    return imgPix;
}

cv::Mat canvas::Array16toMat(ushort* array, int w, int h)
{
	if (array == NULL){
		QMessageBox box;
		box.warning(this, "Array2Mat", "array16 is NULL!");
	}
	else{
		cv::Mat mat = cv::Mat(w, h, CV_16UC1, array);
		return mat;
	}
}

QPixmap canvas::Array8toPix()
{
	if (m_imgData->_array8 == NULL){
		QMessageBox box;
		box.warning(this, "Array8toPix", "array8 is NULL");
		return 0;
	}
	else{
		//#TODO: 一次映射map()将ushort转为uchar 
		//再将uchar转为QImage 再将Image转为QPixmap
		QImage tempImg = QImage(m_imgData->_array8, m_imgData->_width, m_imgData->_height, QImage::Format_Indexed8);
		QVector<QRgb> colorTable;
		for (int k = 0; k < 256; ++k) {
			colorTable.push_back(qRgb(k, k, k));
		}
		tempImg.setColorTable(colorTable);
		QPixmap tempPix = QPixmap::fromImage(tempImg);
		return tempPix;
	}
}

void canvas::on_helpBtn_clicked(bool checked)
{
    if(checked)
        ui->ShortCutTipsLab->show();
    else
        ui->ShortCutTipsLab->hide();
}

void canvas::getMapRange(const int bottom, const int top)
{
	Array16to8(bottom, top);
	m_imgData->_srcPix = Array8toPix();
	m_imgData->_crtPix = QPixmap(m_imgData->_srcPix);
	this->update();
}

void canvas::writeArray(ushort* &array16)
{

	QFile file("infoArray16.txt");
	if (file.open(QIODevice::WriteOnly))
	{
		QTextStream out(&file);
		for (int i = 0; i < m_imgData->_width*m_imgData->_height; i++){
			out << QString("%1").arg(array16[i], 5) << " ";
			if ((i + 1) % m_imgData->_width == 0){
				out << endl;
			}
		}
	}
}

void canvas::writeArray(uchar* &array8)
{
	QFile file("infoArray8.txt");
	if (file.open(QIODevice::WriteOnly))
	{
		QTextStream out(&file);
		for (int i = 0; i < m_imgData->_width*m_imgData->_height; i++){
			out << QString("%1").arg(array8[i], 3) << " ";
			if ((i + 1) % m_imgData->_width == 0){
				out << endl;
			}
		}
	}
}

void canvas::writeMat(const cv::Mat &mat)
{
	QFile file("infoMat.txt");
	if (file.open(QIODevice::WriteOnly))
	{
		QTextStream out(&file);
		for (int i = 0; i < m_imgData->_width*m_imgData->_height; i++){
			if (mat.isContinuous()){
				out << QString("%1").arg(mat.at<ushort>(i), 5) << " ";
				if ((i + 1) % m_imgData->_width == 0){
					out << endl;
				}
			}
		}
	}
}

void canvas::paintEvent(QPaintEvent *event)
{
	if (m_readyDisplay == false)
	{
		QMessageBox mesg;
		mesg.warning(this, "Can Not Paint", "Can Not Find The File Imported!");
	}
	else{
		Q_UNUSED(event)
			QPainter painter(this);

		//获取源Mat信息
		m_imgData->_width = m_imgData->_srcPix.width();
		m_imgData->_height = m_imgData->_srcPix.height();
		int crtWidth = m_drawParams->zoomRatio* m_imgData->_width;
		int crtHeight = m_drawParams->zoomRatio* m_imgData->_height;

		m_imgData->_crtPix = m_imgData->_crtPix.scaled(crtWidth, crtHeight, Qt::KeepAspectRatio);

		if (m_action == canvas::Shrink)							//缩小
		{
			m_drawParams->zoomRatio -= m_drawParams->zoomStepRatio* m_drawParams->zoomRatio;
			if (m_drawParams->zoomRatio< (double)this->width() / m_imgData->_srcPix.width())
				m_drawParams->zoomRatio = (double)this->width() / m_imgData->_srcPix.width();
		}
		else if (m_action == canvas::Amplification)				//放大
		{
			m_drawParams->zoomRatio += m_drawParams->zoomStepRatio*m_drawParams->zoomRatio;
			if (m_drawParams->zoomRatio > m_drawParams->maxZoomRatio)
				m_drawParams->zoomRatio = m_drawParams->maxZoomRatio;
		}
		if (m_action == canvas::Amplification || m_action == canvas::Shrink)			//更新图片
		{
			crtWidth = m_drawParams->zoomRatio *m_imgData->_width;
			crtHeight = m_drawParams->zoomRatio *m_imgData->_height;
			m_imgData->_crtPix = m_imgData->_srcPix;                                              //重新装载,因为之前的图片已经被缩放过
			m_imgData->_crtPix = m_imgData->_crtPix.scaled(crtWidth, crtHeight, Qt::KeepAspectRatio);
			m_action = canvas::None;
		}

		if (m_action == canvas::Move)                                          //移动 限制拖放不移出窗外
		{
			if ((m_imgStartX + this->width()<crtWidth || m_drawParams->singOffset.x()>0) && (m_imgStartX > 0 || m_drawParams->singOffset.x()<0))
				m_drawParams->sumOffset.setX(m_drawParams->sumOffset.x() + m_drawParams->singOffset.x());
			if ((m_imgStartY + this->height()<crtHeight || m_drawParams->singOffset.y()>0) && (m_imgStartY>0 || m_drawParams->singOffset.y() < 0))
				m_drawParams->sumOffset.setY(m_drawParams->sumOffset.y() + m_drawParams->singOffset.y());
			//qDebug()<<"=======总偏移的更新=======\n"<<m_all_offsets.x()<<"\n"<<m_all_offsets.y();
			m_action = canvas::None;
		}
		//    qDebug()<<"总偏移:"<<m_all_offsets.x();
		m_imgStartX = crtWidth / 2 - this->width() / 2 - m_drawParams->sumOffset.x();
		if (m_imgStartX<0)
			m_imgStartX = 0;
		m_imgStartY = crtHeight / 2 - this->height() / 2 - m_drawParams->sumOffset.y();
		if (m_imgStartY<0)
			m_imgStartY = 0;
		if (m_imgStartX + this->width()>crtWidth)
			m_imgStartX = crtWidth - this->width();
		if (m_imgStartY + this->width()>crtHeight){
			m_imgStartY = crtHeight - this->width();
		}

		//    qDebug()<<"==============绘制信息===============";
		/*qDebug() << "\n图像起始点x:" << m_imgStartX << " 图像起始点y:" << m_imgStartY;*/
		painter.drawTiledPixmap(0, 0, this->width(), this->height(), m_imgData->_crtPix, m_imgStartX, m_imgStartY);             //绘画图形

		//更新label信息
		m_status.ratio = m_drawParams->zoomRatio;
		ui->label->setText(QString(" 深度: %1 | 大小: [%2*%3] | 缩放率: %4% | 坐标: (%5, %6) | 灰度值: %7")
			.arg(m_status.depth)
			.arg(m_status.width).arg(m_status.height)
			.arg(m_status.ratio * 100, 3)
			.arg((int)m_status.pos_x, 5).arg((int)m_status.pos_y, 5)
			.arg(m_status.value, 5));
	}
}

void canvas::wheelEvent(QWheelEvent *event)
{
	if (event->delta() < 0) {         //下滑,缩小
		m_action = canvas::Shrink;
		this->update();
	}
	else {                        //上滑,放大
		m_action = canvas::Amplification;
		this->update();
	}
	event->accept();
}

bool canvas::event(QEvent *event)
{
	static bool ctrlLefbtnPressed = false;
	static bool ctrlIsPressed = false;
	static QPoint PreDot;
	//#事件 键盘 ctrl按下与松开的标志位设置
	if (event->type() == QEvent::KeyPress){
		QKeyEvent *keyBoard = dynamic_cast<QKeyEvent*>(event);
		if (keyBoard->key() == Qt::Key_Control){
			ctrlIsPressed = true;
			QApplication::setOverrideCursor(Qt::OpenHandCursor); //设置鼠标样式
		}
	}
	else if (event->type() == QEvent::KeyRelease){
		QKeyEvent *keyBoard = dynamic_cast<QKeyEvent*>(event);
		if (keyBoard->key() == Qt::Key_Control){
			ctrlIsPressed = false;
			QApplication::setOverrideCursor(Qt::CrossCursor);   //改回鼠标样式
		}
	}
	//#事件 键盘 ctrl+0按下 设置初始缩放比例为1.0 即原图大小
	if (event->type() == QEvent::KeyPress){
		QKeyEvent *keyBoard = dynamic_cast<QKeyEvent*>(event);
		if (keyBoard->key() == Qt::Key_0 && ctrlIsPressed){        //ctrl+0 原图比例
			setRatio(1.0);
			update();
		}
	}
	//#事件 键盘 ctrl+1按下 设置缩放比例为布满画板
	if (event->type() == QEvent::KeyPress){
		QKeyEvent *keyBoard = dynamic_cast<QKeyEvent*>(event);
		if (keyBoard->key() == Qt::Key_1 && ctrlIsPressed){
			setRatio(this->width()*1.0 / m_imgData->_srcPix.width());
			//            qDebug()<<"full of canvas";
			update();
		}
	}
	if (event->type() == QEvent::MouseButtonPress)
	{
		QMouseEvent *mouse = dynamic_cast<QMouseEvent*>(event);
		//判断鼠标是否是左键按下,且鼠标位置是否在绘画区域
		if (mouse->button() == Qt::LeftButton && m_drawParams->canvsRect.contains(mouse->pos()))
		{
			if (ctrlIsPressed){
				ctrlLefbtnPressed = true;                 //ctrl+鼠标左键同时按下 设置标志位
				PreDot = mouse->pos();                  //记录左键按下的坐标
			}
		}
	}
	else if (event->type() == QEvent::MouseButtonRelease)
	{
		QMouseEvent *mouse = dynamic_cast<QMouseEvent*>(event);
		if (mouse->button() == Qt::LeftButton && ctrlLefbtnPressed)
		{
			ctrlLefbtnPressed = false;
		}

	}
	if (event->type() == QEvent::MouseMove)              //移动图片
	{
		QMouseEvent *mouse = dynamic_cast<QMouseEvent*>(event);
		if (m_drawParams->canvsRect.contains(mouse->pos())){
			this->setCursor(Qt::CrossCursor);
		}
		else{
			this->setCursor(Qt::ArrowCursor);
		}
		//鼠标移动 记录单次偏移量
		if (ctrlLefbtnPressed){
			//qDebug() << QString("%1").arg(m_is_X_Edge);
			m_drawParams->singOffset.setX((mouse->x() - PreDot.x())*m_drawParams->moveRatio);
			m_drawParams->singOffset.setY((mouse->y() - PreDot.y())*m_drawParams->moveRatio);
			//qDebug()<<mouse->x()<<PreDot.x()<<m_single_offset;
			PreDot = mouse->pos();
			m_action = canvas::Move;
		}
		//计算缩放后的坐标 和坐标处的灰度值
		if (m_drawParams->zoomRatio > 0){
			m_status.pos_x = m_imgStartX / m_drawParams->zoomRatio + mouse->pos().x() / m_drawParams->zoomRatio;  //计算缩放后的坐标
			m_status.pos_y = m_imgStartY / m_drawParams->zoomRatio + mouse->pos().y() / m_drawParams->zoomRatio;  //计算缩放后的坐标
				m_status.value = 65535.0*m_imgData->_array8[(int)m_status.pos_y*(int)m_status.width +(int) m_status.pos_x] / 255.0;
		}
		update();
	}
	return QWidget::event(event);
}
