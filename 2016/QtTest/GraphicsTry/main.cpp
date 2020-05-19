#include <QtGui/QApplication>
#include "widget.h"
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;
    QImage image("D:/QtTest/QtTest16/test.jpg");
    QMatrix matrix;
    matrix.rotate(90);
    QImage newImage=image.transformed(matrix);
    scene.addPixmap(QPixmap::fromImage(newImage));
    Widget w;
    w.graphicsView.setScene(&scene);
    //qDebug()<<w.graphicsView.isVisible();
    w.graphicsView.show();
    w.show();

    return a.exec();
}
