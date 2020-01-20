#include <stdio.h>
/*
1, 数据类型  数组名[数组大小];
   除了定义数组时，下标中的数字表示数组的元素个数，除此情况以外，所有数组名和下标的组合
    表示第几个元素
2,  通过下标访问每个元素,下标从0开始的


3, 使用数组不要越界



   */

#if   0
//初始化
int main()
{
//		int age[5]={1,2,3};//  age数组名   5 数组元素个数   
		           // age[0]=1   age[1]=2 ....

		int age[]={1,2,3,4,5};//省略数组元素个数，必须要有初始化列表
		int i;
		for(i=0;i<5;i++)
		{
				printf("age[%d]=%d\n",i,age[i]);
		}
		return 0;
}
#endif
#if   0
//赋值
int main()
{
		double a[5];
//		a[5]={1.1,2.2,3.3,4.4,5.5};//error

		int  i;
		for(i=0;i<5;i++)
		{
				a[i]=i+1 + (double)(i+1)/10;
		}


		for(i=0;i<5;i++)
		{
				printf("a[%d]=%.2lf\n",i,a[i]);
		}


		return 0;
}
#endif




int main()
{
		int a[5];

	//	int b;
	//	scanf("%d",&b);


		int  i;
		for(i=0;i<5;i++)
		{
				printf("请输入第%d个元素:",i+1);
				scanf("%d",&a[i]);
		}

		for(i=0;i<5;i++)
		{
				printf("a[%d]=%d\n",i,a[i]);
		}
		return 0;
}
