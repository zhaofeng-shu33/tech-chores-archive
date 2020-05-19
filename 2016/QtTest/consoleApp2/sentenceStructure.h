#ifndef SENTENCESTRUCTURE_H
#define SENTENCESTRUCTURE_H
#include <QTextStream>
QTextStream cout(stdout);
class BLNode{
public:
        BLNode():lchild(NULL),rchild(NULL){}
        BLNode(const QString& str):lchild(NULL),rchild(NULL),parent(NULL),data(str){}
        BLNode(const QString& str,BLNode*& parent_pointer):lchild(NULL),rchild(NULL),data(str),parent(parent_pointer){}
        QString data;
        BLNode* lchild;
        BLNode* rchild;
        BLNode* parent;
        };
class BLTree{
public:
        ~BLTree(){ free_BLTree(root); //destroy the BLTree
        }
        BLTree(QString str){root=new BLNode(str);}
        BLTree(){root=new BLNode("S");}
protected:
        BLNode* root;
        BLNode* tmp_pointer;
        QString tmp_str;
        void free_BLTree(BLNode*& starting_pointer){
             if(starting_pointer){
                         cout<<"DELETE "<<starting_pointer->data<<endl;
                         if(starting_pointer->lchild)
                                 free_BLTree(starting_pointer->lchild);
                         if(starting_pointer->rchild)
                         free_BLTree(starting_pointer->rchild);
                         delete starting_pointer;
                 }
        }
        void print_inner(BLNode*& starting_pointer){ //先序
              if(starting_pointer){
                          if(starting_pointer->lchild==NULL)
                           cout<<starting_pointer->data<<' ';
                           print_inner(starting_pointer->lchild);
                           print_inner(starting_pointer->rchild);
                   }
        }
        void search_inner(BLNode*& starting_pointer){ //recursion search;
                   if(starting_pointer){
                           if(starting_pointer->data==tmp_str){
                                   tmp_pointer=starting_pointer;
                               return;
                           }
                           search_inner(starting_pointer->lchild);
                       search_inner(starting_pointer->rchild);
                   }
        }

        BLNode*& get_pointer(const QString& given_data){
           tmp_str=given_data;
           search_inner(root);
           return tmp_pointer;
        }
        void change_l_r(BLNode* starting_pointer){
                if(starting_pointer){
                        tmp_pointer=starting_pointer->lchild;
                        starting_pointer->lchild=starting_pointer->rchild;
                        starting_pointer->rchild=tmp_pointer;
                        }
        }
public:
        void print(){
                print_inner(root);
                cout<<endl;
        }
        void append(const QString& parent_data,const QString& given_data){
                tmp_pointer=get_pointer(parent_data);
                if(tmp_pointer->lchild==NULL){
                tmp_pointer->lchild=new BLNode(given_data,tmp_pointer);
                }
                else if(tmp_pointer->rchild==NULL)
                        tmp_pointer->rchild=new BLNode(given_data,tmp_pointer);
                else
                        cout<<"WARNING: ILLEGAL APPEND"<<endl;
        }
        void append(const QString& parent_data,BLNode*& append_BLNode){
                tmp_pointer=get_pointer(parent_data);
                if(tmp_pointer->lchild==NULL){
                tmp_pointer->lchild=append_BLNode;
                }
                else if(tmp_pointer->rchild==NULL)
                        tmp_pointer->rchild=append_BLNode;
                else
                        cout<<"WARNING: ILLEGAL APPEND"<<endl;
        }

        void replace(const QString& replaced_data,const QString& given_data){
                if(get_pointer(replaced_data))
                        get_pointer(replaced_data)->data=given_data;
                else
                        cout<<replaced_data<<" NOT FOUND"<<endl;

        }
        void clear(const QString& cleared_data){

                if(get_pointer(cleared_data)){
                        BLNode* pointer=get_pointer(cleared_data)->parent;
                        QString str=pointer->data;
                        if(pointer->lchild->data==cleared_data){
                           change_l_r(pointer);
                        }
                        pointer=get_pointer(cleared_data);
                        pointer->parent->rchild=NULL;
                        free_BLTree(pointer);

                        pointer=get_pointer(str);
                        if(pointer->parent->lchild->data==str)
                        pointer->parent->lchild=pointer->lchild;
                        else
                                pointer->parent->rchild=pointer->lchild;

                        pointer->lchild->parent=pointer->parent;
                        delete pointer;
                        }
                else
                        cout<<cleared_data<<" NOT FOUND"<<endl;

        }

};
class Phrase: public BLTree{  //phrase level
public:
    Phrase(QString head,QString Specifier="",Phrase* Complement=NULL){
        XP=new BLTree("XP");
    if(Specifier.size()!=0)
        XP->append("XP",Specifier);
    XP->append("XP","X1");
    XP->append("X1",head);
    if(!Complement)
    XP->append("X1",Complement->root);
    }
    ~Phrase(){
    }

private:
    BLTree* XP;
};


#endif // SENTENCESTRUCTURE_H
