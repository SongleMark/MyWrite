#include <stdio.h>
/*
生存期：变量定义------>变量销毁
作用域：变量的可访问性

局部变量：定义在函数内部的变量   包括形参


生存期：变量定义------>所在函数结束
作用域：变量定义------>所在函数结束
   */


void  fun()
{
		int b=10;
		printf("b = %d\n",b);
}



int main()
{
		int a;
		fun();
		printf("b=%d\n",b);
		return 0;
}
