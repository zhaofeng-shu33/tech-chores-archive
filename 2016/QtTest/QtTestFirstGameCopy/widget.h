#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "wordSource.h"
#include <QVector>
namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;
    QVector<Noun> Nounlist;
    double distribution_function(int n);
    int generate_random_number();
    int total_weight;
    int current_random_number;

public:
    explicit Widget(QWidget *parent = 0,int total_weight=0);
    int get_total_weight(){return total_weight;}
    void set_total_weight(int value){total_weight=value;}
    int get_current_random_number(){return current_random_number;}
    void set_current_random_number(int n){current_random_number=n;}
    int renew();//return the random number generated;
    ~Widget();


private slots:
    void on_lineEdit_editingFinished();
};

#endif // WIDGET_H
