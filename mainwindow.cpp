#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>

// ==================== 构造函数 ====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("🤖 AI 桌宠 · 信息模块");
}

// ==================== 析构函数 ====================
MainWindow::~MainWindow()
{
    delete ui;
}

// ==================== 读取新闻按钮 ====================
void MainWindow::on_btnReadNews_clicked()
{
    QFile file("news.txt");

    // 如果文件不存在，自动创建示例文件
    if (!file.exists()) {
        QFile createFile("news.txt");
        if (createFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&createFile);
            out << "🎉 Qt 6.5 发布啦！新功能抢先看~\n";
            out << "🤖 OpenAI 推出新一代 AI 模型\n";
            out << "☀️ 今天天气晴，适合写代码！\n";
            createFile.close();
        }
    }

    // 打开文件并读取内容
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        ui->textNews->setText(content);   // ✅ 已改为 textNews
        file.close();
    } else {
        QMessageBox::warning(this, "错误", "无法读取新闻文件");
    }
}

// ==================== 模拟收信按钮 ====================
void MainWindow::on_btnReceiveLetter_clicked()
{
    QString currentTime = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString message = QString("[%1] 📬 你有一封新邮件！\n来自：队友A\n内容：桌宠功能已完成，请查收~")
                          .arg(currentTime);

    ui->textNews->setText(message);   // ✅ 已改为 textNews
}

// ==================== 添加任务按钮 ====================
void MainWindow::on_btnAddTask_clicked()
{
    QString task = ui->lineEditTask->text().trimmed();

    if (task.isEmpty()) {
        QMessageBox::information(this, "提示", "请输入任务内容");
        return;
    }

    QString timeStamp = QDateTime::currentDateTime().toString("MM-dd hh:mm");
    QString taskItem = QString("[%1] %2").arg(timeStamp, task);

    ui->listTasks->addItem(taskItem);
    ui->lineEditTask->clear();
    ui->lineEditTask->setFocus();
}