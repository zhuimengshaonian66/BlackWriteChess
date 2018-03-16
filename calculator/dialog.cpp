#include "dialog.h"
#include "ui_dialog.h"




int flag;
double addsum(const char *str, int *num);
double getnum(const char *str, int *num);
double chengsum(const char *str, int *num);
int isnum(char str) {

    if (str <= '9' && str >= '0') {
        return 1;
    }
    else {
        return 0;
    }

 }


char *qukuohao(const char *str, int *num) {
    int left = 1;
     int  temp = *num;
    while (*(str + *num))
    {
        if (*(str + *num) == '(') {
            left++;
        }
        if (*(str + *num) == ')') {
            left--;
            if (left == 0) {
                char* sstr = (char*)calloc(*num-temp+1, 1);
                strncpy(sstr, str + temp, *num - temp);
                return sstr;
            }
        }
        (*num)++;
    }
   flag =1;

}


double getnum(const char *str, int *num) {
    double total = 0;

    if (*(str + *num) == '(') {
        (*num)++;
        char * temp = qukuohao(str,num);
        if(flag==1){
            return 0;
        }
        int k = 0;
        double db = addsum(temp, &k);
        free(temp);
        (*num)++;
        return db;
    }


    while (isnum(*(str + *num))) {
        total = total * 10 + ((*(str + *num)) - '0');
        (*num)++;
    }
    if (*(str + *num) == '.') {
        (*num)++;
        double k = 1;
        while (isnum(*(str + *num))) {
            total = total + k*0.1*(*(str + *num) - '0');
            k *= 0.1;
            (*num)++;
        }
    }

    return total;
}


double chengsum(const char *str,int *num) {
    double chengresult = getnum(str, num);
    if(flag==1){
        return 0;
    }
    while (1)
    {
        switch (*(str + *num))
        {
        case '*':
            (*num)++;
            chengresult = chengresult *getnum(str, num);

            break;
        case '/':
            (*num)++;
            chengresult = chengresult/ getnum(str, num);

            break;
        default:
            return chengresult;
        }
    }



}

double addsum(const char *str,int *num)
{
    double result = chengsum(str, num);

    while (1)
    {
        if(flag==1){
            return 0;
        }
        switch (*(str + *num))
            {
            case '\0':
                return result;
            case '+':
                (*num)++;
                 result = result + chengsum(str,num);
                 break;
            case '-':
                (*num)++;
                result -= chengsum(str,num);
                break;
            default:
                flag=1;
                break;
            }
        }
    }


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"1");


}

void Dialog::on_pushButton_2_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"2");

}

void Dialog::on_pushButton_3_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"3");
}

void Dialog::on_pushButton_6_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"4");
}

void Dialog::on_pushButton_4_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"5");
}










void Dialog::on_pushButton_5_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"6");
}

void Dialog::on_pushButton_9_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"7");
}

void Dialog::on_pushButton_7_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"8");
}

void Dialog::on_pushButton_8_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"9");
}
void Dialog::on_pushButton_12_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+".");
}

void Dialog::on_pushButton_10_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"(");
}

void Dialog::on_pushButton_17_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+")");
}
void Dialog::on_pushButton_13_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"-");
}

void Dialog::on_pushButton_14_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"*");
}

void Dialog::on_pushButton_15_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"/");
}

void Dialog::on_pushButton_11_clicked()
{
    QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str+"+");
}

void Dialog::on_pushButton_16_clicked()
{
    QString str= ui->lineEdit->text();
    int num =0;
    char*  ch;
    QByteArray ba = str.toLatin1(); // must
    ch=ba.data();
    double db = addsum((const char *)(ch),&num);
   QString temp;
    if(flag==1){
          ui->lineEdit->setText(temp.setNum(0));
          return;
    }


    ui->lineEdit->setText(temp.setNum(db));


}

void Dialog::on_pushButton_18_clicked()
{
   QString str= ui->lineEdit->text();

    ui->lineEdit->setText(str.left(str.length()-1));

}
