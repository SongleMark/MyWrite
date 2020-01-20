#include <stdio.h>
/*
整型：


int                4字节
unsigned  int      4字节

short int          2字节
unsigned  short int 2字节


long int          64位：8字节     32位：4字节
unsigned long  int   同上




   */


/*

变量命名规则：
1,由数字，字母，下划线组成
2,除了下划线，不允许有其他特殊字符
3,首字母必须是字母或者下划线
4,中间不允许由空白字符
5,不允许关键字作为变量名
6,区分大小写

   */


int main()
{
		int age=18;

		age = 25;

		short  int  age1 = 90;

		age1 = 32768;   //越界啦


		return 0;
}
