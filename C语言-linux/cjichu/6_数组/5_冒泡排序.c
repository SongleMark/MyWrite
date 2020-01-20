#include <stdio.h>

#define  NUM   5
int main()
{
		int a[NUM]={99,0,-1,55,-100};

		int i,j,temp;

		for(i=0;i<NUM-1;i++)
		{
				for(j=0;j<NUM-1-i;j++)
				{
						if(a[j]>a[j+1])
						{
								temp=a[j];
								a[j]=a[j+1];
								a[j+1]=temp;
						}
				}
		}


		for(i=0;i<NUM;i++)
		{
				printf("%d ",a[i]);
		}
		printf("\n");
		return 0;
}
