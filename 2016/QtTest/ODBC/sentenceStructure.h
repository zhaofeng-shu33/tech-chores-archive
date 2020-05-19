#ifndef SENTENCESTRUCTURE_H
#define SENTENCESTRUCTURE_H
#include <QString>
#include <QStringList>
#include <QTextCodec>
#include <QTextStream>
QTextStream cout(stdout);
const int Tree_Size=30;
bool isPron(QString str){
    if(str=="Ich"||str=="Du"||str=="Er"||str=="Ihr"||str=="Wir"||str=="Man")
       return true;
    return false;
}

class TreeNode{
   public:
        QString data;
        int parent;
        int level;
        int children[3];
        int children_index;
};

class Tree{
public:
    TreeNode treeNode[Tree_Size];
    int Predicate;
    int starting_word;
 private:
    int num;
    QChar punctuation;
    int total_level;//can represent the complexity of the sentence;
    void print_interrogative_question_sentence_inner(int interrogative_index,int pos=0,QTextStream& out=cout){
        if(pos==0){
          QString copy=treeNode[interrogative_index].data;
          out<<copy.replace(0,1,copy[0].toUpper())<<' '<<treeNode[Predicate].data<<flush;
        }
        if((treeNode[pos].children_index==0) && (pos != interrogative_index)&&pos !=Predicate){
                if( (pos==starting_word && treeNode[treeNode[pos].parent].children_index==2) || isPron(treeNode[pos].data))
                   out<<' '<<treeNode[pos].data.toLower()<<flush;
                else out<<' '<<treeNode[pos].data<<flush;
                return;
        }
        for(int i=0;i<treeNode[pos].children_index;i++)
                   print_interrogative_question_sentence_inner(interrogative_index,treeNode[pos].children[i],out);
       if(pos==0){
           out<<'?'<<endl<<flush;
           return;
       }
    }

 public:
    Tree(){num=0;}
    void add_data(QString parent_data,QString given_data,int lv=-1){
       treeNode[num].children[0]=0;
       treeNode[num].children[1]=0;
       treeNode[num].children[2]=0;
       treeNode[num].data=given_data;
       treeNode[num].children_index=0;
       for(int i=0;i<num;i++)
           if(treeNode[i].data==parent_data){
               treeNode[num].parent=i;
               if(parent_data=="VP"&&treeNode[i].children_index==0){
                  Predicate=num;
                }
               treeNode[i].children[treeNode[i].children_index++]=num;
               break;
           }
       if(lv!=-1)
       treeNode[num].level=lv;
       else treeNode[num].level=treeNode[treeNode[num].parent].level+1;

       num++;
    }
    void add_data(QString given_data){
        punctuation=' ';
        treeNode[0].parent=-1;
        treeNode[0].children_index=0;
        treeNode[0].data=given_data;
        treeNode[0].level=0;
        num++;
    }
    void add_data(QString given_data,int parent_ID,int starting_ID=0,int lv=-1){
        if(parent_ID!=-1){
            treeNode[num].children[0]=0;
            treeNode[num].children[1]=0;
            treeNode[num].children[2]=0;
            treeNode[num].data=given_data;
            treeNode[num].children_index=0;
            cout<<'!'<<treeNode[parent_ID-starting_ID].data<<endl<<flush;
            cout<<"Test:"<<treeNode[parent_ID-starting_ID].children_index<<endl<<flush;
            treeNode[parent_ID-starting_ID].children[treeNode[parent_ID-starting_ID].children_index++]=num;
            //treeNode[0].children[0]=num;

            //treeNode[parent_ID-starting_ID].children_index++;
            /*if(lv!=-1)
            treeNode[num].level=lv;
            else treeNode[num].level=treeNode[treeNode[num].parent].level+1;
            */num++;
        }
        else
        add_data(given_data);
    }
        void print_sentence(int pos=0,QTextStream& out=cout){
            QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
            out.setCodec("ISO 8859-1");
                if(treeNode[pos].children_index==0){
                    for(int i=0;i<num;i++)
                        if(treeNode[i].children_index==0){
                           starting_word=i;
                           break;
                        }
                    if(pos==starting_word){
                        QString copy=treeNode[starting_word].data;
                        out<<copy.replace(0,1,copy[0].toUpper())<<flush;
                        return;
                     }
                        out<<' '<<treeNode[pos].data;
                        return;
                }
                for(int i=0;i<treeNode[pos].children_index;i++)
                           print_sentence(treeNode[pos].children[i],out);
             if(pos==0){
               out<<'.'<<endl<<flush;
               return;
             }
        }
        void print_general_question_sentence(int pos=0,QTextStream& out=cout,bool append=0,bool imperativ=0){
            QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
            out.setCodec("ISO 8859-1");
               if(pos==0){
                    QString copy;
                    copy=treeNode[Predicate].data;
                    if(!append) copy.replace(0,1,copy[0].toUpper());
                    out<<copy<<flush;
                }
                if((treeNode[pos].children_index==0) && (pos != Predicate)){
                        if( (pos==starting_word && treeNode[treeNode[pos].parent].children_index==2) || isPron(treeNode[pos].data))
                           out<<' '<<treeNode[pos].data.toLower()<<flush;
                        else out<<' '<<treeNode[pos].data<<flush;
                        return;
                }
                for(int i=0;i<treeNode[pos].children_index;i++)
                           print_general_question_sentence(treeNode[pos].children[i],out);
         if(pos==0){
                  if(!imperativ) out<<'?'<<endl<<flush;
                  else out<<'!'<<endl<<flush;
                  return;
         }
        }
        void print_interrogative_question_sentence(QString interrogative,QTextStream& out=cout){
                   int index=get_searched_data_index(interrogative);
                   if(index<0){
                       out<<interrogative.replace(0,1,interrogative[0].toUpper())<<' ';
                       print_general_question_sentence(0,out,1);
                       return;
                   }
                   print_interrogative_question_sentence_inner(index,0,out);
        }
        void print_imperative_question_sentence(QTextStream& out=cout){
            print_general_question_sentence(0,out,0,1);
        }
        int get_num(){
                return num;
        }

        int get_searched_data_index(QString searched_string){
            for(int i=0;i<num;i++)
                    if(treeNode[i].data==searched_string)
                            return i;
            return -1;
        }

        QString get_parent_data(QString searched_string){
            int searched_string_index=get_searched_data_index(searched_string);
            if(searched_string_index!=-1)
            return treeNode[treeNode[searched_string_index].parent].data;
            else
            return searched_string.append(" does not exist in the searched sentence.");
        }
        void replace(QString replaced_data,QString given_data){
            int replaced_string_index=get_searched_data_index(replaced_data);
            if(replaced_string_index!=-1){
              treeNode[replaced_string_index].data=given_data;
              return;
            }
          cout<<replaced_data.append(" does not exist in the searched sentence.")<<endl<<flush;
        }
        int get_address_from_string(QString given_address){
            QStringList strList=given_address.split(',');
            int address=0;
            for(int i=1;i<strList.size();i++){
                for(int j=0;j<treeNode[address].children_index;j++)
                    if(treeNode[treeNode[address].children[j]].data==strList[i]){
                        address=treeNode[address].children[j];
                        return address;
                    }
            }
            return address;
        }

        void replace_by_address(QString given_address,int relative_position,QString given_data){
            int address=get_address_from_string(given_address);
            treeNode[treeNode[address].children[relative_position]].data=given_data;
            treeNode[treeNode[address].children[relative_position]].children_index=0;
        }
        void add_data_by_address(QString given_address,QString given_data){
            int address=get_address_from_string(given_address);
            cout<<'*'<<address<<'*'<<endl<<flush;
            add_data(given_data,address);
        }
};
Tree replace(Tree given_tree,QString replaced_data,QString given_data){
    Tree newTree=given_tree;
    int replaced_string_index=newTree.get_searched_data_index(replaced_data);
    if(replaced_string_index!=-1){
      newTree.treeNode[replaced_string_index].data=given_data;
      newTree.treeNode[replaced_string_index].children_index=0;
      return newTree;
    }
  cout<<replaced_data.append(" does not exist in the searched sentence. An identical tree is returned")<<endl<<flush;
  return newTree;
}
Tree add_ADJ_after_verb(Tree given_tree,QString given_ADJ){
    Tree newTree;
    for(int i=0;i<=given_tree.Predicate;i++)
        newTree.add_data(given_tree.treeNode[i].data,given_tree.treeNode[i].parent);
         int parent_ID=newTree.treeNode[given_tree.Predicate].parent;
    newTree.add_data(given_ADJ,parent_ID,0);
    for(int i=given_tree.Predicate+1;i<given_tree.get_num();i++)
        newTree.add_data(given_tree.treeNode[given_tree.treeNode[i].parent].data,given_tree.treeNode[i].data);
    return newTree;
}
Tree conjunction_of_two_sentences(Tree sentence_1,Tree sentence_2,QString conjunction="und"){
    Tree newTree;
    newTree.add_data("S");
    newTree.add_data("S","S1");
    for(int i=0;i<sentence_1.get_num();i++){
       QString rename=sentence_1.treeNode[i].data;
       if(rename=="S"||rename=="NP"||rename=="VP"||rename=="PP")
          sentence_1.treeNode[i].data.append('1');
    }

    for(int i=1;i<sentence_1.get_num();i++)
        newTree.add_data(sentence_1.treeNode[sentence_1.treeNode[i].parent].data,sentence_1.treeNode[i].data);


    newTree.add_data("S","CONJ");
    newTree.add_data("CONJ",conjunction);
    newTree.add_data("S","S2");

    for(int i=0;i<sentence_2.get_num();i++){
       QString rename=sentence_2.treeNode[i].data;
       if(rename=="S"||rename=="NP"||rename=="VP"||rename=="PP")
          sentence_2.treeNode[i].data.append('2');
    }
    sentence_2.treeNode[sentence_2.starting_word].data=sentence_2.treeNode[sentence_2.starting_word].data.toLower();
    for(int i=1;i<sentence_2.get_num();i++)
        newTree.add_data(sentence_2.treeNode[sentence_2.treeNode[i].parent].data,sentence_2.treeNode[i].data);
   // for(int i=0;i<newTree.get_num();i++)
   //     cout<<"DEBUGi: "<<newTree.treeNode[i].data<<' '<<newTree.treeNode[i].parent<<endl<<flush;
    return newTree;
}

#endif // SENTENCESTRUCTURE_H
