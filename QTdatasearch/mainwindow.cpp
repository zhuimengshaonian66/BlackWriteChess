#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdio.h>
#include<stdlib.h>
#include<QDebug>
#include<QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    slm = new QStringListModel(this);//模型
    sl = new QStringList();//data
    //sl->append("c");  //添加
   // sl->append("c++");
   // sl->append("c#");
   // sl->append("java");
   // sl->append("linux");
    slm->setStringList(*sl);  //模型连接数据
    ui->listView->setModel(slm);//UI连接模型
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString temp = ui->lineEdit->text();
      QByteArray qstr =temp.toLocal8Bit();
     const char *name = qstr.data();


    //  slm->setStringList(*sl);  //模型连接数据
     // ui->listView->setModel(slm);//UI连接模型

    thread = new mythread(slm,name);
thread->run();


      printf("%s",(char *)temp.data());

}
