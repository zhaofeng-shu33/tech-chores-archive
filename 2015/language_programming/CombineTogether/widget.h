#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <string.h>
using namespace std;
namespace Ui {
     class Widget;
}
struct word{
  QString word1;
  QString meaning;
  word* next;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
        void show1();
    QString getText();


private slots:
    void Create();
    void on_pushButton_7_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void user_input();
};

#endif // WIDGET_H
