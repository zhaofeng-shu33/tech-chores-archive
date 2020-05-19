#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QEventLoop>
#include "wordinput.h"
using namespace std;

namespace Ui {
     class Widget;
}
struct wordN{
  QString wordN1;
  QString wordN2[4][6];
  wordN* next;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    QString word[5][num];
    int cnt;
    ~Widget();

private:
    Ui::Widget *ui;
    void show1();
    void addWord(wordN*);
    void readData(QString,int);
    void loadTextFile();
    QString getText();
    QString Assemble(bool,QString);
    bool currentState;
    void closeEvent(QCloseEvent *event);

private slots:
    void on_lineEdit_returnPressed();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void import();

};

#endif // WIDGET_H
