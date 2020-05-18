#ifndef MAINWINDOW008_H
#define MAINWINDOW008_H

#include <QMainWindow>
#include "Complex.h"
namespace Ui {
    class MainWindow008;
}

class MainWindow008 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow008(QWidget *parent = 0);
    ~MainWindow008();

private:
    Ui::MainWindow008 *ui;
private slots:
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();

private:
   Complex n1,n2;
};
#endif // MAINWINDOW008_H
