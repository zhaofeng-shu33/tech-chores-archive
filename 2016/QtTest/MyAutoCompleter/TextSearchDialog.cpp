#include "inputmethod.h"
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>
TextSearchDialog::TextSearchDialog(QDialog *parent) :
    QDialog(parent)
{
    lineEdit=new QLineEdit(this);
    nextButton=new QPushButton("&NextFind",this);
    cancelButton=new QPushButton("&Cancel",this);

    QHBoxLayout *HLayout=new QHBoxLayout;
    HLayout->addWidget(nextButton);
    HLayout->addWidget(cancelButton);

    QFormLayout* formLayout=new QFormLayout;
    formLayout->addRow("Input the Searched Word",lineEdit);

    QVBoxLayout *VLayout=new QVBoxLayout;
    VLayout->addLayout(formLayout);
    VLayout->addLayout(HLayout);
    this->setLayout(VLayout);
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

TextSearchDialog::~TextSearchDialog()
{
    delete this;
}
