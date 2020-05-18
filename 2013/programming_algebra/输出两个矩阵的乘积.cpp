#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
   cout.setf(ios::showpoint);
   cout.setf(ios::fixed);
   cout.precision(10);  
  double a[5];
  a[0]=39.0/14;
  a[1]=24.0/14;
  a[2]=54.0/14;
  a[3]=39.0/14;
  a[4]=54.0/14;
  double sum=0;
  for(int i=0;i<5;i++)
      sum+=(i+1-a[i])*a[i];
      
  cout<<sum;
    
    //This program calculates the matrix got by multiplication of two matrices.
    //To simplify the program, we regulates that every element of the matrices are integers.
    cout<<"Please input the number of line and the number of columms of a matrix."<<endl;
    int line1,column1;
    cin>>line1>>column1; 
    cout<<"Please input the number of line and the number of columms of another matrix."<<endl
        <<"Remeber the number of line you input are expected to equal to the number of column of the firet matrix."<<endl;                        
    int line2,column2;
    cin>>line2>>column2;
    if(column1!=line2){
      cout<<"illegal in cin!";
      exit(1);
    }
    int line3=line1,column3=column2;
    double* *mat1=new double*[line1], * *mat2=new double*[line2], * *mat3=new double*[line3];
    for(int i=0;i<line1;i++)
       mat1[i]=new double[column1];
    for(int i=0;i<line2;i++)
       mat2[i]=new double[column2];  
    for(int i=0;i<line3;i++)
       mat3[i]=new double[column3];          
    cout<<"now input value of all elements from the first line to the last line,\n"
        <<"from the first column to the last column, in the left matrix that takes part in the operation of multiplication.\n";
    for(int i=0;i<line1;i++)
       for(int j=0;j<column1;j++)
          cin>>mat1[i][j];          
    cout<<"Since you input the first matrix. \n"
        <<"You are expected to input the right matrix which takes part in the operation of multiplication.\n"; 
    for(int i=0;i<line2;i++)
       for(int j=0;j<column2;j++)
          cin>>mat2[i][j];
    for(int i=0;i<line3;i++)
       for(int j=0;j<column3;j++)
           mat3[i][j]=0;
    //All the lines of codes above are in the stage of preparation.
    //The following comes the core code.
    for(int i=0;i<line3;i++)
       for(int j=0;j<column3;j++)
           for(int k=0;k<column1;k++)
               mat3[i][j]+=mat1[i][k]*mat2[k][j];
    //The matrix have been calculated.
    //It will be cout in the next stage.
    cout<<"The outcome of the multiplication of two matrices are as follows:\n";
    for(int i=0;i<line3;i++)
       for(int j=0;j<column3;j++){
           cout<<mat3[i][j]<<'\t';
           if(j==column3-1)
              cout<<endl;   
       }         
    char ch;
    cin>>ch;
    return 0;
}

