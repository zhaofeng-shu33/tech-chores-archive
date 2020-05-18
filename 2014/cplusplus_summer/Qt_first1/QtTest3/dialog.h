#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "Complex.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, Complex c0 = Complex(0.0, 0.0));
    ~Dialog();

private:
    Ui::Dialog *ui;
public:
    Complex c;

private slots:
    void on_buttonBox_rejected();
    void on_buttonBox_accepted();
};

#endif // DIALOG_H
