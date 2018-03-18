#include "mythread.h"
#include <QEventLoop>

MyThread::MyThread(int *_n, ABC *_A, ABC *_B, ABC *_C, QPushButton * _btnStart)
    :n(_n), A(_A), B(_B), C(_C), btnStart(_btnStart)
{
}

void MyThread::run()
{
    move(*n, *A, *B, *C);
    btnStart->setEnabled(true);
}

void MyThread::move(int n, ABC &A, ABC &B, ABC &C)
{
    if (n == 0)
    {
        return;
    }
    move(n - 1, A, C, B);
    QThread::msleep(500);
    /// windows下多线程操作GUI会出问题，只能用这个
    e.processEvents();
    C.push(A.pop());
    move(n - 1, B, A, C);
}
