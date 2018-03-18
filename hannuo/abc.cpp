#include "abc.h"

ABC::ABC(int _xmid, int _bottom)
    :xmid(_xmid), bottom(_bottom)
{
}

void ABC::push(QPushButton * btn)
{
    if (!btn)
    {
        return;
    }
    btns.push(btn);
    QSize size = btn->size();
    btn->setGeometry(xmid - size.width() / 2, bottom - btns.size() * 20, size.width(), size.height());
    //btn->show();
}

QPushButton * ABC::pop()
{
    QPushButton * btn = btns.top();
    btns.pop();
    return btn;
}

unsigned int ABC::size()
{
    return btns.size();
}

void ABC::clear()
{
    while (btns.size())
    {
        QPushButton * btn = btns.top();
        btns.pop();
        delete btn;
    }
}
