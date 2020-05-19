#include <QTextStream>
#include <QString.h> 

QTextStream cout(stdout);
int q=104729;
int Fra(int m,int d=128){
    int fr=d;
    for(int i=1;i<m;i++)
         fr=(fr*d)%q;
    return fr;
}
int Horner_Rule(QString str,int len,int d=128){
    if(len==1)return str[0].toAscii();
    int result=(str[0].toAscii()*d+str[1].toAscii());
    for(int i=2;i<len;i++)
        result=(result*d+str[i].toAscii())%q;
    return result;
}

int main()
{

    QString P("she");
    QString T("She was from the Project Physics Department, fresh female student."
              "Tonight I happened to sit opposite her. I found she was writing ( I thought at that moment) diary. So I could not resist going to look at it while she was away."
              "About her plan in this summer, she was going to assist teaching in some place. She wants to practice her English and learn to cooperate with others. ");
    int d=128;
    int m=P.length();
    int p=Horner_Rule(P,m);
    int t=Horner_Rule(T.mid(0,m),m);
    int digit1=Fra(m-1);
    for(int i=0;i<=T.length()-m;i++){
        if((p-t)%q==0)
           cout<<"Match Pos at "<<i<<' '<<T.mid(i,30)<<"\n"<<flush;
        t=(d*(t-T[i].toAscii()*digit1)+T[i+m].toAscii())%q;
    }
    
    return 0;
}
