/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>


#include "dragwidget.h"
#include <QFile>
#include "imagelabel.h"
DragWidget::DragWidget(QWidget *parent)
    : QWidget(parent)
{
/*    QFile dictionaryFile(":/dictionary/words.txt");
    dictionaryFile.open(QIODevice::ReadOnly);
    QTextStream inputStream(&dictionaryFile);

    int x = 5;
    int y = 5;

    while (!inputStream.atEnd()) {
        QString word;
        inputStream >> word;
        if (!word.isEmpty()) {
            DragLabel *wordLabel = new DragLabel(word, this);
            wordLabel->move(x, y);
            wordLabel->show();
            wordLabel->setAttribute(Qt::WA_DeleteOnClose);
            x += wordLabel->width() + 2;
            if (x >= 195) {
                x = 5;
                y += wordLabel->height() + 2;
            }
        }
    }
*/  labelContainer=new QWidget;
    labelContainer->setObjectName("labelContainer");
    wordLabel = new DragLabel("Martinskirche", labelContainer);
    wordLabel->move(5,5);
    wordLabel->setAttribute(Qt::WA_DeleteOnClose);
    labelContainer->show();
    wordLabel->show();
    QPalette newPalette = labelContainer->palette();
    newPalette.setColor(QPalette::Window, Qt::white);
    labelContainer->setPalette(newPalette);
    QPixmap* myImage=new QPixmap("D:\\ProjectNote\\GermaData\\UnsupervisedCorpus\\TwoDimensionTour\\FWTM_Plan_Freiburg.jpg");
    qDebug()<<"Window size: "<<this->size();
    qDebug()<<"Image Rec: "<<myImage->rect();
    ImageLabel *imageLabel=new ImageLabel;
    imageLabel->setObjectName("imageLabel");
    imageLabel->setPixmap(*myImage);
    scrollArea=new QScrollArea;
    scrollArea->setObjectName("scrollArea");
    scrollArea->setWidget(imageLabel);
    QVBoxLayout* verticalLayout=new QVBoxLayout(this);
    labelContainer->setMinimumHeight(20);
    verticalLayout->addWidget(labelContainer);
    verticalLayout->addWidget(scrollArea);
    this->setLayout(verticalLayout);
    //newPalette.setBrush(backgroundRole(),QBrush(*myImage));
    setAcceptDrops(true);//default is false;
    setMinimumSize(400, qMax(200, 200));
    this->setWindowState(Qt::WindowMaximized);
    setWindowTitle(tr("Draggable Text"));
    qDebug()<<labelContainer->size();
}
void DragWidget::mousePressEvent(QMouseEvent *event)
{
    QWidget* widget=childAt(event->pos());
 //   qDebug()<<"Mouse Pressed, object name"<<widget->objectName();
    if(widget->parent()){
   //     qDebug()<<"parent object name: "<<widget->parent()->objectName();
        if(widget->parent()->objectName()=="imageLabel"){
            event->ignore();
            return;
        }
    }
    if(widget->objectName()!="DragLabel"){
        event->ignore();
        return;
    }
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    QPoint hotSpot = event->pos() - child->pos();
    QMimeData *mimeData = new QMimeData;
    mimeData->setText(child->text());
    mimeData->setData("hotspot_position",
                      QByteArray::number(hotSpot.x())
                      + " " + QByteArray::number(hotSpot.y()));

    QPixmap pixmap(child->size());
    child->render(&pixmap);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(hotSpot);//initial pos

    Qt::DropAction dropAction = drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction);
  //  qDebug()<<"drop action returned";
    //qDebug()<<"dropAction: "<<dropAction;
    if (dropAction != Qt::IgnoreAction)
        child->close();
}

