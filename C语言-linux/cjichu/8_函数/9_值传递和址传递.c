#include <stdio.h>

// 数值传递
void  function1(int a)
{
		a = 10;
}


//地址传递
void  function2(int *a)
{
		*a = 10;
}

int main()
{
		int  a=0;
		//function1(a);
		function2(&a);
		printf("a = %d\n",a);
		return 0;
}
