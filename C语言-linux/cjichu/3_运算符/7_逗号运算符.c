#include <stdio.h>


int main()
{
		int a=1,b=2,c=3,d;

		//d=(a++,--b,c++,4);
		d=(a++,--b,c++);

		printf("a=%d,b=%d,c=%d,d=%d\n",a,b,c,d);
		return 0;
}
