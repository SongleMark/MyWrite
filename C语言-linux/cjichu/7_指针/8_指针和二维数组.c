#include <stdio.h>
/*
定义一个 double a[4][3];
通过数组指针打印第一维数组每个元素的起始地址
通过数组指针打印第二维数组每个元素的起始地址
通过数组指针打印第二维数组每个元素的内容

   */


int main()
{
		int a[3][4]={
				{1,2,3,4},
				{5,6,7,8},
				{11,22,33,44}
		};


		int (*p)[4]=NULL;
		p = &a[0];

        int i,j;
		printf("第一维数组每个元素的起始地址:\n");

		for(i=0;i<3;i++)
		{
				printf("p+%d = %p\n",i,p+i);
		}
	    

		printf("第二维数组每个元素的起始地址:\n");
		for(i=0;i<3;i++)
		{
				for(j=0;j<4;j++)
				{
						printf("*(p+%d)+%d = %p\t",i,j,*(p+i)+j);
				}
				printf("\n");
		}

		printf("第二维数组每个元素内容：\n");
		for(i=0;i<3;i++)
		{
				for(j=0;j<4;j++)
				{
						printf("*(*(p+%d)+%d)=%d\t",i,j,*(*(p+i)+j));
				}
				printf("\n");
		}
		return 0;
}
