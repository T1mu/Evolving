#ifndef PIXCLASS_H
#define PIXCLASS_H

#include <QObject>
#include <QPoint>
#include <QVector>
class PixClass : public QObject
{
	Q_OBJECT

public:
	PixClass(QObject *parent=0);
	~PixClass();
	void updateData(QPoint, QPoint);
	void calData();
	QVector<QPoint> getData();
private:
	QPoint m_start;
	QPoint m_end;
	QVector<QPoint> m_data;
};

#endif // PIXCLASS_H
