#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iterator>
#include<deque>
#include<list>
#include<numeric>
using namespace std;
void input(int& b){
  cin>>b;
}  
bool compare(int a, int b){
  return a>b;
}
struct individual{
    int ID;
    string name;
    double score;
    individual& operator =(individual s){
      ID=s.ID;
      name=s.name;
      score=s.score;
      return *this;
    }  
   
};
ostream& operator << (ostream& fout,individual s){// can not overload <<
       fout<<s.ID<<' '<<s.name<<' '<<s.score;
       return fout; 
    }  
struct student_information{
    vector<individual> student_list;
    int total_number;
    student_information(): total_number(0),student_list(100){}
   void Add(int id, string name1, double grade){
        student_list[total_number].ID=id;
        student_list[total_number].name=name1;
        student_list[total_number].score=grade;
        total_number++;//cout<<total_number;
    }
    individual Search_AccordingTo_Name(string name1){
        for(int i=0;i<total_number;i++)
            if(student_list[i].name==name1)
               return student_list[i];
    }
    void delete_student(string name1){
         individual tem=Search_AccordingTo_Name(name1);
         //erase(&tem); ??
    }  
   
};  

int main(){
  student_information my;
  my.Add(2013012178,"free_wind",90);
  my.Add(2014012133,"Paula",91);
  
  cout<<my.Search_AccordingTo_Name("Paula");
 // Add(2013012177
  
  return 0;
}
 
