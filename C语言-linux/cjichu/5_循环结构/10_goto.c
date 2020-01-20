#include <stdio.h>

#if   0
int main()
{
LOOP:
		printf("hehe\n");
		goto LOOP;
		return 0;
}
#endif



int main()
{
		int i,j;
		for(i=0;i<5;i++)
		{
				for(j=0;j<10;j++)
				{
						printf("i=%d,j=%d\n",i,j);
						if(j == 3)
								goto  LOOP;
				}

		}
LOOP:
		return 0;
}
