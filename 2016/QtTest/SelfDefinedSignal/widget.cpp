#include "widget.h"
#include <QVBoxLayout>
#include <QPushButton>
Widget::Widget(QStringList words,QDialog *parent)
    : QDialog(parent)
{
    model=new QStringListModel(this);
    model->setStringList(words);
    listView=new QListView;
    listView->setModel(model);
    buttonBox = new QDialogButtonBox;
        QPushButton *insertButton = buttonBox->addButton(
                    tr("&Insert"),QDialogButtonBox::ActionRole);
        QPushButton *deleteButton = buttonBox->addButton(
                    tr("&Delete"), QDialogButtonBox::ActionRole);
        buttonBox->addButton(QDialogButtonBox::Ok);
        buttonBox->addButton(QDialogButtonBox::Cancel);
        connect(insertButton, SIGNAL(clicked()), this, SLOT(insert()));
        connect(deleteButton, SIGNAL(clicked()), this, SLOT(del()));
        connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(listView);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("QStringListModel"));


}

Widget::~Widget()
{

}
void Widget::insert(){
    int row = listView->currentIndex().row();
    model->insertRows(row, 1);

    QModelIndex index = model->index(row);
    listView->setCurrentIndex(index);
    listView->edit(index);
}
void Widget::del(){

}
