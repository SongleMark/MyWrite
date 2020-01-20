#include <stdio.h>


int main()
{
		char c1,c2;
		printf("please  input data:");
		c1=getchar();
		setbuf(stdin,NULL);
		c2 =getchar();
		setbuf(stdin,NULL);
        putchar(c1);
        putchar(c2);
        putchar('\n');
		return 0;
}
