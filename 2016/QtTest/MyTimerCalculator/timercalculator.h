#ifndef TIMERCALCULATOR_H
#define TIMERCALCULATOR_H

#include <QWidget>

namespace Ui {
    class TimerCalculator;
}

class TimerCalculator : public QWidget
{
    Q_OBJECT

public:
    explicit TimerCalculator(QWidget *parent = 0);
    ~TimerCalculator();

private:
    Ui::TimerCalculator *ui;

private slots:
    void on_doubleSpinBox_editingFinished();
 };

#endif // TIMERCALCULATOR_H
