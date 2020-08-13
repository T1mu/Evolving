#include "union.h"
#include "ui_union.h"

Union::Union(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Union)
{
    ui->setupUi(this);
}

Union::~Union()
{
    delete ui;
}
