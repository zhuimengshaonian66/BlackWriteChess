#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    t=NULL;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnshow_clicked()
{
   // ui->btnGo->setEnabled(false);
    //for(vector<vector<MyButton*> >::iterator p = btns.begin(); p != btns.end(); p++)
    //{
      //  for (vector<MyButton *>::iterator q = p->begin(); q != p->end(); q++)
        //{
          //  delete *q;
        //}
    //}
   // ui->btnGo->setEnabled(false);
   // for(vector<vector<MyButton*> >::iterator p = btns.begin(); p != btns.end(); p++)
   // {
     //   for (vector<MyButton *>::iterator q = p->begin(); q != p->end(); q++)
    //    {
      //      delete *q;
     //   }
  //  }




    bool ok;
    int num = ui->lineEdit->text().toInt(&ok);
    if(!ok){
        return;
    }
    ui->btngo->setEnabled(false);
    for(auto p = btns.begin();p!=btns.end();p++){
        for(auto q = p->begin();q!=p->end();q++){
            delete *q;
        }
    }
    btns.clear();
    QVector<mybutton*> temp;

    for(int i = 0;i<num;i++){
        for(int j = 0;j<num;j++){
            mybutton *btn = new mybutton;
            ui->gridLayout->addWidget(btn,i,j,1,1);
            temp.push_back(btn);
        }
        btns.push_back(temp);
        temp.clear();
    }
    ui->btngo->setEnabled(true);

}

void Widget::on_btngo_clicked()
{
   // ui->btnStart->setEnabled(false);
   // ui->btnGo->setEnabled(false);
   // delete t;
   // t = new MyThread(&btns, ui->btnStart);
   // t->run();

    ui->btnshow->setEnabled(false);
    ui->btngo->setEnabled(false);
    delete t;
    t=new mythread(&btns,ui->btnshow);
    t->run();
}
