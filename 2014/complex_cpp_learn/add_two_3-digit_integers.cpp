
#include <iostream>
using namespace std;

//------------Functions-------------------------//

void swap_values(int* variable,int length);

//----------------------------------------------//

const int SIZE = 3;

int main()
{
	
// Obtain number values from user
char number_1[SIZE];

int i;
cout<<"Please enter one integer up to " <<SIZE<<" digits in length"<<endl;

for (i = 0; i<SIZE && !cin.eof(); i++)
{
 cin>>number_1[i];
}

char number_2[SIZE]; // is there a way to limit input? or clear it between values?
cout<<"Please enter another integer up to " <<SIZE<<" digits in length"<<endl;
for (i = 0; i<SIZE; i++)
{
cin>>number_2[i];
}

// Convert char to int
int integer_1[SIZE];
int integer_2[SIZE];

cout<<"Integer 1: ";
for ( i = 0; i <SIZE; i++)
	{ integer_1[i] = number_1[i]-48;
	cout<<integer_1[i];
	}
	
  cout<<endl;
  
cout<<"Integer 2: ";
for (i = 0; i <SIZE; i++)
  { integer_2[i] = number_2[i]-48;
    cout<<integer_2[i];
  }
  cout<<endl;
  

// Reverse Order of Numbers
	
swap_values(integer_1,SIZE);
swap_values(integer_2,SIZE);

  
 
  
// Addition

int sum[SIZE+1]={0};

cout<<"Sum: ";

for(i=0;i<SIZE; i++)
{
	sum[i] = sum[i]+integer_1[i]+integer_2[i];
	
	if (sum[i] > 9)
	{
		sum[i+1] =1;  // Alternate to this?
    sum[i]-=10;	
  }
}
swap_values(sum,SIZE+1);
for(int i=0;i<SIZE+1;i++)
{
  cout<<sum[i];
}  

	return 0;
}

//-----------Function Definitions-----------------//


	 void swap_values( int* variable,int length) // How to make this function available for different value of SIZE?
{
		 for(int i =0; i<=(length-1)/2; i++)
		 {
			 swap(variable [i], variable[length-1-i]);
			 }
}



/*#include<iostream>
#include<fstream>
using namespace std;


int main(){
  int sum=0;  
  for(int i=0; i<100000;i++)
      sum+=i;
  cout<<sum;
  
  
  return 0;
}
 */
