#ifndef WORDINPUT_H
#define WORDINPUT_H

#include <QWidget>
const int num=280;
namespace Ui {
    class wordInput;
}

class wordInput : public QWidget
{
    Q_OBJECT

public:
    explicit wordInput(QString word[][num],int cnt);
    Ui::wordInput *ui;
    ~wordInput();

private:    
    void renew();
    void show1();
    QString getRightAnswer(int n);
    void check(QString str,int n);
    double distribution_function(int n);
    int generate_random_number();
    QString wordtem[5][num];
    int total;
    int word_weight[num];
    int cnttem;
    int randN[2][3];//2 random producing processes with ramdom verb, random tense and random person
private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // WORDINPUT_H
