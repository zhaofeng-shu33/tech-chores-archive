#include <QTextCodec>
#include <QString>
#include <QDir>
#include "wordinput.h"
#include "ui_wordinput.h" 
wordInput::wordInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wordInput)
{
    //qDebug()<<"Debug";
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);//NounDicWithDb/NounLibrary
    ui->comboBox->setDisabled(true);
    this->setPalette();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    db=QSqlDatabase::addDatabase("QODBC");
    QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1/NounLib.mdb").arg(dir->currentPath());
    db.setDatabaseName(dsn);
    model=new QSqlTableModel;
    //if(!db.open()){
       // qDebug()<<"Error: "<<db.lastError();
    //}
    model->setQuery("select wordform from WordList where ID <257");//upper limit 2^8??
    int rec_count=model->rowCount();
   // qDebug()<<model->record(1).value(0);
    for(int i=0;i<rec_count;i++)
    wordlist.appendRow(new QStandardItem(model->record(i).value(0).toString()));
    model->setQuery("select wordform from WordList where ID >256");
    rec_count=model->rowCount();
    for(int i=0;i<rec_count;i++)
    wordlist.appendRow(new QStandardItem(model->record(i).value(0).toString()));

    ui->listView->setModel(&wordlist);
    completer=new QCompleter(&wordlist);
    ui->lineEdit->setCompleter(completer);
}
wordInput::~wordInput()
{
    db.close();
    delete ui;
}


void wordInput::on_comboBox_currentIndexChanged(int index)
{
    ui->stackedWidget->setCurrentIndex(index);
}

void wordInput::on_lineEdit_editingFinished()
{
    QString checkString = ui->lineEdit->text();
    seek_word(checkString);
}
void wordInput::seek_word(QString checkString){
    if(checkString.length()==0){
       ui->lineEdit->setFocus();
       return;
    }
    ui->lineEdit->selectAll();
    ui->textEdit_2->clear();
    model->setQuery(QString("select * from Noun where wordform ='%1'").arg(checkString));
    if(model->data(model->index(0,0)).isNull()){
        qDebug()<<"Not found from Noun wordform";
        model->clear();
        model->setQuery(QString("select * from Noun where Plural ='%1'").arg(checkString));
    }

    int rec_count=model->rowCount();

    if(rec_count>0){
        checkString=model->data(model->index(0,1)).toString();//Take the gender of the noun.
        int column=model->record().count();
        QModelIndex myIndex=wordlist.findItems(checkString)[0]->index();
        ui->listView->setCurrentIndex(myIndex);
        ui->listView->scrollTo(myIndex);//synchronously update the word list view
        showmodel.clear();
        for(int i=0;i<column-1;i++){
            QList<QStandardItem*> newRow;
            for(int j=0;j<rec_count;j++)
                newRow.append(new QStandardItem(model->data(model->index(j,i)).toString()));//append the field to the table view
            showmodel.appendRow(newRow);
            showmodel.setHeaderData(i,Qt::Vertical,model->record().fieldName(i));
        }
        //model->record(0).fieldName(i)
    showmodel.removeColumn(column-1);

    ui->tableView->setModel(&showmodel);
    ui->tableView->resizeColumnsToContents();
    showmodel.item(5,0)->setBackground(QBrush(Qt::yellow));
    showmodel.item(5,0)->setToolTip(QString("Beispiel: %1").arg(model->data(model->index(0,5)).toString()));
    showmodel.item(5,0)->setAccessibleText("Beispiel");

    //ui->tableView->setSpan(5,0,4,4);
    bool HaveAudio=model->data(model->index(0,column-1)).toBool();
    if(HaveAudio){
        QString address=QString("%1/audioSource/%2.mp3").arg(dir->currentPath()).arg(model->data(model->index(0,1)).toString());
        //qDebug()<<address;
        music =Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(address));
    if(ui->pushButton->isHidden())
        ui->pushButton->show();
    }
    else   ui->pushButton->hide();
    }else {
     ui->textEdit_2->append("Queried Word not found.");
    }

}

void wordInput::on_pushButton_clicked()
{
    music->play();
    music->seek(0);
    //delete music;
}

void wordInput::on_listView_clicked(QModelIndex index)
{
    QString checkString=wordlist.itemFromIndex(index)->text();
    ui->lineEdit->setText(checkString);
    seek_word(checkString);
}
