#ifndef DRAGANDDROPMAIN_H
#define DRAGANDDROPMAIN_H

#include <QWidget>

namespace Ui {
    class DragAndDropMain;
}

class DragAndDropMain : public QWidget
{
    Q_OBJECT

public:
    explicit DragAndDropMain(QWidget *parent = 0);
    ~DragAndDropMain();

private:
    Ui::DragAndDropMain *ui;
};

#endif // DRAGANDDROPMAIN_H
