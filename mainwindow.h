#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// 这一行是 Qt 自动生成的，不用管
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT  // 这一行必须有，是 Qt 信号槽机制的宏

public:
    MainWindow(QWidget *parent = nullptr);  // 构造函数
    ~MainWindow();                          // 析构函数

private slots:  // 槽函数区域，按钮点击事件都声明在这里
    void on_btnReadNews_clicked();      // 读取新闻按钮
    void on_btnReceiveLetter_clicked(); // 模拟收信按钮
    void on_btnAddTask_clicked();       // 添加任务按钮

private:
    Ui::MainWindow *ui;  // UI 界面指针
};

#endif // MAINWINDOW_H