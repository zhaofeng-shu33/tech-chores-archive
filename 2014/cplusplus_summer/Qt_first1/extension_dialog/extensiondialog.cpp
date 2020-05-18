#include "extensiondialog.h"
ExtensionDialog::ExtensionDialog(QWidget* parent):QDialog(parent){
        setWindowTitle("basic information");
        InitialBaseInformation();
        InitialDetailInformation();
        QVBoxLayout *layout=new QVBoxLayout;
        layout->addWidget(baseWidget);
        layout->addWidget(detailWidget);
        layout->setSizeConstraint(QLayout::SetFixedSize);
        // int tem=layout->sizeConstraint();
        layout->setSpacing(6);
        setLayout(layout);
}


void ExtensionDialog::InitialBaseInformation()
    {   baseWidget=new QWidget;
        QLabel* nameLabel=new QLabel("Name");
        QLabel* sexLabel=new QLabel("Sex");
        QLineEdit* nameLineEdit=new QLineEdit;
        QComboBox* sexChoice=new QComboBox;
        sexChoice->addItem("male");
        sexChoice->addItem("female");
        QPushButton* okPushButton=new QPushButton("OK");
        QPushButton* detailPushButton=new QPushButton("Detail");
        connect(detailPushButton,SIGNAL(clicked()),this,SLOT(SlotExtension()));
        QDialogButtonBox* btnBox=new QDialogButtonBox(Qt::Horizontal);
        btnBox->addButton(okPushButton,QDialogButtonBox::ActionRole);
        btnBox->addButton(detailPushButton,QDialogButtonBox::ActionRole);
        QFormLayout* formLayout=new QFormLayout;
        formLayout->addRow(nameLabel,nameLineEdit);
        formLayout->addRow(sexLabel,sexChoice);
        //QVBoxLayout* vBoxLayout=new QVBoxLayout;
        //vBoxLayout->addLayout(formLayout);
        //vBoxLayout->addWidget(btnBox);
        formLayout->addWidget(btnBox);
        baseWidget->setLayout(formLayout);//vBoxLayout);
 }
void ExtensionDialog::InitialDetailInformation(){
        detailWidget=new QWidget;
        QLabel* ageLabel=new QLabel("Age");
        QLabel* majorLabel=new QLabel("Major");
        QLabel* addressLabel=new QLabel("Address");
        QLineEdit* ageLineEdit=new QLineEdit;
        QComboBox* majorChoice=new QComboBox;
        majorChoice->addItem("Chinesisch");
        majorChoice->addItem("Mathematik");
        majorChoice->addItem("Englisch");
        QLineEdit* addressLineEdit=new QLineEdit;
        QFormLayout* formLayout=new QFormLayout;
        formLayout->addRow(ageLabel,ageLineEdit);
        formLayout->addRow(majorLabel,majorChoice);
        formLayout->addRow(addressLabel,addressLineEdit);
        detailWidget->setLayout(formLayout);
        detailWidget->setVisible(false);//detailWidget->hide();

}
void ExtensionDialog::SlotExtension(){
     if(detailWidget->isHidden())
        detailWidget->show();
     else
        detailWidget->hide();
}
