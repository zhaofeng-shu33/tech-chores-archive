#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "win_qextserialport.h"
#include "MessageWindow.h"
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
    Win_QextSerialPort *myCom;
    MessageWindow* myMessageWindow;
    bool AsciiMode;
private slots:
    void on_sendMsgLineEdit_returnPressed();
    void on_selectSerialPortBtn_currentIndexChanged(const QString & text);
    void on_sendMsgBtn_clicked();
    void on_closeMyComBtn_clicked();
    void on_openMyComBtn_clicked(QString comName="com5");
    void readMyCom();
    void setTextMode();
};

#endif // MAINWINDOW_H
