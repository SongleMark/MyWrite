#include <stdio.h>
/*
return:
1,结束本函数
2,返回一个值
3,如果返回值和返回值类型不匹配，直接将返回值自动转换成返回值类型，然后输出


   */
int   function()
{
		int a=0;
        double b=12.56;
		printf("a=%d\n",a);
		return b;
		a++;
		printf("a=%d\n",a);
}

int main()
{
		printf("%d\n",function());
		int a=1,b=2;
		a++;
		b++;
		printf("a=%d,b=%d\n",a,b)	;
		return 0;
		a++;
		b++;	
		printf("a=%d,b=%d\n",a,b)	;
		return 0;
}
