

#include <stdio.h>
#include "test.h"
/*
1,一般一个 ××.c   提供一个  ××.h
   ××.c文件中提供函数定义
   ××.h文件中提供所有函数声明
2,如果一个××.c文件调用另外一个 ××.c文件的函数,
   需要做的工作:
   1)包含对应 .c文件的头文件
   2)编译时要和对应.c文件一起编译

3,包含c库头文件使用 <>
  包含自己自定义的头文件 " "


4,防止头问加重复包含
 #ifndef   _头文件名称大写
#define   _头文件名称大写
......
#endif


5,默认包含的头文件在当前路径，如果在其他路径的解决方案
 1)#include "../inc/stdio.h"
 2)gcc  -I  ../inc  main.c  test.c   -o  main



   */

int  main()
{
		int x=2,y=3;

		printf("%d\n",my_pow(x,y));

		return 0;
}
