#ifndef ABC_H
#define ABC_H

#include<stack>
#include<QPushButton>
using std::stack;

class ABC
{
public:
    ABC(int _xmid, int _bottom);
    QPushButton * pop();
    void push(QPushButton * btn);
    unsigned int size();
    void clear();
private:
    stack<QPushButton *> btns;
    int xmid;
    int bottom;
};

#endif // ABC_H
