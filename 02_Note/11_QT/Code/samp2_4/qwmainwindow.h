#ifndef QWMAINWINDOW_H
#define QWMAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>
#include <QProgressBar>

QT_BEGIN_NAMESPACE
namespace Ui { class QWMainWindow; }
QT_END_NAMESPACE

class QWMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWMainWindow(QWidget *parent = nullptr);
    ~QWMainWindow();

private slots:
    void on_actioncut_triggered();

    void on_actionbold_triggered(bool checked);

    void on_actionItalic_triggered(bool checked);

    void on_actionUnderLine_triggered(bool checked);

    void on_txtEdit_copyAvailable(bool b);

    void on_txtEdit_selectionChanged();

    void on_spinFontSize_valueChanged(int aFontSize);//创建手工创建的组件的槽函数

    void on_comboFont_currentIndexChanged(const QString &arg1);//同上

private:
    Ui::QWMainWindow *ui;
    QLabel *fLabCurFile;
    QProgressBar *progressBar1;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont; //字体名称
    void iniUI();
    void iniSignalSlots();
};
#endif // QWMAINWINDOW_H
