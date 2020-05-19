#ifndef FRENCHTRY_H
#define FRENCHTRY_H

#include <QWidget>

namespace Ui {
    class FrenchTry;
}

class FrenchTry : public QWidget
{
    Q_OBJECT

public:
    explicit FrenchTry(QWidget *parent = 0);
    ~FrenchTry();

private:
    Ui::FrenchTry *ui;
    void loadTextFile();
    void show1();



private slots:
    void on_renewButton_clicked();
    void on_pushButton_clicked();
    void on_checkButton_clicked();
};

#endif // FRENCHTRY_H
