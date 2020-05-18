#ifndef MAINWINDOW12_H
#define MAINWINDOW12_H

#include <QMainWindow>

namespace Ui {
    class MainWindow12;
}

class MainWindow12 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow12(QWidget *parent = 0);
    ~MainWindow12();

private:
    Ui::MainWindow12 *ui;
private slots:
    void on_lineEdit_2_editingFinished();
    void on_lineEdit_1_editingFinished();
    void show_in_lcdNumber();
};

#endif // MAINWINDOW12_H
