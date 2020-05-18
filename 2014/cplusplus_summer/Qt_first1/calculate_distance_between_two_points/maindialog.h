#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "Point2D.h"
namespace Ui {
    class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private:
    Ui::MainDialog *ui;
    int editState;

private slots:
    void on_pushButton_clicked();
    void try_enable_pushButton();
private:
    double distance;
};

#endif // MAINDIALOG_H
