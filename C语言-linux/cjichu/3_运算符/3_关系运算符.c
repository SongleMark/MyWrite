#include <stdio.h>
/*
   关系运算符:  >  >=  <  <=   ==  !=
   计算结果：   逻辑值，关系成立1,否则0

if(expre)
{
   语句块;
}

执行原理：条件为真，执行语句块，否则，跳过语句块，继续执行下面的语句


ps:
1,默认只能控制一条语句，如果控制两条或者以上要加上{}
2,条件表达式后面不要加分号
3,在c语言中，数值0表示假，其他任何数据都表示真
4,区分赋值运算符'='和关系运算符'=='


   */
/*
int main()
{
		int a=1,b=2;
		printf("a>b :%d\n",a>b);//  0
		printf("a<b :%d\n",a<b);//  1
		printf("a!=b :%d\n",a!=b);// 1
		printf("a==b :%d\n",a==b);//  0
		return 0;
}
*/


/*
int main()
{
		int num;
		printf("please  input data:");
		scanf("%d",&num);

		if(num%2 == 0)
		{
				printf("%d能被2整除！\n",num);
		        printf("hehe\n");
		}

		return 0;
}

*/



/*
int main()
{
		int a = 4;
		if(a)
		{
				printf("hehehe\n");
		}


		if(a == 0)
		{
				printf("我是个好人！\n");
		}


		if(a = 0)
		{
				printf("我很美！\n");
		}
		return 0;
}
*/


int main()
{
		int num;
		printf("please input  data:");
		scanf("%d",&num);

		if(num%2 == 0)
		{
				printf("%d能被2整除！\n",num);
		}
		else
		{
				printf("%d不能被2整除！\n",num);
		}

		printf("hehehe\n");
		return 0;
}


