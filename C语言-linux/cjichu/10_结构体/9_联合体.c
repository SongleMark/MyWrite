#include <stdio.h>

union  s
{
		char a;
		int b;
};


int main()
{
		union s s1;
		s1.b = 0x11223344;
		printf("s1.a = %#x\n",s1.a);
		printf("s1.b = %#x\n",s1.b);
//		printf("sizeof(union s)=%lu\n",sizeof(union s));
		return 0;
}
