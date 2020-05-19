#include <QtCore/QCoreApplication>
#include <QTextStream>
#include <QString>
#include <QTextCodec>
#include <QVector>
#include <QStringList>
QTextStream cout(stdout);
enum Status{none,head,Subject,argument,adjunct};
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
    TreeNode(){}
    TreeNode(QString data1,TreeNode* parent1=NULL,Status status1=none):data(data1),
    parent(parent1),status(status1){}
    TreeNode(const TreeNode& treeNode){
        data=treeNode.data;
        parent=treeNode.parent;
        status=treeNode.status;
    }

    ~TreeNode(){}
        QString data;
        TreeNode* parent;
        Status status;
        QVector<TreeNode*> children;
        int level;
        int position;
};
class Tree{
  public:
     QVector<TreeNode> treeNode;
     Tree(){}
     Tree(QString str){
        punctuation=str[str.size()-1];
        QStringList stringList=str.split(" ");
        for(int i=0;i<stringList.size();i++)
            cout<<stringList[i]<<' ';
     int index=stringList.indexOf(QRegExp("lern.*"));
        treeNode.push_back(TreeNode("S"));
        treeNode.push_back(TreeNode("NP"));
        treeNode[1].parent=&treeNode[0];
        treeNode.push_back(TreeNode("VP"));
        treeNode[2].parent=&treeNode[0];
        for(int i=0;i<index;i++){
          treeNode.push_back(TreeNode(stringList[i]));
          treeNode[i+3].parent=&treeNode[1];
        }
        treeNode.push_back(TreeNode(stringList[index]));
        treeNode[5].parent=&treeNode[2];

        if(stringList.size()-index==2){
        treeNode.push_back(TreeNode(stringList[index+1]));
        treeNode[6].parent=&treeNode[2];
        }
     else{
        treeNode.push_back(TreeNode("NP",&treeNode[2]));
        int tmp=treeNode.size()-1;
        for(int i=index+1;i<stringList.size();i++)
          treeNode.push_back(TreeNode(stringList[i],&treeNode[tmp]));
     }
     cout<<treeNode[6].data<<flush<<endl;
     treeNode[0].position=0;
     for(int i=1;i<treeNode.size();i++){
         treeNode[i].parent->position=i;
     }
     for(int i=1;i<treeNode.size();i++){
         cout<<treeNode[i].parent->data<<flush<<endl;
         cout<<treeNode[i].parent->position<<flush<<endl;
     }

     for(int i=0;i<treeNode.size();i++)
        if(treeNode[i].parent!=NULL)
         treeNode[treeNode[i].parent->position].children.push_back(&treeNode[i]);

     for(int i=0;i<treeNode.size();i++)
         cout<<treeNode[i].children.size()<<' ';

     //  print_sentence();
    }
    void set_position(){
        for(int i=0;i<treeNode.size();i++)
            treeNode[i].position=i;
    }

    void print_sentence(int pos=0){
        if(pos==treeNode.size()-1){
            cout<<treeNode[treeNode.size()-1].data<<punctuation<<endl;
        return;
         }

        if(treeNode[pos].children.size()==0){
          cout<<treeNode[pos].data<<' ';
          return;
       }
        for(int i=0;i<treeNode[pos].children.size();i++)
           print_sentence(treeNode[pos].children[i]->position);
     }
private:
        QChar punctuation;
        int total_level;//can represent the complexity of the sentence;
 /* public:
        void set_num(){
          int nomber=treeNode.size();
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

        int get_total_level(){
          return total_level;
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
        }*/
};


int main()
{
    cout.setCodec("ISO 8859-1");
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    Tree myTree("Der Student lernt Deutsch.");
    QList<QString> sentence;
    sentence.append("Es");
    sentence.append("ist");
    sentence.append("noch");
    sentence.append(QString("früh"));
    sentence.removeOne("noch");
//    for(int i=0;i<sentence.size();i++)
//        cout<<sentence[i]<<' ';
    return 0;
}
