#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class mybutton : public QPushButton
{
public:
    mybutton();
    void mousePressEvent(QMouseEvent *e);

    bool getEmpty()
    {
        return empty;
    }
    void setEmpty(bool _empty)
    {
        empty = _empty;
    }
    void on();
    void off();

private :
    bool empty;
};

#endif // MYBUTTON_H
