#include <stdio.h>

void  fun1();
void  fun2();
void  fun3();



void  fun1()
{
		fun2();
		printf("AAAAAAA\n");
}


void  fun2()
{
		fun3();
		printf("BBBBBB\n");
}


void  fun3()
{
		printf("CCCCCC\n");
}


int main()
{
		fun1();
		return 0;
}
