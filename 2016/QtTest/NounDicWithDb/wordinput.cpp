#include <QTextCodec>
#include <QString>
#include <QDir>
#include <QWebFrame>
#include <QWebView>
#include <QDebug>
#include <QFile>
#include <zlib.h>
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
    //this->setPalette();
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
   // db=QSqlDatabase::addDatabase("QODBC");
   // QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=%1/NounLib.mdb").arg(dir->currentPath());
   // db.setDatabaseName(dsn);
  //  model=new QSqlTableModel;
    //if(!db.open()){
       // qDebug()<<"Error: "<<db.lastError();
    //}
  //  model->setQuery("select wordform from WordList where ID <257");//upper limit 2^8??
  //  int rec_count=model->rowCount();
   // qDebug()<<model->record(1).value(0);
  //  for(int i=0;i<rec_count;i++)
  ////  wordlist.appendRow(new QStandardItem(model->record(i).value(0).toString()));
  //  model->setQuery("select wordform from WordList where ID >256");
 //   rec_count=model->rowCount();
    LoadData();
    ui->listView->setModel(&wordlist);
    completer=new QCompleter(&wordlist);
    ui->lineEdit->setCompleter(completer);
    query=QXmlQuery(QXmlQuery::XSLT20);
    QString out;
    QString xmlDocument=QString::fromUtf8(record_uncompressed.mid(4,1052).data());
    query.setFocus(xmlDocument);
    //query.setFocus(QUrl("D:\\ProjectNote\\GermaData\\DicTest\\Wort\\1.xml"));
    query.setQuery(QUrl("D:\\ProjectNote\\GermaData\\DicTest\\Wort\\NounRenderTemplate.xslt"));
    query.evaluateTo(&out);
    ui->webView->setHtml(out);
    ui->webView->show();

}
wordInput::~wordInput()
{
    //db.close();
    delete ui;
}
void wordInput::LoadData(){
         QFile my_file("D:/ProjectNote/GermaData/DicTest/DicCompressed_1.txt");
        if(my_file.open(QFile::ReadOnly)){
           QByteArray src(my_file.readAll());
           my_file.close();
           qDebug()<<src.size();
           int Header_Length=ToInteger(src.mid(0,4));
           qDebug()<<"Header_Length: "<<Header_Length;
            QString description(src.mid(4,Header_Length));//sometimes there should be encoding problems here,
            qDebug()<<description;//use qstring:fromutf-8 instead
           // qDebug()<<dataSize;
            int offset=4+Header_Length;
            int key_compressed_length=ToInteger(src.mid(offset,4));
            offset+=4;
            int key_decompressed_length=ToInteger(src.mid(offset,4));
            offset+=4;
            qDebug()<<"key_compressed_length: "<<key_compressed_length;
            qDebug()<<"key_decompressed_length: "<<key_decompressed_length;

            // unsigned long len_compress;
           unsigned char buffer_uncompress[key_decompressed_length+1];
           unsigned long len_uncompress;
            qDebug()<<"State: "<<uncompress((Bytef*)&buffer_uncompress,&len_uncompress,(Bytef*)src.mid(offset,key_compressed_length).data(),key_compressed_length);
            qDebug()<<"After uncompress, the data has length: "<<len_uncompress;
            QString wordListTotal(QString::fromUtf8(reinterpret_cast<const char*>(buffer_uncompress)));
           //cout<<wordListTotal.replace('\n',' ');
            QStringList wordList2=wordListTotal.split('\n');
            foreach(QString str,wordList2)
                wordlist.appendRow(new QStandardItem(str));

            qDebug()<<"wordListLength: "<<wordList2.length();
            offset+=key_compressed_length;
            qint64 record_compressed_length=ToLongInteger(src.mid(offset,8));
            offset+=8;
            qint64 record_decompressed_length=ToLongInteger(src.mid(offset,8));
            offset+=8;
            qDebug()<<"record_compressed_length: "<<record_compressed_length;
            qDebug()<<"record_decompressed_length: "<<record_decompressed_length;
            unsigned long len_uncompress2;
            unsigned char buffer_uncompress2[record_decompressed_length+1];
            qDebug()<<"State2: "<<uncompress((Bytef*)&buffer_uncompress2,&len_uncompress2,(Bytef*)src.mid(offset,record_compressed_length).data(),record_compressed_length);
            qDebug()<<"Uncompressed Data: "<<buffer_uncompress2[3]+0;

            record_uncompressed.append(QByteArray::fromRawData(reinterpret_cast<const char*>(buffer_uncompress2),record_decompressed_length));

            qDebug()<<"record_uncompresed_length: "<<len_uncompress2<<' '<<record_uncompressed.length();
            offset=0;
            int cnt=0;

            while(offset<record_uncompressed.length() && cnt<=wordList2.length()){
                int numOfLength=ToInteger(record_uncompressed.mid(offset,4));
                offset+=4;
                m_map[wordList2[cnt]]=pair_type(offset,numOfLength);
                offset+=numOfLength;
                cnt++;
            }

            }
}

int wordInput::ToInteger(QByteArray array){
    int n1=0;
    if(array.length()==4){
        foreach(char t,array){
            if(t<0)n1=256*(n1+256+t);
            else n1=256*(n1+t);
        }
        n1 /=256;
    }
    return n1;
}
qint64 wordInput::ToLongInteger(QByteArray array){
    qint64 n1=0;
    if(array.length()==8){
        foreach(char t,array){
            if(t<0)n1=256*(n1+256+t);
            else n1=256*(n1+t);
        }
        n1 /=256;
    }
    return n1;
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
    //QString word=QString::fromUtf8("Gerät");
    if(m_map.contains(checkString)){
    //cout<<QString::fromUtf8("Gerät")<<endl<<flush;

    QString out;
    QString xmlDocument=QString::fromUtf8(record_uncompressed.mid(m_map[checkString].first,m_map[checkString].second).data());
    query.setFocus(xmlDocument);
    query.evaluateTo(&out);
    ui->webView->setHtml(out);
    }
//    if(checkString.length()==0){
//       ui->lineEdit->setFocus();
//       return;
//    }
//    ui->lineEdit->selectAll();
//    ui->textEdit_2->clear();
//    model->setQuery(QString("select * from Noun where wordform ='%1'").arg(checkString));
//    if(model->data(model->index(0,0)).isNull()){
//        qDebug()<<"Not found from Noun wordform";
//        model->clear();
//        model->setQuery(QString("select * from Noun where Plural ='%1'").arg(checkString));
//    }

//    int rec_count=model->rowCount();

//    if(rec_count>0){
//        checkString=model->data(model->index(0,1)).toString();//Take the gender of the noun.
//        int column=model->record().count();
//        QModelIndex myIndex=wordlist.findItems(checkString)[0]->index();
//        ui->listView->setCurrentIndex(myIndex);
//        ui->listView->scrollTo(myIndex);//synchronously update the word list view
//        showmodel.clear();
//        for(int i=0;i<column-1;i++){
//            QList<QStandardItem*> newRow;
//            for(int j=0;j<rec_count;j++)
//                newRow.append(new QStandardItem(model->data(model->index(j,i)).toString()));//append the field to the table view
//            showmodel.appendRow(newRow);
//            showmodel.setHeaderData(i,Qt::Vertical,model->record().fieldName(i));
//        }
//        //model->record(0).fieldName(i)
//    showmodel.removeColumn(column-1);

//    //ui->tableView->setModel(&showmodel);
//   // ui->tableView->resizeColumnsToContents();
//    showmodel.item(5,0)->setBackground(QBrush(Qt::yellow));
//    showmodel.item(5,0)->setToolTip(QString("Beispiel: %1").arg(model->data(model->index(0,5)).toString()));
//    showmodel.item(5,0)->setAccessibleText("Beispiel");

//    //ui->tableView->setSpan(5,0,4,4);
//    bool HaveAudio=model->data(model->index(0,column-1)).toBool();
//    if(HaveAudio){
//        QString address=QString("%1/audioSource/%2.mp3").arg(dir->currentPath()).arg(model->data(model->index(0,1)).toString());
//        //qDebug()<<address;
//        music =Phonon::createPlayer(Phonon::MusicCategory,Phonon::MediaSource(address));
//    if(ui->pushButton->isHidden())
//        ui->pushButton->show();
//    }
//    else   ui->pushButton->hide();
//    }else {
//     ui->textEdit_2->append("Queried Word not found.");
//    }

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

void wordInput::on_webView_loadProgress(int progress)
{
    qDebug()<<progress;
}
