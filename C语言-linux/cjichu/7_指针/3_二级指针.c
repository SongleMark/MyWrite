#include <stdio.h>



int main()
{
		int a = 10;
		int *p = &a;
		int* *q = &p;

		printf("a=%d,*p=%d,**q=%d\n",a,*p,**q);
		printf("&a=%p,p=%p,*q=%p\n",&a,p,*q);
		printf("&p=%p,q =%p\n",&p,q);
		printf("&q=%p\n",&q);
		return 0;
}
