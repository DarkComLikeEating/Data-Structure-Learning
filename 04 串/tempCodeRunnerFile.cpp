#include <iostream>
#include "顺序串.cpp"
#include "BF算法模式串匹配.cpp"

using namespace std;

int main() {
	SqString str1, str2;
	char str[100] = "Hello, World!";
	char a[100] = "llo";
	StrAssign(str1, str);
	StrAssign(str2, a);
	DispStr(str2);
	DispStr(str1);
	cout << BF(str1, str2);
	return 0;	
}
