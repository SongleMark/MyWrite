#include <stdio.h>

//  a  b  
int main()
{
		int a,b;
		printf("请输入两个整数：");
		scanf("%d%d",&a,&b);

		if(a>b)
				printf("a>b\n");
		else if(a<b)
		{
				printf("a<b\n");
		}
		else
		{
				printf("a==b\n");
		}
		return 0;
}
