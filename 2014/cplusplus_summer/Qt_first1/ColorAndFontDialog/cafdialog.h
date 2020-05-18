#ifndef CAFDIALOG_H
#define CAFDIALOG_H

#include <QtGui/QDialog>
#include <QLabel>
class CAFDialog : public QDialog
{
    Q_OBJECT

public:
    CAFDialog(QWidget *parent = 0);
    ~CAFDialog();
private:
    QLabel* colorLabel;
    QLabel* fontLabel;
private slots:
    void set_color();
    void set_font();
};

#endif // CAFDIALOG_H
