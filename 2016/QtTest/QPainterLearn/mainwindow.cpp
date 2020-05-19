#include "mainwindow.h"
#include <QDebug>
#include <QPainterPath>
QPainterPath roundRectPath(const QRect &rect)
{
        // 半径
        int radius = qMin(rect.width(), rect.height()) / 2;
        int diam = 2 * radius;

        // 获取区域
        int x1, y1, x2, y2;
        rect.getCoords(&x1, &y1, &x2, &y2);

        // 初始化路径
        QPoint p1(x2, y1 + radius);
        QPoint p2(x1 + radius, y1);
        QPoint p3(x1 + radius, y2);
        QRect rect1(x2 - diam, y1, diam, diam);
        QRect rect2(x1, y1, diam, diam);
        QRect rect3(x1, y2 - diam, diam, diam);
        QRect rect4(x2 - diam, y2 - diam, diam, diam);

        QPainterPath path;
        path.moveTo(p1);
        path.arcTo(rect1, 0.0, +90.0);
        path.lineTo(p2);
        path.arcTo(rect2, 90.0, +90.0);
        path.lineTo(x1, y2 - radius);
        path.arcTo(rect3, 180.0, +90.0);
        path.lineTo(p3);
        path.arcTo(rect4, 270.0, +90.0);
        path.closeSubpath();

        // 返回路径
        return path;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setGeometry(100,100,200,200);

}
void MainWindow::paintEvent(QPaintEvent*)

//paintEvent函数由系统自动调用，用不着我们人为的去调用。
 {
    paint=new QPainter;
      paint->begin(this);
      paint->setPen(QPen(Qt::blue,4,Qt::DashLine));//设置画笔形式
      paint->setBrush(QBrush(Qt::red,Qt::SolidPattern));//设置画刷形式
      QRect rec(20,20,80,140);
      QPainterPath path=roundRectPath(rec);
      paint->drawRect(rec);
      paint->drawPath(path);
      paint->end();
     }

MainWindow::~MainWindow()
{
}
