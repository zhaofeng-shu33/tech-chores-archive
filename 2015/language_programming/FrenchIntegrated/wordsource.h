#ifndef WORDSOURCE_H
#define WORDSOURCE_H

#include <QWidget>
const int num=44;//库里单词个数
class wordSource : public QWidget
{
    Q_OBJECT
public:
    explicit wordSource(QWidget *parent = 0);
protected:
    void loadTextFile();
    double distribution_function(int n);
    int generate_random_number();
    QString word[num];
    QString word_2[num];
    QString wordAudioAddress[num];
    int word_weight[num];
    int total;
   signals:

public slots:

};

#endif // WORDSOURCE_H
