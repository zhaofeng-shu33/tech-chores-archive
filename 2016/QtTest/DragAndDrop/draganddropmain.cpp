#include "draganddropmain.h"
#include "ui_draganddropmain.h"

DragAndDropMain::DragAndDropMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DragAndDropMain)
{
    ui->setupUi(this);
}

DragAndDropMain::~DragAndDropMain()
{
    delete ui;
}
