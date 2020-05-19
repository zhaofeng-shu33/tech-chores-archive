#ifndef WORDSOURCE2_H
#define WORDSOURCE2_H

#include <QWidget>
const int num2=95;//库里能容纳的最多单词个数
class wordSource2 : public QWidget
{
    Q_OBJECT
public:
    explicit wordSource2(QWidget *parent = 0);

protected:
    void loadTextFile();
    double distribution_function(int n);
    int generate_random_number();
    QString word[num2*6];
    QString wordp[num2*6];
    QString word_2[num2];
    int word_weight[num2];
    int total;


};

#endif // WORDSOURCE2_H
