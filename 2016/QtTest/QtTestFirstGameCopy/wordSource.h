#ifndef WORDSOURCE_H
#define WORDSOURCE_H
#include <QString>
#include <QVector>
#include "iostream"
#define NUM 5
using namespace std;
class Word{
      private:
      QString spell;
      QString meaning;
      QVector<QString> example_sentence;
      int weight;
      int order;
      public:
      Word(){}
      Word(QString s, QString p, int x){ order=x; spell=s; meaning=p; weight=order;}
      ~Word(){}
      int get_weight(){return weight;}
      void set_weight(int n){weight=n;}
      QString get_spell(){return spell;}
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
      };
class Noun: public Word{
     private:
     QString gender;
     QString plural;
     public:
     Noun(){}
     Noun(QString s, QString p,int x,QString gen):Word(s,p,x),gender(gen){}
       QString get_gender(){return gender;}
       QString get_plural(){return plural;}
};
#endif // WORDSOURCE_H
