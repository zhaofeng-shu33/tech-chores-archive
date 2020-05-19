#ifndef WORDINPUT_H
#define WORDINPUT_H

#include <QWidget>
const int num=48;

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
    void loadTextFile();

    double distribution_function(int n);
    int generate_random_number(int n);
    QString word[num];//�ĸ�ά�ȷֱ𴢴治�����λ���ʵ�ԭ�ͣ�����ʱ����ȥʱ�����ʱ��
    int total;
    int word_weight[num];
    int cnt;
    int random;//2 random producing processes with ��������򶯴ʣ����ʱ̬������˳�.
    QString wordAudioAddress[num];
private slots:
    void on_lineEdit_editingFinished();
    };

#endif // WORDINPUT_H
