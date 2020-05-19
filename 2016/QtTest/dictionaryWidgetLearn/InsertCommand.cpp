#include "InsertCommand.h"

#include <QStringListModel>
#include <QDebug>
InsertCommand::InsertCommand(const QModelIndex& theIndex, QStringListModel* theModel,QString& content)
: QUndoCommand(("Insert ") + QString::number(theIndex.row()))
, mIndex(theIndex)
, mModel(theModel)
, Content(content)
{
}


InsertCommand::~InsertCommand()
{
}

void InsertCommand::undo()
{
    mModel->removeRows(mIndex.row(), 1);
}

void InsertCommand::redo()
{
    mModel->insertRows(mIndex.row(), 1);
    mModel->setData(mIndex,Content);
    qDebug()<<"redo is called";
}
