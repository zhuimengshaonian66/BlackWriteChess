#include "mybutton.h"
mybutton::mybutton()
{
    this->empty = true;
    this->setStyleSheet("background-color:rgb(255, 255, 255);");
    this->setIcon(QIcon(":/images/1.ico"));
}

void mybutton::mousePressEvent(QMouseEvent *e)
{
    empty = !empty;
    if (!empty)
    {
        this->setStyleSheet("background-color:rgb(0, 0, 0);");
    }
    else
    {
        this->setStyleSheet("background-color:rgb(255, 255, 255);");
    }
}

void mybutton::on()
{
    this->setStyleSheet("background-color:rgb(255, 0, 0);");

}
void mybutton::off()
{
    this->setStyleSheet("background-color:rgb(255, 255, 255);");
}
