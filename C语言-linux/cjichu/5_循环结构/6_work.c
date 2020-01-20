/*
for:

1，打印
1 *  10  = 10
2 *  10  = 20
3 *  10  = 30
4 *  10  = 40
5 *  10  = 50
6 *  10  = 60
7 *  10  = 70
8 *  10  = 80
9 *  10  = 90
#include <stdio.h>

int main()
{
		int  i;
		for(i=1;i<=9;i++)
		{
				printf("%d * 10 = %d\n",i,i*10);
		}
		return 0;
}

*/

/*

2,  从键盘输入一个整数n，计算 n!

   */



#include <stdio.h>

int main()
{
		int i,n,s=1;
		printf("请输入一个整数:");
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
				s *= i;
		}
		printf("%d! = %d\n",n,s);
		return 0;
}
