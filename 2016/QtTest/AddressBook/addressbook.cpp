#include "addressbook.h"
#include "ui_addressbook.h"
#include <QUrl>
#include <QWebView>
QTextStream cout(stdout);

AddressBook::AddressBook(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddressBook)
{
    ui->setupUi(this);
    cout.setCodec("UTF-8");
  /*  QFile my_file("D:/ProjectNote/GermaData/DicTest/DicCompressed_1.txt");
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
        unsigned char *buffer_uncompress=new unsigned char[key_decompressed_length+1];
        unsigned long len_uncompress;
         qDebug()<<"State: "<<uncompress(buffer_uncompress,&len_uncompress,(Bytef*)src.mid(offset,key_compressed_length).data(),key_compressed_length);
         qDebug()<<"After uncompress, the data has length: "<<len_uncompress;
         QString wordListTotal(QString::fromUtf8(reinterpret_cast<const char*>(buffer_uncompress)));
        //cout<<wordListTotal.replace('\n',' ');
         QStringList wordList=wordListTotal.split('\n');
         qDebug()<<"wordListLength: "<<wordList.length();
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
         QByteArray record_uncompressed=QByteArray::fromRawData(reinterpret_cast<const char*>(buffer_uncompress2),record_decompressed_length);
        qDebug()<<"record_uncompresed_length: "<<len_uncompress2<<' '<<record_uncompressed.length();
         offset=0;
         int cnt=0;
         typedef QPair<int,int> pair_type;
         QMap<QString,pair_type> m_map;
         while(offset<record_uncompressed.length() && cnt<=wordList.length()){
             int numOfLength=ToInteger(record_uncompressed.mid(offset,4));
             offset+=4;
             m_map[wordList[cnt]]=pair_type(offset,numOfLength);
             offset+=numOfLength;
             cnt++;
         }
         QString word=QString::fromUtf8("Gerät");
         qDebug()<<m_map.contains(word)<<' '<<m_map[word].second;
         cout<<QString::fromUtf8("Gerät")<<endl<<flush;
         cout<<QString::fromUtf8(record_uncompressed.mid(m_map[word].first,m_map[word].second).data());
     }
    */
    connect(ui->webView,SIGNAL(loadStarted()),this,SLOT(LoadStart()));
    connect(ui->webView,SIGNAL(loadProgress(int)),this,SLOT(LoadProgress(int)));
    ui->webView->load(QUrl("http://www.baidu.com"));  //QUrl("D:\\QtTest\\AddressBook-build-desktop\\example.html"));
    ui->webView->show();
}

AddressBook::~AddressBook()
{
    delete ui;
}
void AddressBook::LoadStart(){
    qDebug()<<"Load Started";
}
void AddressBook::LoadProgress(int state){
    qDebug()<<state;
}

