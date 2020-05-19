#ifndef SENTENCESTRUCTURE_H
#define SENTENCESTRUCTURE_H
#include <QString>
#include <QTextStream>
QTextStream cout(stdout);
const int Tree_Size=20;

class TreeNode{
   public:
        QString data;
        int parent;
        int level;
        int children[2];
        int children_index;
};

class Tree{
public:
    TreeNode treeNode[Tree_Size];
 private:
    int num;
    int Predicate;
    int starting_word;
    QChar punctuation;
    int total_level;//can represent the complexity of the sentence;
 public:
    Tree(){num=0;}
    void add_data(QString parent_data,QString given_data,int lv){
       treeNode[num].children[0]=0;
       treeNode[num].children[1]=0;
       treeNode[num].data=given_data;
       treeNode[num].level=lv;
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
    void add_data(QString given_data,int parent_ID,int starting_ID,int lv){
        if(parent_ID!=-1)
        add_data(treeNode[parent_ID-starting_ID].data,given_data,lv);
        else
        add_data(given_data);
    }


    int get_num(){
            return num;
    }
    void set_punctuation(QChar p){
         punctuation=p;
       for(int i=0;i<num;i++)
           if(treeNode[i].children_index==0){
              starting_word=i;
              return;
          }

     }
        int get_total_level(){
          return total_level;
        }
        void print_sentence(int pos=0,QTextStream& out=cout){
                if(pos==num-1){
                   if(punctuation!=' ')
                   out<<treeNode[num-1].data<<punctuation<<endl<<flush;
                   else
                       out<<treeNode[num-1].data<<endl<<flush;
               return;
                }

                if(treeNode[pos].children_index==0){
                        out<<treeNode[pos].data<<' ';
                        return;
                }
                for(int i=0;i<treeNode[pos].children_index;i++)
                           print_sentence(treeNode[pos].children[i],out);
        }
        void print_sentence(QString form,int pos=0,QTextStream& out=cout){
            if(form=="general_question"){
                if(pos==0){
                   QString copy=treeNode[Predicate].data;
                  out<<copy.replace(0,1,copy[0].toUpper())<<' '<<flush;
                }
                if(pos==num-1){
                   out<<treeNode[num-1].data<<'?'<<endl<<flush;
                   return;
                }

                if((treeNode[pos].children_index==0) && (pos != Predicate)){
                        if(pos==starting_word && treeNode[treeNode[pos].parent].children_index==2)
                           out<<treeNode[pos].data.toLower()<<' '<<flush;
                        else out<<treeNode[pos].data<<' '<<flush;
                        return;
                }
                for(int i=0;i<treeNode[pos].children_index;i++)
                           print_sentence(form,treeNode[pos].children[i],out);
          }
           else print_sentence(0,out);
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

};
Tree replace(Tree given_tree,QString replaced_data,QString given_data){
    Tree newTree=given_tree;
    int replaced_string_index=newTree.get_searched_data_index(replaced_data);
    if(replaced_string_index!=-1){
      newTree.treeNode[replaced_string_index].data=given_data;
      return newTree;
    }
  cout<<replaced_data.append(" does not exist in the searched sentence. An identical tree is returned")<<endl<<flush;
  return newTree;
}

#endif // SENTENCESTRUCTURE_H
