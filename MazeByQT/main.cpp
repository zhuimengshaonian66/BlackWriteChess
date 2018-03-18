#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.setWindowTitle("by 追梦少年 QQ:1131052403");
    w.show();
   // mybutton *p = new mybutton;
    //p->show();
    return a.exec();
}
