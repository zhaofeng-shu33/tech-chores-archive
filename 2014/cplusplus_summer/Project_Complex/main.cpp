#include "Complex.h"
using namespace std;
struct student{
  string name;
}mystudent;   
int main(){
  mystudent.name="zhao";
  cout<<mystudent.name;
  complex a(4,5);
  complex b=complex(2,3); 
  complex c=a-b;
  
  return 0;
}
