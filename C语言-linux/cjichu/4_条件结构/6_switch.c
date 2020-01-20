#include <stdio.h>
/*
switch(条件表达式)
{
   case  常量1:
       ....
	   break;
   case  常量2:
       ....
	   break;
   case  常量3:
       ....
	   break;
   ....
   default:
       ....
	   break;
}


注意事项：
1,default可以省略，同时位置不固定，所有后面要加上break;
2,分支由多条语句可以不用加{}，有结束标志break;
3,case后面的常量整型的常量表达式，不允许有变量
4,代码块不可以定义变量
5,如果每个分支都是独立的，那么每个分支后面都要加break关键字，否则会发生穿透现象
   */
int main()
{
		char ch;
	    char temp='a';
		printf("请输入一个字符:");
		scanf("%c",&ch);
       
		switch(ch)
		{
				default:
						printf("%c不是元音字符\n",ch);
						break;
				//error: case label does not reduce to an integer constant
				//case  97.0: // error
				case  'a':
						
						// error: a label can only be part of a statement and a declaration is not a statemen
					//	int temp;//  error
						printf("%c是元音字符\n",ch);
						break;
				case  'o':
						printf("%c是元音字符\n",ch);
						break;
				case  'e':
						printf("%c是元音字符\n",ch);
						break;
				case  'i':
						printf("%c是元音字符\n",ch);
						break;
				case  'u':
						printf("%c是元音字符\n",ch);
						break;
		}
		return 0;
}
