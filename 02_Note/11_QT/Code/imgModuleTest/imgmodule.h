#ifndef IMGMODULE_H
#define IMGMODULE_H

#include <QMainWindow>

namespace Ui {
class ImgModule;
}

class ImgModule : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImgModule(QWidget *parent = 0);
    ~ImgModule();

private:
    Ui::ImgModule *ui;
};

#endif // IMGMODULE_H
