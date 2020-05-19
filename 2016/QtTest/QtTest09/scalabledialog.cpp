#include "scalabledialog.h"

scalabledialog::scalabledialog(QWidget *parent) :
    QDialog(parent)
{

    setupUi(this);
    this->secondaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}
void scalabledialog::on_moreButton_clicked(){
    this->moreButton->setText(this->secondaryGroupBox->isVisible()?"&less":"&more");
}
