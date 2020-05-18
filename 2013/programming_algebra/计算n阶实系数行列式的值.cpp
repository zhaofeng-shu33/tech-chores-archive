//计算n阶实系数行列式的值 by 傅岱石 //if the order is somewhat small ,it is all right.
// 2013.11.2 
#include <iostream>
using namespace std;
double sign( int n )                                //符号函数 
{
    if( n % 2 == 1 )
        return -1.0;
    return 1.0;
}    
int N( int k[], int n )                             //逆序函数,也是数出来的。 
{
    int s = 0;
    for( int i = 0; i < n - 1; i ++ )
        for( int j = i + 1; j < n; j ++ )
            if( k[i] > k[j] )
                s = s + 1;
    return s;
}
bool bePermutation( int k[], int n )                //判断是否为排列函数（有无更佳方法？） 
{
    int s = 0, p = 1;
    for( int i = 1; i <= n; i ++ )
        p = p * i;//p=n!;
        int t=1;
    for( int i = 0; i < n; i ++ )
    {
        s = s + k[i];
        t*= k[i];//Do not use the integer division.
    }
    if( s == n * ( n + 1 ) / 2 && p == t )
        return true;
    else return false;  
}
int add( int m, int n )                             //步进函数 Part I 
{
    if( m != n )//n进制 
        return m + 1;
    /*（写不写else这里都一样）*/ else return 1;
}
int * step_forward( int k[] ,int n )                //步进函数 Part II 
{
    int i = n - 1;//从最后一位开始。 
    for( ; ; )
    {
        k[i] = add( k[i], n );
        if( k[i] != 1 )
            break;
        i = i - 1;
    }
    return k;
}    
void change_order( int * k, int n )                 //步进函数 Part III 
{
    for( ; ; )
    {
        step_forward(k,n);//相当于进位 
        if( bePermutation( k, n ) == true )//如果条件始终不能满足呢？ 
            return;
    }
}
int main()                                          //主函数 
{

  
    cout << "请输入所求行列式阶数n" << endl; 
    int n = 0;
    cin >> n;
    cout << "请按行或列依次输入行列式中的数" << endl;
    double a[n][n];
    for( int i = 0; i < n; i ++ )
        for( int j = 0; j < n; j ++ )
            cin >> a[i][j];
    
    int k[n];
    for( int i = 0; i < n; i ++ )
        k[i] = i + 1;//现在该数组是1~n的自然数排列。 
    double det = 0;
    double S;
    for( ; ; )//循环次数比n!大，比n的n次方小，为（n-1)*n^(n-1)+(n-2)*n^(n-2)+......+3*n^3+2*n^2+1*n+1;
    {
        S = sign( N( k, n ) );
        for( int j = 0 ;j < n; j ++ ){
           // cout<<'^'<<S<<'^'<<' ';
            S = S * a[j][k[j]-1]; //cout<<' '<<k[j]<<' '; 
        }
       // cout<<endl;      
        det = det + S;
            
        if( N( k, n ) != n * ( n - 1 ) / 2 )
            change_order( k, n );//core!
        else
            break;
    }
    cout << "所求结果为" << endl << det << endl; 
    
    return 0;
}
