#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
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
    void on_btnStart_clicked();

private:
    Ui::Widget *ui;
    ABC A, B, C;
    int n;
    MyThread * t;
};

#endif // WIDGET_H
