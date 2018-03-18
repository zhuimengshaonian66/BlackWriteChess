#include "mythread.h"

mythread::mythread(QVector<QVector<mybutton *> > *_btns, QPushButton * _btnStart)

{
    this->btns = _btns;
    this->btnStart =_btnStart;
}

void mythread::run()
{
    go(0, 0);
    btnStart->setEnabled(true);
}

bool mythread::go(int x, int y)
{
    if (x < 0 || y < 0 || x >= btns->size() || y >= btns->size())
    {
        return false;
    }
    if (!(*btns)[y][x]->getEmpty())
    {
        return false;
    }
    e.processEvents();
    QThread::msleep(200);
    if (x == btns->size() - 1 && y == btns->size() - 1)
    {
        (*btns)[y][x]->on();
        return true;
    }
    for(QVector<QPair<int, int> >::iterator p = his.begin(); p != his.end(); p++)
    {
        if (p->first == x && p->second == y)
        {
            return false;
        }
    }
    (*btns)[y][x]->on();
    his.push_back(QPair<int, int>(x, y));
    if (go(x, y + 1) || go(x + 1, y) || go(x, y - 1) || go(x - 1, y))
    {
        return true;
    }
    (*btns)[y][x]->off();
    return false;
}
