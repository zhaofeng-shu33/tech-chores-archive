#ifndef WORDINPUT_H
#define WORDINPUT_H

#include <QWidget>
#include "wordsource.h"
namespace Ui {
    class wordInput;
}

class wordInput : public wordSource
{
    Q_OBJECT

public:
    explicit wordInput(wordSource *parent = 0);
    ~wordInput();

private:
    Ui::wordInput *ui;
    void renew();
    void show1();
    void ChoiceOfAudioResource(int);
    void ChoiceOfAudioResource(int,int);
    int rand1,rand2;

private slots:
    void on_AudioTwoButton_clicked();
    void on_AudioOneButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // WORDINPUT_H
