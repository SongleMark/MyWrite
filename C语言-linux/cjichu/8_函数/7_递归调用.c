



#include <stdio.h>

int factorial(int a) 
{
		if (a == 1)
				return 1;
		else
		{
				a = a * factorial(a-1);
				return a;
		}
}



int main()
{
		printf("%d\n",factorial(5));
		return 0;
}
