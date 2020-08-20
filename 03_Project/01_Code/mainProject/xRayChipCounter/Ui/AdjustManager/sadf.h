#ifndef SADF_H
#define SADF_H

#include <QWidget>
#include "ui_sadf.h"

class sadf : public QWidget
{
	Q_OBJECT

public:
	sadf(QWidget *parent = 0);
	~sadf();

private:
	Ui::sadf ui;
};

#endif // SADF_H
