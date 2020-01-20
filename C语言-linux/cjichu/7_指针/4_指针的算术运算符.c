
#include <stdio.h>


int main()
{
		double a = 10;
		double *p = &a;

		printf("p=%p\n",p);

		p --;// p = p-1
		printf("p=%p\n",p);
		return 0;
}
