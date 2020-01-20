#include <stdio.h>
/*

静态局部变量：
作用域：  定义函数内部
生存期：程序开始-----》程序结束

   */

void  func()
{
		static int a=1;//静态局部变量
		a++;
		printf("a=%d\n",a);
}


int main()
{
		int i=1;
		for(i=0;i<5;i++)
		{
			func();
		}
		printf("a =%d\n",a);
		return 0;
}
