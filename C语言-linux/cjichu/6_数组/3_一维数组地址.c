#include <stdio.h>
/*
1,数组每个元素的起始地址
 &a[0]  &a[1]  ......&a[n]   ------>表示第n+1个元素的起始地址
 a      a+1    ......a+n   

2,数组名表示数组首元素的起始地址，同时相当于一个常量，不可改变


3,&a    &a+1



4,sizeof(a)


   */

int main()
{
		int a[5]={1,2,3,4,5};
		printf("sizeof(a)=%lu\n",sizeof(a));

        int i;
		for(i=0;i<5;i++)
		{
				printf("&a[%d]=%p\n",i,&a[i]);
		}

		printf("a = %p\n",a);

		printf("\n==============================================\n");
		for(i=0;i<5;i++)
		{
				printf("a+%d = %p\n",i,a+i);
		}
		

		printf("\n==============================================\n");
		printf("&a = %p\n",&a);
		printf("&a+1 = %p\n",&a+1);


         for(i=0;i<5;i++)
		 {
				 printf("a[%d]=%d\n",i,a[i]);
		 }

		return 0;
}
