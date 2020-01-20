#include <stdio.h>
/*
sizeof:
ps:
1,计算数据类型或者变量在内存中所占的内存大小
2,计算结果是  long  unsigned  int 
3,计算结果的单位  字节

   */

int main()
{
		printf("sizeof(int)=%lu,sizeof(double)=%lu\n",sizeof(int),sizeof(double));
		return 0;
}
