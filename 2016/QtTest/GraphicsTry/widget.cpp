#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    graphicsView.setParent(this);
}

Widget::~Widget()
{

}
