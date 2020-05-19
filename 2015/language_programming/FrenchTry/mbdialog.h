#ifndef MBDIALOG_H
#define MBDIALOG_H

#include <QtGui/QtGui>
#include <QMessageBox>
#include <QDialog>
class MBDialog : public QDialog
{
    Q_OBJECT

public:
    MBDialog(QWidget *parent = 0);
    ~MBDialog();
private:
    QLabel* warningLabel;
    QLabel* informationLabel;
    QLabel* questionLabel;
    QLabel* criticalLabel;
    QLabel* errorLabel;
    QLabel* aboutLabel;
};

#endif // MBDIALOG_H
