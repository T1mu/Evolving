// 源代码编码必须是: UTF-8(BOM)  
//#if _MSC_VER >= 1600
//#pragma execution_character_set("utf-8")
//#endif
#ifndef Global_H
#define Global_H

#include <QObject>
typedef enum //ShapeMode
{
	Line_angle,
	PerdenWire,
	Perpen,
	Pix
}ShapeMode;


class Global : public QObject
{    
	Q_OBJECT
public:
    Global(QObject *parent = 0);
    ~Global();


private:	

};

#endif // Global_H