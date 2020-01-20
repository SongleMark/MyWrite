#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


#if   0
int main()
{
		double x,ret;
		printf("请输入一个数：");
		scanf("%lf",&x);

	//	ret=sqrt(x);

		printf("ret=%.2lf\n",sqrt(x));
		return 0;
}
#endif

#if   0
int main()
{
		double x,y,ret;
		printf("请输入数据：");
		scanf("%lf%lf",&x,&y);
		ret=pow(x,y);
		
		printf("ret=%.2lf\n",ret);
		return 0;
}
#endif


#if   0
int  main()
{
		char a,ret;
		printf("请输入一个字符:");
		scanf("%c",&a);

//		ret=toupper(a);

		ret=tolower(a);
		printf("ret=%c\n",ret);
		return 0;
}
#endif


#if   0
int main()
{
		int a[5],i;
		srand(time(NULL));
		for(i=0;i<5;i++)
		{
				a[i]=rand()%100;
		}

		for(i=0;i<5;i++)
		{
				printf("%d\t",a[i]);
		}
		printf("\n");
		return 0;
}
#endif




int  main()
{
		int a=1,b=2;
		a++;
		b++;
		printf("a=%d,b=%d\n",a,b);
		exit(0);
		a++;
		b++;
		printf("a=%d,b=%d\n",a,b);
		return 0;
}
