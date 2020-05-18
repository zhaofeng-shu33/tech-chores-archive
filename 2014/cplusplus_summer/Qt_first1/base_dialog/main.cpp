#include<QApplication>
#include <QtGui>

class ExtensionDialog : public QDialog
{
    Q_OBJECT

public:
    ExtensionDialog(){
        setWindowTitle("basic information");
        InitialBaseInformation();
        QVBoxLayout *layout=new QVBoxLayout;
        layout->addWidget(baseWidget);
        layout->setSizeConstraint(QLayout::SetFixedSize);
        // int tem=layout->sizeConstraint();
        //layout->setSpacing(6);
        setLayout(layout);
    }


    void InitialBaseInformation()
    {   baseWidget=new QWidget;
        QLabel* nameLabel=new QLabel("Name");
        QLabel* sexLabel=new QLabel("Sex");
        QLineEdit* nameLineEdit=new QLineEdit;
        QComboBox* sexChoice=new QComboBox;
        sexChoice->addItem("male");
        sexChoice->addItem("female");
        QPushButton* okPushButton=new QPushButton("OK");
        QPushButton* detailPushButton=new QPushButton("Detail");
        QDialogButtonBox* btnBox=new QDialogButtonBox(Qt::Horizontal);
        btnBox->addButton(okPushButton,QDialogButtonBox::ActionRole);
        btnBox->addButton(detailPushButton,QDialogButtonBox::ActionRole);
        QFormLayout* formLayout=new QFormLayout;
        formLayout->addRow(nameLabel,nameLineEdit);
        formLayout->addRow(sexLabel,sexChoice);
        QVBoxLayout* vBoxLayout=new QVBoxLayout;
        vBoxLayout->addLayout(formLayout);
        vBoxLayout->addWidget(btnBox);
        baseWidget->setLayout(vBoxLayout);
 }

    //InitialDetailInformation();


private:
    QWidget* baseWidget;
   // QWidget detailWidget;
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QPushButton my("weiblich");
    //my.show();
     ExtensionDialog w;
     w.show();

    return a.exec();
}
