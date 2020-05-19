#ifndef WORDINPUT_H
#define WORDINPUT_H

#include <QWidget>
const int num=95;
const int audioNum=11;
namespace Ui {
    class wordInput;
}
class wordInput : public QWidget
{
    Q_OBJECT

public:
    explicit wordInput(QWidget *parent = 0);
    Ui::wordInput *ui;
    ~wordInput();

private:    
    void renew();
    void show1();
    void readData(QString str,int n,QString wordlist[]);
    void loadTextFile();

    QString getRightAnswer(int n);
    void dictation(QString str);
    void seek(QString str);
    void check(QString str,int n);
    void ChoiceOfAudioResource(int rand);
    double distribution_function(int n);
    int generate_random_number(int n);
    QString word[4][num];//四个维度分别储存不规则变位动词的原型，现在时，过去时和完成时。
    int total;
    int word_weight[num];
    int cnt;
    int randN[2][3];//2 random producing processes with 随机不规则动词，随机时态和随机人称.
    QString wordWithAudio[audioNum];
    QString wordAudioAddress[audioNum];
private slots:
    void on_comboBox_currentIndexChanged(int index);
    void on_lineEdit_editingFinished();
    };

#endif // WORDINPUT_H
