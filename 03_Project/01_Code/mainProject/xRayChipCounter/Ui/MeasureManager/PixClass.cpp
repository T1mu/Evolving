#include "PixClass.h"

PixClass::PixClass(QObject *parent)
	: QObject(parent)
{

}

PixClass::~PixClass()
{

}
void PixClass::updateData(QPoint s, QPoint e){
	m_start = s;
	m_end = e;
	calData();
}
void PixClass::calData(){
	int x1 = m_start.x();
	int y1 = m_start.y();
	int x2 = m_end.x();
	int y2 = m_end.y();
	if (m_data.size() != 0){
		m_data.clear();
	}
	if (x1 != x2){
		double k = (double)(y2 - y1) / (x2 - x1);
		double b = y1 - k*x1;
		if (m_start.x() < m_end.x()){
			for (int i = m_start.x(); i <= m_end.x(); i++){
				int x = i;
				double y = k*x + b;
				m_data.append(QPoint(x, y));
			}

		}
		else{
			for (int i = m_end.x(); i <= m_start.x(); i++){
				int x = i;
				double y = k*x + b;
				m_data.append(QPoint(x, y));
			}
		}
	}
	else{
		for (int i = m_start.y(); i < m_end.y(); i++){
			int x = m_start.x();
			int y = i;
			m_data.append(QPoint(x, y));
		}
	
	}
	



}
QVector<QPoint> PixClass::getData(){
	return m_data;
}