#ifndef EVENTLABEL_H
#define EVENTLABEL_H
#include<QtGui/QDialog>
#include <QPushButton>
#include <QLabel>
#include <QBoxLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QMouseEvent>
class EventLabel: public QLabel
{
public:
 void mousePressEvent(QMouseEvent* event );
 void mouseMoveEvent(QMouseEvent *event);
 void mouseReleaseEvent(QMouseEvent *event);

};
class ChildLabel: public EventLabel
{
public:
  void mousePressEvent(QMouseEvent* event );

};

#endif // EVENTLABEL_H
