#include "imgmodule.h"
#include "ui_imgmodule.h"

ImgModule::ImgModule(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImgModule)
{
    ui->setupUi(this);
}

ImgModule::~ImgModule()
{
    delete ui;
}
