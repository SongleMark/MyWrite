#include <stdio.h>

#if 0
// &&    运算规则：两个条件同时成立结果为1,否则为 0 
int main()
{
		int a=1,b=2;
        printf("a<b && a!=b :%d\n",a<b&&a!=b);   // 1
        printf("a>b && a!=b :%d\n",a>b&&a!=b);   // 0
        printf("a<b && a==b :%d\n",a<b&&a==b);   // 0
        printf("a>b && a==b :%d\n",a>b&&a==b);   // 0
		return 0;
}
#endif
#if  0
int main()
{
		char ch;
		printf("please input data:");
		scanf("%c",&ch);

		if(ch>='a'&& ch<='z')
		{
				printf("%c是小写字符!\n",ch);
		}
		else
		{
				printf("%c不是小写字符!\n",ch);
		}
		return 0;
}

#endif


#if   0
int main()
{
		int a=1,b=2;
		if(a>b && ++b)//如果第一个表达式为假，则后面的表达式就不会执行了
		{
				printf("hehehe\n");
		}

		printf("a=%d,b=%d\n",a,b);  //a=1  b=2
		return 0;
}
#endif


#if  0
//  ||:  运算规则：两个表达式同时不成立结果为0,否则1
int main()
{
		int a=1,b=2;

		printf("a<b || a!=b:%d\n",a<b ||a!=b);//   1
		printf("a>b || a!=b:%d\n",a>b ||a!=b);//   1
		printf("a<b || a==b:%d\n",a<b ||a==b);//   1
		printf("a>b || a==b:%d\n",a>b ||a==b);//   0
		return 0;
}
#endif

#if   0
int main()
{
		int num;
		printf("请输入一个整数：");
		scanf("%d",&num);

		if(num%3 == 0 || num%5==0)
		{
				printf("num = %d\n",num);
		}
		return 0;
}

#endif


#if   0
int main()
{
		int a=1,b=2;
		if(a<b ||  ++b)//如果第一个表达式为真，则后面的表达式就不执行了
		{
				printf("hehehe\n");
		}
		printf("a=%d,b=%d\n",a,b);//  a=1,b=2
		return 0;
}
#endif




//  ！

#if  0
int  main()
{
		int a=5,b=0;
		printf("!a :%d\n",!a);//0
		printf("!b:%d\n",!b);// 1

		return 0;
}
#endif

int main()
{
		int num;
		printf("please input data:");
		scanf("%d",&num);

		if(!(num%5) )
		{
				printf("%d能被5整除！\n",num);
		}
		return 0;
}


