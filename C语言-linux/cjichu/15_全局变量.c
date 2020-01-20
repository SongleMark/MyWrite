#include <stdio.h>
#include "test.h"


/*

全局变量：
生存期：程序开始-----》程序结束
作用域：所有.c文件


   */


#if    0
extern int  g_num;//全局变量的声明


void  func()
{
		g_num = 100;
		printf("func:%d\n",g_num);
}

int  g_num = 10;//全局变量的定义


int main()
{
		g_num= 50;
		printf("main:g_num=%d\n",g_num);
		func();
        test();
		return 0;
}
#endif


int g_num = 100;
int main()
{
		int g_num = 10;
		printf("main:g_num=%d\n",g_num);
        {
				int g_num=200;
				printf("{}:g_nmum=%d\n",g_num);
		}
		printf("main:g_num=%d\n",g_num);

		return 0;
}
