#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QStringListModel>
#include<QEventLoop>
class mythread : public QThread
{
public:
    mythread(QStringListModel *listvi, const char *name);
    void run();
    QStringListModel *_listvi;
    const char *_name;
     QEventLoop e;
};

#endif // MYTHREAD_H
