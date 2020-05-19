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
#include <QTextStream>
#include "mainwindow.h"
#include "textedit.h"
#include <QDebug>

//! [0]
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    completingTextEdit = new TextEdit("D:\\PythonDemo\\wordform.txt",this);
    setCentralWidget(completingTextEdit);
    resize(500, 300);
    setWindowTitle(tr("Completer"));
    myPopupWord=new undoTest(this);
    myPopupWord->hide();
    createMenu();

}
void MainWindow::createMenu()
{
    QAction *exitAction = new QAction(tr("Exit"), this);
    QAction *aboutAct = new QAction(tr("About"), this);
    QAction *aboutQtAct = new QAction(tr("About Qt"), this);
    QAction *editAction = new QAction("PopupWord",this);

    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    connect(editAction,SIGNAL(triggered()),this,SLOT(showPopupWords()));
    connect(myPopupWord,SIGNAL(closed(QStringList)),completingTextEdit,SLOT(AskForAcceptWordList(QStringList)));
    QMenu* fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(exitAction);
    QMenu* editMenu = menuBar()->addMenu("Edit");
    editMenu->addAction(editAction);
    QMenu* helpMenu = menuBar()->addMenu(tr("About"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}
void MainWindow::showPopupWords(){

    QStringList copyOfWordList=completingTextEdit->GetGerCompleterWordList();
    myPopupWord->initModel(copyOfWordList);
    myPopupWord->show();
}
void MainWindow::setStringList(QStringList newList){
    list=newList;
    qDebug()<<"stringList Length: "<<list.length();
}

void MainWindow::about()
{
    qDebug()<<myPopupWord->isHidden();
    QMessageBox::about(this, tr("About"), tr("This example demonstrates the "
        "different features of the GerCompleter class."));
}

