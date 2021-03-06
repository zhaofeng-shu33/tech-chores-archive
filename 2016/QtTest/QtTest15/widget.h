#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <phonon/MediaObject>
#include <phonon/VideoPlayer>

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    Phonon::VideoWidget *vwidget;
    Phonon::VideoPlayer *player;


private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
};

#endif // WIDGET_H
