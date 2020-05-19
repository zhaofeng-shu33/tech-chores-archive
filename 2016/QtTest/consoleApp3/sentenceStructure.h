#ifndef SENTENCESTRUCTURE_H
#define SENTENCESTRUCTURE_H
#include <QString>
#include <QTextStream>
#include "wordSource.h"
QTextStream cout(stdout);
const int Tree_Size=20;
using namespace std;
enum Status{head,Subject,argument,adjunct,none};

QString status_conversion(Status status){
        if(status==Subject)
           return "Subject";
        else if(status==head)
           return "head";
        else if(status==argument)
           return "argument";
        else if(status==adjunct)
       return "adjunct";
        return "";
}
class TreeNode{
   public:
        QString data;
        int parent;
        Status status;
        int level;
        int children[2];
        int children_index;
};

class Tree{
  public:
        TreeNode treeNode[Tree_Size];
private:
        int num;
        char punctuation;
        int total_level;//can represent the complexity of the sentence;
  public:
        friend void Change_Subject_to_Pronoun(Tree &tree,QVector<Noun>& nounlist);

        void print_sentence(Tree tree){
          return;
    }
        void set_num(int nomber){
          for(int i=0;i<nomber;i++)
                  treeNode[i].children_index=0;
          num=nomber;
        }
        int get_num(){
            return num;
        }

        void set_punctuation(QString str){
          if(str=="full stop")
                  punctuation='.';
          if(str=="question mark")
                  punctuation='?';
        }
        void set_level(){
          int max1=0;
                for(int i=0;i<num;i++){
                        int try1=0;
                        int j=i;
                        while(treeNode[j].parent!=-1){
                                  try1++;
                                  int r=treeNode[j].parent;
                                  if(treeNode[r].children_index<2)
                                  treeNode[r].children[treeNode[r].children_index++]=j;
                                  j=r;
                        }
                        treeNode[i].level=try1+1;
                if(try1>max1)
                  max1=try1;
         }
         total_level=max1+1;
        }
        int get_total_level(){
          return total_level;
        }
        void print_sentence(int pos=0){
                if(pos==num-1){
                   cout<<treeNode[num-1].data<<punctuation<<endl;
               return;
                }

                if(treeNode[pos].children_index==0){
                        cout<<treeNode[pos].data<<' ';
                        return;
                }
                for(int i=0;i<treeNode[pos].children_index;i++)
                           print_sentence(treeNode[pos].children[i]);
        }
        QString get_parent(QString search_QString){
                for(int i=0;i<num;i++){
                        if(treeNode[i].data==search_QString)
                                return treeNode[treeNode[i].parent].data;
                }
                return search_QString.append(" does not exist in the searched sentence.");
        }

        QString get_status(QString search_QString){
                for(int i=0;i<num;i++){
                        if(treeNode[i].data==search_QString)
                                return status_conversion(treeNode[i].status);
                }
                return search_QString.append(" does not exist in the searched sentence.");
        }
};

void Change_Subject_to_Pronoun(Tree &tree,QVector<Noun>& nounlist){
    int pos_of_Subject;
    for(int i=0;i<tree.get_num();i++){
        if(tree.treeNode[i].status==Subject){
            pos_of_Subject=i;
            break;
        }
    }
    QString str=tree.treeNode[pos_of_Subject].data;
    for(int i=0;i<nounlist.size();i++){
        if(str==nounlist[i].get_spell()||str==nounlist[i].get_plural()){
           pos_of_Subject=i;
           break;
        }
    }
    Tree newTree;
    newTree.treeNode[0].data="S";

    if(nounlist[pos_of_Subject].get_gender()=="der")
    newTree.treeNode[1].data="Er";
    else if(nounlist[pos_of_Subject].get_gender()=="die")//plural or femine
    newTree.treeNode[1].data="Sie";
    else
        newTree.treeNode[1].data="Es";

    newTree.treeNode[1].status=Subject;
    newTree.treeNode[2].data="VP";
    int first_child_index=tree.treeNode[2].children[0];
    for(int i=0;i<tree.get_num()-first_child_index;i++){
    newTree.treeNode[3+i].data=tree.treeNode[first_child_index+i].data;
    if(i>=2)
    newTree.treeNode[3+i].parent=4;
    }
    newTree.treeNode[3].status=head;
    newTree.treeNode[4].status=argument;
    newTree.treeNode[0].parent=-1;
    newTree.treeNode[1].parent=0;
    newTree.treeNode[2].parent=0;
    newTree.treeNode[3].parent=2;
    newTree.treeNode[4].parent=2;
    newTree.set_num(tree.get_num()-2);
    newTree.set_level();
    newTree.set_punctuation("full stop");
    newTree.print_sentence();
}

#endif // SENTENCESTRUCTURE_H
