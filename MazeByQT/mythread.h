#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QPair>
#include <QThread>
#include <Qvector>
#include <utility>
#include <QEventLoop>
#include "mybutton.h"
class mythread : public QThread
{
public:
    mythread(QVector<QVector<mybutton *> > *_btns, QPushButton * _btnStart);
    void run();
private :
    QEventLoop e;
    QVector<QPair<int,int> > his;
    QVector<QVector<mybutton *> > *btns;
    QPushButton * btnStart;
    bool go(int x, int y);
};

#endif // MYTHREAD_H
