#ifndef TRANSPARENT_H
#define TRANSPARENT_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
#include <QMessageBox>

class Transparent : public QWidget
{
    Q_OBJECT
public:
    explicit Transparent(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    bool event(QEvent *event);
    //接口:设定横纵坐标在窗体上的相对坐标范围
    void setRelativeAbscissaRange(const int minX, const int maxX);
    void setRelativeOrdinateRange(const int minY, const int maxY);

signals:
    void sendMappingRange(const double bottom, const double top);
public slots:
private:
    // Relative coordinates 相对窗体表格的坐标范围
    int relativeAbscissaRange[2];
    int relativeOrdinateRange[2];

    // 两个端点
    QPoint* m_bottom;
    QPoint* m_top;

    // 相对坐标映射到16位
    double relativeCoordinateValueMapTo16Bit(const double &coordinateValue);

    // 定义用于改变端点的颜色变量
    Qt::GlobalColor m_pointerColor = Qt::blue;
};

#endif // TRANSPARENT_H
