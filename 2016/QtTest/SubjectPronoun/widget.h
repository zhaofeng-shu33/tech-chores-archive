#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QStringList"
namespace Ui {
    class Widget;
}
class QPushButton;
//person 1 2 3 number s p and gender der die das
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QStringList list;
    QPushButton* button[9];
    bool RightAnswer[9];
private slots:
    void ProcessingSubmit();
};

#endif // WIDGET_H
