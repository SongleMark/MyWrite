#include <stdio.h>

/*
float    4字节
double   8字节


   */
int  main()
{
		float  a=3.14;//本质就是在内存中申请4字节空间，并命名为  a

		a = 4.56e2;

		double  gdp = 34.56e10;

		gdp = 5.67e100;
		return 0;
}
