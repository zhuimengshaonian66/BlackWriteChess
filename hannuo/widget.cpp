#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    A(150, 420),
    B(380, 420),
    C(610, 420),
    t(NULL)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnStart_clicked()
{
    bool isok;
    unsigned int num = ui->txtNum->text().toUInt(&isok);
    if (!isok)
    {
        return;
    }
    ui->btnStart->setEnabled(false);
    A.clear();
    B.clear();
    C.clear();
    this->n = num;
    while (num)
    {
        QPushButton * btn = new QPushButton(this);
        btn->setText(QString::number(num));
        btn->setGeometry(0, 0, num * 30, 20);
        A.push(btn);
        btn->show();
        num--;
    }
    delete t;
    t = new MyThread(&n, &A, &B, &C, ui->btnStart);

    t->run();
}
