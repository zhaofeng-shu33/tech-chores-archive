#ifndef STANDARDINPUTDIALOG_H
#define STANDARDINPUTDIALOG_H
#include <QtGui>
#include <QApplication>
#include <QDialog>
#include <QTextCodec>
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#include <QGridLayout>
#include <QInputDialog>
#include <QStringList>

class StandardInputDialog: public QDialog{
    Q_OBJECT
public:
      StandardInputDialog();
private:
     // QLabel* label1;
     // QLabel* label2;
      QLabel* nameLabel;
      QLabel* ageLabel;
      QPushButton* nameButton;
      QPushButton* ageButton;
    //  QLabel* label3;
      QLabel* sexLabel;
      QPushButton* sexButton;
    //  QLabel* label4;
      QLabel* statureLabel;
      QPushButton* statureButton;
  private slots:
      void slotName();
      void slotAge();
      void slotSex();
     void slotStatue();
};

#endif // STANDARDINPUTDIALOG_H
