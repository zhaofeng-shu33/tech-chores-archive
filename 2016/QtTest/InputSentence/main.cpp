#include <QtGui>
#include <QtSql>
#include <QDebug>
#include <QTextCodec>
#include "sentenceStructure.h"
#include <ctime>
int offset(int given_value, int offset_value){
    if(given_value==0)
        return given_value;
    else
        return given_value+offset_value;
}
int main(int argc,char* argv[]){
    srand(time(0));
    QApplication app(argc,argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    cin.setCodec("ISO 8859-1");
    cout.setCodec("ISO 8859-1");
    QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/QtTest/ODBC/germanWord.mdb");
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName(dsn);
    if(!db.open()){
        qDebug()<<"Error: "<<db.lastError();
        return 1;
    }
    QSqlQuery query(db);
    QSqlQueryModel model;
    int current_ID;
        if(!query.exec(QString("select count(ID) from Satz"))){
            qDebug()<<query.lastError();
            return 1;
        }
        else{
            query.next();
            current_ID=query.value(0).toInt()+1;
            }

        QRegExp rx("(\\s+\\w)");//take the space before the first character.
        QFile data("D:/QtTest/InputSentence/SentenceInput.txt");
          data.open(QFile::ReadOnly|QFile::Text);
          QTextStream output(&data);
          QString str=output.readLine(25);
          while(!output.atEnd()){
              if(str=="S"){
                     Tree SimpleTree;
      SimpleTree.add_data("S");
      str=output.readLine(25);
        while(str!="S"){
          if(str.length()==1) {
             SimpleTree.set_punctuation(str[0]);
             str=output.readLine(25);
             break;
           }
      for(int i=SimpleTree.get_num()-1;i>=0;i--){
       int pos=rx.indexIn(str);
        if(SimpleTree.treeNode[i].level==rx.cap(1).length()-2){
         SimpleTree.add_data(SimpleTree.treeNode[i].data,str.remove(0,rx.cap(1).length()-1),rx.cap(1).length()-1);
         break;
        }
      }
      str=output.readLine(25);
      }
        int Subject_ID=current_ID;
        if(!query.exec(QString("insert into Satz values (%1, '%2', %3, %4, %5, 0)").arg(current_ID++).arg("S").arg(-1).arg(SimpleTree.treeNode[0].children[0]+Subject_ID).arg(SimpleTree.treeNode[0].children[1]+Subject_ID)))
        {
            qDebug()<<query.lastError();
            return 1;
        }
        else cout<<"Success! "<<current_ID<<endl;
        //cout<<(current_ID++)<<' '<<"S"<<' '<<-1<<' '<<SimpleTree.treeNode[0].children[0]+Subject_ID<<' '<<SimpleTree.treeNode[0].children[1]+Subject_ID<<' '<<0<<endl;
        for(int i=1;i<SimpleTree.get_num();i++){
            if(!query.exec(QString("insert into Satz values (%1, '%2', %3, %4, %5, %6)").arg(current_ID).arg(SimpleTree.treeNode[i].data).arg(SimpleTree.treeNode[i].parent+Subject_ID).arg(offset(SimpleTree.treeNode[i].children[0],Subject_ID)).arg(offset(SimpleTree.treeNode[i].children[1],Subject_ID)).arg(SimpleTree.treeNode[i].level)))
            {
                qDebug()<<query.lastError();
                return 1;
            }
            else cout<<"Success! "<<current_ID+1<<endl;

          //  cout<<(current_ID)<<' '<<SimpleTree.treeNode[i].data<<' '<<SimpleTree.treeNode[i].parent+Subject_ID<<' '
          //          <<SimpleTree.treeNode[i].children[0]+Subject_ID<<' '<<SimpleTree.treeNode[i].children[1]+Subject_ID<<' '<<SimpleTree.treeNode[i].level<<endl;
            current_ID++;
        }
     // SimpleTree.print_sentence();
      }
      }


    db.close();

    return 0;
}


