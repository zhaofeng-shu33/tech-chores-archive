#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H
#include <QDialog>
#include "ui_rectangledialog.h"
class RectangleDialog:public QDialog,public Ui::RectangleDialog{
    Q_OBJECT
public:
      RectangleDialog(QWidget* parent=0);
private slots:
      void calculateClicked();
      void enableCalculateButton();
      void rectangleAreaCalculate(const QString &lengthString, const QString &widthString);
signals:
     void rectangleLengthWidth(const QString &lengthString, const QString &widthString);



};

#endif // RECTANGLEDIALOG_H
