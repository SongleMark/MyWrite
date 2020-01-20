#include <stdio.h>

#if   0
int main()
{
		char a[5][128]={"apple","orange","banana","lemon","mango"};

		int i;

        for(i=0;i<5;i++)
		{
				(*(a[i]))  -= 32;
		}

		for(i=0;i<5;i++)
		{
				printf("a[%d]:%s\n",i,a[i]);
		}
		return 0;
}
#endif



int  main()
{
		char a[] = "hello";
		printf("%p\n",a);
		printf("%s\n",a);
		printf("%c\n",*a);
		return 0;
}
