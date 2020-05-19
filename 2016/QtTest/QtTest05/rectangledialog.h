#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H
#include <QDialog>
class QLabel;
class QLineEdit;
class QPushButton;
class RectangleDialog: public QDialog{
    Q_OBJECT
public:
      RectangleDialog(QWidget* parent=0);
private:
      QLabel* lengthLabel;
      QLabel* widthLabel;
      QLabel* rectangleAreaLabel;
      QLineEdit* lengthEdit;
      QLineEdit* widthEdit;
      QLineEdit* rectangleAreaEdit;
      QPushButton* calculateButton;
      QPushButton* closeButton;
  private slots:
      void calculateClicked();
      void enableCalculateButton();
      void rectangleAreaCalculate(const QString &lengthString, const QString &widthString);
signals:
     void rectangleLengthWidth(const QString &lengthString, const QString &widthString);


};

#endif // RECTANGLEDIALOG_H
