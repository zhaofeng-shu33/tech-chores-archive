#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QAction>
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QAction* openAction1;
    QAction* openAction2;
    QAction* openAction3;
    QAction* openAction4;
    QLabel*  label;
private slots:
    void open1();
    void open2();
    void open3();
    void open4();
};

#endif // MAINWINDOW_H
