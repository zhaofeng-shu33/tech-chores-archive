#ifndef WIDGET_H
#define WIDGET_H
#include "wordlist.h"
#include <QWidget>

namespace Ui {
    class Widget;
}

class Widget : public QWidget,public WordList
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
  };

#endif // WIDGET_H
