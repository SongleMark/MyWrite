#include <stdio.h>
/*
char             1字节      -128-127
unsigned  char   1字节      0-255

ps:
1,字符是以ascii码存储的
2,字符常量必须用英文下的单引号引起来
3,可以将字符常量赋值给字符变量，也可以将字符对应的ascii赋值给变量，但不可以超出范围，
  ascii码的八进制 '\0××',  十六进制 '\x××'


   */

int main()
{
		char sex='f';
		sex = '0';
        
		sex = 49;

		sex = 97;

        sex = '\062';
		sex = '\x33';


//        char a = '111';//  error


        char b = '\n';

		char  c = '\t';
		return 0;
}
