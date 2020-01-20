#include <stdio.h>
//二维数组是按行连续的
//二维数组行数可以省略，列数不可以省略
#if   0
int main()
{
	int a[4][2]={1,2,3,4,5,6,7,8};

	int i,j;

	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}

#if  0
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("&a[%d][%d]=%p\t",i,j,&a[i][j]);
		}
		printf("\n");
	}
#endif



	return 0;
}

#endif



int main()
{
	int a[4][2];

	int  i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("请输入第%d行第%d列的数据:",i+1,j+1);
			scanf("%d",&a[i][j]);

		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
