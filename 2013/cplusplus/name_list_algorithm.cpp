#include<iostream>
#include<fstream>
#include <cstring>

using namespace std;
void swap(int& a, int& b){
    int t=a;
    a=b;
    b=t;
}
//Thid program links with a name list and devotes to sort all names in alphebatical order and calculate the total sum of name order multipied by alphebatical sum of every name.   
//design a program to sort the name list; total number is 5163
int alphabetical_sum(char a[]){
    int sum=0;
    for (int t= 0; a[t]!= '\0'; t++) 
         sum += (static_cast<int>(a[t])-64);
    return sum;       
}    
int main(){
    char a[6000][20];
    ifstream fin("names.txt");
    char sh;
    int i = 0, j = 0;
    while (fin >> sh) {
        if (sh == ',') {
            a[i++][j] = '\0';
            j = 0;
        }
        else if (sh != '"') {
            a[i][j++] = sh; //equal to a[i][j] = sh; j++; 
            //a[i][++j] = sh; 
        }
    }    
    cout<< i << " " << a[i-1] << endl;
    int n = i;
    
    for (int i = n-1; i >0; i--) {
        for (int j = 0; j < i; j++) {
            if (strcmp(a[j], a[j+1]) > 0) {//put the smallest to the last item
                char tmp[20];
                strcpy(tmp, a[j]);
                strcpy(a[j], a[j+1]);
                strcpy(a[j+1], tmp);
            }
        }
    //    cout << a[i] << endl;
    }    int sum=0;
    for(int i=0;i<n;i++)
        sum+=(i+1)*alphabetical_sum(a[i]);
    cout<<sum;
  //using bubble sort method to sort the alphabetic string.
 /* for(int i=0;i<5163;i++)
      for(int j=0
  */
  fin.close();
                            
  char ch;
  cin>>ch;
  return 0;
}             
