#include "inputmethod.h"
#include <QLineEdit>
#include <QPushButton>
#include <QBoxLayout>
TextSearchDialog::TextSearchDialog(QDialog *parent) :
    QDialog(parent)
{
    //lineEdit=new QLineEdit(this);
    nextButton=new QPushButton("&NextFind",this);
    cancelButton=new QPushButton("&Cancel",this);
    QVBoxLayout *VLayout=new QVBoxLayout;
    VLayout->addWidget(nextButton);
    VLayout->addWidget(cancelButton);
    this->setLayout(VLayout);
}

TextSearchDialog::~TextSearchDialog()
{
    delete this;
}
