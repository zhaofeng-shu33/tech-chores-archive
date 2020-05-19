#include <QStringListModel>
#include <QStringList>
#include <QPoint>
#include <QDebug>
#include "gercompleter.h"

GerCompleter::GerCompleter(QStringList words,QObject *parent) :
    QObject(parent)
{

    CompletionView=new QListView();
    CompletionView->setWindowModality(Qt::NonModal);
    wordList=words;
    qDebug()<<"Total word: "<<wordList.length();
    CompletionView->setWindowFlags(Qt::ToolTip);
    connect(CompletionView,SIGNAL(clicked(QModelIndex)),this,SLOT(ReturnMatchedPattern(QModelIndex)));
    currentSelection=0;
}
void GerCompleter::setCompletionPrefix(QString Prefix){
    CompletionPrefix=Prefix;
   // qDebug()<<"CompletionPrefix: "<<CompletionPrefix;
    LoadCompletionView();
}
void GerCompleter::ReturnMatchedPattern(QModelIndex modelIndex){
    QString insertText=CompletionView->model()->data(modelIndex).toString();
    CompletionView->hide();
    currentSelection=0;
    emit this->activated(insertText);
}
void GerCompleter::appendNew(QString word){
    wordList.append(word);
}

void GerCompleter::LoadCompletionView(){

    qDebug()<<"Load Completion View";
    QStringList CompletionList=wordList.filter(QRegExp(QString("\\b%1.*").arg(CompletionPrefix)));
    qDebug()<<"CompletionListLength: "<<CompletionList.length();
    QStringListModel* CompletionModel=new QStringListModel(CompletionList);
    if(CompletionModel==NULL)qDebug()<<"Null Model!";
    CompletionView->setModel(CompletionModel);
    //CompletionView->show();

}
void GerCompleter::complete(QPoint cr,int dir){
   // CompletionView->setGeometry(cr);
    int totalRow=CompletionView->model()->rowCount();
    if(totalRow==0)return;
    currentSelection=(currentSelection+dir+totalRow)%totalRow;
    QModelIndex index = CompletionView->model()->index(currentSelection, 0);
    CompletionView->setCurrentIndex(index);
    CompletionView->move(cr);
    CompletionView->show();
}
void GerCompleter::activateReturnMatchedPattern(QModelIndex modelIndex){
    ReturnMatchedPattern(modelIndex);
}
