#include<stdio.h>

#if   0
int main()
{
		int a[3][4]={
		     {1,9,-8,0},
		     {11,19,-28,10},
		     {21,93,-81,-110}
		};

		int  (*p)[4]=NULL;
		p = &a[0];

		int  i,j,max=a[0][0],m=0,n=0;
		for(i=0;i<3;i++)
		{
				for(j=0;j<4;j++)
				{
						if(*(*(p+i)+j) >max)
						{
								max = *(*(p+i)+j) ;
								m = i;
								n = j;
						}
				}
		}

		printf("max = %d,m=%d,n=%d\n",max,m,n);
		return 0;
}
#endif

#if    0

int main()
{
		int a[3][4]={
		     {1,9,-8,0},
		     {11,19,-28,10},
		     {21,93,-81,-110}
		};


		int  (*p)[4]=NULL;
		p = a;

		int i,j;
		double ave=0;
		for(j=0;j<4;j++)
		{
				for(i=0,ave=0;i<3;i++)
				{
						ave+=*(*(p+i)+j);
				}
				printf("%.2lf\t",ave/3);
		}
		printf("\n");
		return 0;
}
#endif



#include <stdio.h>


int main()
{
		int  a[6]={1,2,3,4,5,6};
		int  i,j;
		int *p[3];
		for(i=0,j=0;i<6;i++)
		{
				if(i%2==0)
				{
                      p[j++]= &a[i];
				}
		}

#if  0
		for(i=0;i<3;i++)
		{
				for(j=0;j<2;j++)
				{
						//printf("%d\t",*(p[i]+j));
						printf("%d\t",p[i][j]);
				}
		}
#endif


		for(i=0;i<2;i++)
		{
				for(j=0;j<3;j++)
				{
						printf("%d\t",p[j][i]);
				}
		
		}
		printf("\n");

		return 0;
}
