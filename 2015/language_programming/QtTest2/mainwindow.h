#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_lineEdit2_editingFinished();
    void on_lineEdit1_editingFinished();
    void on_lineEdit2_textChanged(QString );
    void on_lineEdit1_textChanged(QString );
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
