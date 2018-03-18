#ifndef MYTHREAD_H
#define MYTHREAD_H
#include "mythread.h"
#include <QThread>
#include <QEventLoop>
#include "abc.h"

class MyThread : public QThread
{
public:
    MyThread(int *_n, ABC *_A, ABC *_B, ABC *_C, QPushButton * _btnStart);
    void run();
private :

    /// windows下多线程操作GUI会出问题，只能用这个
    QEventLoop e;

    void move(int n, ABC &A, ABC &B, ABC &C);
    int *n;
    ABC *A, *B, *C;
    QPushButton * btnStart;
};

#endif // MYTHREAD_H
