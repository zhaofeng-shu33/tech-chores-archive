#ifndef ADWIDGET_H
#define ADWIDGET_H

#include <QWidget>
#include <QTime>
#include "win_qextserialport.h"

namespace Ui {
    class ADWidget;
}

class ADWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ADWidget(QWidget *parent = 0);
    ~ADWidget();

private:
    Ui::ADWidget *ui;
    Win_QextSerialPort *myCom;
    bool ok;
    int previousData;
private slots:
    void on_pushButton_clicked();
    void readMyCom();

};

#endif // ADWIDGET_H
