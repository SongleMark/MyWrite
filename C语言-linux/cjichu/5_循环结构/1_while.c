#include <stdio.h>
/*
while(条件表达式)
{
    循环体;
}

工作原理：首先条件判断，如果条件为真，执行循环体，然后再进行条件判断，如果为真，继续执行
      循环体，如果为假，则执行循环结构下面的语句

注意事项：
1.定义循环变量要初始化
2,循环体内要改变循环变量的值，一般在循环体最后改变
3,循环体默认只能控制一条语句，如果两条或者以上必须加{}
4,不要在条件表达式后面加分号
   */
#if   0
int main()
{
		int i=1;

		while(i<=5)
		{
				printf("hello world\n");
				i++;
		}
		printf("循环结束!\n");
		return 0;
}
#endif


/*
break:
1,跳出switch
2,跳出循环结构：一旦在循环体中遇到break关键字，则循环体下面的语句就不会执行了，
             直接跳出循环结构，继续执行整个循环结构下面的程序
*/

#if  0
int main()
{
		int i=1;
		while(1);
		{
				if(i>3)
				{
						break;
				}
				printf("hehehe\n");
				i ++;
		}
		printf("循环结束！\n");
		return 0;
}

#endif



// continue:结束本次循环，继续下一次循环

#include <stdio.h>


int main()
{
		int i=1;

		while(i<=10)
		{
				if(i%2 !=0)
				{
						i++;
						continue;
				}
				printf("%d ",i);
				i++;
		}
		printf("\n");
		return 0;
}
