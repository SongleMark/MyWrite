/*

定义一个double a[5],
(1)打印每个元素的起始地址(2种方法)
(2)打印数组的起始地址
(3)从键盘输入数据，输出每个元素的数据
(4)计算数组所占的内存大小并输出

   */

#include <stdio.h>
int main()
{
		double a[5];
		int i;
		for(i=0;i<5;i++)
		{
		     printf("&a[%d]=%p\n",i,&a[i]);
		}

		for(i=0;i<5;i++)
		{
				printf("a + %d =%p\n",i,a+i);
		}

		printf("&a = %p,&a+1=%p\n",&a,&a+1);
		return 0;
}

