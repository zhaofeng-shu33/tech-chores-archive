#include <iostream>
#include <stdio.h>
#include <sstream>
#include <string>
#include <locale>

#include <locale>
using namespace std;
int main()
{
/*	BYTE a=0x0b;//single byte int type
  LPRECT b=new RECT;
  b->top=100;
 	printf("%d",b->top);
*/
  wchar_t a=L'��';
  wchar_t *str = L"hello";
  //basic_string<wchar_t> s(L"hello");
  //wcout.imbue(locale("chs"));
//	wcout <<"size is: " << sizeof(s[1]) << endl << s << endl; 
  printf("%#x\n",a); //C means wide character 
  printf("%#x\n",str[0]);//S means wide character string
  
	return 0;

}
	

