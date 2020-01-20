#include <stdio.h>
/*

for(表达式1;表达式2;表达式3)
{
    循环体;
}

工作原理:首先执行表达式1,初始化循环变量,然后执行表达式，进行条件判断，如果条件为真，
         执行循环体，然后再执行表达式3,改变循环变量的值，再去执行嗯表达式2;
		 如果为假，跳出循环，继续执行循环结构下面的程序
注意事项：
1,表达式1只执行一次，可以省略，但在循环之前要初始化循环变量
2,表达式2可以省略，默认表示条件为真
3,表达式3可以省略，但在循环体最后要改变循环变量的值

   */


#if   0
int main()
{
		int i=1;

		for(i=1;i<=5;i++)
		{
				printf("hehe\n");
		}
		return 0;
}
#endif


#if   0
int main()
{
        int i=1;
		for(;;i++)
		{
				printf("hehe\n");
				if(i==5)
				{
						break;
				}
		}
		return 0;
}
#endif


//  在for中遇到continue,那么循环体下面的语句就不会执行，直接执行表达式3,然后再执行表达式2
int main()
{
		int i;
		for(i=1;i<=10;i++)
		{
				if(i%2 != 0)
				{
						continue;
				}
				printf("%d ",i);
		}
		printf("\n");
		return 0;
}
