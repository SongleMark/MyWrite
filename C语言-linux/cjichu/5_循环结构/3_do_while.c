#include <stdio.h>
/*
do
{
    循环体
}while(条件表达式);
工作原理：先执行循环体,然后进行条件判断，如果条件为真，继续执行循环体，
          如果为假，则执行循环结构下面的程序


注意事项：
1,定义循环变量要初始化
2,在循环体内要改变循环变量的值
3,条件表达式后面要加分号


   */
#if   0
int main()
{
		int i=1;

		do
		{
				printf("hehe\n");
				i++;
		}while(i<=3);
		return 0;
}
#endif


#if   0
//break
int main()
{
        int i=1;
		do
		{
				if(i>3)
				{
						break;
				}
				printf("hehe\n");
				i ++;
		}while(1);
		return 0;
}
#endif



int main()
{
		int i=1;
		do
		{
				if(i%2!=0)
				{
						i++;
						continue;
				}
				printf("%d ",i);
				i++;
		}while(i<=10);
		printf("\n");
		return 0;
}


