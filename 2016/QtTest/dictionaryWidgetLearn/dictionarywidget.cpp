#include "dictionarywidget.h"
#include "ui_dictionarywidget.h"
#include "InsertCommand.h"
#include <QDebug>
#include <QStringListModel>
#include <QUndoStack>
#include <QModelIndex>
#include <QPalette>
dictionarywidget::dictionarywidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dictionarywidget)
{
    ui->setupUi(this);
    QStringList stringList;
    stringList<<"Abend "<<"Arzt";
    ListModel=new QStringListModel(stringList);
    stringList<<"Abteilung";
    ui->listView->setModel(ListModel);
    connect(ui->lineEdit,SIGNAL(editingFinished()),this,SLOT(setData()));
    mUndoStack=new QUndoStack;
    mUndoAction = mUndoStack->createUndoAction(this, tr("Undo"));
    mRedoAction=mUndoStack->createRedoAction(this);
    connect(ui->pushButton,SIGNAL(clicked()),mUndoAction,SLOT(trigger()));
    connect(ui->pushButton_2,SIGNAL(clicked()),mRedoAction,SLOT(trigger()));
    ui->textEdit->append("<font color='red'>Test</font>");
}

dictionarywidget::~dictionarywidget()
{
    delete ui;
}
void dictionarywidget::setData(){
    QString content=ui->lineEdit->text();
    if(content!=""){
        QModelIndex aIndex = ui->listView->currentIndex();
    mUndoStack->push(new InsertCommand(aIndex, ListModel,content));
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();}
}
