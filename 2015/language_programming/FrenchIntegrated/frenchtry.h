#ifndef FRENCHTRY_H
#define FRENCHTRY_H

#include <QWidget>
#include "wordsource.h"
namespace Ui {
    class FrenchTry;
}

class FrenchTry : public wordSource
{
    Q_OBJECT

public:
    explicit FrenchTry(wordSource *parent = 0);
    ~FrenchTry();

private:
    Ui::FrenchTry *ui;

    void renew();
    void show1();
    int ran[5],ran2[5];





private slots:
    void on_renewButton_clicked();
    void on_pushButton_clicked();
    void on_checkButton_clicked();
};

#endif // FRENCHTRY_H
