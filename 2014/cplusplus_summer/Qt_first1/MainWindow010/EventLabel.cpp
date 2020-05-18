#include "EventLabel.h"
#include <QMessageBox>
void EventLabel::mousePressEvent(QMouseEvent* event){
    this->setText(QString("Press:(%1,%2)").arg((QString::number(event->x()))).arg(QString::number(event->y())));
}
void EventLabel::mouseMoveEvent(QMouseEvent* event){
    this->setText(QString("Move:(%1,%2)").arg((QString::number(event->x()))).arg(QString::number(event->y())));

}
void EventLabel::mouseReleaseEvent(QMouseEvent *event){
    this->setText(QString("Release:(%1,%2)").arg((QString::number(event->x()))).arg(QString::number(event->y())));

}
void ChildLabel::mousePressEvent(QMouseEvent* event){
   // if(event->button()==(Qt::LeftButton()))
     if(true)
      QMessageBox::information(NULL,"title","content",QMessageBox::Yes|QMessageBox::No);
    else
        EventLabel::mousePressEvent(event);
    }
