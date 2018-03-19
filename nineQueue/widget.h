#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QVector>
#include<QString>
#include <utility>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_btnStart_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Widget *ui;
    QVector<QVector<QVector<bool> > > maps;
    void fillMaps(QVector<QVector<bool> > &map, const int num = 0);
    bool check1(const QVector<QVector<bool> > & map, const unsigned int x, const unsigned int y);
};

#endif // WIDGET_H
