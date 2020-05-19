#include <QtGui/QApplication>
#include <QLabel>
#include <QDebug>
#include <QTextCodec>
int N_gram(QString x,QString y,int n){
    int num_x=x.length()-n+1;
    int num_y=y.length()-n+1;
    int num_s=0;
    for(int i=0;i<num_x;i++){
        QString sub_str=x.mid(i,n);
        if(y.contains(sub_str))
            num_s++;
    }
    return num_x+num_y-2*num_s;
}
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
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString str(QString::fromUtf8("öffnen"));
    QChar ch(QChar::fromLatin1('\xf6'));
    qDebug()<<EditDistance("Stadt","Staat");
    QLabel* label=new QLabel(str);
    label->show();

    return a.exec();
}
