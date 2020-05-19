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

#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileInfo>
#include <QApplication>
#include <QFileDialog>
#include <QCloseEvent>
#include <QPushButton>
#include <QMenu>
#include "mdichild.h"

MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);//widget attribute
    isUntitled = true;
}

void MdiChild::newFile()
{
    static int sequenceNumber = 1;

    isUntitled = true;
    curFile = tr("document%1.txt").arg(sequenceNumber++);
    setWindowTitle(curFile + "[*]");

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));
}

bool MdiChild::loadFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    QApplication::setOverrideCursor(Qt::WaitCursor);
    setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);

    connect(document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));

    return true;
}

bool MdiChild::save()
{
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MdiChild::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"),
                                                    curFile);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

bool MdiChild::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("MDI"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    return true;
}

QString MdiChild::userFriendlyCurrentFile()
{
    return strippedName(curFile);
}

void MdiChild::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}
void MdiChild::contextMenuEvent(QContextMenuEvent *event){
    QMenu *menu=new QMenu;
    QAction *undoAct = menu->addAction(QIcon(":/images/undo.png"), tr("&Undo"),
                                       this,SLOT(undo()),QKeySequence::Undo);
    undoAct->setEnabled(document()->isUndoAvailable());
    QAction *redoAct = menu->addAction(QIcon(":/images/redo.png"), tr("&Redo"),
                                       this,SLOT(redo()),QKeySequence::Redo);
    redoAct->setEnabled(document()->isRedoAvailable());

    menu->addSeparator();

    QAction *cutAct =  menu->addAction(QIcon(":/images/cut.png"), tr("Cu&t"),
                                       this,SLOT(cut()),QKeySequence::Cut);
    cutAct->setEnabled(textCursor().hasSelection());
    QAction *copyAct = menu->addAction(QIcon(":/images/copy.png"), tr("&Copy"),
                                       this,SLOT(copy()),QKeySequence::Copy);
    copyAct->setEnabled(textCursor().hasSelection());

    menu->addAction(QIcon(":/images/paste.png"), tr("&Paste"),
                                        this,SLOT(paste()),QKeySequence::Paste);

    QAction *clearAct =menu->addAction(tr("Clear"),this,SLOT(clear()));
    clearAct->setEnabled(!this->document()->isEmpty());

    menu->addSeparator();

    QAction *selectAllAct =menu->addAction(tr("Select All"),
                                           this,SLOT(selectAll()),QKeySequence::SelectAll);
    selectAllAct->setEnabled(!document()->isEmpty());

    menu->exec(event->globalPos());
    delete menu;
}

void MdiChild::documentWasModified()
{
    setWindowModified(document()->isModified());
}

bool MdiChild::maybeSave()
{
    if (document()->isModified()) {
	QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("MDI"),
                     tr("'%1' has been modified.\n"
                        "Do you want to save your changes?")
                     .arg(userFriendlyCurrentFile()),
                     QMessageBox::Save | QMessageBox::Discard
		     | QMessageBox::Cancel);
        if (ret == QMessageBox::Save)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
    return true;
}

void MdiChild::setCurrentFile(const QString &fileName)
{
    curFile = QFileInfo(fileName).canonicalFilePath();
    isUntitled = false;
    document()->setModified(false);
    setWindowModified(false);
    setWindowTitle(userFriendlyCurrentFile() + "[*]");
}

QString MdiChild::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}
