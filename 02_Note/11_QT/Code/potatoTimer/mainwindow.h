#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void iniUi();

private:
    Ui::MainWindow *ui;
    QLabel *statuWorkTimeLab;
    QLabel *statuSleepTimeLab;
    QLabel *statuRemainTimeLab;
};
#endif // MAINWINDOW_H
