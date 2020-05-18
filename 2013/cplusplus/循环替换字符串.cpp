#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;
void process(char* str,int l,int r){//写好的程序代码已过提交期限。 
    int n1;
    
    char sh=str[l-1];//这里寻找最小数的方式太慢！ 
    for(int i=l;i<r;i++)
        if(str[i]<sh)
           sh=str[i];
            
    
        n1=static_cast<int>(sh);
    
       for(int i=(l-1);(i<=(r-1));i++){
           if((n1+i-(l-1))<=122)
        str[i]=static_cast<char>(n1+i-(l-1));
        else{
           int  tem=(n1+i-(l-1)-26);
           
            while(tem>122 ){
                if(tem<26000)
                      tem-=26;
                else if(tem>(26130))
                      tem-=26000;
                else
                    tem-=25870;
                  }    
                  
            str[i]=static_cast<char>(tem);
        }}
}    
int main()
{
    string S;
    cin>>S;
    char* str=new char[S.length()+1];
    sprintf(str, "%s", S.c_str());
    int n;
    cin>>n;
    while(n--){
        int l,r;
        cin>>l>>r;
        process(str,l,r);
        cout<<str<<' ';
    }    
    cout<<str<<endl;
    delete[] str;                
    char ch;
    cin>>ch;
    return 0;
} 
