//#include <iostream>
//#include <cmath>
#include "Complex1001.h"
using namespace std;
int main(){
    Complex * a = new Complex();
    Complex * b = new Complex();
    (*a).Input();
    b->Input();
    Complex * a2 = new Complex(*a);
    a2->Mul(*a);
    Complex * b2 = new Complex(*b);
    b2->Mul(*b);
    Complex sum; 
    sum= comp_add(*a2,*b2);
    sum.Output();
    delete b2; delete a2;
    delete b; delete a;

system("pause"); 
 return 0;
}

