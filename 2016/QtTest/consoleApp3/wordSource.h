#ifndef WORDSOURCE_H
#define WORDSOURCE_H
#include <QString>
#include <QList>
#include <QVector>
class Word{
      private:
      QString morphology;
      QString part_of_speech;
      public:
      Word(){}
      Word(QString s):morphology(s){}
      Word(QString s,QString ps):morphology(s),part_of_speech(ps){}
      ~Word(){}
      QString get_part_of_speech(){return part_of_speech;}
      QString get_morphology(){return morphology;}
};
class Noun{
     private:
     QString gender;
     Word* Singular;
     Word* Plural;
     QString Chinese_counterpart;
     public:
     Noun(){}
     Noun(QString gen,QString s,QString plu):gender(gen){
         Singular=new Word(s,"Singular");
         Plural=new Word(plu,"Plural");
     }
     Noun(QString gen,Word* s,Word* plu):gender(gen){
         Singular=s;
         Plural=plu;
     }
     QString get_gender(){return gender;}
     QString get_Singular(){return Singular->get_morphology();}
     QString get_Plural(){return Plural->get_morphology();}
 };
QString get_stem_of_verb(QString verb){
    if(verb.lastIndexOf("en")==verb.size()-2)//then it is the infinitive form of the verb
       return verb.left(verb.size()-2);
    if(verb.lastIndexOf("e")==verb.size()-1)//then it is the first person singular form of the verb
        return verb.left(verb.size()-1);
    if(verb.lastIndexOf("st")==verb.size()-2){//then it is the second person singular form of the verb
       if(verb.lastIndexOf("est")!=verb.size()-3)
        return verb.left(verb.size()-2);
       else
        return verb.left(verb.size()-3);
    }
    if(verb.lastIndexOf("t")==verb.size()-1){//then it is the third person singular form of the verb
        if(verb.lastIndexOf("et")!=verb.size()-2)//or the second person plural form of the verb
         return verb.left(verb.size()-1);
        else
         return verb.left(verb.size()-2);
    }
    return "";
}
QString get_Singular_2_Person(QString verb){
    QString stem=get_stem_of_verb(verb);
    if ((stem[stem.length()-1]==QChar('t'))||(stem[stem.length()-1]==QChar('d'))||((stem[stem.length()-3]==QChar('f'))&&(stem[stem.length()-2]==QChar('f'))&&(stem[stem.length()-1]==QChar('n')))
       ||((stem[stem.length()-3]==QChar('c'))&&(stem[stem.length()-2]==QChar('h'))&&(stem[stem.length()-1]==QChar('n')))
       ||((stem[stem.length()-2]==QChar('g'))&&(stem[stem.length()-1]==QChar('n'))))
        return stem+"est";
    if ((stem[stem.length()-1]==QChar('s'))||(stem[stem.length()-1]==QChar('-'))||((stem[stem.length()-2]==QChar('s'))&&(stem[stem.length()-1]==QChar('s')))
       ||(stem[stem.length()-1]==QChar('z'))||((stem[stem.length()-2]==QChar('t'))&&(stem[stem.length()-1]==QChar('z')))) return stem+'t';
        return stem+"t";
    return stem+"st";
}
QString get_Plural_2_Person(QString verb){
    QString stem=get_stem_of_verb(verb);
    if ((stem[stem.length()-1]==QChar('t'))||(stem[stem.length()-1]==QChar('d'))||((stem[stem.length()-3]==QChar('f'))&&(stem[stem.length()-2]==QChar('f'))&&(stem[stem.length()-1]==QChar('n')))
       ||((stem[stem.length()-3]==QChar('c'))&&(stem[stem.length()-2]==QChar('h'))&&(stem[stem.length()-1]==QChar('n')))
       ||((stem[stem.length()-2]==QChar('g'))&&(stem[stem.length()-1]==QChar('n'))))
        return stem+"et";
   return stem+"t";
}

class Verb{
    private:
    Word* Infinitiv;
    Word* Singular_3_Person;
    QString Wortstamm;
    QString Singular_1_Person;
    QString Singular_2_Person,Plural_2_Person;
    public:
    Verb(){}
    Verb(QString s,QString t)
    {   Infinitiv=new Word(s);
        Wortstamm=get_stem_of_verb(s);
        Singular_3_Person=new Word(t);
    }
    Verb(Word* s,Word* t)
    {   Infinitiv=s;
        Wortstamm=get_stem_of_verb(s->get_morphology());
        Singular_3_Person=t;
    }
    QString get_Infinitiv(){return Infinitiv->get_morphology();}
    QString get_Wortstamm(){return Wortstamm;}
    QString get_Singular_3_Person(){return Singular_3_Person->get_morphology();}
};
class Adjective{
private:
    Word* Positiv;
public:
    Adjective(){}
    Adjective(QString s){Positiv=new Word(s);}
    Adjective(Word* s){Positiv=s;}
    QString get_Positiv(){return Positiv->get_morphology();}
};
QString get_gender_from_NounList(QList<Noun> NounList,QString Substantiv){
    for(int i=0;i<NounList.size();i++){
        if(NounList[i].get_Singular()==Substantiv||NounList[i].get_Plural()==Substantiv)
            return NounList[i].get_gender();
    }
    return "";
}


#endif // WORDSOURCE_H
