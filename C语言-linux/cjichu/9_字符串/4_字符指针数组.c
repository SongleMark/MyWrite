#include <stdio.h>

int main()
{
		char *a[5]={"apple","orange","banana","lemon","mango"};

		int i;


		for(i=0;i<5;i++)
		{
				printf("a[%d]=%s\n",i,a[i]);
		}
		return 0;
}
