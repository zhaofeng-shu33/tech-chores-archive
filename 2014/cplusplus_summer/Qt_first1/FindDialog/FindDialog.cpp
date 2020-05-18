#include "FindDialog.h"

FindDialog::FindDialog(){
    setWindowTitle("Find an element");
    label=new QLabel("Find &what");
    lineEdit=new QLineEdit;
    label->setBuddy(lineEdit);
    box1=new QCheckBox("stand &1");
    box2=new QCheckBox("Search backward");
    findButton=new QPushButton("&Find");
    closeButton=new QPushButton("&Close");
    findButton->setEnabled(false);
    closeButton->setDefault(true);
    QHBoxLayout* hupLayout=new QHBoxLayout;
    hupLayout->addWidget(label);
    hupLayout->addWidget(lineEdit);
    hupLayout->addWidget(findButton);
    QVBoxLayout* vsmalLayout=new QVBoxLayout;
    vsmalLayout->addWidget(box1);
    vsmalLayout->addWidget(box2);
    QHBoxLayout* hdownLayout=new QHBoxLayout;
    hdownLayout->addLayout(vsmalLayout);
    hdownLayout->addStretch();
    hdownLayout->addWidget(closeButton);
    QVBoxLayout* vbigLayout=new QVBoxLayout;
    vbigLayout->addLayout(hupLayout);
    vbigLayout->addLayout(hdownLayout);
    setLayout(vbigLayout);
    setFixedHeight(sizeHint().height());
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
    bool ok=true;
    connect(box1,SIGNAL(clicked(bool)),findButton,SLOT(setEnabled(bool)));
    connect(box2,SIGNAL(clicked(bool)),findButton,SLOT(setDisabled(bool)));
    connect(lineEdit,SIGNAL(textChanged(QString)),this,SLOT(EnableFindButton(QString)));
}
FindDialog::~FindDialog(){}
/*void FindDialog::FindClicked(){
    QString text=lineEdit->text();
    Qt::CaseSensitivity cs=box1->isChecked() ? Qt::CaseInsensitive:Qt::CaseSensitive;
    if(box2->isChecked())
       emit FindPrevious(text,cs);
    else
       emit FindNext(text,cs);
}*/
void FindDialog::EnableFindButton(QString text){
    findButton->setEnabled(!text.isEmpty());
}
