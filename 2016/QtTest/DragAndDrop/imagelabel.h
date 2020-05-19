#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>

class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ImageLabel(QWidget *parent = 0);

signals:
protected:
   void dragEnterEvent(QDragEnterEvent *event);
   void dropEvent(QDropEvent *event);
   //void mousePressEvent(QMouseEvent *event);
public slots:

};

#endif // IMAGELABEL_H
