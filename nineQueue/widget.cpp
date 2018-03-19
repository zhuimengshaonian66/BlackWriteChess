#include "widget.h"
#include "ui_widget.h"
#include "mybutton.h"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

bool Widget::check1(const QVector<QVector<bool> > & map, const unsigned int x, const unsigned int y){
    int xx = x;
    int yy = y-1;
    while (yy>=0) {
        if(map[yy--][xx]){
            return false;
        }
    }

    xx=x-1;
    yy = y-1;
    while(xx>=0 &&yy>=0){
        if(map[yy--][xx--]){
            return false;
        }
    }
    xx = x+1;
    yy=  y-1;

    while(xx<map.size() && yy >=0){
        if(map[yy--][xx++]){
            return false;
        }
    }
    return true;
}
void  Widget::fillMaps(QVector<QVector<bool> > &map, const int num){

    if(num>=map.size()){
        return;
    }
    for(int col = 0;col<map.size();col++){
        map[num][col]=true;
        if(check1(map,col,num)){
            if(num+1==map.size()){
                maps.push_back(map);
            }else{
                fillMaps(map,num+1);
            }
        }
        map[num][col]=false;
    }


}
void Widget::on_btnStart_clicked()
{
    bool isok;
    unsigned int num = ui->lineEdit->text().toUInt(&isok);
    if(!isok){
        ui->infoMsg->setText("please input a uint number");
        return;
    }

    ui->btnStart->setEnabled(false);
    ui->infoMsg->setText("追梦少年正在为你计算");
    maps.clear();
    QVector<QVector<bool>> map(num,QVector<bool>(num,false));
    fillMaps(map);
    ui->infoMsg->setText("追梦少年提示计算完成");
    ui->btnStart->setEnabled(true);
    if(maps.size()){
        ui->comboBox->addItem("--");
        for(int i= 0;i<maps.size();i++){
                ui->comboBox->addItem(QString::number(i));
                ui->comboBox->setEnabled(true);
        }
    }else{
        ui->comboBox->setEnabled(true);
    }
}

void Widget::on_comboBox_activated(const QString &arg1)
{
    bool isok;
    int index = arg1.toInt(&isok);
    if(!isok){
        return;
    }

    while(ui->gridLayout->count()){
        QWidget *w = ui->gridLayout->itemAt(0)->widget();
        ui->gridLayout->removeWidget(w);
        delete w;
    }
    QVector<QVector<bool>> map = maps[index];
    for(int i = 0;i<map.size();i++){
        for(int j = 0;j<map[i].size();j++){
                mybutton *btn = new mybutton;

                if(map[i][j]){
                    btn->setStyleSheet("background-color:rgb(255,0,0);");
                   // btn->setIcon(QIcon(":/images/1.ico"));
                }else{
                    btn->setEnabled(false);
                }
                // btn->setIcon();
                ui->gridLayout->addWidget(btn,i,j,1,1);
        }
    }

}
