#ifndef CONJUGAISON_H
#define CONJUGAISON_H

#include <QWidget>
#include "wordsource2.h"
namespace Ui {
    class Conjugaison;
}

class Conjugaison : public wordSource2
{
    Q_OBJECT

public:
    explicit Conjugaison(wordSource2 *parent = 0);
    ~Conjugaison();
private:
    Ui::Conjugaison *ui;
    void renew();
    void show1();
    int rand1[3],rand2[3];//随机数向量，三个数分别表示动词的随机性，时态的随机性和人称的随机性

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();


};

#endif // CONJUGAISON_H
