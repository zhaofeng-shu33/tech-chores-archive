#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QWidget>

class QPushButton;
class QTextEdit;
class QLineEdit;
class TextFinder : public QWidget
{
    Q_OBJECT

public:
    explicit TextFinder(QWidget *parent = 0);
    ~TextFinder();

private slots:
     void on_pushButton_clicked();

 private:
     QWidget* loadUiFile();
     void loadTextFile();

     QPushButton *ui_pushButton;
     QTextEdit *ui_textEdit;
     QLineEdit *ui_lineEdit;
     bool isFirstTime;
};

#endif // TEXTFINDER_H
