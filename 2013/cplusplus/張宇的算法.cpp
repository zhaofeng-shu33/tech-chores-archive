# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;
int val[10000]={0};
int main()
{
    ifstream instr("names.txt");
    string str;
    vector<string> vec;
    while(instr >> str)
        vec.push_back(str);
    sort(vec.begin(),vec.end());
    //以上为排序部分
    //ofstream outstr("names_sorted.txt");
    for(int j = 0; j != vec.size(); ++j)
    {
        str = vec[j];
       // outstr << str << " ";//加注释的代码部分的作用是产生重排后的文件names_sorted.txt
        for(int i=0;i<str.length();i++)
        {
            if((str[i]>='A')&&(str[i]<='Z'))
                val[j]+=str[i]-'A'+1;
        }
    }
    instr.close();
    int sum = 0;
    for(int i=0;i<vec.size();++i)
        sum+=(i+1)*val[i];
    cout<<sum<<endl;
    return 0;
}
