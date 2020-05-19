#include <string>
#include <iostream>
using namespace std;
int main()
{
	basic_string<char> s1;
	basic_string<char> s2 ("hello world");
	basic_string<char> s3 ("hello world", 5);
	basic_string<char> s4 ( s2, 6);
	cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
  cout<<s2.at(2);
  system("pause");
  return 0;

}
