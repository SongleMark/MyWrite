#include <stdio.h>
#include "test.h"
static int g_num = 10;
/*
静态全局变量：
生存期：程序开始------》程序结束
作用域：   本.c文件


   */


void  fun()
{
//		g_num = 100;
		printf("fun:%d\n",g_num);
}



int main()
{
		g_num = 200;
		printf("main:g_num=%d\n",g_num);
		fun();
//		test();
		return 0;
}
