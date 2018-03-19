#include "mythread.h"
#include<QTextCodec>
#include<QDebug>
mythread::mythread(QStringListModel *listvi, const char *name):_listvi(listvi),_name(name)
{

}

void mythread::run()
{
    FILE * pf = fopen("E:\\test\\dangdangwang.txt","r");
    if(pf==NULL){
    return;
    }
    int i = 0;
    while(!feof(pf)){
        char str[1024]={0};
        fgets(str,1023,pf);

        if(str){
            if(strstr(str,_name)){
                QTextCodec *codec = QTextCodec::codecForName("gb2312");
                QString qstrall =codec->toUnicode(str);
                 qDebug()<<i++<<endl;
                qDebug()<<qstrall<<endl;
               // sl->append(qstrall);
  e.processEvents();
                _listvi->insertRows(0, 1);
                 QModelIndex index = _listvi->index(0);
                  _listvi->setData(index, qstrall);
            }
        }
    }
     fclose(pf);
}
