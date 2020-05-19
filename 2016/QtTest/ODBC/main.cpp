#include <QtSql>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QRegExp>
QSqlQueryModel model;
QTextStream cout(stdout);
int main(int argc,char* argv[]){
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextStream cin(stdin);
    QTextStream cout(stdout);
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/QtTest/NounDicWithDb-build-desktop/NounLib.mdb");
    db.setDatabaseName(dsn);
    if(!db.open()){
        qDebug()<<"Error: "<<db.lastError();
        return 1;
    }
    QSqlQuery query(db);

   // cin.setCodec("ISO 8859-1");
   // cout.setCodec("ISO 8859-1");
    QFile file1("NounEntryFormat.txt");
    if(file1.exists()){
        for(int i=100;i<=446;i++){

        QString filename=QString("NounEntryFormat%1.xml").arg(i);
        QFile file2(filename);
        QTextStream out2(&file2);
        out2.setCodec("UTF-8");
        file2.open(QIODevice::ReadWrite|QIODevice::Text);
        model.setQuery(QString("select * from NounRevised where ID = %1").arg(i));
        if(model.lastError().isValid()){cout<<"Update Error!";break;}

        QString content=out2.readAll();
        QString data=model.data(model.index(0,6)).toString();
        content.replace(QRegExp("<Chinesisch>.*</Chinesisch>"),QString("<Chinesisch>%1</Chinesisch>").arg(data));
        file2.resize(0);
        out2.seek(0);
        out2<<content;
        file2.close();
     }}
    /* cout<<(QString("Apfel")<QString("Baum"))<<endl;
    QFile myFile("D:/QtTest/MDictPC/mydic.txt");

    myFile.open(QFile::ReadOnly|QFile::Text);
    QTextStream out(&myFile);
    int index=0;

    for(int i=0;i<446;i++){
       model.setQuery(QString("select * from DicResource where Word ='%1'").arg(wordList[i]));
       if(model.rowCount()==0){cout<<wordList[i];continue;}
        QString fileName=model.data(model.index(0,2)).toString();
        if(!query.exec(QString("update WordList set Audio =1 where wordform ='%1'").arg(wordList[i])))
            qDebug()<<query.lastError();
        QString filepath=QString("D:/QtTest/GermanP/De-De-Langenscheidt-Vokabeln/%1").arg(fileName);
            QFile file1(filepath);
       file1.copy(QString("%1.spx").arg(wordList[i]));

    }*/
    //cout<<line.split(QRegExp("\\t\\t"))[0]<<endl<<endl;
    cout<<"Closed";
    //myFile.close();
    db.close();

    return 0;
}

