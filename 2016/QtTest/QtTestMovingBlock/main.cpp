#include <QtCore>
#include <QtGui>

class QGraphicsRectWidget : public QGraphicsWidget
{
public:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *,
               QWidget *)
    {
        painter->fillRect(rect(), Qt::blue);
    }
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget window;
    QPalette palette;
    palette.setBrush(QPalette::Window, Qt::green);
    window.setPalette(palette);

    window.resize(300, 300);
    window.show();

    return app.exec();
}
