#include <QtGui>
#include "file_dialog.h"
#include "ui_file_dialog.h"

File_Dialog::File_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::File_Dialog)
{
    ui->setupUi(this);
    dirModel=new QDirModel;
    selModel=new QItemSelectionModel(dirModel);
    ui->listView->setModel(dirModel);
    ui->treeView->setModel(dirModel);
    ui->tableView->setModel(dirModel);
    ui->listView->setSelectionModel(selModel);
    ui->treeView->setSelectionModel(selModel);
    ui->tableView->setSelectionModel(selModel);
    QModelIndex cwdIndex=dirModel->index(QDir::rootPath());
    ui->listView->setRootIndex(cwdIndex);
    ui->treeView->setRootIndex(cwdIndex);
    ui->tableView->setRootIndex(cwdIndex);

    for(int r=0;r<dirModel->rowCount(QModelIndex());r++){
        QModelIndex index=dirModel->index(r,0,QModelIndex());
        if(index.isValid())
           ui->comboBox->addItem(dirModel->fileIcon(index),dirModel->filePath(index));
    }
    connect(ui->switchButton,SIGNAL(clicked()),this,SLOT(switchView()));
}

File_Dialog::~File_Dialog()
{
    delete ui;
}
