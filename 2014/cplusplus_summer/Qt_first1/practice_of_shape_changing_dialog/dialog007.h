#ifndef DIALOG007_H
#define DIALOG007_H

#include <QDialog>

namespace Ui {
    class Dialog007;
}

class Dialog007 : public QDialog//,public Ui::Dialog007
{
    Q_OBJECT

public:
    explicit Dialog007(QWidget *parent = 0);
    ~Dialog007();

private:
   Ui::Dialog007 *ui;

private slots:
    void on_buttonBox_accepted();
    void on_pushButton_clicked();
};

#endif // DIALOG007_H
