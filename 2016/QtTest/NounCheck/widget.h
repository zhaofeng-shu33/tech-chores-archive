#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "wordSource.h"
#include <QVector>
namespace Ui {
    class Widget;
}
struct screenPt{
   double x;
   double y;
};

class Widget : public QWidget
{
    Q_OBJECT

private:
    QVector<Noun> Nounlist;
    double distribution_function(int n);
    int generate_random_number();
    int total_weight;
    int current_random_number;
    QString instruction;
public:
    Ui::Widget *ui;
    explicit Widget(QWidget *parent = 0,int total_weight=0);
    int get_total_weight(){return total_weight;}
    void set_total_weight(int value){total_weight=value;}
    int get_current_random_number(){return current_random_number;}
    void set_current_random_number(int n){current_random_number=n;}
    int renew();//return the random number generated;
   // void intersect(screenPt pt[]);
    void display1();
    void setUpCallBack();


    ~Widget();


private slots:
    void on_lineEdit_2_editingFinished();
    void on_pushButton_clicked();
    void on_lineEdit_editingFinished();
};


#endif // WIDGET_H
