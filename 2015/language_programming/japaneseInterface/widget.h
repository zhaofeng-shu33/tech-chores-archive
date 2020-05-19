#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <string.h>
using namespace std;
namespace Ui {
     class Widget;
}
struct word{
  QString verb;
  QString first_continuative_form;
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
    void Create();
    void show1();
    QString getText();


private slots:
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void user_input();
    void my_export();
};

#endif // WIDGET_H
