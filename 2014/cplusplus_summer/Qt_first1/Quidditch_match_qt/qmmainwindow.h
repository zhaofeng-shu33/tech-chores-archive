#ifndef QMMAINWINDOW_H
#define QMMAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QtGui>
namespace Ui {
    class QMMainWindow;
}

class QMMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QMMainWindow(QWidget *parent = 0);
    ~QMMainWindow();

private:
    Ui::QMMainWindow *ui;
private slots:
    void try_enable_PushButton();
    void begin_output();
private:
    QString name[7];
    int hit_target_factor[7];
    int endurance[7];
    int nimble[7];
};

#endif // QMMAINWINDOW_H
