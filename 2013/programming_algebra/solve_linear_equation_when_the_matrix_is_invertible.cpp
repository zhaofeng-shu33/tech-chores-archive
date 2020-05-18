#include<iostream>
#include<fstream>
#include <cstring>
#include<cmath>
#include<iomanip>
using namespace std;
//ofstream fout("answerOfExperimentProblem.txt");

double setprecision1(double n){
  return n;
} 
double setprecision(double n){ 
  ofstream fout("precision_adjust.txt");
  fout<<std::setprecision(3)<<n;
  fout.close();
  ifstream fin("precision_adjust.txt");
  fin>>n;
  fin.close();
  return n;
}  
void swap(double* a,double* b){
  double t=*a;
  *a=*b;
  *b=t;
 // cout<<*a<<' '<<*b<<endl;
}
bool is_solution(double *a,double* b,int index){
   for(int i=0;i<index;i++){
       double tem=0;
       for(int j=0;j<index;j++)
          tem+=a[i*index+j]*b[j];
       if(fabs(tem-b[i])>0.1){
         cout<<i<<' '<<tem<<' '<<b[i]<<endl;
       return false;
       }  
 }

 return true;
}   
class Matrix{
  public:
    Matrix(int a){
      order=a;
      initial_address=new double[order*order];
    }
    ~Matrix(){}
    void Set_Matrix(double* p){
      for(int i=0;i<order*order;i++){
          initial_address[i]=p[i];
      }  
    }
    void Print_Matrix(){
      for(int i=0;i<order;i++){
          for(int j=0;j<order;j++)
              cout<<initial_address[i*order+j]<<'\t';
          cout<<endl;
      }
    }     
  protected:
    int order;
    double* initial_address;
};  
class Linear_Equation: public Matrix{
  public:
    Linear_Equation(int a):Matrix(a){ 
      b=new double[a];
      solution_vector=new double[a];
    }
    ~Linear_Equation(){}
    void Set_Linear_Equation(double* a){
        for(int i=0;i<order;i++)
            b[i]=a[i];
     
    }
    void Print_Linear_Equation(){
         for(int i=0;i<order;i++){
           for(int j=0;j<order;j++)
              cout<<initial_address[i*order+j]<<'\t';
          cout<<b[i]; 
          cout<<endl;
         }
    } 
    void Solve();
    void show_solution(){
         cout<<"The order is "<<order<<endl;
         for(int i=0;i<order;i++)
             cout<<solution_vector[i]<<endl;
    }      
  private: 
    double* solution_vector,*b;
};  
int main(){
  //for(int n=2;n<20;n++){
/*  int n=4;
  double* p=new double[n*n];
  for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
         p[i*n+j]=1.0/(i+j+1);
  double* q=new double[n];
  for(int i=0;i<n;i++)
      q[i]=1;
  Linear_Equation my_linear_equation(n);
  my_linear_equation.Set_Matrix(p);
  my_linear_equation.Set_Linear_Equation(q); 
  my_linear_equation.Print_Linear_Equation();
  my_linear_equation.Solve();
  my_linear_equation.show_solution();
  delete [] p;
  delete [] q;
  cout<<n<<endl;
  //}  */
  double p[4]={0.00001,1,1,1};
  double q[2]={1,2};
  Linear_Equation my_linear_equation(2);
  my_linear_equation.Set_Matrix(p);
  my_linear_equation.Set_Linear_Equation(q);
  my_linear_equation.Print_Linear_Equation();
  my_linear_equation.Solve();
  my_linear_equation.show_solution();
  
 // fout.close();
  char ch;
  cin>>ch;
  return 0;
}    
void Linear_Equation::Solve(){
    for(int k = 0; k <= order - 2; k++ ){ //从矩阵第一行到第order-1行进行 高斯消去
       double max1=initial_address[k*order+k];int row=k;
        for(int i = k; i < order; i++ ){
            if(abs(initial_address[i*order+k])>abs(max1)){
                 max1=initial_address[k*order+k];
                 row=i;
               }
        }  
        if(row!=k){
           for(int j=k; j<order; j++)
             swap(initial_address+k*order+j,initial_address+row*order+j);
           swap(b+k,b+row);
        }  
          
      
      //上面的算法使用选主元的Gauss 消去法使得a[k][k]为所在列绝对值最大的元素。  
    /*  {
      b[k]/=initial_address[k*order+k]; double tem=initial_address[k*order+k];   
      for(int i=k;i<order;i++)         
          initial_address[k*order+i]/=tem;
      }  */
      //上面的代码解决将高斯消去的因子所在的行归一化的问题。 
     for(int i = k+1; i < order; i++ ){
         b[i]-=initial_address[i*order+k]*b[k]/initial_address[k*order+k];
         b[i]=setprecision(b[i]);
         
          for(int j=k+1; j< order; j++ ){
              initial_address[i*order+j]-=initial_address[i*order+k]*initial_address[k*order+j]/initial_address[k*order+k];
              initial_address[i*order+j]=setprecision(initial_address[i*order+j]);
          }  
     }
           
  }
 //上面的代码将矩阵化为上三角阵 
  solution_vector[order-1]=b[order-1]/initial_address[order*order-1]; //从最后一行开始求解。 
   solution_vector[order-1]=setprecision(solution_vector[order-1]);
  for(int i=order-2; i>=0; i--){
      double tem=0;
      for(int j=i+1;j<order;j++)
          tem+=initial_address[i*order+j]*solution_vector[j]; 
      solution_vector[i]=(b[i]-tem)/initial_address[i*order+i];//cout<<solution_vector[i]<<endl;
      solution_vector[i]=setprecision(solution_vector[i]);
   }      
  
}  
