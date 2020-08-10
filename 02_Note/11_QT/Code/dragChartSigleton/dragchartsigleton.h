#ifndef DRAGCHARTSIGLETON_H
#define DRAGCHARTSIGLETON_H

#include <QWidget>

namespace Ui {
class dragChartSigleton;
}

class dragChartSigleton : public QWidget
{
    Q_OBJECT

public:
    explicit dragChartSigleton(QWidget *parent = 0);
    ~dragChartSigleton();

private:
    Ui::dragChartSigleton *ui;
};

#endif // DRAGCHARTSIGLETON_H
