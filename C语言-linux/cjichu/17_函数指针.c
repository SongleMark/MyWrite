#include <stdio.h>

#if   0
void   function()
{
		int a=10;
		printf("a = %d\n",a);
}
//  void  (*pfun)()
int  main()
{
//		function();

		void  (*pfun)()=NULL;
        pfun = function ;
		pfun();// 回调函数
		return 0;
}
#endif

int add(int a,int b)
{
		return a+b;
}


int sub(int a,int b)
{
		return a-b;
}

int mul(int a,int b)
{
		return a*b;
}

int  div(int a,int b)
{
		return a/b;
}


int main()
{
		int sel,re;
        int (*pfun)(int,int)=NULL;
		while(1)
		{
				printf("1,add\n");
				printf("2,sub\n");
				printf("3,mul\n");
				printf("4,div\n");
                printf("5,exit\n");
				scanf("%d",&sel);
				if(sel == 1)
				{
					//	re=add(2,3);
						pfun = add;
				}
				else if(sel == 2)
				{
					//	re = sub(2,3);
						pfun = sub;
				}
				else if(sel == 3)
				{
				//		re = mul(2,3);
						pfun = mul;
				}
				else if(sel == 4)
				{
				//		re = mul(2,3);
						pfun = div;
				}
				else if(sel == 5)
				{
						break;
				}
				pfun(2,3);
                printf("re = %d\n",re);
		}
		return 0;
}

