#ifndef DIALOG008_H
#define DIALOG008_H

#include <QDialog>
#include "Complex.h"
namespace Ui {
    class Dialog008;
}

class Dialog008 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog008(QWidget *parent = 0,Complex n=Complex(0,0));
    ~Dialog008();
public:
    Complex d;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    Ui::Dialog008 *ui;
};

#endif // DIALOG008_H
