#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string str;
	char ch[32]; // 不能用char *ch否则段错误
	sprintf(ch, "hello world %s", "hahha");
	str = ch;
	cout << str << endl;

	return 0;
}
