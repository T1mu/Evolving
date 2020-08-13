#ifndef UNION_H
#define UNION_H

#include <QWidget>

namespace Ui {
class Union;
}

class Union : public QWidget
{
    Q_OBJECT

public:
    explicit Union(QWidget *parent = 0);
    ~Union();

private:
    Ui::Union *ui;
};

#endif // UNION_H
