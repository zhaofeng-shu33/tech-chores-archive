#ifndef WORDSOURCE_H
#define WORDSOURCE_H
#include <QString>
#include <QVector>
using namespace std;
class Word{
      private:
      QString spell;
      QString meaning;
      QVector<QString> example_sentence;
      public:
      Word(){}
      Word(QString s, QString p=""){spell=s; meaning=p;}
      ~Word(){}
      QString get_spell(){return spell;}
      QString get_meaning(){return meaning;}
      void set_example_sentence(QString sentence){
          example_sentence.push_back(sentence);
      }
      bool whether_have_example_sentence(){
          if(example_sentence.size()==0)
              return false;
          else return true;
      }

      QString get_example_sentence_randomly(){
         return example_sentence[rand()%example_sentence.size()];
      }
      QString get_example_sentence(int seq=0){
         if(seq>=1&&seq<=example_sentence.size())
         return example_sentence[seq-1];
         else
         return " ";
      }
};
class Noun: public Word{
     private:
     QString gender;
     QString plural;
     public:
     Noun(){}
     Noun(QString s,QString gen,QString plu,QString p=""):Word(s,p),gender(gen),plural(plu){}
     QString get_gender(){return gender;}
     QString get_plural(){return plural;}
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

class Verb: public Word{
    private:
    QString stem;
    QString first_person_singular_present_form,third_person_singular_present_form;
    QString second_person_singular_present_form,second_person_plural_present_form;
    public:
    Verb(){}
    Verb(QString s,QString third,QString p=""):Word(s,p),third_person_singular_present_form(third)
    {   stem=get_stem_of_verb(s);
    }
    QString get_stem(){return stem;}
    QString get_third_person_singular_present_form(){return third_person_singular_present_form;}
};

#endif // WORDSOURCE_H
