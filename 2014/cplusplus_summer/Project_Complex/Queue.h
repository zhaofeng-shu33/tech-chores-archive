
const int MaxQSize=5;
template <class T>
class Queue{// firstly realize the cycle queue
  private:
      int front,rear,count;
      T queue_list[MaxQSize];
  public:
      Queue():front(0),rear(0),count(0){}
      void Enter_Queue(T item){
        queue_list[rear]=item;
        rear=(rear+1)%MaxQSize;
        count++;
      }
      void Quit_Queue(){
        front=(front+1)%MaxQSize;
        count--;
      }
      void Output_Queue(){
        for(int i=0;i<count;i++)
            cout<<queue_list[(i+front)%MaxQSize]<<endl;            
       }      
};    
