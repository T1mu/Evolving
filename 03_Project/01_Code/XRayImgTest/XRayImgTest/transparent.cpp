#include "transparent.h"

Transparent::Transparent(QWidget *parent) : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint |
                   Qt::SubWindow |
                   Qt::WindowStaysOnTopHint);               // 设置无边框、子窗口
    setAttribute(Qt::WA_TranslucentBackground, true);       // 设置为透明窗口
    setMouseTracking(true);                                 // 设置鼠标移动事件生效

    setRelativeAbscissaRange(25, 400);
    setRelativeOrdinateRange(15, 180);

    m_bottom = new QPoint(relativeAbscissaRange[0],relativeOrdinateRange[1]);
    m_top = new QPoint(relativeAbscissaRange[1],relativeOrdinateRange[0]);

}

void Transparent::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter linePainter(this);
    //抗锯齿和使用平滑转换算法
    linePainter.setRenderHints(QPainter::Antialiasing |
                               QPainter::SmoothPixmapTransform);
    linePainter.setPen(QPen(Qt::darkGray, 2));
    //用线连接两个端点
    linePainter.drawLine(*m_bottom, *m_top);

    QPainter pointPainter(this);
    //抗锯齿和使用平滑转换算法
    pointPainter.setRenderHints(QPainter::Antialiasing |
                                QPainter::SmoothPixmapTransform);
    pointPainter.setPen(QPen(m_pointerColor, 4));
    //绘制起始端点
    pointPainter.drawRect(m_bottom->x() - 2, m_bottom->y() - 2, 4, 4);
    //绘制终止端点
    pointPainter.drawRect(m_top->x() - 2, m_top->y() - 2, 4, 4);

}


bool Transparent::event(QEvent *event)
{
    static int diffBottomX= INT_MAX;
    static int diffBottomY= INT_MAX;
    static int diffTopX= INT_MAX;
    static int diffTopY= INT_MAX;

    static bool bottomHasPressed = false;
    static bool topHasPressed = false;
    static bool bottomCanMove = false;
    static bool topCanMove = false;
    if(event->type() == QEvent::MouseMove){
        QMouseEvent* mouse = dynamic_cast<QMouseEvent* >(event);
        diffBottomX = abs(mouse->pos().x() - m_bottom->x());
        diffBottomY = abs(mouse->pos().y() - m_bottom->y());
        diffTopX = abs(mouse->pos().x() - m_top->x());
        diffTopY = abs(mouse->pos().y() - m_top->y());
        if ((diffBottomX <= 7 && diffBottomY <= 7)|| bottomCanMove){
            m_pointerColor = Qt::red;
			setCursor(Qt::SizeHorCursor);
            bottomHasPressed = true;
        }
        else if((diffTopX <= 7 && diffTopY <= 7)|| bottomCanMove){
            m_pointerColor = Qt::red;
			setCursor(Qt::SizeHorCursor);
            topHasPressed = true;
        }else{
            m_pointerColor = Qt::blue;
			unsetCursor();
            bottomHasPressed = false;
            topHasPressed = false;
        }
        if(bottomCanMove){
            if(mouse->pos().x()<relativeAbscissaRange[0]){
                m_bottom->setX(relativeAbscissaRange[0]);
            }else if (mouse->pos().x()>relativeAbscissaRange[1]){
                m_bottom->setX(relativeAbscissaRange[1]);
            }else{
                m_bottom->setX(mouse->pos().x());
                emit sendMappingRange(relativeCoordinateValueMapTo16Bit((double)m_bottom->x()),
                                      relativeCoordinateValueMapTo16Bit((double)m_top->x()));
            }
        }
        if(topCanMove){
            if(mouse->pos().x()<relativeAbscissaRange[0]){
                m_top->setX(relativeAbscissaRange[0]);
            }else if (mouse->pos().x()>relativeAbscissaRange[1]){
                m_top->setX(relativeAbscissaRange[1]);
            }else{
                m_top->setX(mouse->pos().x());
                emit sendMappingRange(relativeCoordinateValueMapTo16Bit((double)m_bottom->x()),
                                      relativeCoordinateValueMapTo16Bit((double)m_top->x()));
            }
        }
        update();
    }
    if(event->type() == QEvent::MouseButtonPress){
        QMouseEvent* mouse = dynamic_cast< QMouseEvent* >(event);
        if(mouse->button()==Qt::LeftButton && bottomHasPressed){
            bottomCanMove = true;
			m_pointerColor = Qt::red;
        }else{
            bottomCanMove = false;
			m_pointerColor = Qt::blue;
        }
        if(mouse->button()==Qt::LeftButton && topHasPressed){
            topCanMove = true;
			m_pointerColor = Qt::red;
        }else{
            topCanMove = false;
			m_pointerColor = Qt::blue;
        }
    }
    if(event->type() == QEvent::MouseButtonRelease){
        QMouseEvent* mouse = dynamic_cast< QMouseEvent* >(event);
        if(mouse->button()==Qt::LeftButton){
            bottomCanMove = false;
            topCanMove = false;
        }
    }
    return QWidget::event(event);
}

void Transparent::setRelativeAbscissaRange(const int minX, const int maxX)
{
    if(minX> maxX){
        QMessageBox box;
        box.warning(this,"minX< maxX","minX should lower than maxX");
    }else{
        this->relativeAbscissaRange[0] = minX;
        this->relativeAbscissaRange[1] = maxX;
    }
}

void Transparent::setRelativeOrdinateRange(const int minY, const int maxY)
{
    if(minY> maxY){
        QMessageBox box;
        box.warning(this,"minY< maxY","minY should lower than maxY");
    }else{
        this->relativeOrdinateRange[0] = minY;
        this->relativeOrdinateRange[1] = maxY;
    }
}

double Transparent::relativeCoordinateValueMapTo16Bit(const double &coordinateValue)
{
    return 65535*(coordinateValue-relativeAbscissaRange[0])/(relativeAbscissaRange[1]-relativeAbscissaRange[0]);
}
