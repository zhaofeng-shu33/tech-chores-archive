#include <iostream>
#include "MinHeap.h"
#include "pqueue.h"
using namespace std;
int main()                                          //Ö÷º¯Êý 
{
    int n=2;
    student studentGroup[n];
    for(int i=0;i<n;i++){
        studentGroup[i].setID(i);
       // myHeap.Insert(studentGroup[i]);
    }
    int teacherNum=1;
    teacher te1;
    te1.setID(1);
    int currentTeacherIndex=0;

    PQueue<int> myqueue;
    for(int i=5;i>0;i--)
        myqueue.Insert(i);
    int x;
    while(!myqueue.IsEmpty()){
    myqueue.RemoveMin(x);
    cout<<x<<endl;}
    /* for(int i=0;i<n;i++){


                    r=-1;
                }
               }
            while(!myqueue.isEmpty())myHeap.Insert(myqueue.dequeue());

        }
        else{
            teacherNum++;
            teacher te2;
            te2.setID(teacherNum);
            myHeap.Insert(te2);
            j--;
            myHeap.Insert(te1);
        }


     }
    }
    cout<<teacherNum<<endl;
    for(int i=0;i<n;i++)
    studentGroup[i].printTeacher();
*/
    system("pause");
  
    return 0;
}
