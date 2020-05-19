#include <QtGui/QApplication>

#include "addressbook.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AddressBook myBook;
    myBook.show();
 //        QString input;
//        cin>>input;
//        while(input!="End"){
//          if(!m_map.contains(input))cout<<"The wordList does not contain the one you searched"<<endl;
//          else qDebug()<<m_map[input].first<<' '<<m_map[input].second;
//          cin>>input;
//        }
        //  foreach(QString str,wordList)
       //     cout<<str<<endl<<flush;
        //qDebug()<<"After uncompress, the data is "<<reinterpret_cast<const char*>(buffer_uncompress);


    //compress(buffer_compress,&len_compress,(Bytef*)src.data(),src.length());
//   qDebug()<<"Before compress, the data is "<<src.data();
 //   qDebug()<<"The length of uncompressed data is "<<src.length();
    //buffer_compress[len_compress]='\0';
   // qDebug()<<"After compress. the data is(in hex form) "<<*buffer_compress;
   // qDebug()<<"The length of compressed data is "<<len_compress;
   // buffer_uncompress[len_uncompress]='\0';
 //   qDebug()<<"The length of the uncompressed data is "<<len_uncompress;
    
    return a.exec();
}
