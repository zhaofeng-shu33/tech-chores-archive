#include "cafdialog.h"
#include <QMenu>
#include <QMenuBar>
#include <QKeySequence>
#include <QToolBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QFileDialog>
#include <QColorDialog>
#include <QPushButton>
#include <QFormLayout>
#include <QGroupBox>
#include <QFont>
#include <QFontDialog>
CAFDialog::CAFDialog(QWidget *parent)
    : QDialog(parent)
{
    colorLabel=new QLabel("color");
    //colorLabel->setLineWidth(29);
    //colorLabel->setFrameStyle(colorLabel->frameStyle());
    QPushButton* button1=new QPushButton("Set Color");
    fontLabel=new QLabel("font");
   // fontLabel->setLineWidth(29);
    QPushButton* button2=new QPushButton("Set Font");
    connect(button1,SIGNAL(clicked()),this,SLOT(set_color()));
    connect(button2,SIGNAL(clicked()),this,SLOT(set_font()));
    QFormLayout* layout=new QFormLayout;
    layout->addRow(button1,colorLabel);
    layout->addRow(button2,fontLabel);
    setLayout(layout);


}

CAFDialog::~CAFDialog()
{

}
void CAFDialog::set_color(){

   QColor color=QColorDialog::getColor();
   if(color.isValid()){
      colorLabel->setText(color.name());
  }
}
void CAFDialog::set_font(){
   bool ok;
   QFont font=QFontDialog::getFont(&ok,this);
   if(ok){
      fontLabel->setText(font.key());
      fontLabel->setFont(font);
   }
}
