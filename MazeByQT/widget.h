#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QVector>
#include "mybutton.h"
#include "mythread.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnshow_clicked();

    void on_btngo_clicked();

private:
    Ui::Widget *ui;
    QVector<QVector<mybutton*> > btns;
    mythread * t;
};

#endif // WIDGET_H
