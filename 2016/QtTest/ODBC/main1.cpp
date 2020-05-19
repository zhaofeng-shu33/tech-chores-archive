#include <QtSql>
#include <QDebug>
#include <QTextStream>
#include <QStringList>
int Min3(int a,int b,int c){
    int temp=a;
    if(b<=c&&b<=a)temp=b;
    else if(c<=a&&c<=b)temp=c;

    return temp;
}

int EditDistance(QString s,QString t){
   // For all i and j, d[i,j] will hold the Levenshtein distance between
   // the first i characters of s and the first j characters of t.
   // Note that d has (m+1)  x(n+1) values.
   int m=s.length(),n=t.length();
   int** d=new int*[m+1];
   for(int i=0;i<m+1;i++)
       d[i]=new int[n+1];

   for(int i=0;i<m+1;i++)
     d[i][0]=i; // the distance of any first string to an empty second string
   for(int j=0;j<n+1;j++)
     d[0][j]=j; // the distance of any second string to an empty first string
   for(int j=1;j<n+1;j++)
       for(int i=1;i<m+1;i++)
          if(s[i-1] == t[j-1])
             d[i][j]=d[i-1][j-1];       // no operation required
          else
             d[i][j]=Min3(d[i-1][j] + 1,  // a deletion
                      d[i][j-1] + 1,  // an insertion
                      d[i-1][j-1] + 1 // a substitution
                    );

    int answer=d[m][n];


    for(int i=0;i<m+1;i++)
        delete [] d[i];
    delete [] d;
    return answer;
}
QSqlQueryModel model;
QTextStream cout(stdout);
int main(int argc,char* argv[]){
    QTextStream cout(stdout);
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    QString dsn=QString("DRIVER={Microsoft Access Driver (*.mdb)};FIL={MS Access};DBQ=D:/QtTest/NounDicWithDb/NounLib.mdb");
    db.setDatabaseName(dsn);
    if(!db.open()){
        qDebug()<<"Error: "<<db.lastError();
        return 1;
    }
    cout.setCodec("UTF-8");
    QSqlQuery query(db);
    QStringList strLst;
    query.exec("select wordform from Noun");
    while(query.next()){
        strLst.append(query.value(0).toString());
    }
    for(int i=0;i<strLst.size();i++){
        if(EditDistance("Fahhe",strLst[i])<=1)
            cout<<strLst[i]<<endl;
    }
    db.close();

    return 0;
}


