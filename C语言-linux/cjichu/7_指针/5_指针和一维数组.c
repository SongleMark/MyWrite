#include <stdio.h>

#if   0
int main()
{
		int a[5]={1,2,3,4,5};
		int *p = a;

		while(p<a+5)
		{
				(*p)++;
				p ++;
		}

        p = &a[0];
 		while(p<a+5)
		{
				printf("%d\t",*p);
				p ++;
		}
		printf("\n");
		return 0;
}

#endif


#if   0
int main()
{
		int a[5]={1,2,3,4,5};

		int i;
		int  *p = &a[0];
		for(i=0;i<5;i++)
		{
				*(p+i)=*(p+i)+1;
		}


		for(i=0;i<5;i++)
		{
				printf("%d\t",*(p+i));
		}
		printf("\n");
		return 0;
}
#endif



int main()
{
		int a[5]={1,2,3,4,5};

		int i,*p=a;

		for(i=0;i<5;i++)
		{
				p[i] ++;
		}


		for(i=0;i<5;i++)
		{
				printf("%d\t",p[i]);
		}
        printf("\n");
		return 0;
}
