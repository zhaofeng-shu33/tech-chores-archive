#include "imagelabel.h"
#include <QMimeData>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDebug>
#include "draglabel.h"
ImageLabel::ImageLabel(QWidget *parent) :
    QLabel(parent)
{
    setAcceptDrops(true);
}
void ImageLabel::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasText()) {
        qDebug()<<"Event Source: "<<event->source()->objectName();
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void ImageLabel::dropEvent(QDropEvent *event)
{
    qDebug()<<"Drop Pos: "<<event->pos();
    if (event->mimeData()->hasText()) {
        const QMimeData *mime = event->mimeData();
        qDebug()<<"dropEvent mimeText: "<<mime->text();
        QStringList pieces = mime->text().split(QRegExp("\\s+"),
                             QString::SkipEmptyParts);
        QPoint position = event->pos();
        QPoint position_true(position.x()-1265,position.y()-650);
        if(position_true.manhattanLength()>30){
            event->ignore();
            event->setDropAction(Qt::IgnoreAction);
            return;
        }
        QPoint hotSpot;
        qDebug()<<"StringListLength: "<<pieces.length();
        QList<QByteArray> hotSpotPos = mime->data("hotspot_position").split(' ');
        if (hotSpotPos.size() == 2) {
            hotSpot.setX(hotSpotPos.first().toInt());
            hotSpot.setY(hotSpotPos.last().toInt());
        }

        foreach (QString piece, pieces) {
            DragLabel *newLabel = new DragLabel(piece, this);
            newLabel->move(position - hotSpot);
            newLabel->show();
            newLabel->setAttribute(Qt::WA_DeleteOnClose);

            position += QPoint(newLabel->width(), 0);
        }

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
    foreach (QObject *child, children()) {
        if (child->inherits("QWidget")) {
            QWidget *widget = static_cast<QWidget *>(child);
            if (!widget->isVisible())
                widget->deleteLater();
        }
    }
}

